cmake_minimum_required(VERSION 3.3.2)
project(Algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES c_main/double_dlink_main.c c_header/double_link.h c_source/double_link.c main.c)
add_executable(Algorithm ${SOURCE_FILES})