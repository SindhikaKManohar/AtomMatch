#pragma once

class Order {
public:
    int id;
    int price;
    int quantity;
    bool isBuy;

    Order(int _id, int _price, int _qty, bool _buy);

    bool isFilled() const;
};