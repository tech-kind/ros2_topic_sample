#!/usr/bin/env python3
# coding: utf-8

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy, QoSDurabilityPolicy, QoSLivelinessPolicy

from sample_msgs.msg import SimpleMsg

class SimplePublisher(Node):

    def __init__(self):
        super().__init__("simple_publisher")
        logger = self.get_logger()

        self._num = 0

        period = self.declare_parameter("period", 1.0)
        depth = self.declare_parameter("qos_depth", 5)

        logger.info("param period={}"
            .format(period.get_parameter_value().double_value))
        logger.info("param qos_depth={}"
            .format(depth.get_parameter_value().integer_value))
        
        profile = QoSProfile(depth=depth.get_parameter_value().integer_value)
        profile.reliability = QoSReliabilityPolicy.BEST_EFFORT
        profile.durability = QoSDurabilityPolicy.TRANSIENT_LOCAL
        profile.liveliness = QoSLivelinessPolicy.AUTOMATIC

        self._pub = self.create_publisher(SimpleMsg, "sample_topic", profile)

        self.create_timer(
            period.get_parameter_value().double_value,
            self.on_timer_callback)
        
        logger.info("publisher start!")
    
    def on_timer_callback(self):
        msg = SimpleMsg()
        msg.stamp = self.get_clock().now().to_msg()
        msg.num = self._num
        self._num += 1

        self.get_logger().info("publish num={}".format(msg.num))

        self._pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)

    node = SimplePublisher()

    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()