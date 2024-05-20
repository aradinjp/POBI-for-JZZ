#include <iostream>
#include "typedefs.h"

int main() {
    //Menagers
    ClientMenagerPtr clientMenager = std::make_shared<ClientMenager>();
    OrderMenagerPtr orderMenager = std::make_shared<OrderMenager>();
    TransactionMenagerPtr transactionMenager = std::make_shared<TransactionMenager>();

    //Client type
    ClientTypePtr defaultType = std::make_shared<Default>();
    ClientTypePtr honoraryType = std::make_shared<Honorary>();

    //Register clients
    auto client1 = clientMenager->registerClient("John", "Doe", "0123456789", 305.10, defaultType);
    auto client2 = clientMenager->registerClient("Adnrzej", "Trawnik", "9876543210", 221.3, honoraryType);
    auto client3 = clientMenager->registerClient("Bob", "Marks", "5432167890", 0.99, defaultType);

    std::cout << std::endl << "-------- Informacje na temat klientów: --------" << std::endl;
    std::cout << "-> Klient 1 <-\n" << client1->getClientInfo() << "-> Klient 2 <-\n" << client2->getClientInfo()  << "-> Klient 3 <-\n" << client3->getClientInfo();

    //Register orders
    auto order1 = orderMenager->registerOrder(253, 69.8);
    auto order2 = orderMenager->registerOrder(2948, 149.99);
    auto order3 = orderMenager->registerOrder(3931, 387.20);

    std::cout << std::endl << "-------- Informacje na temat zamowien: --------" << std::endl;
    std::cout << "-> Zamowienie 1 <-\n" << order1->getOrderInfo() << "-> Zamowienie 2 <-\n" << order2->getOrderInfo() << "-> Zamowienie 3 <-\n" << order3->getOrderInfo();

    //Complete transactions
    std::cout << std::endl << "-------- Logi na temat dokonanych transakcji: --------" << std::endl;
    auto transaction1 = transactionMenager->completeTransaction(1, client1, order2);
    std::cout << "-> Transakcja " << transaction1->getId() << " <-\n" << transaction1->getTransactionInfo();

    auto transaction2 = transactionMenager->completeTransaction(2, client2, order3);
    std::cout << "-> Transakcja " << transaction2->getId() << " <-\n" << transaction2->getTransactionInfo();

    auto transaction3 = transactionMenager->completeTransaction(3, client2, order1);
    std::cout << "-> Transakcja " << transaction3->getId() << " <-\n" << transaction3->getTransactionInfo();

    //Filter transactions
    auto foundOrders = transactionMenager->findTransactions([](TransactionPtr ptr)->bool{
        return ptr->getTransactionCost() > 100;
    });

    std::cout << std::endl << "-------- Klienci ktorzy dokonali transakcji ktorych koszt jest wiekszy niz 100 zl: --------" << std::endl;
    std::cout << "Ilosc transakcji: " << foundOrders.size() << std::endl << std::endl;

    for(int i = 0; i < foundOrders.size(); i++) {
        std::cout << "PESEL | Nazwisko klienta " << i << ": " << foundOrders[i]->getClient()->getPersonalID() << " | " << foundOrders[i]->getClient()->getLastName() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
