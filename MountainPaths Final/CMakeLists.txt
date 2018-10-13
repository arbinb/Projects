cmake_minimum_required(VERSION 3.10)
project(MountainPaths2)

set(CMAKE_CXX_STANDARD 11)

add_executable(MountainPaths2
        main.cpp
        map-input-100-100.dat
        map-input-480-480.dat
        map-input-844-480.dat
        sample-4-4.dat functions.cpp functions.h)
