#include <boost/test/unit_test.hpp>
#include "typedefs.h"

struct OrderMenagerFixture {
    OrderMenager orderMenager;

    OrderMenagerFixture() {}

    ~OrderMenagerFixture() {}
};

BOOST_FIXTURE_TEST_SUITE(OrderMenagerSuite, OrderMenagerFixture)

    BOOST_AUTO_TEST_CASE(RegisterOrderTest) {
        auto order = orderMenager.registerOrder(1, 100.0);
        BOOST_CHECK(orderMenager.findAllOrders().size() == 1);
        BOOST_CHECK(orderMenager.findAllOrders()[0] == order);
        try {
            orderMenager.registerOrder(1, 150.0);
        } catch (std::exception& e) {
            BOOST_TEST(std::string(e.what()) == "Zamowienie o podanym ID juz istnieje");
        }
        BOOST_CHECK(orderMenager.findAllOrders().size() == 1);
    }

    BOOST_AUTO_TEST_CASE(UnregisterOrderTest) {
        auto order = orderMenager.registerOrder(1, 100.0);
        BOOST_CHECK(order != nullptr);
        orderMenager.unregisterOrder(order);
        BOOST_CHECK(orderMenager.findAllOrders().size() == 0);
        BOOST_CHECK(orderMenager.findAllArchivedOrders()[0] == order);
        BOOST_CHECK(orderMenager.findAllArchivedOrders().size() == 1);

        try {
            orderMenager.unregisterOrder(order);
        } catch (std::exception& e) {
            BOOST_TEST(std::string(e.what()) == "Zamowienie nie istnieje");
        }
    }

    BOOST_AUTO_TEST_CASE(GetOrderTest) {
        auto order = orderMenager.registerOrder(1, 100.0);
        BOOST_CHECK(order != nullptr);
        auto foundOrders = orderMenager.getOrder(1);
        BOOST_CHECK_EQUAL(foundOrders->getId(), 1);
        try {
            orderMenager.getOrder(2);
        } catch (std::exception& e) {
            BOOST_TEST(std::string(e.what()) == "Nie znaleziono zamowienia o podanym ID");
        }
    }

    BOOST_AUTO_TEST_CASE(FindOrdersTest) {
        auto order1 = orderMenager.registerOrder(1, 100.0);
        auto order2 = orderMenager.registerOrder(2, 200.0);
        BOOST_CHECK(order1 != nullptr);
        BOOST_CHECK(order2 != nullptr);
        auto foundOrders = orderMenager.findOrders([](OrderPtr o)->bool{
            return o->getSumPrice() > 150.0;
        });
        BOOST_CHECK_EQUAL(foundOrders.size(), 1);
        BOOST_CHECK_EQUAL(foundOrders[0]->getId(), 2);
    }

    BOOST_AUTO_TEST_CASE(FindAllOrdersTest) {
        auto order1 = orderMenager.registerOrder(1, 100.0);
        auto order2 = orderMenager.registerOrder(2, 100.0);
        BOOST_CHECK(order1 != nullptr);
        BOOST_CHECK(order2 != nullptr);
        auto foundOrders = orderMenager.findAllOrders();
        BOOST_CHECK_EQUAL(foundOrders.size(), 2);
    }

BOOST_AUTO_TEST_SUITE_END()