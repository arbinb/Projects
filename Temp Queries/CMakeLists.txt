cmake_minimum_required(VERSION 3.10)
project(Temp_Queries)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Temp_Queries
        LinkedList.cpp
        LinkedList.h
        main.cpp
        Node.cpp
        Node.h
        TemperatureData.cpp
        TemperatureData.h
        TemperatureDatabase.cpp
        TemperatureDatabase.h)
