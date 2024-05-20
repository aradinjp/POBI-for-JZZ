#include "menagers/OrderMenager.h"

OrderMenager::OrderMenager() {
    orderRepository = std::make_shared<OrderRepository>();
    orderArchive = std::make_shared<OrderRepository>();
}

OrderMenager::~OrderMenager() = default;

OrderPtr OrderMenager::registerOrder(const int id, const double sumPrice) {
    auto order = std::make_shared<Order>(id, sumPrice);

    if(orderRepository->findBy([id](const OrderPtr &ptr)->bool{
        return ptr->getId() == id;
    }).empty() && orderArchive->findBy([id](const OrderPtr &ptr)->bool{
        return ptr->getId() == id;
    }).empty()) {
        orderRepository->addOrder(order);
    } else {
        throw std::logic_error("Zamowienie o podanym ID juz istnieje");
    }

    return order;
}

void OrderMenager::unregisterOrder(const OrderPtr &order) {
    if(orderRepository->findBy([order](const OrderPtr &ptr)->bool{
        return ptr == order;
    }).empty()) {
        throw std::logic_error("Zamowienie nie istnieje");
    } else {
        orderRepository->removeOrder(order);
        orderArchive->addOrder(order);
    }
}

OrderPtr OrderMenager::getOrder(const int id) const {
    std::vector<OrderPtr> found = orderRepository->findBy([id](const OrderPtr &ptr)->bool{
        return ptr->getId() == id;
    });
    if(found.empty()){
        throw std::logic_error("Nie znaleziono zamowienia o podanym ID");
    } else {
        return found[0];
    }
}

std::vector<OrderPtr> OrderMenager::findAllOrders() const {
    return orderRepository->findBy([](OrderPtr)->bool{
        return true;
    });
}

std::vector<OrderPtr> OrderMenager::findAllArchivedOrders() const {
    return orderArchive->findBy([](OrderPtr)->bool{
        return true;
    });
}

std::vector<OrderPtr> OrderMenager::findOrders(OrderPredicate predicate) const {
    return orderRepository->findBy(predicate);
}


