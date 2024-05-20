#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include <boost/date_time.hpp>

struct TransactionMenagerFixture {
    TransactionMenager transactionMenager;
    ClientTypePtr defaultType;
    ClientPtr client1;
    OrderPtr order1;
    OrderPtr order2;

    TransactionMenagerFixture() {
        defaultType = std::make_shared<Default>();
        client1 = std::make_shared<Client>("Jon", "Arbuckle", "0123456789", 400, defaultType);
        order1 = std::make_shared<Order>(1, 99.99);
        order2 = std::make_shared<Order>(1, 150.0);
    }

    ~TransactionMenagerFixture() {}
};

BOOST_FIXTURE_TEST_SUITE(TransactionMenagerSuite, TransactionMenagerFixture)

BOOST_AUTO_TEST_CASE(completeTransactionTest) {
    auto transaction = transactionMenager.completeTransaction(1, client1, order1);
    BOOST_CHECK(transactionMenager.findAllTransactions().size() == 1);
    BOOST_CHECK(transactionMenager.findAllTransactions()[0] == transaction);
    try {
        transactionMenager.completeTransaction(1, client1, order1);
    } catch (std::exception& e) {
        BOOST_TEST(std::string(e.what()) == "Transakcja o podanym ID juz istnieje");
    }
    BOOST_CHECK(transactionMenager.findAllTransactions().size() == 1);
}

BOOST_AUTO_TEST_CASE(GetTransactionTest) {
        auto transaction = transactionMenager.completeTransaction(1, client1, order1);
    BOOST_CHECK(transaction != nullptr);
    auto foundOrders = transactionMenager.getTransaction(1);
    BOOST_CHECK_EQUAL(foundOrders->getId(), 1);
    try {
        transactionMenager.getTransaction(2);
    } catch (std::exception& e) {
        BOOST_TEST(std::string(e.what()) == "Nie znaleziono transakcji o podanym ID");
    }
}

BOOST_AUTO_TEST_CASE(FindTransactionsTest) {
    auto transaction1 = transactionMenager.completeTransaction(1, client1, order1);
    auto transaction2 = transactionMenager.completeTransaction(2, client1, order2);
    BOOST_CHECK(transaction1 != nullptr);
    BOOST_CHECK(transaction2 != nullptr);
    auto foundOrders = transactionMenager.findTransactions([](TransactionPtr ptr)->bool{
        return ptr->getTransactionTime() == pt::second_clock::local_time();
    });
    BOOST_CHECK_EQUAL(foundOrders.size(), 2);
    BOOST_CHECK_EQUAL(foundOrders[0]->getId(), 1);
}

BOOST_AUTO_TEST_CASE(FindAllTransactionsTest) {
    auto transaction1 = transactionMenager.completeTransaction(1, client1, order1);
    auto transaction2 = transactionMenager.completeTransaction(2, client1, order2);
    BOOST_CHECK(transaction1 != nullptr);
    BOOST_CHECK(transaction2 != nullptr);
    auto foundOrders = transactionMenager.findAllTransactions();
    BOOST_CHECK_EQUAL(foundOrders.size(), 2);
}

BOOST_AUTO_TEST_SUITE_END()