# Install script for directory: /home/roboboat/ros2_ws/src/zed-examples

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Camera_Control" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Camera_Control")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Camera_Control"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Camera_Control")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/camera control/cpp/ZED_Camera_Control")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Camera_Control" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Camera_Control")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Camera_Control"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Camera_Control")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Depth_Sensing" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Depth_Sensing")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Depth_Sensing"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Depth_Sensing")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/depth sensing/cpp/ZED_Depth_Sensing")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Depth_Sensing" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Depth_Sensing")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Depth_Sensing"
         OLD_RPATH "/usr/local/zed/lib:/home/roboboat/ros2_ws/src/zed-examples/depth sensing/cpp/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Depth_Sensing")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Object_detection_image_viewer" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Object_detection_image_viewer")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Object_detection_image_viewer"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Object_detection_image_viewer")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/object detection/image viewer/cpp/ZED_Object_detection_image_viewer")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Object_detection_image_viewer" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Object_detection_image_viewer")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Object_detection_image_viewer"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Object_detection_image_viewer")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Object_detection_birds_eye_viewer" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Object_detection_birds_eye_viewer")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Object_detection_birds_eye_viewer"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Object_detection_birds_eye_viewer")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/object detection/birds eye viewer/cpp/ZED_Object_detection_birds_eye_viewer")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Object_detection_birds_eye_viewer" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Object_detection_birds_eye_viewer")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Object_detection_birds_eye_viewer"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Object_detection_birds_eye_viewer")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_ROI_Exposure" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_ROI_Exposure")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_ROI_Exposure"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_ROI_Exposure")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/camera roi/auto exposure/cpp/ZED_ROI_Exposure")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_ROI_Exposure" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_ROI_Exposure")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_ROI_Exposure"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_ROI_Exposure")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Body_Tracking_Viewer" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Body_Tracking_Viewer")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Body_Tracking_Viewer"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Body_Tracking_Viewer")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/body tracking/cpp/ZED_Body_Tracking_Viewer")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Body_Tracking_Viewer" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Body_Tracking_Viewer")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Body_Tracking_Viewer"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Body_Tracking_Viewer")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Plane_Detection" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Plane_Detection")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Plane_Detection"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Plane_Detection")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/plane detection/overview/cpp/ZED_Plane_Detection")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Plane_Detection" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Plane_Detection")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Plane_Detection"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Plane_Detection")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Positional_Tracking" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Positional_Tracking")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Positional_Tracking"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Positional_Tracking")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/positional tracking/cpp/ZED_Positional_Tracking")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Positional_Tracking" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Positional_Tracking")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Positional_Tracking"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Positional_Tracking")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Spatial_Mapping" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Spatial_Mapping")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Spatial_Mapping"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Spatial_Mapping")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/spatial mapping/overview/cpp/ZED_Spatial_Mapping")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Spatial_Mapping" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Spatial_Mapping")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Spatial_Mapping"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Spatial_Mapping")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Export" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Export")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Export"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Export")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/svo recording/export/cpp/ZED_SVO_Export")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Export" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Export")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Export"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Export")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Playback" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Playback")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Playback"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Playback")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/svo recording/playback/cpp/ZED_SVO_Playback")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Playback" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Playback")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Playback"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Playback")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Recording" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Recording")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Recording"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Recording")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/svo recording/recording/cpp/ZED_SVO_Recording")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Recording" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Recording")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Recording"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_SVO_Recording")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Streaming_Receiver" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Streaming_Receiver")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Streaming_Receiver"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Streaming_Receiver")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/camera streaming/receiver/cpp/ZED_Streaming_Receiver")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Streaming_Receiver" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Streaming_Receiver")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Streaming_Receiver"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Streaming_Receiver")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Streaming_Sender" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Streaming_Sender")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Streaming_Sender"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Streaming_Sender")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/camera streaming/sender/cpp/ZED_Streaming_Sender")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Streaming_Sender" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Streaming_Sender")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Streaming_Sender"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Streaming_Sender")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Point_Cloud_Mapping" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Point_Cloud_Mapping")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Point_Cloud_Mapping"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Point_Cloud_Mapping")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/spatial mapping/advanced point cloud mapping/cpp/ZED_Point_Cloud_Mapping")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Point_Cloud_Mapping" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Point_Cloud_Mapping")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Point_Cloud_Mapping"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Point_Cloud_Mapping")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Floor_Plane_Detection" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Floor_Plane_Detection")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Floor_Plane_Detection"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Floor_Plane_Detection")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/plane detection/floor plane/cpp/ZED_Floor_Plane_Detection")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Floor_Plane_Detection" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Floor_Plane_Detection")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Floor_Plane_Detection"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Floor_Plane_Detection")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Sensing_ROI" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Sensing_ROI")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Sensing_ROI"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Sensing_ROI")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/camera roi/sensing roi/cpp/ZED_Sensing_ROI")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Sensing_ROI" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Sensing_ROI")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Sensing_ROI"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Sensing_ROI")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_CUDA_Refocus" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_CUDA_Refocus")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_CUDA_Refocus"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_CUDA_Refocus")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/other/cuda refocus/ZED_CUDA_Refocus")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_CUDA_Refocus" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_CUDA_Refocus")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_CUDA_Refocus"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_CUDA_Refocus")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_openGL" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_openGL")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_openGL"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_openGL")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/other/opengl gpu interop/ZED_openGL")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_openGL" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_openGL")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_openGL"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_openGL")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Multi_Camera" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Multi_Camera")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Multi_Camera"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Multi_Camera")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/roboboat/ros2_ws/src/zed-examples/bin" TYPE EXECUTABLE FILES "/home/roboboat/ros2_ws/build/SamplesAndTutos/other/multi camera/cpp/ZED_Multi_Camera")
  if(EXISTS "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Multi_Camera" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Multi_Camera")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Multi_Camera"
         OLD_RPATH "/usr/local/zed/lib:/usr/local/cuda/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/roboboat/ros2_ws/src/zed-examples/bin/ZED_Multi_Camera")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/camera control/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/depth sensing/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/object detection/image viewer/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/object detection/birds eye viewer/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/camera roi/auto exposure/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/body tracking/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/plane detection/overview/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/positional tracking/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/spatial mapping/overview/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/svo recording/export/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/svo recording/playback/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/svo recording/recording/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/camera streaming/receiver/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/camera streaming/sender/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/spatial mapping/advanced point cloud mapping/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/plane detection/floor plane/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/camera roi/sensing roi/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/other/cuda refocus/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/other/opengl gpu interop/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/other/multi camera/cpp/cmake_install.cmake")
  include("/home/roboboat/ros2_ws/build/SamplesAndTutos/tutorials/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/roboboat/ros2_ws/build/SamplesAndTutos/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
