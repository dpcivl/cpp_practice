cmake_minimum_required(VERSION 3.0)
project(CameraExample)

find_package(OpenCV REQUIRED) # OpenCV 찾기
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(CameraExample opencv_test.cpp)
target_link_libraries(CameraExample ${OpenCV_LIBS}) # OpenCV와 링크

