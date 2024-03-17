// client 모듈 만들기

#include "client.h"
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

SocketClient::SocketClient(std::string addr, int port) : address(addr), port(port) {
    // 소켓 생성
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        throw std::runtime_error("Could not create socket");
    }

    server.sin_addr.s_addr = inet_addr(address.c_str());
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
}

bool SocketClient::connectToServer() {
    // 서버에 연결
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return false;
    }

    std::cout << "Connected to server" << std::endl;
    return true;
}

bool SocketClient::sendData(std::string data) {
    // 데이터 송신
    if (send(sock, data.c_str(), data.size(), 0) < 0) {
        perror("Send failed : ");
        return false;
    }
    return true;
}

std::string SocketClient::receiveData() {
    // 데이터 수신
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        puts("recv failed");
        return "";
    }
    return std::string(buffer);
}

void SocketClient::closeSocket() {
    // 소켓 종료
    close(sock);
}

SocketClient::~SocketClient() {
    closeSocket();
}
