#include <iostream>
#include "Order.h"
#include "Trade.h"

int main() {

    Order order1(101, 500, 10, true);

    std::cout << "Order Created\n";

    std::cout << "ID: " << order1.id << "\n";
    std::cout << "Price: " << order1.price << "\n";
    std::cout << "Quantity: " << order1.quantity << "\n";

    Trade t1(1, "TATA", 500, 10);

    t1.announce();

    return 0;
}