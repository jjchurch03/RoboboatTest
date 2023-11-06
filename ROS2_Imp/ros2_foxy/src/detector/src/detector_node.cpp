#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "detector/msg/yolov5helper.hpp"
#include <string>
#include <iostream>
#include <memory>
#include <cstdio>
#include <chrono>

class DetectorPublisherNode : public rclcpp::Node {
public:
    DetectorPublisherNode() : Node("detector_publisher_node") {
        publisher_ = create_publisher<std_msgs::msg::String>("detector", 10);
        timer_ = create_wall_timer(std::chrono::milliseconds(1000), std::bind(&DetectorPublisherNode::publishDetectorData, this));
    }

private:
    void publishDetectorData() {
        std::string data = executePythonScript();
        std_msgs::msg::String msg;
        msg.data = data;
        publisher_->publish(msg);
        RCLCPP_INFO(get_logger(), "Published: %s", msg.data.c_str());
    }

    std::string executePythonScript() {
        std::string command = "python3 ~/RoboBoat_Cyber_Minority/ROS2_Imp/ros2_foxy/src/detector/detector.py";
        RCLCPP_INFO(get_logger(), "Executing Python script: %s", command.c_str());

        FILE *pipe = popen(command.c_str(), "r");
        if (!pipe) {
            RCLCPP_ERROR(get_logger(), "Failed to execute the Python script");
            return "Error";
        }

        char buffer[128];
        std::string result = "";
        while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
            result += buffer;
        }

        pclose(pipe);
        RCLCPP_INFO(get_logger(), "Python script output: %s", result.c_str());
        return result;
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DetectorPublisherNode>());
    rclcpp::shutdown();
    return 0;
}