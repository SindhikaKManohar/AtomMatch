#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>

class Order {

public:

    int id;
    T price;
    int quantity;

    Order(int _id, T _price, int _qty) {

        if (_price < 0) {
            throw std::runtime_error(
                "ERROR: Price cannot be negative!"
            );
        }

        if (_qty <= 0) {
            throw std::runtime_error(
                "ERROR: Quantity must be positive!"
            );
        }
        if (_price > 1000000){
            throw std::runtime_error(
                "ERROR: Price too large!"
            );

        }

        id = _id;
        price = _price;
        quantity = _qty;
    }

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