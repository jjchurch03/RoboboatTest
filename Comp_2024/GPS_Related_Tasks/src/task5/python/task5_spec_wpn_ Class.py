# Code for GPS calcs
# Pin Definitions
# Pin 18: PWM Output - Controls Right Thruster (Grey wire)
r_thrust_pwm = 18
# Pin 15: PWM Output - Controls Left Thruster (Yellow wire)
l_thrust_pwm = 15

# Imports
from typing import List
import RPi.GPIO as GPIO
import time
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix
import math
from vectornav_msgs.msg import CommonGroup

latitude = None
longitude = None



# Initial GPIO Setup
GPIO.setmode(GPIO.BOARD)
GPIO.setup(r_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(l_thrust_pwm, GPIO.OUT, initial=GPIO.LOW)

class Thrusters:
    # 1500 = neuteral
    # 1100 = max ahead
    # 1900 = max reverse
    p_r = GPIO.PWM(r_thrust_pwm, 50)
    p_l = GPIO.PWM(l_thrust_pwm, 50)
    # right_speed and left_speed should be initiated at 1500, which is neuteral
    def __init__(thrusters, left_speed, right_speed):
        thrusters.right_speed = right_speed
        thrusters.left_speed = left_speed
        thrusters.changeSpeed(left_speed, right_speed)

    def changeSpeed(thrusters, left_speed, right_speed):
        # Change right thruster to set value
        thrusters.right_speed = right_speed
        thrusters.p_r.start(right_speed/200)
        # Change left thruster to set value
        thrusters.left_speed = left_speed
        thrusters.p_l.start(left_speed/200)

    def stop(thrusters):
        thrusters.p_r.stop()
        thrusters.p_l.stop()

# Initialize the thrusters into neutral then set them to go straight forward
thrusters = Thrusters(1500, 1500)
time.sleep(5)
thrusters.changeSpeed(1350, 1350)

# class InitialPointGrabber(Node):
#     def __init__(self):
#         global latitude, longitude
#         super().__init__('desired_waypoint_grab')
        
#     def callback(self, msg):
#         global latitude, longitude
#         if latitude is None:
#         # Grab the first set of information
#             latitude = msg.latitude
#             longitude = msg.longitude
#             print(f"Received latitude information: {latitude}")
#             print(f"Received longitude information: {longitude}")
#             return latitude, longitude
#         if longitude is None:
#             print("Failed to grab longitude information.")
#         if latitude is None:
#             print("Failed to grab latitude information")


class WaypointNavigator(Node):
    def __init__(self):
        super().__init__('waypoint_navigator')
        self.subscription_grab = self.create_subscription(NavSatFix, 'vectornav/gnss', self.callback, 10)
        self.subscription_gps = self.create_subscription(NavSatFix, 'vectornav/gnss', self.dirtbag_callback, 10)
        self.subscription_heading = self.create_subscription(CommonGroup, 'vectornav/raw/common', self.yaw_callback, 10)
        
        self.waypoint_tolerance = 0.75  # Tolerance for considering a waypoint reached (adjust as needed)
        self.steady_counter = 0  # Counter to keep track of steady state
        self.backward_duration = 3 # Duration (in seconds) to apply reverse thrust
        self.degrees_true = None  # Store current heading

    def yaw_callback(self, msg):
        # Extract yaw angle from the message
        yaw = msg.yawpitchroll.x  # Assuming yaw is a field in the message
        # Convert yaw angle to degrees true (if needed)
        self.degrees_true = yaw
        
        # Print or use the degrees true value
        print(f"Degrees True: {self.degrees_true}")
        return self.degrees_true
        
    def dirtbag_callback(self, msg):
        global latitude, longitude
        current_latitude = msg.latitude
        current_longitude = msg.longitude
        print(f"Latitude: {current_latitude} and longitude: {current_longitude}")
        distance_to_waypoint = self.calculate_distance(current_latitude, current_longitude, latitude, longitude)
        angle_to_waypoint = self.calculate_angle(current_latitude, current_longitude, latitude, longitude)
        self.navigate_to_waypoint(distance_to_waypoint, angle_to_waypoint) 

    def navigate_to_waypoint(self, distance, angle):
        # Tolerance for angle to consider facing the waypoint
        if self.degrees_true is not None:
            if distance <= self.waypoint_tolerance:
                print("Waypoint reached. Stabilizing.")
                if self.steady_counter < self.backward_duration * 10:
                    # Apply reverse thrust for a short duration to counter forward momentum
                    thrusters.changeSpeed(1525, 1525)
                    self.steady_counter += 1
                else:
                # Stop thrusters after applying reverse thrust
                    print("Vessel stabilized. Stopping thrusters.")
                    thrusters.stop()
            else:
            # Reset the steady counter if not reached the waypoint yet
                self.steady_counter = 0
            
                if (angle-self.degrees_true) < -.05:
                    print("Facing waypoint. Continuing straight.")
                    thrusters.changeSpeed(1350, 1350)
                else:
                    if (angle-self.degrees_true) <= 180:
                        print("Need to turn right.")
                        thrusters.changeSpeed(1400, 1300)
                    elif (angle-self.degrees_true) > 180:
                        print("Need to turn left.")
                        thrusters.changeSpeed(1300, 1400)
        else:
            print("Waiting for heading information...")



    
    def calculate_angle(self, lat1, long1, lat2, long2):
        dLon = (long2 - long1) #this should be a double
        y = math.sin(dLon) * math.cos(lat2)
        x = math.cos(lat1) * math.sin(lat2) - math.sin(lat1)* math.cos(lat2) * math.cos(dLon)
        brng = math.atan2(y, x)
        brng = (brng + 2 * math.pi) % (2 * math.pi)
        brng = math.degrees(brng)
        brng = (brng + 360) % 360
        brng = 360 - brng #count degrees counter-clockwise - remove to make clockwise
        print(f"angle: {brng}")
        return brng

    def calculate_distance(self, lat1, lon1, lat2, lon2):
        # Calculate distance between two GPS coordinates using Haversine formula
        R = 6371  # Earth radius in kilometers
        d_lat = math.radians(lat2 - lat1)
        d_lon = math.radians(lon2 - lon1)
        a = math.sin(d_lat / 2) * math.sin(d_lat / 2) + math.cos(math.radians(lat1)) * math.cos(math.radians(lat2)) * math.sin(d_lon / 2) * math.sin(d_lon / 2)
        c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))
        distance = R * c
        distance_meters = distance * 1000  # Convert kilometers to meters
        print(f"Distance: {distance_meters}")
        return distance_meters

def main(args=None):
    if latitude or longitude is None:
        rclpy.init()
        uno = InitialPointGrabber()
        print("Spinning first node...")
        rclpy.spin_once(uno)
    else:
        try:
            rclpy.init(args=args)
            navigator = WaypointNavigator()
            print("Spinning second node...")
            rclpy.spin(navigator)  # Spin the node to handle incoming messages
        except KeyboardInterrupt:
            print("Keyboard interrupt detected. Exiting...")
        except Exception as e:
            print(f"An error occurred: {str(e)}")
        finally:
            if 'navigator' in locals():
                navigator.destroy_node()
            if 'uno' in locals():
                uno.destroy_node()
            rclpy.shutdown()




if __name__ == '__main__':
    main()


GPIO.cleanup()
