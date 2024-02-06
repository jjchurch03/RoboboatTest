import rclpy
from sensor_msgs.msg import NavSatFix
from threading import Timer

# Global variables to store GPS data and timer object
latitude = None
longitude = None
file_path = "location_data.txt"
write_interval = 5  # Update interval in seconds
timer = None

def callback(msg):
    global latitude, longitude, timer
    latitude = msg.latitude
    longitude = msg.longitude
    print("Received GPS data.")

    # Cancel the previous timer
    if timer:
        timer.cancel()
        print("Cancelled previous timer.")

    # Schedule writing to file every 5 seconds
    if latitude is not None and longitude is not None:
        timer = Timer(write_interval, write_to_file)
        timer.start()
        print("Scheduled writing to file.")

def write_to_file():
    global timer, latitude, longitude
    # Write latitude and longitude to file
    with open(file_path, 'a') as file:
        file.write(f"Latitude: {latitude}, Longitude: {longitude}\n")
        print(f"Latitude: {latitude}, Longitude: {longitude} written to file.")
    
    # Reset the timer
    timer = Timer(write_interval, write_to_file)
    timer.start()
    print("Reset timer.")

def ros():
    global timer
    rclpy.init()
    node = rclpy.create_node('gps_subscriber')
    subscription = node.create_subscription(NavSatFix, 'vectornav/gnss', callback, 10)
    print("Subscribed to GPS topic.")
    rclpy.spin(node)
    timer.cancel()  # Ensure timer is cancelled when exiting
    node.destroy_node()
    print("Node destroyed.")

if __name__ == '__main__':
    try:
        ros()
    except KeyboardInterrupt:
        pass