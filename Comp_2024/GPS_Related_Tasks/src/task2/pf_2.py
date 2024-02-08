obstacle_avoidance_node = None  # Initialize obstacle_avoidance_node

class ObstacleAvoidance(Node):
    def __init__(self):
        super().__init__('obstacle_avoidance_node')
        self.subscription = self.create_subscription(LaserScan, 'scan', self.scan_callback, 10)

        # Set minimum distance threshold for obstacle detection
        self.min_distance_threshold = MIN_DISTANCE_THRESHOLD  
        # Set starting distance for obstacle consideration
        self.starting_distance = 0.6  # meters
        # Set degree range for checking path ahead
        self.degree_range = 20  # degrees

        # Initialize the number of laser scan readings
        self.num_readings = 0  

        # Define left and right range for laser scan readings
        self.left_range = None
        self.right_range = None

        self.obstacle_distances = []

    def scan_callback(self, msg):
        global obstacle_avoidance_node  # Access global obstacle_avoidance_node
        distances = msg.ranges
        self.obstacle_distances = [x for x in distances if not np.isnan(x)]

        # Filter distances starting from 0.6 meters away
        start_index = int(self.starting_distance / msg.range_max * len(distances))
        filtered_distances = distances[start_index:]

        # Check if there are obstacles within the specified degree range
        degree_range_indices = int(self.degree_range / msg.angle_increment)
        path_clear = self.is_path_clear(filtered_distances, degree_range_indices)

        if not path_clear:
            if obstacle_avoidance_node is None:  # Check if obstacle_avoidance_node is None
                obstacle_avoidance_node = self  # Assign self to obstacle_avoidance_node
                rclpy.spin_once(obstacle_avoidance_node)  # Run the obstacle avoidance node once
                obstacle_avoidance_node.destroy_node()
                rclpy.shutdown()
        else:
            print("Clear path")  # Print statement indicating clear path
            # Continue moving straight
            thrusters.change_speed(1400, 1400)  # Adjust thrusters to move straight

    def is_path_clear(self, distances, degree_range_indices):
        # Get distances within the specified degree range
        front_distances = distances[:degree_range_indices]
        back_distances = distances[-degree_range_indices:]

        # Check if there are obstacles within the specified distance threshold
        if min(front_distances) < self.min_distance_threshold or min(back_distances) < self.min_distance_threshold:
            return False
        else:
            return True