import rclpy
from sensor_msgs.msg import NavSatFix

# Global variables to store GPS data
latitude = None
longitude = None
file_path = "location_data.txt"

def callback(msg):
    global latitude, longitude
    latitude = msg.latitude
    longitude = msg.longitude
    if latitude is not None and longitude is not None:
        # Write latitude and longitude to file
        with open(file_path, 'a') as file:
            file.write(f"Latitude: {latitude}, Longitude: {longitude}\n")
            print(f"Latitude: {latitude}, Longitude: {longitude} written to file.")

def ros():
    rclpy.init()
    node = rclpy.create_node('gps_subscriber')  # Node name changed here
    subscription = node.create_subscription(NavSatFix, 'vectornav/gnss', callback, 10)  # Topic changed here
    rclpy.spin(node)
    node.destroy_node()

if __name__ == '__main__':
    try:
        ros()
    except KeyboardInterrupt:
        pass