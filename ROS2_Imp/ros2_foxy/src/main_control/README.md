# main_control folder

This is where all the required files/folders are stored for the node to be able to work.

## Table of contents for important items
- build
- include
- install
- log
- msg
- src
- CMakeLists.txt
- MainControl.py
- package.xml

### build

When you run the command `colcon build` this is where anything new should be stored. If you want to verify that items you needed added/removed has done so you can organize it by timestamp. If using `colcon build` doesn't work in this folder cd to the ros2_foxy folder and run it there. 

### include

Once the msg files are built correctly the .hpp version of these custom msg files should be stored here so they can be referenced in the .cpp script

### install

This is where your source files, files included via the include folder, libraries for the pacakge, and shared files are stored. Whenever the package is built things that are needed for the pkg to run is stored here so if things are correct in the build folder you may want to look for your missing/unecceary files here and if it isn't here there is a problem with your CMakeLists.txt file. 

### log

Each build is stored here so if you need to reference an old build or figure out why something didn't build correctly it should be stored here

### msg

Where custom message files are stored. This allows for data which is outputted to be done correctly with the correct variable type and names. 
- MyCustomMsgMC.msg

## scr

This is the source file where the actual nodes will be stored. Current list of nodes will be listed below. These should be .cpp files running python script due to reliablity and amount of data being outputted
- detector_sub.cpp
- main_control_pub.cpp

### CMakeLists.txt

- uses dependencies defined in package.xml
- sets and generates msg files 
- makes nodes executable and tells node what dependencies it needs to use
- sets up include folder
- set up install/lib folder
- test if build is correct

### MainControl.py

Local copy of currently used MainControl.py script

### package.xml

- Defines name and description
- Makes sure all dependences are added to package which can be used by CMakeLists.txt which allows package to use the dependencies

## Tasks that need to be done with this node
- figure out better way to output to terminal (it currently only publishes that the python script is running)
- Figure out how to get data out of continuously running script and publish it
- Get detector_sub up and running with the detector topic
- figure out how to get custom msg file to turn into an .hpp file which can be used as a msg file to allow for outputs to the subscriber
- figure out how to get the output to the terminal to go into logger files so we can reference them later

## Order of prescidence 
1. msg file
2. data out of continuously running script
3. opposite subscriber opperational
4. terminal output
5. logger file
