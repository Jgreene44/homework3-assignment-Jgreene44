cmake_minimum_required(VERSION 3.6)   # CMake version check
project(Homework3-Assignment)
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard
set(SOURCE_FILES Main.c Board.c Board.h Board.c Board.h Main.c)
add_executable(Homework3 ${SOURCE_FILES})