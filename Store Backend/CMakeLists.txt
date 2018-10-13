cmake_minimum_required(VERSION 3.10)
project(Store_Backend)

set(CMAKE_CXX_STANDARD 11)

add_executable(Store_Backend main.cpp Customer.cpp Customer.h Product.cpp Product.h Store.cpp Store.h)