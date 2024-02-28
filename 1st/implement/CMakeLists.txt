cmake_minimum_required(VERSION 3.0)
project(CameraCapture)

set(CMAKE_CXX_STANDARD 11)

# OpenCV 찾기
find_package(OpenCV REQUIRED)

# 포함 디렉토리 설정
include_directories(${OpenCV_INCLUDE_DIRS})

# 실행 파일 생성
add_executable(CameraCapture camera_capture.cpp)

# 라이브러리 링크
target_link_libraries(CameraCapture ${OpenCV_LIBS})
