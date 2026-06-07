/* ######################################                         SETUP                          ###################################### */
#include <rclcpp/rclcpp.hpp>

#include <std_msgs/msg/float64.hpp>
#include <std_srvs/srv/set_bool.hpp>

#include <chrono>
#include <thread>
#include <cmath>

#include <rclcpp_action/rclcpp_action.hpp>
#include "turret_control/action/rotate_turret.hpp"

/* ######################################                         CLASSES                           ###################################### */

/* ------------------------------ Primary Node --------------------------- */
class TurretNode : public rclcpp::Node {
  public:
      TurretNode() : Node("turret_node") {
         RCLCPP_INFO(this->get_logger(), "Turret System Online");

         publisher_ = this->create_publisher<std_msgs::msg::Float64>("turret_angle", 10);
         subscription_ = this->create_subscription<std_msgs::msg::Float64>("turret_command", 10, std::bind(&TurretNode::command_callback, this, std::placeholders::_1));
         safety_service_ = this->create_service<std_srvs::srv::SetBool>("toggle_safety", std::bind(&TurretNode::toggle_safety_callback, this, std::placeholders::_1, std::placeholders::_2));
         timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&TurretNode::publish_message, this));

         action_server_ = rclcpp_action::create_server<RotateTurret>(
            this,
            "rotate_turret",
            std::bind(&TurretNode::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
            std::bind(&TurretNode::handle_cancel, this, std::placeholders::_1),
            std::bind(&TurretNode::handle_accepted, this, std::placeholders::_1)
         );
      }


  private:
    /* ######################################
                Attributes 
      ###################################### */
      using RotateTurret = turret_control::action::RotateTurret;
      using GoalHandleRotateTurret = rclcpp_action::ServerGoalHandle<RotateTurret>;

      rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
      rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr subscription_;
      rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr safety_service_;
      rclcpp_action::Server<RotateTurret>::SharedPtr action_server_;

      rclcpp::TimerBase::SharedPtr timer_;

      double current_angle_ = 30.0;
      bool turret_active_ = false;

      /* ######################################
                Methods 
     ###################################### */

     // Publisher
     void publish_message(){
         std_msgs::msg::Float64 message;
         message.data = this->current_angle_; // Object has that attribute

         RCLCPP_INFO(this->get_logger(), "Publishing my angle: '%f' degrees", message.data);

         publisher_->publish(message);
     }

     // Subscription 
     void command_callback(const std_msgs::msg::Float64::SharedPtr msg){
         if (this->turret_active_){
            this->current_angle_ = msg->data; // Pointed object's attribute
            RCLCPP_INFO(this->get_logger(), "Recieving my angle: '%f' degrees", this->current_angle_);
         } else {
            RCLCPP_WARN_ONCE(this->get_logger(), "Ignored command: Turret is Locked!");
         }
     }

     // Service
     void toggle_safety_callback(
         const std::shared_ptr<std_srvs::srv::SetBool::Request> request,
         std::shared_ptr<std_srvs::srv::SetBool::Response> response){
         
         this->turret_active_ = request->data;
         response->success = true;

         if (this->turret_active_){
            response->message = "Turret Enabled. Weapons Free.";
            RCLCPP_WARN(this->get_logger(), "SAFETY DISENGAGED");
         } else {
            response->message = "Turret Disabled. Systems Down.";
            RCLCPP_INFO(this->get_logger(), "Safety Engaged");
         }
      }

      // Action
      rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const RotateTurret::Goal> goal){
         RCLCPP_INFO(this->get_logger(), "Recieved goal request for angle: %f", goal->target_angle);

         if (goal->target_angle < 0.0 || goal->target_angle > 360.0){
            RCLCPP_ERROR(this->get_logger(), "Goal Rejected: Angle out of bounds");
            return rclcpp_action::GoalResponse::REJECT;
         }

         (void)uuid; // Suppress warning
         return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
      }

      rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandleRotateTurret> goal_handle){
         RCLCPP_INFO(this->get_logger(), "Recieved request to cancel goal");
         (void)goal_handle;
         return rclcpp_action::CancelResponse::ACCEPT;
      }

      void handle_accepted(const std::shared_ptr<GoalHandleRotateTurret> goal_handle){
         // in order for the action loop to perform as expected it needs to be multi-threaded, the actions will take place in the thread while the main revieves commands
         std::thread{std::bind(&TurretNode::execute, this, std::placeholders::_1), goal_handle}.detach();
      }

      void execute(const std::shared_ptr<GoalHandleRotateTurret> goal_handle){
         RCLCPP_INFO(this->get_logger(), "Executing goal...");

         // 1. Setup
         rclcpp::Rate loop_rate(10); // 10hz
         const auto goal = goal_handle->get_goal();
         auto feedback = std::make_shared<RotateTurret::Feedback>();
         auto result = std::make_shared<RotateTurret::Result>();

         // 2. Movement Loop
         while (rclcpp::ok() && std::abs(this->current_angle_ - goal->target_angle) > 1.0){

            // A. Check if cancel
            if (goal_handle->is_canceling()){
               result->result_message = "Operation Cancelled by Operator";
               goal_handle->canceled(result);
               RCLCPP_WARN(this->get_logger(), "Goal Cancelled");
               return;
            }

            // B. Update Position
            if (this->current_angle_ < goal->target_angle){
               this->current_angle_ += 1.0;
            }else{
               this->current_angle_ -= 1.0;
            }

            // C. Publish Feedback
            feedback->current_angle = this->current_angle_;
            goal_handle->publish_feedback(feedback);
            RCLCPP_INFO(this->get_logger(), "Feedback: %f", this->current_angle_);

            // D. Next Cycle
            loop_rate.sleep();
         }

         // 3. Finish Task
         if (rclcpp::ok()){
            result->result_message = "Turret aligned successfully";
            goal_handle->succeed(result);
            RCLCPP_INFO(this->get_logger(), "Goal Succeeded");
         }
      }
};



/* ######################################                         PROGRAM START                           ###################################### */

int main(int argc, char const *argv[])
{
  /* ######################################
                Init ROS 
     ###################################### */
  rclcpp::init(argc, argv);

  /* ######################################
                Create Nodes 
     ###################################### */
  auto node1 = std::make_shared<TurretNode>();

  /* ######################################
                Setup Spin 
     ###################################### */
  rclcpp::spin(node1);

  /* ######################################
                Terminate Program 
     ###################################### */
  rclcpp::shutdown();

  return 0;
}

