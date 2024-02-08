import rclpy
from sensor_msgs.msg import NavSatFix
from threading import Timer
from datetime import datetime

# Global variables to store GPS data and timer object
latitude = None
longitude = None
file_path_1 = "dock_time.txt"
file_path_2 = "dock_notime.txt"
write_interval = 5  # Update interval in seconds
timer = None

def callback(msg):
    global latitude, longitude, timer
    latitude = msg.latitude
    longitude = msg.longitude

    # Schedule writing to file every 5 seconds
    if latitude is not None and longitude is not None:
        if timer is None:
            # Start a new timer only if there's no existing timer
            timer = Timer(write_interval, write_to_file)
            timer.start()
        else:
            # Otherwise, the timer is already running, do nothing
            pass

def write_to_file():
    global timer, latitude, longitude
    # Write latitude and longitude to file
    dt = datetime.now()
    config_dt = dt.strftime("%c")
    with open(file_path_1, 'a') as file:
        file.write(f"{config_dt}: {latitude}, {longitude}\n")
        print(f"Latitude: {latitude}, Longitude: {longitude} written to file one.")
    with open(file_path_2, 'a') as file:
        file.write(f"{latitude}, {longitude}\n")
        print(f"Latitude: {latitude}, Longitude: {longitude} written to file two.")
    
    # Reset the timer
    timer = Timer(write_interval, write_to_file)
    timer.start()

def ros():
    global timer
    rclpy.init()
    node = rclpy.create_node('gps_subscriber')
    subscription = node.create_subscription(NavSatFix, 'vectornav/gnss', callback, 10)
    rclpy.spin(node)
    if timer:
        timer.cancel()  # Ensure timer is cancelled when exiting
    node.destroy_node()

if __name__ == '__main__':
    try:
        ros()
    except KeyboardInterrupt:
        pass