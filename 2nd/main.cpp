#include "client.h"
#include <iostream>

int main() {
    try {
        SocketClient client("127.0.0.1", 8080);
        if (client.connectToServer()) {
            client.sendData("Hello from Client");
            std::cout << "Server reply : " << client.receiveData() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
