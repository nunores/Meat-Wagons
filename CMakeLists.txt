cmake_minimum_required(VERSION 3.16)
project(Meat_Wagons)

set(CMAKE_CXX_STANDARD 14)
#link_libraries(ws2_32 wsock32)

include_directories(src/DataStructure)
include_directories(src/Menu)
include_directories(src/Misc)
include_directories(src/Prisoner)

add_executable(Meat_Wagons
        src/graphviewer/graphviewer.h
        src/graphviewer/graphviewer.cpp
        src/graphviewer/edgetype.h
        src/graphviewer/connection.cpp
        src/graphviewer/connection.h
        src/DataStructure/Graph.h
        src/DataStructure/MutablePriorityQueue.h
        src/Menu/menu.cpp
        src/Menu/menu.h
        src/Misc/misc.cpp
        src/Misc/misc.h
        src/Prisoner/Prisoner.cpp
        src/Prisoner/Prisoner.h
        src/main.cpp
        )
