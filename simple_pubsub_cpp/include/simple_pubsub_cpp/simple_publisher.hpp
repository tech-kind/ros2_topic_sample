#ifndef SIMPLE_PUBLISHER_HPP_
#define SIMPLE_PUBLISHER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "sample_msgs/msg/simple_msg.hpp"

class SimplePublisher : public rclcpp::Node
{
public:
  SimplePublisher(const rclcpp::NodeOptions & options);
  ~SimplePublisher();

private:
  void onTimerCallback();

  int32_t num_;
  rclcpp::Publisher<sample_msgs::msg::SimpleMsg>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

#endif // SIMPLE_PUBLISHER_HPP_
