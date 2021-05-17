#include <simple_pubsub_cpp/simple_subscription.hpp>

SimpleSubscription::SimpleSubscription(const rclcpp::NodeOptions & options)
: Node("simple_publisher", options)
{
  int depth = this->declare_parameter<int>("qos_depth", 5);

  RCLCPP_INFO(this->get_logger(), "param qos_depth=%d", depth);

  // QoSの設定
  rclcpp::QoS qos_param(depth);
  qos_param.reliability(RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  qos_param.durability(RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL);
  qos_param.liveliness(RMW_QOS_POLICY_LIVELINESS_AUTOMATIC);

  sub_ = this->create_subscription<sample_msgs::msg::SimpleMsg>(
    "sample_topic", qos_param,
    std::bind(&SimpleSubscription::onMessageCallback, this, std::placeholders::_1));

  RCLCPP_INFO(this->get_logger(), "subscription start!");
}

SimpleSubscription::~SimpleSubscription()
{
}

void SimpleSubscription::onMessageCallback(const sample_msgs::msg::SimpleMsg::ConstSharedPtr msg)
{
  num_ = msg->num;
  RCLCPP_INFO(this->get_logger(), "subscribe num=%d", num_);
}
