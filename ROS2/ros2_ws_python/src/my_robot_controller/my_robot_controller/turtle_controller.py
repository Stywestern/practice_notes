#!/usr/bin/env python3

# ==========================================
# 1. IMPORTS & SETUP
# ==========================================

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from turtlesim.srv import SetPen
from functools import partial

# ==========================================
# 2. CLASSES
# ==========================================
class TurtleControllerNode(Node):
    def __init__(self):
        super().__init__("turtle_controller_n")
        self.previous_x_ = 0
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "/turtle1/cmd_vel", 10)
        self.pose_subscriber_ = self.create_subscription(Pose, "/turtle1/pose", self.pose_callback, 10)

        self.get_logger().info(f"Turtle Controller Initiated")

    def pose_callback(self, pose: Pose):
        cmd = Twist()
        if pose.x > 9 or pose.x < 2 or pose.y > 9 or pose.y < 2:
            cmd.linear.x = 1.0
            cmd.angular.z = 0.9
        else:
            cmd.linear.x = 5.0
            cmd.angular.z = 0.0

        if pose.x > 5.5 and self.previous_x_ <= 5.5:
            self.previous_x_ = pose.x
            self.get_logger().info("CODE RED")
            self.call_set_pen_service(255, 0, 0, 3, 0)
        elif pose.x <= 5.5 and self.previous_x_ > 5.5:
            self.previous_x_ = pose.x
            self.get_logger().info("CODE GREEN")
            self.call_set_pen_service(0, 255, 0, 3, 0)
            
        self.cmd_vel_publisher_.publish(cmd)
    
    def call_set_pen_service(self, r, g, b, width, off):
        client = self.create_client(SetPen, "turtle1/set_pen")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for service")

        request = SetPen.Request()
        request.r = r
        request.g = g
        request.b = b
        request.width = width
        request.off = off

        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_set_pen))

    def callback_set_pen(self, future):
        try:
            response = future.result()
        except Exception as e:
            self.get_logger().error(f"Service call failed: {e}")


# ==========================================
# 3. PROCESS
# ==========================================

def main(args=None):
    #### ENTER ####
    rclpy.init(args=args)

    #### NODES ####
    node = TurtleControllerNode()
    rclpy.spin(node)

    #### EXIT ####
    rclpy.shutdown()

if __name__ == '__main__':
    main()