#ifndef APTEKA_TRANSACTION_H
#define APTEKA_TRANSACTION_H
#include "typedefs.h"
#include "Order.h"
#include "Client.h"
#include <boost/date_time.hpp>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Transaction {
private:
    unsigned int id;
    ClientPtr client;
    OrderPtr order;
    pt::ptime time;

    double transactionCost;

public:
    Transaction(const unsigned int &uId, const ClientPtr &uClient, const OrderPtr &uOrder);
    ~Transaction();

    const unsigned int &getId() const;
    const double &getTransactionCost() const;
    const pt::ptime &getTransactionTime() const;
    std::string getTransactionInfo() const;

    const ClientPtr getClient() const;
    const OrderPtr getOrder() const;
};


#endif //APTEKA_TRANSACTION_H