#include <iostream>
#include <string>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {

    WSADATA wsaData;

    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET senderSocket = socket(
        AF_INET,
        SOCK_DGRAM,
        0
    );

    sockaddr_in targetAddr;

    targetAddr.sin_family = AF_INET;

    targetAddr.sin_port = htons(9999);

    targetAddr.sin_addr.s_addr =
        inet_addr("127.0.0.1");

    std::cout
        << "=== MARKET DATA PUBLISHER ===\n";

    while (true) {

        std::string message;

        std::cout
            << "\nEnter Market Update: ";

        std::getline(std::cin, message);

        sendto(
            senderSocket,
            message.c_str(),
            message.length(),
            0,
            (sockaddr*)&targetAddr,
            sizeof(targetAddr)
        );

        std::cout
            << ">> UPDATE BROADCASTED!\n";
    }

    closesocket(senderSocket);

    WSACleanup();

    return 0;
}