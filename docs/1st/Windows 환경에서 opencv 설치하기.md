# 1) OpenCV 사용하기
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
ChatGPT를 통해 MinGW를 사용하기 위해 링커 설정이 추가적으로 필요하다는 사실을 알게 됐다. 

## 2.3> 링커 설정
링커 설정은 `find_package()`와 `target_link_libraries()`로도 충분하다고 한다. 
그렇다면, 현재 `target_link_libraries()`의 인자로 들어가있는 `OpenCV_LIBS`의 값이 무엇인지 알아야 될 것 같다는 생각이 들었다. 

`OpenCV_LIBS`의 값이 무엇인지 알기 위해 다음과 같은 라인을 넣었다.
```cmake
message(STATUS "OpenCV library status:")

message(STATUS "    version: ${OpenCV_VERSION}")

message(STATUS "    libraries: ${OpenCV_LIBS}")

message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
```

이후에 cmake를 했고, make까지 해준다.
```bash
cmake -G "MinGW Makefiles" .

mingw32-make
```

아직도 해결하지 못했다...
계속해서 발생하는 오류는 아래와 같다. 
```bash
PS C:\Users\cad\hyoin\cpp_practice\1st\implement> mingw32-make
[ 50%] Linking CXX executable CameraCapture.exe
CMakeFiles\CameraCapture.dir/objects.a(opencv_test.cpp.obj):opencv_test.cpp:(.text+0x28): undefined reference to `cv::VideoCapture::VideoCapture(int, int)'
CMakeFiles\CameraCapture.dir/objects.a(opencv_test.cpp.obj):opencv_test.cpp:(.text+0x33): undefined reference to `cv::VideoCapture::isOpened() const'
CMakeFiles\CameraCapture.dir/objects.a(opencv_test.cpp.obj):opencv_test.cpp:(.text+0x72): undefined reference to `cv::Mat::Mat()'
CMakeFiles\CameraCapture.dir/objects.a(opencv_test.cpp.obj):opencv_test.cpp:(.text+0x92): undefined reference to `cv::Mat::empty() const'
CMakeFiles\CameraCapture.dir/objects.a(opencv_test.cpp.obj):opencv_test.cpp:(.text+0xe0): undefined reference to `cv::imshow(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, cv::_InputArray const&)'
CMakeFiles\CameraCapture.dir/objects.a(opencv_test.cpp.obj):opencv_test.cpp:(.text+0x10e): undefined reference to `cv::waitKey(int)'
CMakeFiles\CameraCapture.dir/objects.a(opencv_test.cpp.obj):opencv_test.cpp:(.text+0x132): undefined reference to `cv::Mat::~Mat()'
CMakeFiles\CameraCapture.dir/objects.a(opencv_test.cpp.obj):opencv_test.cpp:(.text+0x13d): undefined reference to `cv::VideoCapture::~VideoCapture()'
CMakeFiles\CameraCapture.dir/objects.a(opencv_test.cpp.obj):opencv_test.cpp:(.text+0x17e): undefined reference to `cv::Mat::~Mat()'
CMakeFiles\CameraCapture.dir/objects.a(opencv_test.cpp.obj):opencv_test.cpp:(.text+0x18e): undefined reference to `cv::VideoCapture::~VideoCapture()'
CMakeFiles\CameraCapture.dir/objects.a(opencv_test.cpp.obj):opencv_test.cpp:(.rdata$.refptr._ZN2cv12VideoCapturersERNS_3MatE[.refptr._ZN2cv12VideoCapturersERNS_3MatE]+0x0): undefined reference to `cv::VideoCapture::operator>>(cv::Mat&)'
collect2.exe: error: ld returned 1 exit status
mingw32-make[2]: *** [CMakeFiles\CameraCapture.dir\build.make:115: CameraCapture.exe] Error 1
mingw32-make[1]: *** [CMakeFiles\Makefile2:82: CMakeFiles/CameraCapture.dir/all] Error 2
mingw32-make: *** [Makefile:90: all] Error 2
```

구글링 결과, 두 가지 결론에 도달했다. 
1. 리눅스 환경에서 CMake를 사용하든지
2. 윈도우에서 쓸 거면 vscode가 아니라 Visual Studio를 써야 한다. 
리눅스를 또 받아야 하는 상황에 봉착했다;;

# 3) 리눅스에서는 된다!
윈도우에서 볼륨 축소 후 리눅스에서 같은 과정을 반복해보았다. 
심지어, VSCode 없이 CMakeLists.txt만 이용해서 같은 과정을 수행했는데 됐었다. 
윈도우에서는 링커 설정이 잘 안되는데 어떻게 해야 제대로 불러올 수 있는지 모르겠다. 

```
🥲 윈도우에서 OpenCV 사용하기가 제목인데;;
```