import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import NavSatFix
from vectornav_msgs.msg import gnss
import math

class WaypointNavigator(Node):
    def __init__(self):
        super().__init__('waypoint_navigator')
        self.subscription = self.create_subscription(NavSatFix, 'vectornav/gnss', self.dirtbag_callback, 10)
        self.publisher = self.create_publisher(Twist, 'cmd_vel', 10)
        self.waypoints = self.load_waypoints_from_file("waypoints.txt")
        self.current_waypoint_index = 0
        self.waypoint_tolerance = 0.5  # Tolerance for considering a waypoint reached

    def dirtbag_callback(self, msg):
        current_latitude = msg.latitude
        current_longitude = msg.longitude
        current_waypoint = self.waypoints[self.current_waypoint_index]
        distance_to_waypoint = self.calculate_distance(current_latitude, current_longitude, *current_waypoint)

        if distance_to_waypoint < self.waypoint_tolerance:
            self.current_waypoint_index += 1
            if self.current_waypoint_index >= len(self.waypoints):
                self.current_waypoint_index = 0
            self.navigate_to_next_waypoint()

    def navigate_to_next_waypoint(self):
        next_waypoint = self.waypoints[self.current_waypoint_index]
        # Implement navigation algorithm here, e.g., PID control (this is the term right?) to steer towards the waypoint
        # Publish velocity commands to cmd_vel topic to drive towards the waypoint (if we want to do it ROS2 style)
        cmd_vel_msg = Twist()
        # Populate cmd_vel_msg fields based on your navigation algorithm
        self.publisher.publish(cmd_vel_msg)

    def calculate_distance(self, lat1, lon1, lat2, lon2):
        # Calculate distance between two GPS coordinates using Haversine formula
        R = 6371  # Earth radius in kilometers
        d_lat = math.radians(lat2 - lat1)
        d_lon = math.radians(lon2 - lon1)
        a = math.sin(d_lat / 2) * math.sin(d_lat / 2) + math.cos(math.radians(lat1)) * math.cos(math.radians(lat2)) * math.sin(d_lon / 2) * math.sin(d_lon / 2)
        c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))
        distance = R * c
        return distance

    def load_waypoints_from_file(self, file_path):
        waypoints = []
        with open(file_path, 'r') as file:
            lines = file.readlines()
            for line in lines:
                if line.strip():
                    lat, lon = map(float, line.split(','))
                    waypoints.append((lat, lon))
        return waypoints

def main(args=None):
    rclpy.init(args=args)
    navigator = WaypointNavigator()
    rclpy.spin(navigator)
    navigator.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
