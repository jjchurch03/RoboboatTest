import rclpy
from sensor_msgs.msg import LaserScan

class LidarProcessor:
    def __init__(self):
        self.node = rclpy.create_node('lidar_processor')
        self.subscription = self.node.create_subscription(LaserScan, 'lidar_topic', self.lidar_callback, 10)

    def lidar_callback(self, msg):
        # Process the LiDAR data here
        ranges = msg.ranges
        closest_distance = min(ranges)

        # Define your desired minimum distance
        desired_min_distance = 0.5  # Adjust this value according to your needs. Will probably need another variable because of target objects as well

        if closest_distance < desired_min_distance:
            # Stop the robot or take appropriate action
            print("I have docked in my berth!")

        else:
            # Move the robot forward or take appropriate action
            print("I am closing in on my target")

# Takes in Zed Objects, which contains info on distance, bounding box position, etc.
class ZedObjects:
    def __init__(self, objects):
        self.objects = objects
        self.duck_list = []
        self.blue_circle_list = []         # Holds all zed objects in the frame that are green buoys
        self.green_triangle_list = []
        self.red_plus_list = []
        self.blue_plus_list = []
        self.green_plus_list = []
        self.red_square_list = []
        self.docking_list = []
        self.duck_detected = False
        self.blue_circle_detected = False
        self.green_triangle_detected = False
        self.red_plus_detected = False
        self.blue_plus_detected = False
        self.green_plus_detected = False
        self.red_square_detected = False
        self.dock_sign_detected = False
        self.nearest_duck_detected = False
        self.nearest_blue_circle_detected = False
        self.nearest_green_triangle_detected = False
        self.nearest_red_plus_detected = False
        self.nearest_blue_plus_detected = False
        self.nearest_green_plus_detected = False
        self.nearest_red_square_detected = False
        self.nearest_duck_index = -1
        self.nearest_blue_circle_index = -1
        self.nearest_green_triangle_index = -1
        self.nearest_red_plus_index = -1
        self.nearest_blue_plus_index = -1
        self.nearest_green_plus_index = -1
        self.nearest_red_square_index = -1
        self.center_point = 0

    def detect_signs(self):
		# Fills red_buoy_list and green_buoy_list (Change this once labeling problem is solved)
        for obj in self.objects.object_list:
            if (str(obj.raw_label) == "0") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): # Will say "green_buoy or whatever the label is for a green buoy"
                self.green_buoys_list.append(obj)
                self.green_buoy_detected = True
            elif (str(obj.raw_label) == "2") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK):
                self.red_buoys_list.append(obj)
                self.red_buoy_detected = True
    
    def sort_dock_signs(self):
        if self.dock_sign_detected == False:
            print("Error: No dock detected.")
        else:
			# Find sign with closest distance (continue later)
            sign_distances = []
            for green_buoy in self.green_buoys_list:
                green_distances.append(abs((green_buoy.position[2])))
            green_distances.sort()
            i = 0
            for green_buoy in self.green_buoys_list:
                if abs(green_buoy.position[2]) == green_distances[0]:
                    self.nearest_green_index = i
                    self.nearest_green_detected = True
                    i = i + 1
    def get_nearest_dock_sign(self):
        if self.green_buoy_detected == False:
            print("Error: No green buoys detected.")
        elif self.nearest_green_detected == False:
            print("Error: Nearest green buoy not yet detected.")
        else:
            return self.green_buoys_list[self.nearest_green_index] 
        
# Takes in list of objects from Zed 2i Camera each frame
def set_objects(objects_in):
	objects = ZedObjects(objects_in)
	objects.detect_signs()
	objects.sort_dock_signs()
	print("Closest signed detected is: " objects.get_nearest_dock_sign())
	##Add more later
	

def main():
    rclpy.init()
    lidar_processor = LidarProcessor()
    print('Waiting for LiDAR data...')
    rclpy.spin(lidar_processor.node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
