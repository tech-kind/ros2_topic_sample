#!/usr/bin/env python3
# coding: utf-8

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy, QoSDurabilityPolicy, QoSLivelinessPolicy

from sample_msgs.msg import SimpleMsg

class SimpleSubscription(Node):

    def __init__(self):
        super().__init__("simple_subscription")
        logger = self.get_logger()

        self._num = 0

        depth = self.declare_parameter("qos_depth", 5)

        logger.info("param qos_depth={}"
            .format(depth.get_parameter_value().integer_value))
        
        profile = QoSProfile(depth=depth.get_parameter_value().integer_value)
        profile.reliability = QoSReliabilityPolicy.BEST_EFFORT
        profile.durability = QoSDurabilityPolicy.TRANSIENT_LOCAL
        profile.liveliness = QoSLivelinessPolicy.AUTOMATIC

        self.create_subscription(SimpleMsg, "sample_topic",
            self.on_message_callback, profile)
        
        logger.info("subscription start!")

    def on_message_callback(self, msg):
        self._num = msg.num
        self.get_logger().info("subscribe num={}".format(self._num))


def main(args=None):
    rclpy.init(args=args)

    node = SimpleSubscription()

    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
