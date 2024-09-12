cmake_minimum_required(VERSION 3.10) 
project(my_project
        LANGUAGES   CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR})

add_executable(
    BankAccountApp

    BankAccount.cpp
    ../sources/main.cpp
)

target_include_directories(BankAccountApp PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(BankAccountApp PRIVATE ../includes)

add_executable (
    BankAccountTest
    
    ../tests/test_BankAccount.cpp
    BankAccount.cpp)

target_link_libraries(BankAccountTest GTest::GTest GTest::Main)