cmake_minimum_required(VERSION 3.15)
project(googletest)

set(CMAKE_CXX_STANDARD 14)

include_directories(gtest_src)
include_directories(gtest_src/gtest)
include_directories(include)
include_directories(src)
include_directories(test)

add_executable(googletest
        gtest_src/gtest/gtest-all.cc
        gtest_src/gtest/gtest.h
        include/factorial.h
        src/factorial.cpp
        test/gtest_main.cpp
        test/test_factorial.cpp)
