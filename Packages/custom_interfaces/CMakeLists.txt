cmake_minimum_required(VERSION 3.8)
project(custom_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

find_package(rosidl_default_generators REQUIRED)

#Generator ROS2 Interface
rosidl_generate_interfaces(
  ${PROJECT_NAME} "msg/TerminateSys.msg" "srv/InitSys.srv" "msg/SetWeighIO.msg" "msg/WeighValue.msg" "msg/SetServoIO.msg" "msg/SetServoRotate.msg" "msg/SendFileName.msg" "msg/SetStartStopPending.msg"
)

#Setup stuff for all packages that need it
ament_export_dependencies(rosidl_default_runtime)

ament_package()
