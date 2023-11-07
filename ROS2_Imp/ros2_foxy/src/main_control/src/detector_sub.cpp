#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <fstream>

void callback(const std_msgs::msg::String::SharedPtr msg) {
    std::string message = msg->data;

    // Log the received message
    RCLCPP_INFO(rclcpp::get_logger("detector_subscriber_node"), "Received message: %s", message.c_str());

    // Open a log file for writing
    std::ofstream logFile("subscriber_log.txt", std::ios::app);

    if (logFile.is_open()) {
        // Log the message to the file
        logFile << "Received message: " << message << std::endl;
        logFile.close();
    } else {
        RCLCPP_ERROR(rclcpp::get_logger("detector_subscriber_node"), "Failed to open the log file.");
    }
}

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("detector_subscriber_node");

    // Create a subscriber to the desired topic
    auto sub = node->create_subscription<std_msgs::msg::String>(
        "detector", 10, callback);

    rclcpp::spin(node); // Keep the node running

    return 0;
}
