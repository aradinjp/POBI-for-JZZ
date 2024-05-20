#include <boost/test/unit_test.hpp>
#include "typedefs.h"

struct TestSuiteClientFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";

    ClientTypePtr defaultType;
    ClientTypePtr honoraryType;

    TestSuiteClientFixture() {
        defaultType = std::make_shared<Default>();
        honoraryType = std::make_shared<Honorary>();
    }

    ~TestSuiteClientFixture() {
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        Client client1(testFirstName, testLastName, testPersonalID, 400, defaultType);
        BOOST_TEST(client1.getFirstName() == testFirstName);
        BOOST_TEST(client1.getLastName() == testLastName);
        BOOST_TEST(client1.getPersonalID() == testPersonalID);
        BOOST_TEST(client1.getBudget() == 400);
    }
    BOOST_AUTO_TEST_CASE(setFirstNameTest){
        Client client1(testFirstName, testLastName, testPersonalID, 400, defaultType);
        client1.setFirstName("Jozef");
        BOOST_TEST_CHECK(client1.getFirstName() == "Jozef");
        client1.setFirstName("");
        BOOST_TEST_CHECK(client1.getFirstName() == "Jozef");
    }
    BOOST_AUTO_TEST_CASE(setLastNameTest){
        Client client1(testFirstName, testLastName, testPersonalID, 400, defaultType);
        client1.setLastName("Nowak");
        BOOST_TEST_CHECK(client1.getLastName() == "Nowak");
        client1.setLastName("");
        BOOST_TEST_CHECK(client1.getLastName() == "Nowak");
    }
    BOOST_AUTO_TEST_CASE(setBudget){
        Client client1(testFirstName, testLastName, testPersonalID, 400, defaultType);
        client1.setBudget(300);
        BOOST_TEST_CHECK(client1.getBudget() == 300);
    }

BOOST_AUTO_TEST_SUITE_END()