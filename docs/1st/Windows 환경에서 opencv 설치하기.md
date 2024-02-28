# 1) OpenCV 설치하기
https://opencv.org/releases/
🔼 위 링크로 들어가서 사용하고 싶은 버전의 opencv를 다운 받는다. 
![[Pasted image 20240228153754.png]]
나는 가장 최근 걸로 했음. 😎
exe 파일을 실행하고 설치할 경로를 선택한 후, Extract 해주면 끝이다. 
## 1.1) OpenCV 경로 지정
OpenCV가 설치된 경로를 찾아서 "시스템 환경 변수 설정"에서 설정해준다. 
보통은 `C:\opencv\build\x64\vc16\bin` 여기에 있다. 

# 2) OpenCV 사용하기
OpenCV를 사용해보려고 하니까, 이게 소스 코드는 준비가 됐는데...
CMakeLists.txt를 사용할 줄 몰라서 아래로 이동한다. 
[[CMakeLists.txt 작성 방법]]

## 2.1) CMakeLists.txt 작성
```cmake
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
```

## 2.2) opencv test 코드 작성
```cpp
#include <opencv2/opencv.hpp>

#include <iostream>

  

int main() {

    cv::VideoCapture cap(0); // 기본 카메라 열기

    if (!cap.isOpened()) {

        std::cerr << "카메라를 열 수 없습니다." << std::endl;

        return -1;

    }

  

    cv::Mat frame;

    while (true) {

        cap >> frame; // 카메라로부터 새 프레임 캡처

        if (frame.empty()) break; // 프레임이 비었으면 종료

  

        cv::imshow("Camera Capture", frame);

  

        if (cv::waitKey(10) == 27) break; // 'ESC'를 누르면 종료

    }

  

    return 0;

}
```

위의 코드를 작성하고 컴파일 했는데, 실행 파일이 어딨는지 모르겠다. 
빌드 과정에서 오류가 나타난 것 같다. ➡️ 일부 메소드를 찾을 수 없다고 나옴.
