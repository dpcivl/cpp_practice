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