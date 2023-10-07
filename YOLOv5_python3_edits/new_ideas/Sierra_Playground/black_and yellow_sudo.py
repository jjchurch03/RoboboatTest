
import pyzed.sl as sl

class B_and_y:
	def __init__(self, objects):
		self.objects = objects
		self.yellow_buoys_list = []
		self.black_buoys_list = []         # Holds all zed objects in the frame that are black buoys
		self.yellow_buoy_detected = False
		self.black_buoy_detected = False
		self.nearest_black_detected = False
		self.nearest_yellow_detected = False
		self.nearest_black_index = -1
		self.nearest_yellow_index = -1
		counter = 0
		
    def detect_buoys(self):
		# Fills black_buoy_list and yellow_buoy_list
		for obj in self.objects.object_list:
			if (str(obj.raw_label) == "0") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK): 
				self.yellow_buoys_list.append(obj)
				self.yellow_buoy_detected = True
				counter = counter +1
			elif (str(obj.raw_label) == "2") and (obj.tracking_state == sl.OBJECT_TRACKING_STATE.OK):
				self.black_buoys_list.append(obj)
				self.black_buoy_detected = True

	def sort_yellow_buoys(self):
		if self.yellow_buoy_detected == False:
			print("Error: No yellow buoys detected.")
		else:
			yellow_distances = []
			for yellow_buoy in self.green_buoys_list:
				yellow_distances.append(abs((yellow_buoy.position[2])))
			yellow_distances.sort()
			i = 0
			for yellow_buoy in self.yellow_buoys_list:
				if abs(yellow_buoy.position[2]) == yellow_distances[0]:
					self.nearest_yellow_index = i
					self.nearest_yellow_detected = True
				i = i + 1
	
	def sort_black_buoys(self):
		if self.black_buoy_detected == False:
			print("Error: No black buoys detected.")
		else:
			black_distances = []
			for black_buoy in self.black_buoys_list:
				black_distances.append(abs((black_buoy.position[2])))
			black_distances.sort()
			i = 0
			for black_buoy in self.black_buoys_list:
				if abs(black_buoy.position[2]) == black_distances[0]:
					self.nearest_black_index = i
					self.nearest_black_detected = True
				i = i + 1

    def get_nearest_yellow_buoy(self):
		if self.yellow_buoy_detected == False:
			print("Error: No yellow buoys detected.")
		elif self.nearest_yellow_detected == False:
			print("Error: Nearest yellow buoy not yet detected.")
		else:
			return self.yellow_buoys_list[self.nearest_yellow_index] 
		
    def get_nearest_black_buoy(self):
		if self.black_buoy_detected == False:
			print("Error: No black buoys detected.")
		elif self.nearest_black_detected == False:
			print("Error: Nearest black buoy not yet detected.")
		else:
			return self.black_buoys_list[self.nearest_black_index] 