cmake_minimum_required(VERSION 3.16)
project(Meat_Wagons)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/DataStructure)
include_directories(src/Menu)
include_directories(src/Prisoner)

add_executable(Meat_Wagons
        src/DataStructure/Graph.h
        src/DataStructure/MutablePriorityQueue.h
        src/Menu/menu.cpp
        src/Menu/menu.h
        src/Prisoner/Prisoner.cpp
        src/Prisoner/Prisoner.h
        src/main.cpp)
