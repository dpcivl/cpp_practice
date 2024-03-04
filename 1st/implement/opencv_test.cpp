#include <opencv2/opencv.hpp>

int main() {
    cv::VideoCapture cap(0); // 0은 기본 카메라를 나타냅니다.
    if (!cap.isOpened()) {
        std::cerr << "카메라를 열 수 없습니다." << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (true) {
        cap >> frame; // 카메라로부터 새 프레임을 캡처
        if (frame.empty()) break; // 캡처 실패 시 루프 종료

        cv::imshow("Camera Feed", frame); // 프레임을 화면에 표시
        if (cv::waitKey(10) >= 0) break; // 10ms 기다리고, 어떤 키가 눌리면 루프를 종료
    }

    return 0;
}

