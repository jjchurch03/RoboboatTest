import rclpy
from sensor_msgs.msg import NavSatFix
from threading import Timer

# Global variables to store GPS data
latitude = None
longitude = None
file_path = "location_data.txt"
write_interval = 5  # Update interval in seconds

def callback(msg):
    global latitude, longitude
    latitude = msg.latitude
    longitude = msg.longitude

    # Schedule writing to file every 5 seconds
    if latitude is not None and longitude is not None:
        Timer(write_interval, write_to_file).start()

def write_to_file():
    # Write latitude and longitude to file
    with open(file_path, 'a') as file:
        file.write(f"Latitude: {latitude}, Longitude: {longitude}\n")
        print(f"Latitude: {latitude}, Longitude: {longitude} written to file.")

def ros():
    rclpy.init()
    node = rclpy.create_node('gps_subscriber')
    subscription = node.create_subscription(NavSatFix, 'vectornav/gnss', callback, 10)
    rclpy.spin(node)
    node.destroy_node()

if __name__ == '__main__':
    try:
        ros()
    except KeyboardInterrupt:
        pass