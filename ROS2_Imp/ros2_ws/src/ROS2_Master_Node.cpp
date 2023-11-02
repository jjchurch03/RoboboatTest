// Node Establishment
#include <rclcpp/rclcpp.hpp>
#include <your_msg_type.hpp>
#include <cstdlib>

class PythonNode : public rclcpp::Node {
public:
    PythonNode() : Node("python_node") {
        // Create subscribers for each Python script you want to run
        MC_subscriber = create_subscription<YourMsgType>("Main_Control", 10, std::bind(&PythonNode::runPythonScript1, this, std::placeholders::_1)
        );

        detector_subscriber = create_subscription<YourMsgType>("detection",10, std::bind(&PythonNode::runPythonScript2, this, std::placeholders::_1)
        );
    }

private:
    rclcpp::Subscription<YourMsgType>::SharedPtr subscriber_1;
    rclcpp::Subscription<YourMsgType>::SharedPtr subscriber_2;

    void runPythonScript1(const YourMsgType::SharedPtr msg) {
        // Execute Python script 1 based on the received message
        int return_code = std::system("python3 /path/to/MainControl.py");

        if (return_code != 0) {
            //return error message
        }
    }

    void runPythonScript2(const YourMsgType::SharedPtr msg) {
        // Execute Python script 2 based on the received message
        int return_code = std::system("python3 /path/to/detector.py");

        if (return_code != 0) {
            // Handle the error
        }
    }
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PythonNode>());
    rclcpp::shutdown();
    return 0;
}

