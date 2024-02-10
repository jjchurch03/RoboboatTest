import rclpy
from sensor_msgs.msg import NavSatFix
from threading import Timer
from datetime import datetime

latitude_pos = None
longitude_pos = None
latitude_act = None
longitude_act = None
longitude_correct = None
latitude_correct = None
file_path_1 = "dock_time1.txt"
file_path_2 = "dock_notime1.txt"
write_interval = 5  # Update interval in seconds
timer = None
match_counter = 0

def callback(msg):
    global latitude_pos, latitude_act, latitude_correct, longitude_pos, longitude_act, longitude_correct, timer, match_counter
    latitude_pos = msg.latitude
    longitude_pos = msg.longitude

    if latitude_act is None:
        longitude_act = round(longitude_pos, 8)
        latitude_act = round(latitude_pos, 8)
        latitude_correct = latitude_act
        longitude_correct = longitude_act
        print("Creating comparison values")
    else:
        latitude_pos = round(latitude_pos, 8)
        longitude_pos = round(longitude_pos, 8)
        
        if abs(latitude_act - latitude_pos) < 1e-8 and abs(longitude_act - longitude_pos) < 1e-8:
            match_counter += 1
        else:
            match_counter = 0
            latitude_correct = latitude_pos
            longitude_correct = longitude_pos

        if match_counter == 5:
            write_to_file(file_path_2)
        else:
            if timer is None:
                timer = Timer(write_interval, write_to_file, [file_path_1])
                timer.start()

def write_to_file(file_path):
    global timer, latitude_correct, longitude_correct
    dt = datetime.now()
    config_dt = dt.strftime("%c")
    with open(file_path, 'a') as file:
        file.write(f"{config_dt}: {latitude_correct}, {longitude_correct}\n")
        print(f"Latitude: {latitude_correct}, Longitude: {longitude_correct} written to file: {file_path}")

    if timer:
        timer.cancel()  # Cancel the existing timer
    timer = Timer(write_interval, write_to_file, [file_path_1])
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

