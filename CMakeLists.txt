cmake_minimum_required(VERSION 2.8.3)
project(teleop)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
 LIBRARIES teleop
 CATKIN_DEPENDS roscpp std_msgs
 DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(joy2double src/joy2double.cpp)
target_link_libraries(joy2double
  ${catkin_LIBRARIES}
)
