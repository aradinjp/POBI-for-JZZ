#ifndef APTEKA_TRANSACTIONREPOSITORY_H
#define APTEKA_TRANSACTIONREPOSITORY_H
#include "typedefs.h"
#include "Transaction.h"
#include <vector>

class Transaction;

class TransactionRepository {
private:
    std::vector<TransactionPtr> transactions;

public:
    const TransactionPtr getTransactionByIndex(const unsigned int &uId) const;
    void addTransaction(const TransactionPtr uTransaction);
    void removeTransaction(const TransactionPtr uTransaction);

    unsigned int getSize() const;
    std::vector<TransactionPtr> findBy(TransactionPredicate predicate) const;

    TransactionRepository();
    virtual ~TransactionRepository();

};

#endif //APTEKA_TRANSACTIONREPOSITORY_H
