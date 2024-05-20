#ifndef APTEKA_TRANSACTIONMENAGER_H
#define APTEKA_TRANSACTIONMENAGER_H

#include "typedefs.h"
#include <vector>

class TransactionMenager {
private:
    TransactionRepositoryPtr transactionRepository;

public:
    TransactionMenager();
    ~TransactionMenager();

    TransactionPtr completeTransaction(const unsigned int &id, const ClientPtr &client, const OrderPtr &order);

    TransactionPtr getTransaction(const int id) const;
    std::vector<TransactionPtr> findTransactions(TransactionPredicate predicate) const;
    std::vector<TransactionPtr> findAllTransactions() const;
};


#endif //APTEKA_TRANSACTIONMENAGER_H