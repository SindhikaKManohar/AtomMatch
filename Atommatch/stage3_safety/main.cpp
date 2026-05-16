#include <iostream>
#include <stdexcept>

#include "GenericOrder.h"

int main() {

    std::cout
        << "--- SAFETY TEST STARTED ---\n\n";

    try {

        std::cout
            << "Creating VALID order...\n";

        Order<int> o1(1, 100, 10);

        o1.print();

        std::cout
            << "\nVALID ORDER ACCEPTED\n\n";

        std::cout
            << "Creating INVALID order...\n";

        Order<int> o2(2, 10000000, 10);

        o2.print();
    }

    catch (const std::exception& e) {

        std::cout
            << ">>> EXCEPTION CAUGHT: "
            << e.what()
            << "\n";
    }

    std::cout
        << "\nSYSTEM CONTINUES RUNNING.\n";

    return 0;
}