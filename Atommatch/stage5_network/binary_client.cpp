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

    SOCKET clientSocket = socket(
        AF_INET,
        SOCK_DGRAM,
        0
    );

    if (clientSocket == INVALID_SOCKET) {

        std::cout << "Socket Creation Failed\n";
        return 1;
    }

    sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET;

    serverAddr.sin_port = htons(5000);

    serverAddr.sin_addr.s_addr =
        inet_addr("127.0.0.1");

    OrderPacket packet;

    packet.orderId = 1001;

    packet.quantity = 50;

    packet.price = 2500;

    packet.side = 'B';

    std::cout
        << "Sending Binary Order...\n";

    int sent = sendto(
        clientSocket,
        (char*)&packet,
        sizeof(OrderPacket),
        0,
        (sockaddr*)&serverAddr,
        sizeof(serverAddr)
    );

    if (sent == SOCKET_ERROR) {

        std::cout
            << "Send Failed: "
            << WSAGetLastError()
            << "\n";
    }
    else {

        std::cout
            << "Packet Sent Successfully!\n";
    }

    closesocket(clientSocket);

    WSACleanup();

    return 0;
}