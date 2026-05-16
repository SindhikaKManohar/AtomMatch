#pragma once

#include <iostream>

template <typename T>

class Order {

public:

    int id;
    T price;
    int quantity;

    Order(int _id, T _price, int _qty)
        : id(_id),
          price(_price),
          quantity(_qty) {}

    void print() {

        std::cout
            << "Order #"
            << id
            << " | Price: "
            << price
            << " | Qty: "
            << quantity
            << "\n";
    }
};