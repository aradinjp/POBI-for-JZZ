#include "Order.h"
#include <sstream>
#include <iomanip>

Order::Order(const int id, const double sumPrice) : id(id), sumPrice(sumPrice), isRealized(false) {}

Order::~Order() {}

int Order::getId() const {
    return id;
}

std::string Order::getOrderInfo() const {
    std::stringstream ss;
    ss << "ID zamowienia: " << id << "\n";
    ss << "Cena zamowienia: " << std::fixed << std::setprecision(2) << sumPrice << "zl\n";
    ss << "Zrealizowne: " << (isRealized ? "Tak" : "Nie") << "\n \n";
    return ss.str();
}

double Order::getSumPrice() const {
    return sumPrice;
}

bool Order::getIsRealized() const {
    return isRealized;
}

void Order::setSumPrice(double sumPrice) {
    Order::sumPrice = sumPrice;
}

void Order::setRealized(bool isRealized) {
    Order::isRealized = isRealized;
}

void Order::setId(int id) {
    Order::id = id;
}