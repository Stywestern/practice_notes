#!/usr/bin/env python3

# ==========================================
# 1. IMPORTS & SETUP
# ==========================================

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

# ==========================================
# 2. CLASSES
# ==========================================
class DrawCircleNode(Node):
    def __init__(self):
        super().__init__("draw_circle_n")
        self.cmd_vel_pub_ = self.create_publisher(Twist, "/turtle1/cmd_vel", 10)
        self.timer_ = self.create_timer(0.5, self.send_velocity_command)
        self.get_logger().info(f"Draw Circle Node Initiated")

    def send_velocity_command(self):
        msg = Twist()
        msg.linear.x = 2.0
        msg.angular.z = 1.0
        self.cmd_vel_pub_.publish(msg)


# ==========================================
# 3. PROCESS
# ==========================================

def main(args=None):
    #### ENTER ####
    rclpy.init(args=args)

    #### NODES ####
    node = DrawCircleNode()
    rclpy.spin(node)

    #### EXIT ####
    rclpy.shutdown()

if __name__ == '__main__':
    main()