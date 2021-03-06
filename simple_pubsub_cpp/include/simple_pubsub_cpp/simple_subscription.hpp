#ifndef SIMPLE_PUBSUB_CPP__SIMPLE_SUBSCRIPTION_HPP_
#define SIMPLE_PUBSUB_CPP__SIMPLE_SUBSCRIPTION_HPP_

#include "rclcpp/rclcpp.hpp"
#include "sample_msgs/msg/simple_msg.hpp"

class SimpleSubscription : public rclcpp::Node
{
public:
  explicit SimpleSubscription(const rclcpp::NodeOptions & options);
  ~SimpleSubscription();

private:
  void onMessageCallback(const sample_msgs::msg::SimpleMsg::ConstSharedPtr msg);

  int32_t num_;
  rclcpp::Subscription<sample_msgs::msg::SimpleMsg>::SharedPtr sub_;
};

#endif  // SIMPLE_PUBSUB_CPP__SIMPLE_SUBSCRIPTION_HPP_
