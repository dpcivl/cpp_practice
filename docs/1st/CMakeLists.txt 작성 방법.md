# 1) 최소 CMake 버전 지정
모든 'CMakeLists.txt' 파일은 사용할 최소 CMake 버전을 지정해야 한다. 
```cmake
cmake_minimum_required(VERSION 3.10)
```

# 2) 프로젝트 이름 설정
`project()` 명령을 사용하여 프로젝트의 이름과 사용할 언어를 지정한다. 
C++ 프로젝트인 경우 'CXX'를 사용.
```cmake
project(MyProjectName VERSION 1.0 LANGUAGES CXX)
```

# 3) C++ 표준 설정
`set()` 명령을 사용하여 `CMAKE_CXX_STANDARD` 변수를 설정할 수 있다. 
```cmake
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```

# 4) 소스 파일 및 실행 파일 설정
프로젝트의 소스 파일을 지정하고, 이를 바탕으로 실행 파일을 생성한다. 
```cmake
add_executable(MyExecutableName main.cpp)
```

프로젝트가 여러 소스 파일로 구성된 경우, 모든 파일을 `add_executable()` 명령에 추가한다. 
```cmake
add_executable(MyExecutableName main.cpp file1.cpp file2.cpp)
```

# 5) 라이브러리 링크
프로젝트가 외부 라이브러리에 의존하는 경우 `find_package()` 명령을 사용하여 필요한 라이브러리를 찾고, `target_link_libraries()` 명령을 사용하여 실행 파일과 라이브러리를 링크한다. 
```cmake
find_package(SomeLibrary REQUIRED)
target_link_libraries(MyExecutableName PRIVATE SomeLibrary::SomeLibrary)
```

# 6) 포함 디렉토리 추가
프로젝트에서 사용하는 헤더 파일이 특정 디렉토리에 위치할 때, `target_include_directories()` 명령을 사용하여 포함 디렉토리를 추가한다. 
```cmake
target_include_directories(MyExecutableName PRIVATE ${PROJECT_SOURCE_DIR}/include)
```
# 7) 빌드 옵션 및 정의 추가
컴파일 시 추가적인 빌드 옵션이나 전처리기 정의가 필요한 경우, `target_compile_options()` 및 `target_compile_definitions()` 명령을 사용할 수 있다. 
```cmake
target_compile_options(MyExecutableName PRIVATE -Wall -Wextra)
target_compile_definitions(MyExecutableName PRIVATE SOME_DEFINITION=1)
```
