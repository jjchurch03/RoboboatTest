cmake_minimum_required(VERSION 3.5)
project(detector)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

add_executable(detector_node src/detector_node.cpp)

ament_target_dependencies(detector_node rclcpp std_msgs rosidl_default_runtime)

target_include_directories(detector_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

install(TARGETS detector_node
  DESTINATION lib/${PROJECT_NAME})

set(msg_files
  "msg/MyCustomMsg.msg"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
)

install(
  DIRECTORY include/
  DESTINATION include
)


# Include the generated message headers
include_directories(${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_cpp/${PROJECT_NAME}/msg)





if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # The following line skips the linter which checks for copyrights
  # Comment the line when a copyright and license are added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # The following line skips cpplint (only works in a git repo)
  # Comment the line when this package is in a git repo and when
  # a copyright and license are added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

