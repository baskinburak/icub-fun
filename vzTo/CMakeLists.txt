# Copyright: (C) 2010 RobotCub Consortium
# Author: Paul Fitzpatrick
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
# YARP needs CMake 2.8.9 or greater
cmake_minimum_required(VERSION 2.8.9)
# find YARP
find_package(YARP REQUIRED)
find_package (Threads)
# add YARP include directories
include_directories(${YARP_INCLUDE_DIRS})
# set up our program
add_executable(vzOneLed vzOneLed.cpp)
add_executable(gazeCalculate gazeCalculate.cpp)
add_executable(sync sync.cpp)
add_executable(vzMultiLed vzMultiLed.cpp)
add_executable(gaze gaze.cpp ../class/ObjPosClient.cpp)
# link with YARP libraries
target_link_libraries(vzOneLed ${YARP_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(sync ${YARP_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(vzMultiLed ${YARP_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(gazeCalculate ${YARP_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(gaze ${YARP_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
