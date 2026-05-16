#include <iostream>
#include <chrono>

struct Order {

    int id;

    int price;

    int quantity;

    char side;
};

void runStandardAllocationTest() {

    auto start =
        std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++) {

        Order* o = new Order();

        delete o;
    }

    auto end =
        std::chrono::high_resolution_clock::now();

    long long duration =
        std::chrono::duration_cast<
            std::chrono::nanoseconds
        >(
            end - start
        ).count();

    std::cout
        << "Standard new/delete: "
        << duration
        << " ns\n";
}

Order memoryPool[1000000];

void runMemoryPoolTest() {

    auto start =
        std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++) {

        Order* o = &memoryPool[i];
    }

    auto end =
        std::chrono::high_resolution_clock::now();

    long long duration =
        std::chrono::duration_cast<
            std::chrono::nanoseconds
        >(
            end - start
        ).count();

    std::cout
        << "Memory Pool Access:  "
        << duration
        << " ns\n";
}

int main() {

    std::cout
        << "=== MEMORY PERFORMANCE TEST ===\n\n";

    Order* warmup = new Order();

    delete warmup;

    runStandardAllocationTest();

    runMemoryPoolTest();

    return 0;
}