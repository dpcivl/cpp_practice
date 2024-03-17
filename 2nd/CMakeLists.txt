cmake_minimum_required(VERSION 3.10) # 최소 CMake 버전 지정
project(SocketClientApp) # 프로젝트 이름 설정

set(CMAKE_CXX_STANDARD 17) # C++17 표준 사용
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 소스 파일 지정
set(SOURCE_FILES
    client.cpp
    main.cpp
)

# 실행 파일 추가
add_executable(SocketClientApp ${SOURCE_FILES})

# 필요한 경우, 추가 라이브러리 링크 지정
# target_link_libraries(SocketClientApp some_library)
