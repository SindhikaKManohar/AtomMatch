#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

#pragma pack(push, 1)

struct OrderPacket {

    int orderId;
    int quantity;
    int price;
    char side;
};

#pragma pack(pop)

int main() {

    WSADATA wsaData;

    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET serverSocket = socket(
        AF_INET,
        SOCK_DGRAM,
        0
    );

    if (serverSocket == INVALID_SOCKET) {

        std::cout << "Socket Creation Failed\n";
        return 1;
    }

    sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5000);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (
        bind(
            serverSocket,
            (sockaddr*)&serverAddr,
            sizeof(serverAddr)
        ) == SOCKET_ERROR
    ) {

        std::cout << "Bind Failed: "
                  << WSAGetLastError()
                  << "\n";

        return 1;
    }

    std::cout
        << "=== BINARY ENGINE ONLINE ===\n";

    std::cout
        << "Listening on Port 5000...\n\n";

    OrderPacket packet;

    sockaddr_in clientAddr;

    int clientLen = sizeof(clientAddr);

    while (true) {

        int bytes = recvfrom(
            serverSocket,
            (char*)&packet,
            sizeof(OrderPacket),
            0,
            (sockaddr*)&clientAddr,
            &clientLen
        );

        if (bytes == SOCKET_ERROR) {

            std::cout
                << "Receive Error: "
                << WSAGetLastError()
                << "\n";

            continue;
        }

        std::cout
            << ">>> BINARY PACKET RECEIVED\n";

        std::cout
            << "Order ID: "
            << packet.orderId
            << "\n";

        std::cout
            << "Side: "
            << packet.side
            << "\n";

        std::cout
            << "Quantity: "
            << packet.quantity
            << "\n";

        std::cout
            << "Price: "
            << packet.price
            << "\n\n";
    }

    closesocket(serverSocket);

    WSACleanup();

    return 0;
}