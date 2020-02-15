cmake_minimum_required(VERSION 3.10)

project(eparser VERSION 0.0.1)

if(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
endif()

SET(CMAKE_C_FLAGS_DEBUG   "-O0 -g -coverage")
SET(CMAKE_C_FLAGS_RELEASE -O3)

add_executable(skip_amp_test skip_amp_test.c)

enable_testing()

add_test(NAME SkipAmp0 COMMAND skip_amp_test)
add_test(NAME SkipAmp1 COMMAND skip_amp_test year=2020&month=02 rc:1,offset:9)
add_test(NAME SkipAmp2 COMMAND skip_amp_test year=2020          rc:0,offset:9)
