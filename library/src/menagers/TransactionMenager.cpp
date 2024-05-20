#include "menagers/TransactionMenager.h"

TransactionMenager::TransactionMenager() {
    transactionRepository = std::make_shared<TransactionRepository>();
}
TransactionMenager::~TransactionMenager() = default;

TransactionPtr TransactionMenager::completeTransaction(const unsigned int &id, const ClientPtr &client, const OrderPtr &order) {
    auto transaction = std::make_shared<Transaction>(id, client, order);

    if(transactionRepository->findBy([id](const TransactionPtr &ptr)->bool{
        return ptr->getId() == id;
    }).empty()) {
        transactionRepository->addTransaction(transaction);
    } else {
        throw std::logic_error("Transakcja o podanym ID juz istnieje");
    }

    return transaction;
}

TransactionPtr TransactionMenager::getTransaction(int id) const {
    std::vector<TransactionPtr> found = transactionRepository->findBy([id](const TransactionPtr &ptr)->bool{
        return ptr->getId() == id;
    });
    if(found.empty()){
        throw std::logic_error("Nie znaleziono transakcji o podanym ID");
    } else {
        return found[0];
    }
}

std::vector<TransactionPtr> TransactionMenager::findTransactions(TransactionPredicate predicate) const {
    return transactionRepository->findBy(predicate);
}

std::vector<TransactionPtr> TransactionMenager::findAllTransactions() const {
    return transactionRepository->findBy([](TransactionPtr)->bool{
        return true;
    });
}