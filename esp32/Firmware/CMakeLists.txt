cmake_minimum_required(VERSION 3.9)
project(Firmware)

set(CMAKE_CXX_STANDARD 11)
set(${CMAKE_PROJECT_NAME}_BOARD uno)
set(${CMAKE_PROJECT_NAME}_PORT /dev/ttys0)

add_executable(Firmware
        pins.h
        TFTLib.cpp
        TFTLib.h)
