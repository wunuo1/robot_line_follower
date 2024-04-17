# Copyright (c) 2022，Horizon Robotics.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.5)
project(robot_line_follower)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ai_msgs REQUIRED)
# find_package(backward_ros REQUIRED)

include_directories(include
  /usr/include
  /usr/include/python3.8
)

add_executable(robot_line_follower
  src/line_follower.cpp
)

target_link_libraries(robot_line_follower
  python3.8
)

ament_target_dependencies(
    robot_line_follower
    rclcpp
    ai_msgs
)


install(
  TARGETS robot_line_follower
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()