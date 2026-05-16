#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {

    WSADATA wsaData;

    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET clientSocket = socket(
        AF_INET,
        SOCK_STREAM,
        0
    );

    sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET;

    serverAddr.sin_port = htons(8080);

    serverAddr.sin_addr.s_addr =
        inet_addr("127.0.0.1");

    std::cout
        << "Connecting to Exchange...\n";

    if (
        connect(
            clientSocket,
            (sockaddr*)&serverAddr,
            sizeof(serverAddr)
        ) == SOCKET_ERROR
    ) {

        std::cout
            << "Connection Failed.\n";
    }

    else {

        std::cout
            << "Connected Successfully!\n";

        const char* message =
            "BUY 100 shares @ 500";

        send(
            clientSocket,
            message,
            strlen(message),
            0
        );

        std::cout
            << "Order Sent!\n";
    }

    closesocket(clientSocket);

    WSACleanup();

    return 0;
}