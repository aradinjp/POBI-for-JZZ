#include <boost/test/unit_test.hpp>
#include "typedefs.h"

struct TestSuiteTransactionFixture {
    ClientPtr client1;
    OrderPtr order1;
    OrderPtr order2;
    OrderPtr order3;

    ClientTypePtr defaultType;
    ClientTypePtr honoraryType;
    pt::ptime now = pt::second_clock::local_time();

    TestSuiteTransactionFixture() {
        defaultType = std::make_shared<Default>();
        honoraryType = std::make_shared<Honorary>();
        client1 = std::make_shared<Client>("Jon", "Arbuckle", "0123456789", 400, defaultType);
        order1 = std::make_shared<Order>(1, 100);
        order2 = std::make_shared<Order>(2, 500);
        order3 = std::make_shared<Order>(3, 1000);
    }

    ~TestSuiteTransactionFixture() {
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteTransaction, TestSuiteTransactionFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        Transaction transaction1(1, client1, order1);
        BOOST_TEST(transaction1.getId() == 1);
        BOOST_TEST(transaction1.getClient() == client1);
        BOOST_TEST(transaction1.getOrder() == order1);
        BOOST_TEST(transaction1.getTransactionCost() == 100);
        BOOST_TEST(transaction1.getTransactionTime() == now);
    }
    BOOST_AUTO_TEST_CASE(isRealizedTest){
        Transaction transaction1( 12, client1, order1);
        BOOST_TEST(order1->getIsRealized() == true);
        order1->setRealized(false);
        BOOST_TEST(order1->getIsRealized() == false);
    }
    BOOST_AUTO_TEST_CASE(DefaultClientTypeTest){
        Transaction transaction1(1,client1,order1);

        BOOST_TEST(transaction1.getTransactionCost() == 100);
        BOOST_TEST(order1->getIsRealized() == true);

        Transaction transaction2(2,client1,order2);
        BOOST_TEST(transaction2.getTransactionCost() == 500);
        BOOST_TEST(order2->getIsRealized() == false);
    }
    BOOST_AUTO_TEST_CASE(HonoraryClientTypeTest){
        client1->setClientType(honoraryType);
        Transaction transaction1(1,client1,order1);

        BOOST_TEST(transaction1.getTransactionCost() == 80);
        BOOST_TEST(order1->getIsRealized() == true);

        Transaction transaction2(2,client1,order2);
        BOOST_TEST(transaction2.getTransactionCost() == 400);
        BOOST_TEST(order2->getIsRealized() == true);

        Transaction transaction3(3,client1,order3);
        BOOST_TEST(transaction3.getTransactionCost() == 800);
        BOOST_TEST(order3->getIsRealized() == false);
    }
    BOOST_AUTO_TEST_CASE(ReTransactionTest){
        Transaction transaction1(1,client1,order1);
        BOOST_TEST(order1->getIsRealized() == true);

        try {
            Transaction transaction2(2,client1,order1);
        } catch (std::exception& e) {
            BOOST_TEST(std::string(e.what()) == "Zamowienie zostalo zrealizowane");
        }
    }


BOOST_AUTO_TEST_SUITE_END()