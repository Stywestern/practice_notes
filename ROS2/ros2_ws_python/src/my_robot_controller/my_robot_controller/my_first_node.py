#!/usr/bin/env python3

# ==========================================
# 1. IMPORTS & SETUP
# ==========================================

import rclpy
from rclpy.node import Node

# ==========================================
# 2. CLASSES
# ==========================================
class MyNode(Node):
    def __init__(self):
        super().__init__("first_node")
        self.counter_ = 0
        self.create_timer(1.0, self.timer_callback)


    def timer_callback(self):
        self.get_logger().info(f"Greetings {str(self.counter_)}")
        self.counter_ += 1

# ==========================================
# 3. PROCESS
# ==========================================

def main(args=None):
    #### ENTER ####
    rclpy.init(args=args)

    #### NODES ####
    node = MyNode()
    rclpy.spin(node)

    #### EXIT ####
    rclpy.shutdown()

if __name__ == '__main__':
    main()