cmake_minimum_required(VERSION 3.5)
project(waypoint_nav2)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# Find packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(yaml-cpp REQUIRED)

# Add executable
add_executable(run src/run.cpp)
ament_target_dependencies(run rclcpp yaml-cpp)

# Install executable
install(TARGETS
  run
  DESTINATION lib/${PROJECT_NAME})

# Install launch files
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME})

# Export dependecies
ament_export_dependencies(rclcpp yaml-cpp)
ament_package()
