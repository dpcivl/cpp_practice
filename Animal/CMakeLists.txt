cmake_minimum_required(VERSION 3.10)
project(my_project
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR})

add_executable (
    AnimalApp
    
    ../sources/main.cpp
    Cat.cpp
    Dog.cpp
    Cow.cpp)

target_include_directories(AnimalApp PRIVATE ../includes)

add_executable (
    AnimalTest
    
    ../tests/test_Animal.cpp
    Cat.cpp
    Dog.cpp
    Cow.cpp)

target_link_libraries(AnimalTest GTest::GTest GTest::Main)