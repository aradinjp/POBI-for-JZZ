#include <boost/test/unit_test.hpp>
#include "typedefs.h"

struct TestSuiteTransactionRepoFixture {
    ClientPtr client1;
    OrderPtr order1;

    ClientTypePtr defaultType;

    TestSuiteTransactionRepoFixture() {
        defaultType = std::make_shared<Default>();
        client1 = std::make_shared<Client>("Jon", "Arbuckle", "0123456789", 400, defaultType);
        order1 = std::make_shared<Order>(1, 99.99);
    }

    ~TestSuiteTransactionRepoFixture() {
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteTransactionRepository, TestSuiteTransactionRepoFixture)

    BOOST_AUTO_TEST_CASE(TransactionRepositoryTest){
        TransactionRepository transactionRepository;
        TransactionPtr transaction1 = std::make_shared<Transaction>(1, client1, order1);
        BOOST_TEST(transactionRepository.getSize() == 0);

        transactionRepository.addTransaction(transaction1);
        BOOST_TEST(transactionRepository.getSize() == 1);
        BOOST_TEST(transactionRepository.getTransactionByIndex(0) == transaction1);

        transactionRepository.addTransaction(nullptr);
        BOOST_TEST(transactionRepository.getSize() == 1);

        transactionRepository.removeTransaction(nullptr);
        BOOST_TEST(transactionRepository.getSize() == 1);

        BOOST_TEST(transactionRepository.findBy([](const TransactionPtr ptr)->bool{
            return ptr->getId() == 1;
        })[0] == transaction1);

        transactionRepository.removeTransaction(transaction1);
        BOOST_TEST(transactionRepository.getSize() == 0);
    }

BOOST_AUTO_TEST_SUITE_END()