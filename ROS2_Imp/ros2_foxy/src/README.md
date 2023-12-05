# src folder

This is where all the packages are stored. Basically this is where the node topics are stored and naming conventions are either based on the component name or python package it publishes

## Old packages we are keeping just in case
- detector: Publishes detector.py information
- Main_control: Publishes Main_control.py information

## Table of contents of used packages
- Task_2: Where task 2 maincontrol and detector will be hosted and ran
- Task_2_msg: Where message and action files will be stored for Task_2 to be used
- vectornav: where vectornav raw data is published and with message files stored here are translated to useable data
- yolov5_pkgs: How ROS2 translate yolov5 to be useable by the middleware
- zed-ros-wrapper: Initalizes cameras and makes it usable to ROS2
