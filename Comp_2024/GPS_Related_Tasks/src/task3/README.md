# Helpful Tips for Grabbing Info from LiDAR!

Hi Ed! Here is where I am going to give advice about how LiDAR works. I have a script in the python folder which grabs all the output from the datastream. If you want a specific variable from it define a variable as such:

`variable = msg.variable`

If you want an example look at what I am doin in task1

## Configuring the LiDAR

1. Go to urg_node/src/urg_node.cpp
2. after going here update the variables you need to under: `UrgNode::UrgNode(const rclcpp::NodeOptions & node_options)`


## How to run ROS2 Node for LiDAR

Please follow these step!

1. make sure you are in the `~/RoboBoat_Cyber_Minority/Comp_2024/GPS_Related_Tasks` folder and no further down or up
2. run the command `colcon build`
3. type in `source install/setup.bash`
4. `ros2 run urg_node urg_node_driver`
	- From here it should output something like this
![pic of success](https://github.com/DarkAngelRed/RoboBoat_Cyber_Minority/Comp_2024/GPS_Related_Tasks/src/task3/pic.png)
5. Go into the `src/task3/python` folder and then run `python3 insert_name_of detector_form_here.py`
