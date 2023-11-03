//Detetctor Node created in .cpp
#include "rclcpp/rclcpp.hpp"
#include "big_brain/msg/YOLOv5Detection.hpp"  // Include your custom message header
#include <thread>
#include <fstream>

void runDetectorPythonScript() {
    // Execute your Python script here
    int detectorReturnCode = system("python3 home/roboboat/RoboBoat_Cyber_Minority/ROS2_Imp/ros2_ws/src/big_brain/detector.py");
     if (detectorReturnCode == 0) {
        // Python script executed successfully
        cout << "detector.py has been found and is being loaded..."
    } 
    else{
        cout << "detector.py cannot be found. Error will be published here and in logs"
    }
}

void publishDetectorData() {
    // Create a publisher and publish custom messages
    // Create a publisher for your custom message
    auto publisher = node->create_publisher<big_brain::msg::YOLOv5Detection>("detector", 10);

    rclcpp::WallRate loop_rate(0.1);  // Publish data every 0.1 second
    while (rclcpp::ok()) {
        auto message = big_brain::msg::YOLOv5Detection();
        message.data_field = "Data generated by C++ node";

        // Publish the message
        publisher->publish(message);
        RCLCPP_INFO(node->get_logger("detector_cpp_publisher_node"), "Data published: %s", message.data_field.c_str());
        loop_rate.sleep();
        }

        rclcpp::shutdown();
        return 0;
}


void subscribeDetectorData(const big_brain::msg::YOLOv5Detection::SharedPtr msg) {
    // Process received data and log it
    // Create a subscriber for the topic where data is being published by the Python script
    auto subscriber = node->create_subscription<big_brain::msg::YOLOv5Detection>("custom_topic", 10, processDetectorData);

    RCLCPP_INFO(rclcpp::get_logger("detector_cpp_subscriber_node"), "Received: %s", msg->data_field.c_str());
}

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("detector_cpp_node");

    // Set up a publisher and a subscriber
    auto publisher = node->create_publisher<big_brain::msg::YOLOv5Detection>("detection", 10);
    auto subscription = node->create_subscription<big_brain::msg::YOLOv5Detection>("detection", 10, subscribeDetectorData);

    // Create threads for Python execution, publishing, and subscribing
    std::thread pythonThread(runDetectorPythonScript);
    std::thread publishThread(publishDetectorData);

    // Set up logging to a separate log file
    rclcpp::Logger logger = rclcpp::get_logger("detector_cpp_node");
    rclcpp::LogFileOutput::SharedPtr log_file_output = std::make_shared<rclcpp::LogFileOutput>("log_detector_cpp_node.log");
    rclcpp::get_logger("detector_cpp_node")->add_output(detector_log_file_output);

    rclcpp::spin(node);

    pythonThread.join();
    publishThread.join();

    rclcpp::shutdown();
    return 0;
}
