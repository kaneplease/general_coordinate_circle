cmake_minimum_required(VERSION 3.10)
project(general_coordinate_circle)

set(CMAKE_CXX_STANDARD 11)

add_executable(general_coordinate_circle main.cpp flow_conditions.cpp flow_conditions.h SetCondition.cpp SetCondition.h)