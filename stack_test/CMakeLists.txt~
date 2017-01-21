cmake_minimum_required(VERSION 2.8)
PROJECT( astar )
# where is cmake_source_dir. the root of this project
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
include_directories(include)
file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
MESSAGE( STATUS "CMAKE_BINARY_DIR:" ${CMAKE_BINARY_DIR} )
MESSAGE( STATUS "CMAKE_SOURCE_DIR:" ${CMAKE_SOURCE_DIR} )
include_directories("${PROJECT_SOURCE_DIR}")
add_executable(stack_test ${SOURCES})

