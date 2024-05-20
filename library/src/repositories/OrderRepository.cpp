#include "repositories/OrderRepository.h"

const OrderPtr OrderRepository::getOrderByIndex(const unsigned int &uId) const {
    if(orders[uId] != nullptr) {
        return orders[uId];
    }
    return nullptr;
}

void OrderRepository::addOrder(const OrderPtr uOrder) {
    if(uOrder != nullptr) {
        orders.push_back(uOrder);
    }
}

void OrderRepository::removeOrder(const OrderPtr uOrder) {
    if(uOrder != nullptr) {
        for (int i = 0; i < orders.size(); i++) {
            if (orders[i] == uOrder) {
                orders.erase(orders.begin() + i);
            }
        }
    }
}

unsigned int OrderRepository::getSize() const {
    return orders.size();
}

OrderRepository::OrderRepository() {}

OrderRepository::~OrderRepository() {
}

std::vector<OrderPtr> OrderRepository::findBy(OrderPredicate predicate) const {
    std::vector<OrderPtr> found;
    for (unsigned int i = 0; i < orders.size(); i++) {
        if (orders[i] != nullptr && predicate(orders[i])) {
            found.push_back(orders[i]);
        }
    }
    return found;
}