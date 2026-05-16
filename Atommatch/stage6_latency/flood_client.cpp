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

    order.quantity = 10;

    order.price = 500;

    order.side = 'B';

    const int TOTAL_ORDERS = 10000;

    std::cout
        << "=== FLOOD TEST STARTING ===\n";

    auto start =
        std::chrono::high_resolution_clock::now();

    for (int i = 0; i < TOTAL_ORDERS; i++) {

        order.orderId = i;

        auto now =
            std::chrono::high_resolution_clock::now();

        order.timestamp =
            std::chrono::duration_cast<
                std::chrono::nanoseconds
            >(
                now.time_since_epoch()
            ).count();

        sendto(
            clientSocket,
            (char*)&order,
            sizeof(OrderPacket),
            0,
            (sockaddr*)&serverAddr,
            sizeof(serverAddr)
        );
    }

    auto end =
        std::chrono::high_resolution_clock::now();

    long long duration =
        std::chrono::duration_cast<
            std::chrono::milliseconds
        >(
            end - start
        ).count();

    std::cout
        << "Sent "
        << TOTAL_ORDERS
        << " orders in "
        << duration
        << " ms\n";

    closesocket(clientSocket);

    WSACleanup();

    return 0;
}