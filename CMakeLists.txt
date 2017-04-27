cmake_minimum_required(VERSION 3.6)
project(GolfStats)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Golfer.h Round.h Course.h Hole.h Career.h Utils.h)
add_executable(GolfStats ${SOURCE_FILES})