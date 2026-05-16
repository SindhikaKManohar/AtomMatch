#include <iostream>
#include <vector>

struct Order {

    int id;
    int price;
    int quantity;
    bool isBuy;
};

std::vector<Order> buyOrders;
std::vector<Order> sellOrders;

void matchOrder(Order newOrder) {

    std::cout
        << "\n-----------------------------------\n";

    std::cout
        << "Processing Order #"
        << newOrder.id
        << (newOrder.isBuy ? " [BUY]" : " [SELL]")
        << " @ "
        << newOrder.price
        << "\n";

    if (newOrder.isBuy) {

        bool matched = false;

        for (size_t i = 0; i < sellOrders.size(); i++) {

            if (sellOrders[i].price <= newOrder.price) {

                std::cout
                    << ">>> TRADE EXECUTED!\n";

                std::cout
                    << "Buyer #"
                    << newOrder.id
                    << " bought from Seller #"
                    << sellOrders[i].id
                    << " @ "
                    << sellOrders[i].price
                    << "\n";

                sellOrders.erase(
                    sellOrders.begin() + i
                );

                matched = true;

                break;
            }
        }

        if (!matched) {

            std::cout
                << "No seller found.\n";

            std::cout
                << "Added to BUY BOOK.\n";

            buyOrders.push_back(newOrder);
        }
    }

    else {

        bool matched = false;

        for (size_t i = 0; i < buyOrders.size(); i++) {

            if (buyOrders[i].price >= newOrder.price) {

                std::cout
                    << ">>> TRADE EXECUTED!\n";

                std::cout
                    << "Seller #"
                    << newOrder.id
                    << " sold to Buyer #"
                    << buyOrders[i].id
                    << " @ "
                    << buyOrders[i].price
                    << "\n";

                buyOrders.erase(
                    buyOrders.begin() + i
                );

                matched = true;

                break;
            }
        }

        if (!matched) {

            std::cout
                << "No buyer found.\n";

            std::cout
                << "Added to SELL BOOK.\n";

            sellOrders.push_back(newOrder);
        }
    }
}

int main() {

    matchOrder({101, 100, 10, false});

    matchOrder({202, 90, 10, true});

    matchOrder({203, 100, 10, true});

    matchOrder({300, 95, 5, false});

    std::cout
        << "\n=== ORDER BOOK STATUS ===\n";

    std::cout
        << "Remaining BUY Orders: "
        << buyOrders.size()
        << "\n";

    std::cout
        << "Remaining SELL Orders: "
        << sellOrders.size()
        << "\n";

    return 0;
}