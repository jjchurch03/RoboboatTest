def set_objects(objects_in):
    objects = ZedObjects(objects_in)
    objects.detect_buoys()
    objects.sort_green_buoys()
    objects.sort_red_buoys()
    objects.sort_red_ball()
    objects.sort_green_ball()
    objects.sort_yellow_ball()
    objects.sort_black_ball()
    desired_center_point, obstacle_detected = objects.find_desired_center_point()
    print("Desired Center Point: " + str(desired_center_point))
    adjust_thrusters = move_to_center(desired_center_point)
    if adjust_thrusters and obstacle_detected:
        if obstacle_avoidance_node is None:
            obstacle_avoidance_node = ObstacleAvoidance()
            rclpy.spin_once(obstacle_avoidance_node)  # Run the obstacle avoidance node once
            obstacle_avoidance_node.destroy_node()
            rclpy.shutdown()

def move_to_center(desired_center_point):
    zed_center_pixel = 1280/2

    if desired_center_point == -1:
        # Go straight slowly if buoy channel not detected
        thrusters.change_speed(1425, 1425)
        return True  # Indicate thruster adjustment needed due to lack of buoy channel detection
    # Turn to the left when on the right side of channel
    elif desired_center_point <= zed_center_pixel - 20:
        thrusters.change_speed(1400, 1300)
        return True  # Indicate thruster adjustment needed due to being off-center
    # Turn to the right when on left side of channel
    elif desired_center_point >= zed_center_pixel + 20:
        thrusters.change_speed(1300, 1400)
        return True  # Indicate thruster adjustment needed due to being off-center
    else:
        # Go forward if within 20 pixels of center channel
        thrusters.change_speed(1400, 1400)
        return False  # Indicate no adjustment needed

    # No need to check for obstacles here, as it's done in set_objects
    
    class ObstacleAvoidance(Node):
    def __init__(self):
        super().__init__('obstacle_avoidance_node')
        self.subscription = self.create_subscription(LaserScan, 'scan', self.scan_callback, 10)

        # Set minimum distance threshold for obstacle detection
        self.min_distance_threshold = MIN_DISTANCE_THRESHOLD  
        
        # Initialize the number of laser scan readings
        self.num_readings = 0  

        # Define left and right range for laser scan readings
        self.left_range = None
        self.right_range = None

        self.obstacle_distances = []

    def scan_callback(self, msg):
        distances = msg.ranges
        self.obstacle_distances = [x for x in distances if not np.isnan(x)]

        # Find the minimum distance from the laser scan readings
        min_distance = min(self.obstacle_distances) 

        # Update the number of laser scan readings
        self.num_readings = len(self.obstacle_distances)  

        if min_distance < self.min_distance_threshold:
            print("Obstacle Detected! Deciding best course of action...")
            # Call method to handle obstacle avoidance
            self.avoid_obstacle(self.obstacle_distances, msg)  
        else:
            if min_distance > 0.6:  # Check if the path ahead is clear (adjust threshold as needed)
                print("Clear path")  # Print statement indicating clear path
                # Continue moving straight
                thrusters.change_speed(1400, 1400)  # Adjust thrusters to move straight

    def avoid_obstacle(self, distances, msg):
        # Implement obstacle avoidance logic as before