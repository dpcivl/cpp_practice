cmake_minimum_required(VERSION 3.10) 
project(my_project
        LANGUAGES   CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(CalculatorApp
    ../sources/main.cpp     
    Calculator.cpp
)

include_directories(${CMAKE_SOURCE_DIR})
target_include_directories(CalculatorApp PRIVATE ${CMAKE_SOURCE_DIR}/../includes)

add_executable (
    CalculateTest
    
    ../tests/test_Calculator.cpp
    Calculator.cpp)

target_include_directories(CalculateTest PRIVATE includes)
target_link_libraries(CalculateTest GTest::GTest GTest::Main)