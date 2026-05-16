#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {

    WSADATA wsaData;

    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET receiverSocket = socket(
        AF_INET,
        SOCK_DGRAM,
        0
    );

    sockaddr_in receiverAddr;

    receiverAddr.sin_family = AF_INET;

    receiverAddr.sin_port = htons(9999);

    receiverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(
        receiverSocket,
        (sockaddr*)&receiverAddr,
        sizeof(receiverAddr)
    );

    std::cout
        << "=== UDP MARKET FEED ONLINE ===\n";

    std::cout
        << "Listening on Port 9999...\n";

    char buffer[1024];

    sockaddr_in senderAddr;

    int senderLen = sizeof(senderAddr);

    while (true) {

        int bytesIn = recvfrom(
            receiverSocket,
            buffer,
            1024,
            0,
            (sockaddr*)&senderAddr,
            &senderLen
        );

        if (bytesIn > 0) {

            buffer[bytesIn] = '\0';

            std::cout
                << ">> MARKET UPDATE: "
                << buffer
                << "\n";
        }
    }

    closesocket(receiverSocket);

    WSACleanup();

    return 0;
}