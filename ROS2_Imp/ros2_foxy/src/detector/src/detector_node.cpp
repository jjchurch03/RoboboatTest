#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
//#include "detector/msg/MyCustomMsg.hpp"
#include <string>
#include <iostream>
#include <memory>
#include <cstdio>
#include <chrono>

class DetectorPublisherNode : public rclcpp::Node {
public:
//This is where the publisher node is created. In its working state now it creates a string based node called "detector_publisher_node"
    DetectorPublisherNode() : Node("detector_publisher_node") {
        //Creates the publisher which is called detector with a buffer of 10
        publisher_ = create_publisher<std_msgs::msg::String>("detector", 10);
        //Creates a timer which allows publisher to update every 1000ms
        timer_ = create_wall_timer(std::chrono::milliseconds(1000), std::bind(&DetectorPublisherNode::publishDetectorData, this));
    }

private:
//This is how the publisher extracts the detector data and pushes it to the publisher
    void publishDetectorData() {
        //Python code data grab
        std::string data = executePythonScript();
        //creates a string variable called msg
        std_msgs::msg::String msg;
        //puts the output from the script execution into a string variable
        msg.data = data;
        //have publisher push the string data grabbed from the previous step
        publisher_->publish(msg);
        //create a logger which states what the publisher pushed to the subscriber
        RCLCPP_INFO(get_logger(), "Published: %s", msg.data.c_str());
    }
//Here is where the python script gets executed 
    std::string executePythonScript() {
        //find the exact path of .py script. It is being accessed from the repo for ease of access
        std::string command = "python3 ~/RoboBoat_Cyber_Minority/ROS2_Imp/ros2_foxy/src/detector/detector.py";
        //Log that there was an attempt to execute said script
        RCLCPP_INFO(get_logger(), "Executing Python script: %s", command.c_str());
        
//opens the python script and attempts to read and store the data in a temporary and constantly updating
        FILE *pipe = popen(command.c_str(), "r");
        //If it cannot access the .py script then log an error
        if (!pipe) {
            RCLCPP_ERROR(get_logger(), "Failed to execute the Python script");
            return "Error";
        }
        
//create a variable which returns the data we need. May need to be updated as personalized msg is implemented
        char buffer[128];
        std::string result = "";
        while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
            result += buffer;
        }
//logs that the code execution was a success and what is being sent to to the publishDetectorData function
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
