cmake_minimum_required(VERSION 3.16)
project(MyTensorFlowLiteProject CXX)

# TensorFlow Lite 정적 라이브러리의 경로를 설정합니다.
# 여기서는 라이브러리 파일이 '/path/to/tensorflow-lite/lib' 디렉터리 안에 있다고 가정합니다.
set(TENSORFLOW_LITE_LIB_PATH "/home/hyoin/Downloads/git_clone/tflite_build")

# TensorFlow Lite 헤더 파일의 경로를 설정합니다.
# 헤더 파일은 소스 코드 빌드 시에 사용된 'tensorflow' 디렉터리 내에 있습니다.
set(TENSORFLOW_LITE_INCLUDE_PATH "/home/hyoin/Downloads/git_clone/tensorflow_src")

# TensorFlow Lite 정적 라이브러리를 찾습니다.
add_library(tensorflow-lite STATIC IMPORTED)
set_target_properties(tensorflow-lite PROPERTIES
    IMPORTED_LOCATION "${TENSORFLOW_LITE_LIB_PATH}/libtensorflow-lite.a"
    INTERFACE_INCLUDE_DIRECTORIES "${TENSORFLOW_LITE_INCLUDE_PATH}"
)

# 실행 가능한 파일을 정의하고 TensorFlow Lite 라이브러리를 링크합니다.
add_executable(MyExecutable tflite.cpp)
target_link_libraries(MyExecutable tensorflow-lite)
