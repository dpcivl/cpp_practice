cmake_minimum_required(VERSION 3.10)
project(MyTensorFlowLiteProject)

# C++11을 사용합니다.
set(CMAKE_CXX_STANDARD 17)

# TensorFlow Lite 라이브러리 경로를 지정합니다.
set(TENSORFLOW_LITE_DIR /home/hyoin/Documents/tensorflow_src)

# 헤더 파일을 찾을 디렉토리를 지정합니다.
include_directories(${TENSORFLOW_LITE_DIR})
#include_directories(/usr/local/include/flatbuffers)

# TensorFlow Lite 라이브러리를 링크합니다.
link_directories(${TENSORFLOW_LITE_DIR}/bazel-bin/tensorflow/lite)

# 실행 파일을 정의합니다.
add_executable(my_project tflite.cpp)

# 실행 파일에 TensorFlow Lite 라이브러리를 링크합니다.
target_link_libraries(my_project tensorflowlite)