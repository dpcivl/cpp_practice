cmake_minimum_required(VERSION 3.10) 
project(my_project
        LANGUAGES   CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR})

add_executable (
    StudentTest
    
    ../tests/test_Student.cpp
    Student.cpp)

target_link_libraries(StudentTest GTest::GTest GTest::Main)