#include "nav_msgs/msg/detail/odometry__struct.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "rclcpp/rclcpp.hpp"

using std::placeholders::_1;

class OdometrySubscriber : public rclcpp::Node {
public:
  OdometrySubscriber() : Node("odometry_subscriber") {
    subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "odom", 10, std::bind(&OdometrySubscriber::odom_callback, this, _1));
  }

private:
  void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg) {
    RCLCPP_INFO(this->get_logger(), "X: %.04f", msg->pose.pose.position.x);
  }

  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<OdometrySubscriber>());
  rclcpp::shutdown();
  return 0;
}