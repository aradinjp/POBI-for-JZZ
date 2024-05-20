#ifndef APTEKA_ORDER_H
#define APTEKA_ORDER_H

#include <string>

class Order {
private:
    int id;
    double sumPrice;
    bool isRealized;

public:
    Order(const int id, const double sumPrice);
    ~Order();

    int getId() const;
    std::string getOrderInfo() const;
    double getSumPrice() const;
    bool getIsRealized() const;

    void setSumPrice(double sumPrice);
    void setRealized(bool isRealized);
    void setId(int id);
};

#endif //APTEKA_ORDER_H
