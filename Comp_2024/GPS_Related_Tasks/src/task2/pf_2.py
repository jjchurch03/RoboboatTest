# Your existing code...

def set_objects(objects_in):
    objects = ZedObjects(objects_in)
    objects.detect_buoys()
    objects.sort_green_buoys()
    objects.sort_red_buoys()
    objects.sort_red_ball()
    objects.sort_green_ball()
    objects.sort_yellow_ball()
    objects.sort_black_ball()
    print("Desired Center Point: " + str(objects.find_desired_center_point()))
    move_to_center(objects.find_desired_center_point())

def move_to_center(desired_center_point):
    global obstacle_avoidance_node
    zed_center_pixel = 1280/2

    if desired_center_point == -1:
        # Go straight slowly if buoy channel not detected
        thrusters.change_speed(1425, 1425)
    # Turn to the left when on the right side of channel
    elif desired_center_point <= zed_center_pixel - 20:
        thrusters.change_speed(1400, 1300)
    # Turn to the right when on left side of channel
    elif desired_center_point >= zed_center_pixel + 20:
        thrusters.change_speed(1300, 1400)
    else:
        # Go forward if within 20 pixels of center channel
        thrusters.change_speed(1400, 1400)
    
    # Instantiate ObstacleAvoidance class if not already instantiated
    if obstacle_avoidance_node is None:
        obstacle_avoidance_node = ObstacleAvoidance()
    
    # Call scan_callback method of ObstacleAvoidance class
    obstacle_avoidance_node.scan_callback()

# Start the ROS 2 node and run obstacle avoidance
obstacle_avoidance_node = ObstacleAvoidance()
rclpy.spin(obstacle_avoidance_node)