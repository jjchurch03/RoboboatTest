# Install script for directory: /home/roboboat/ros2_ws/src/zed-examples/tutorials

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/roboboat/ros2_ws/install/SamplesAndTutos")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/tutorials/tutorial 1 - hello ZED/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/tutorials/tutorial 2 - image capture/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/tutorials/tutorial 3 - depth sensing/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/tutorials/tutorial 4 - positional tracking/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/tutorials/tutorial 5 - spatial mapping/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/tutorials/tutorial 6 - object detection/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/tutorials/tutorial 7 - sensor data/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/tutorials/tutorial 8 - body tracking/cpp/cmake_install.cmake")

endif()

