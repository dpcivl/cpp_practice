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