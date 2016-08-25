cmake_minimum_required(VERSION 3.3.2)
project(Algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES c_main/link_struct_test/double_dlink_main.c c_header/link_struct/double_link.h c_source/link_struct/double_link.c c_source/link_struct/offset.c c_source/stack/array_stack.c c_source/stack/slink_stack.c c_source/queue/arrary_queue.c c_source/tree/tree.c)
add_executable(Algorithm ${SOURCE_FILES})