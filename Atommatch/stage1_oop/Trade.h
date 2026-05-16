#pragma once

#include <string>

struct Trade {
    int tradeId;
    std::string symbol;
    int price;
    int quantity;

    Trade(int _id, std::string _symbol, int _price, int _qty);

    void announce() const;
};