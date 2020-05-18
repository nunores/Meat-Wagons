cmake_minimum_required(VERSION 3.16)
project(Meat_Wagons)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/DataStructure)

add_executable(Meat_Wagons
        src/DataStructure/MutablePriorityQueue.h
        src/main.cpp src/Menu/menu.cpp src/Menu/menu.h)
