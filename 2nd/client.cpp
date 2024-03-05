#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *message = "Hello, server!";
    char buffer[1024] = {0};

    int sock = 0;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Socket creation error\n";
        return -1;
    }

    sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported\n";
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection Failed\n";
        return -1;
    }

    // Send and receive data
    // 서버에 메시지 보내기
    send(sock, message, strlen(message), 0);
    std::cout << "Message sent: ";
    std::cout << message << "\n";

    // 서버로부터의 응답 받기
    int valread = read(sock, buffer, 1024);
    std::cout << "Server: " << buffer << std::endl;

    close(sock);

    return 0;
}
