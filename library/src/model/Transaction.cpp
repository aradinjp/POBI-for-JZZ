#include "Transaction.h"

Transaction::Transaction(const unsigned int &uId, const ClientPtr &uClient, const OrderPtr &uOrder) : id(uId), client(uClient), time(pt::second_clock::local_time()) {
    if (uOrder->getIsRealized() != false) {
        throw std::logic_error("Zamowienie zostalo zrealizowane");
    } else {
        order = uOrder;
        const ClientTypePtr clientType = client->getClientType();
        transactionCost = order->getSumPrice() - client->applyDiscount(order->getSumPrice());

        if (clientType->getTypeName() == "honorary" && client->getBudget() - transactionCost >= -400) {
            order->setRealized(true);
            client->setBudget(client->getBudget() - transactionCost);

        } else {
            if (client->getBudget() > transactionCost) {
                order->setRealized(true);
                client->setBudget(client->getBudget() - transactionCost);
            } else {
                order->setRealized(false);
            }

        }
    }
}

Transaction::~Transaction() {
}

const unsigned int &Transaction::getId() const {
    return id;
}

const double &Transaction::getTransactionCost() const {
    return transactionCost;
}

const pt::ptime &Transaction::getTransactionTime() const {
    return time;
}

std::string Transaction::getTransactionInfo() const {
    std::stringstream ss;
    ss << "ID transakcji: " << id << "\n";
    ss << "Cena zamowienia po znizkach: " << std::fixed << std::setprecision(2) << transactionCost << "zl\n";
    ss << "Czas transakcji: " << time << "\n";
    ss << "\n" << client->getClientInfo() << order->getOrderInfo();
    return ss.str();
}

const ClientPtr Transaction::getClient() const {
    return client;
}

const OrderPtr Transaction::getOrder() const {
    return order;
}
