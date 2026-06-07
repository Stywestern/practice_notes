#!/usr/bin/env python3

# ==========================================
# 1. IMPORTS & SETUP
# ==========================================

import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose

# ==========================================
# 2. CLASSES
# ==========================================
class PoseSubscriberNode(Node):
    def __init__(self):
        super().__init__("pose_subscriber_n")
        self.pose_subscriber_ = self.create_subscription(Pose, "/turtle1/pose", self.pose_callback, 10)

    def pose_callback(self, msg: Pose):
        self.get_logger().info(f"{str(msg.x), str(msg.y)}")


# ==========================================
# 3. PROCESS
# ==========================================

def main(args=None):
    #### ENTER ####
    rclpy.init(args=args)

    #### NODES ####
    node = PoseSubscriberNode()
    rclpy.spin(node)

    #### EXIT ####
    rclpy.shutdown()

if __name__ == '__main__':
    main()