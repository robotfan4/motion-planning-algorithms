cmake_minimum_required(VERSION 2.8)
PROJECT( astar )
set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(source_files src/findpath.cpp)
include_directories(include)
add_executable(test_astar ${source_files})
#target_link_libraries(test_astar)

