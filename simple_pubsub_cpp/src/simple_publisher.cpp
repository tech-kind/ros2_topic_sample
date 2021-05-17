#include "simple_pubsub_cpp/simple_publisher.hpp"

SimplePublisher::SimplePublisher(const rclcpp::NodeOptions & options)
: Node("simple_publisher", options)
{
  num_ = 0;

  double period = this->declare_parameter<double>("period", 1);
  int depth = this->declare_parameter<int>("qos_depth", 5);

  RCLCPP_INFO(this->get_logger(), "param period=%lf", period);
  RCLCPP_INFO(this->get_logger(), "param qos_depth=%d", depth);

  // QoSの設定
  rclcpp::QoS qos_param(depth);
  qos_param.reliability(RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  qos_param.durability(RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL);
  qos_param.liveliness(RMW_QOS_POLICY_LIVELINESS_AUTOMATIC);

  // Publisherの生成
  pub_ = this->create_publisher<sample_msgs::msg::SimpleMsg>("sample_topic", qos_param);

  timer_ =
    this->create_wall_timer(
    rclcpp::duration<double>(period),
    std::bind(&SimplePublisher::onTimerCallback, this));

  RCLCPP_INFO(this->get_logger(), "publisher start!");
}

SimplePublisher::~SimplePublisher()
{
}

void SimplePublisher::onTimerCallback()
{
  sample_msgs::msg::SimpleMsg msg;
  msg.stamp = this->get_clock()->now();
  msg.num = num_;
  num_++;

  RCLCPP_INFO(this->get_logger(), "publish num=%d", msg.num);

  pub_->publish(msg);
}
