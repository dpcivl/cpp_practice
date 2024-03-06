# 1) 참고 사이트
https://www.tensorflow.org/lite/guide/build_arm
🔼 위의 사이트를 참고하여 진행했다. 

그러나 좀 다르게 진행했다.

# 2) 과정
## 2.1> Bazel 설치
링크에서는 Bazel build System의 최신 버전을 설치하라고 되어있었으나, 
뒷 순서에서 `apt install` 명령어를 통해 새로 깔아야 해서 그냥 아래의 명령어로 설치하면 될 것 같다. 
```bash
sudo apt update && sudo apt install bazel-6.5.0
```

## 2.2> tensorflow repository 복제
```bash
git clone https://github.com/tensorflow/tensorflow.git tensorflow_src
```
🔼 위의 명령어를 입력하면 *tensorflow_src* 폴더가 생성된다. 
이후에 *tensorflow_src* 폴더에 들어간 후 아래의 과정을 진행한다. 

## 2.3> ARM binary 빌드
```bash
bazel build --config=elinux_aarch64 -c opt //tensorflow/lite:libtensorflowlite.so
```

![[Pasted image 20240305163927.png]]
🔼 완료되면 위와 같은 INFO 로그를 볼 수 있다. 

# 3) 확인도 해야지!
## 3.1> 라이브러리 파일 확인
`bazel`을 사용해서 빌드한 디렉토리에서 아래의 명령어로 확인한다. 
```bash
hyoin@hu-lab:~/Documents/tensorflow_src$ ls bazel-bin/tensorflow/lite/libtensorflowlite.so
```

없으면 없다고 뜰 거다. (No such 어쩌구 저쩌구)

## 3.2> 간단한 tensorflow lite 파일 작성
ChatGPT한테 간단한 tensorflow lite 소스 코드를 받아서 컴파일 해본다. 

⚠️ 컴파일 문제가 생겼는데 헤더 파일 경로를 잘못 알려줘서 발생한 것이었다. *tensorflow/lite* 경로까지 주는 게 아니었다. 
⚠️ *flatbuffers*라는 헤더가 필요했다. 이건 tensorflow lite와 별개로 새로 설치해줘야 하는 것 같다. 

## 3.2.1] flatbuffers 설치 ➡️ 해결 방안이 아니었음
## 3.2.2] C++ 표준 변경
C++ 표준을 C++17로 변경했더니 에러 로그가 크게 줄었다. 
그렇지만 해결하지 못했다;;

# 4) CMake로 빌드 재도전
https://www.tensorflow.org/lite/guide/build_cmake
🔼 위의 링크 절차대로 tensorflow lite 빌드를 해본다. 

## 4.1> thread 덜 사용하기
```bash
cmake --build . -j
```
🔼 위의 과정을 진행하다가 시스템 과부하가 되었는지 OS가 다운이 됐다. 그래서 -j 옵션 값을 4로 줬다. 

![[Pasted image 20240306093101.png]]


## 4.2> 제대로 설치되었는지 확인
제대로 설치되지 않았다. 
다시 링커 문제가 발생했다. 
