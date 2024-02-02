# Python Folder Info

Hi Ed! Here is what you need to know about the ROS2 side of things!

- Object Avoidance can be found in `Docking_LiDAR_grab.py`
  	- The distances for safety of travel can be changed but until we get the boat it may not be wise
  	- What it does is it subscribes to the LiDAR processed data and with the calculations that I made (I'll make my comments better later) it either lets it do what it will do (probably go straight) or if the LiDAR senses an object in front of the vessel it will figure out based on the distances of the other objects detected and decide which way to turn is better and send that info to MainControl.py when you are done with the logic for it
