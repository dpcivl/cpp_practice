#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <string>

class SocketClient {
public:
    SocketClient(std::string addr, int port);
    bool connectToServer();
    bool sendData(std::string data);
    std::string receiveData();
    void closeSocket();
    ~SocketClient();

private:
    int sock;
    std::string address;
    int port;
    struct sockaddr_in server;
};

#endif
