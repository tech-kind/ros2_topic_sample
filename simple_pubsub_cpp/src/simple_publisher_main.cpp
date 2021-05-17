#include <memory>

#include "simple_pubsub_cpp/simple_publisher.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::NodeOptions options = rclcpp::NodeOptions();

    rclcpp::spin(std::make_shared<SimplePublisher>(options));
    rclcpp::shutdown();
}