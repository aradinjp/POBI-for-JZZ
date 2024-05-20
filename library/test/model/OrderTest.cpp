#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../../../include/model/Order.h"

BOOST_AUTO_TEST_SUITE(OrderTests)

BOOST_AUTO_TEST_CASE(TestOrderInitialization) {
        // Arrange
        Order order(1, 99.99);

        // Act & Assert
        BOOST_CHECK_EQUAL(order.getId(), 1);
        BOOST_CHECK_CLOSE(order.getSumPrice(), 99.99, 0.0001);
        BOOST_CHECK_EQUAL(order.getIsRealized(), false);
}

BOOST_AUTO_TEST_CASE(TestOrderSetters) {
        // Arrange
        Order order(1, 99.99);

        // Act
        order.setSumPrice(50.50);
        order.setRealized(true);

        // Assert
        BOOST_CHECK_CLOSE(order.getSumPrice(), 50.50, 0.0001);
        BOOST_CHECK_EQUAL(order.getIsRealized(), true);
}

BOOST_AUTO_TEST_SUITE_END()
