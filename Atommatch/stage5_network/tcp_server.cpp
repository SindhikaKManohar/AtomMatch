#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {

    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {

        std::cout
            << "Winsock startup failed.\n";

        return 1;
    }

    SOCKET serverSocket = socket(
        AF_INET,
        SOCK_STREAM,
        0
    );

    sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET;

    serverAddr.sin_port = htons(8080);

    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(
        serverSocket,
        (sockaddr*)&serverAddr,
        sizeof(serverAddr)
    );

    listen(serverSocket, SOMAXCONN);

    std::cout
        << "=== ATOMMATCH EXCHANGE ONLINE ===\n";

    std::cout
        << "Waiting for traders...\n";

    SOCKET clientSocket;

    sockaddr_in clientAddr;

    int clientSize = sizeof(clientAddr);

    clientSocket = accept(
        serverSocket,
        (sockaddr*)&clientAddr,
        &clientSize
    );

    std::cout
        << ">>> TRADER CONNECTED!\n";

    char buffer[1024] = {0};

    recv(
        clientSocket,
        buffer,
        1024,
        0
    );

    std::cout
        << "Client says: "
        << buffer
        << "\n";

    closesocket(clientSocket);

    closesocket(serverSocket);

    WSACleanup();

    return 0;
}