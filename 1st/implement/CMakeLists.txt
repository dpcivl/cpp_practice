cmake_minimum_required(VERSION 3.10) # 최소 CMake 버전 지정
project(CameraCapture) # 프로젝트 이름 설정

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# OpenCV 패키지 찾기
set(OpenCV_DIR "C:/opencv/build/x64/vc16/lib")
find_package(OpenCV REQUIRED)

# 포함 디렉토리 설정
include_directories(${OpenCV_INCLUDE_DIRS})

# 실행 파일 생성
add_executable(CameraCapture opencv_test.cpp)

# 실행 파일에 OpenCV 라이브러리 링크
target_link_libraries(CameraCapture ${OpenCV_LIBS})