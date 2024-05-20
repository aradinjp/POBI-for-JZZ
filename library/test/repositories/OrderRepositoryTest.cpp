#include <boost/test/unit_test.hpp>
#include "typedefs.h"

struct TestSuiteOrderRepoFixture {
    OrderPtr order1;

    TestSuiteOrderRepoFixture() {
        order1 = std::make_shared<Order>(1, 99.99);
    }

    ~TestSuiteOrderRepoFixture() {
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteOrderRepository, TestSuiteOrderRepoFixture)

    BOOST_AUTO_TEST_CASE(OrderRepositoryTest){
        OrderRepository orderRepository;
        BOOST_TEST(orderRepository.getSize() == 0);

        orderRepository.addOrder(order1);
        BOOST_TEST(orderRepository.getSize() == 1);
        BOOST_TEST(orderRepository.getOrderByIndex(0) == order1);

        orderRepository.addOrder(nullptr);
        BOOST_TEST(orderRepository.getSize() == 1);

        orderRepository.removeOrder(nullptr);
        BOOST_TEST(orderRepository.getSize() == 1);

        BOOST_TEST(orderRepository.findBy([](const OrderPtr ptr)->bool{
            return ptr->getId() == 1;
        })[0] == order1);

        orderRepository.removeOrder(order1);
        BOOST_TEST(orderRepository.getSize() == 0);
    }

BOOST_AUTO_TEST_SUITE_END()