cmake_minimum_required(VERSION 3.8)
project(module_log_file)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(custom_interfaces REQUIRED)

add_executable(module_log_file src/module_log_file.cpp)

ament_target_dependencies(module_log_file rclcpp custom_interfaces)

target_link_libraries(
  module_log_file
  stdc++fs
)


INSTALL(
  TARGETS module_log_file
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
