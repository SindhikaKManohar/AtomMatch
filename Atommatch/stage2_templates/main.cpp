#include <iostream>
#include "GenericOrder.h"

int main() {
    std::cout << "----multi - asset engine ---\n\n";
    Order<int> stockOrder(101, 500, 10);
    stockOrder.print();
    Order<double> forexOrder(102, 83.45, 1000);
    forexOrder.print();
    Order<float> cryptoOrder(103, 45000.0f, 50);
    cryptoOrder.print();
    Order<long long> bigOrder(104, 999999999LL, 5000);
    bigOrder.print();
    return 0;
}