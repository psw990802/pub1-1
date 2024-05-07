#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include <memory>
#include <chrono>
int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node=std::make_shared<rclcpp::Node>("node_pub1_1");
    auto qos_profile=rclcpp::QoS(rclcpp::KeepLast(10));
    auto mypub=node->create_publisher<std_msgs::msg::Int32>("topic_psub1_2", 
    qos_profile);
    std_msgs::msg::Int32 x;
    x.data=0;
    rclcpp::WallRate loop_rate(1.0);
    while(rclcpp::ok())
    {
        RCLCPP_INFO(node->get_logger(), "Publish: %d", x.data);
        mypub->publish(x);
        //rclcpp::spin_some(node);
        x.data++;
        loop_rate.sleep(); //반복주파수에서남은시간만큼sleep
    }
    rclcpp::shutdown();
    return 0;
}