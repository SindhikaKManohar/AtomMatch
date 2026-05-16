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

    SOCKET serverSocket = socket(
        AF_INET,
        SOCK_DGRAM,
        0
    );

    sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET;

    serverAddr.sin_port = htons(8888);

    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(
        serverSocket,
        (sockaddr*)&serverAddr,
        sizeof(serverAddr)
    );

    std::cout
        << "=== LATENCY ENGINE ONLINE ===\n";

    std::cout
        << "Listening on Port 8888...\n\n";

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

        if (bytes == sizeof(OrderPacket)) {

            auto now =
                std::chrono::high_resolution_clock::now();

            long long currentTime =
                std::chrono::duration_cast<
                    std::chrono::nanoseconds
                >(
                    now.time_since_epoch()
                ).count();

            long long latency =
                currentTime - packet.timestamp;

            std::cout
                << ">>> PACKET RECEIVED\n";

            std::cout
                << "Latency: "
                << latency
                << " ns\n";

            std::cout
                << "Latency: "
                << latency / 1000
                << " microseconds\n\n";
        }
    }

    closesocket(serverSocket);

    WSACleanup();

    return 0;
}