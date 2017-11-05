cmake_minimum_required (VERSION 2.6)
project(SVProject)

set(CMAKE_CXX_FLAGS "-O3 -W -Wall -pedantic -std=c++11")

enable_testing()
add_subdirectory(gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable (SVproject neuron.cpp main.cpp)
add_executable (unittest neuron.cpp unittest.cpp)

target_link_libraries(unittest gtest gtest_main)
add_test(unittest unittest)

