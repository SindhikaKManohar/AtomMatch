#include <iostream>
#include "Trade.h"

Trade::Trade(int _id, std::string _symbol, int _price, int _qty)
    : tradeId(_id),
      symbol(_symbol),
      price(_price),
      quantity(_qty) {}

void Trade::announce() const {
    std::cout << "TRADE EXECUTED -> "
              << quantity
              << " "
              << symbol
              << " @ "
              << price
              << "\n";
}