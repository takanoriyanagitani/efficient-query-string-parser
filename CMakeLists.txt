cmake_minimum_required(VERSION 3.10)

project(eparser VERSION 0.0.1)

if(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
endif()

SET(CMAKE_C_FLAGS_DEBUG   "-O0 -g -coverage")
SET(CMAKE_C_FLAGS_RELEASE -O3)

add_executable(skip_amp_test skip_amp_test.c)
add_executable(skip_eq_test  skip_eq_test.c)
add_executable(get_value_c_test get_value_c_test.c)

enable_testing()

add_test(NAME SkipAmp0 COMMAND skip_amp_test)
add_test(NAME SkipAmp1 COMMAND skip_amp_test year=2020&month=02 rc:1,offset:9)
add_test(NAME SkipAmp2 COMMAND skip_amp_test year=2020          rc:0,offset:9)

add_test(NAME SkipEq0 COMMAND skip_eq_test)
add_test(NAME SkipEq1 COMMAND skip_eq_test year=2020 rc:1,offset:4)
add_test(NAME SkipEq2 COMMAND skip_eq_test year      rc:0,offset:4)

add_test(NAME GetValueC0 COMMAND get_value_c_test)
add_test(NAME GetValueC1 COMMAND get_value_c_test a alarms=634&time=3    rc:1,offset:10,size:3,val:634)
add_test(NAME GetValueC2 COMMAND get_value_c_test t alarms=634&time=3776 rc:1,offset:20,size:4,val:3776)
add_test(NAME GetValueC3 COMMAND get_value_c_test m alarms=634&time=3776 rc:0,offset:20,size:0,val:)
add_test(NAME GetValueC4 COMMAND get_value_c_test m ""                   rc:0,offset:0,size:0,val:)
add_test(NAME GetValueC5 COMMAND get_value_c_test t alarms=634           rc:0,offset:10,size:0,val:)
add_test(NAME GetValueC6 COMMAND get_value_c_test t alarms=              rc:0,offset:7,size:0,val:)
add_test(NAME GetValueC7 COMMAND get_value_c_test t t                    rc:0,offset:1,size:0,val:)
