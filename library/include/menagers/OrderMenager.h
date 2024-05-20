#ifndef APTEKA_ORDERMENAGER_H
#define APTEKA_ORDERMENAGER_H

#include "typedefs.h"
#include <vector>

class OrderMenager {
private:
    OrderRepositoryPtr orderRepository;
    OrderRepositoryPtr orderArchive;

public:
    OrderMenager();
    ~OrderMenager();

    OrderPtr registerOrder(const int id, const double sumPrice);
    void unregisterOrder(const OrderPtr &order);

    OrderPtr getOrder(const int id) const;
    std::vector<OrderPtr> findOrders(OrderPredicate predicate) const;
    std::vector<OrderPtr> findAllOrders() const;
    std::vector<OrderPtr> findAllArchivedOrders() const;
};


#endif //APTEKA_ORDERMENAGER_H