cmake_minimum_required(VERSION 3.8)
project(assignment1_rt2)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(assignment1_interfaces REQUIRED)
find_package(tf2 REQUIRED)

add_library(nav_server_component SHARED src/nav_server_component.cpp)
target_include_directories(nav_server_component PRIVATE include)
ament_target_dependencies(nav_server_component
  rclcpp rclcpp_components rclcpp_action geometry_msgs nav_msgs assignment1_interfaces tf2)
rclcpp_components_register_node(nav_server_component 
  PLUGIN "assignment1_rt2::NavServerComponent" 
  EXECUTABLE nav_server_node)

add_library(ui_client_component SHARED src/ui_client_component.cpp)
target_include_directories(ui_client_component PRIVATE include)
ament_target_dependencies(ui_client_component
  rclcpp rclcpp_components rclcpp_action assignment1_interfaces)
rclcpp_components_register_node(ui_client_component 
  PLUGIN "assignment1_rt2::UiClientComponent" 
  EXECUTABLE ui_client_node)

install(TARGETS
  nav_server_component
  ui_client_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
