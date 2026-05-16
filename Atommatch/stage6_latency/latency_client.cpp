#include <iostream>
#include <winsock2.h>
#include <chrono>

#pragma comment(lib, "ws2_32.lib")

#pragma pack(push, 1)

struct OrderPacket {

    int orderId;

    int quantity;

    int price;

    char side;

    long long timestamp;
};

#pragma pack(pop)

int main() {

    WSADATA wsaData;

    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET clientSocket = socket(
        AF_INET,
        SOCK_DGRAM,
        0
    );

    sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET;

    serverAddr.sin_port = htons(8888);

    serverAddr.sin_addr.s_addr =
        inet_addr("127.0.0.1");

    OrderPacket order;

    order.orderId = 1;

    order.quantity = 100;

    order.price = 500;

    order.side = 'B';

    auto now =
        std::chrono::high_resolution_clock::now();

    order.timestamp =
        std::chrono::duration_cast<
            std::chrono::nanoseconds
        >(
            now.time_since_epoch()
        ).count();

    std::cout
        << "Sending packet with timestamp...\n";

    sendto(
        clientSocket,
        (char*)&order,
        sizeof(OrderPacket),
        0,
        (sockaddr*)&serverAddr,
        sizeof(serverAddr)
    );

    std::cout
        << "Packet Sent.\n";

    closesocket(clientSocket);

    WSACleanup();

    return 0;
}