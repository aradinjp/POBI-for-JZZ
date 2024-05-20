#ifndef APTEKA_ORDERREPOSITORY_H
#define APTEKA_ORDERREPOSITORY_H
#include "typedefs.h"
#include "Order.h"
#include <vector>

class Order;

class OrderRepository {
private:
    std::vector<OrderPtr> orders;

public:
    const OrderPtr getOrderByIndex(const unsigned int &uId) const;
    void addOrder(const OrderPtr uOrder);
    void removeOrder(const OrderPtr uOrder);

    unsigned int getSize() const;
    std::vector<OrderPtr> findBy(OrderPredicate predicate) const;

    OrderRepository();
    virtual ~OrderRepository();

};


#endif //APTEKA_ORDERREPOSITORY_H
