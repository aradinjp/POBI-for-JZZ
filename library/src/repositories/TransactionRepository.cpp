#include "repositories/TransactionRepository.h"

const TransactionPtr TransactionRepository::getTransactionByIndex(const unsigned int &uId) const {
    if(transactions[uId] != nullptr) {
        return transactions[uId];
    }
    return nullptr;
}

void TransactionRepository::addTransaction(const TransactionPtr uTransaction) {
    if(uTransaction != nullptr) {
        transactions.push_back(uTransaction);
    }
}

void TransactionRepository::removeTransaction(const TransactionPtr uTransaction) {
    if(uTransaction != nullptr) {
        for (int i = 0; i < transactions.size(); i++) {
            if (transactions[i] == uTransaction) {
                transactions.erase(transactions.begin() + i);
            }
        }
    }
}

unsigned int TransactionRepository::getSize() const {
    return transactions.size();
}

TransactionRepository::TransactionRepository() {}

TransactionRepository::~TransactionRepository() {
}

std::vector<TransactionPtr> TransactionRepository::findBy(TransactionPredicate predicate) const {
    std::vector<TransactionPtr> found;
    for (unsigned int i = 0; i < transactions.size(); i++) {
        if (transactions[i] != nullptr && predicate(transactions[i])) {
            found.push_back(transactions[i]);
        }
    }
    return found;
}