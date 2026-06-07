#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class DrawHeartNode(Node):
    def __init__(self):
        super().__init__("draw_heart_n")
        self.cmd_vel_pub_ = self.create_publisher(Twist, "/turtle1/cmd_vel", 10)
        self.timer_ = self.create_timer(0.1, self.send_velocity_command)
        self.get_logger().info("Draw Heart Node Initiated")

        self.state = 0
        self.counter = 0
        self.msg = Twist()

    def send_velocity_command(self):
        # Reset velocities every loop
        self.msg.linear.x = 0.0
        self.msg.angular.z = 0.0

        # =====================================================
        # STEP 0: Turn Left 140 deg, turtle starts (this -->) direction
        # =====================================================
        if self.state == 0:
            self.msg.angular.z = 1.0
            # 2.44 radians = 140 degrees
            if self.counter >= 24:
                self.switch_state(1)
            else:
                self.counter += 1

        # =====================================================
        # STEP 1: Straight Line Up
        # =====================================================
        elif self.state == 1:
            self.msg.linear.x = 2.0
            if self.counter >= 15:
                self.switch_state(2)
            else:
                self.counter += 1

        # =====================================================
        # STEP 2: First Curve (The Left Lobe)
        # FIX: Increased duration 30 -> 35 to hit 200 degrees
        # FIX: Increased speed 1.0 -> 1.5 to match size
        # =====================================================
        elif self.state == 2:
            self.msg.linear.x = 1.5    
            self.msg.angular.z = -1.0  
            
            if self.counter >= 35: 
                self.switch_state(3)
            else:
                self.counter += 1

        # =====================================================
        # STEP 3: Turn Left 120 deg (Center of Heart)
        # =====================================================
        elif self.state == 3:
            self.msg.angular.z = 1.0
            # 2.09 radians = 120 degrees
            if self.counter >= 21:
                self.switch_state(4)
            else:
                self.counter += 1

        # =====================================================
        # STEP 4: Second Curve (The Right Lobe)
        # FIX: Same fixes as Step 2
        # =====================================================
        elif self.state == 4:
            self.msg.linear.x = 1.5
            self.msg.angular.z = -1.0
            
            if self.counter >= 35:
                self.switch_state(5)
            else:
                self.counter += 1

        # =====================================================
        # STEP 5: Straight Line Down
        # =====================================================
        elif self.state == 5:
            self.msg.linear.x = 2.0
            if self.counter >= 15:
                self.switch_state(6)
            else:
                self.counter += 1

        # =====================================================
        # STEP 6: Stop
        # =====================================================
        elif self.state == 6:
            self.msg.linear.x = 0.0
            self.msg.angular.z = 0.0
            self.get_logger().info("Heart Complete")
            self.timer_.cancel()

        self.cmd_vel_pub_.publish(self.msg)

    def switch_state(self, new_state):
        self.state = new_state
        self.counter = 0
        self.get_logger().info(f"Switching to State {new_state}")

def main(args=None):
    rclpy.init(args=args)
    node = DrawHeartNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
