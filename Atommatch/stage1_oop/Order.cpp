#include "Order.h"

Order::Order(int _id, int _price, int _qty, bool _buy)
    : id(_id), price(_price), quantity(_qty), isBuy(_buy) {}

bool Order::isFilled() const {
    return quantity == 0;
}