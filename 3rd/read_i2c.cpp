#include <iostream>
#include <fcntl.h>      // open
#include <unistd.h>     // close
#include <sys/ioctl.h>  
#include <linux/i2c-dev.h> // I2C 관련 정의

int main() {
    const char *device = "/dev/i2c-1"; // I2C 버스 번호 1 사용
    int file = open(device, O_RDWR);   // 장치 파일 열기
    if (file < 0) {
        std::cerr << "장치를 열 수 없습니다" << std::endl;
        return 1;
    }

    int addr = 0x48; // I2C 장치 주소
    if (ioctl(file, I2C_SLAVE, addr) < 0) {
        std::cerr << "I2C 슬레이브 설정 실패" << std::endl;
        close(file);
        return 1;
    }

    // 읽을 레지스터의 주소
    char reg = 0x10; // 예시 레지스터 주소
    write(file, &reg, 1); // 레지스터 주소 설정

    char data[1] = {0};
    if (read(file, data, 1) != 1) {
        std::cerr << "데이터 읽기 실패" << std::endl;
    } else {
        std::cout << "읽은 데이터: " << static_cast<int>(data[0]) << std::endl;
    }

    close(file); // 장치 파일 닫기
    return 0;
}
