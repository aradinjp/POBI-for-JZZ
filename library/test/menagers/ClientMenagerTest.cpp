#include <boost/test/unit_test.hpp>
#include "typedefs.h"

struct ClientMenagerFixture {
    ClientMenager clientMenager;
    ClientTypePtr defaultType;

    ClientMenagerFixture() {
        defaultType = std::make_shared<Default>();
    }

    ~ClientMenagerFixture() {}
};

BOOST_FIXTURE_TEST_SUITE(ClientMenagerSuite, ClientMenagerFixture)

BOOST_AUTO_TEST_CASE(RegisterClientTest) {
        auto client = clientMenager.registerClient("Adnrzej", "Trawnik", "123456789", 1000.0, defaultType);
        BOOST_CHECK(clientMenager.findAllClients().size() == 1);
        BOOST_CHECK(clientMenager.findAllClients()[0] == client);
        try {
            clientMenager.registerClient("Adnrzej", "Trawnik", "123456789", 500.0, defaultType);
        } catch (std::exception& e) {
            BOOST_TEST(std::string(e.what()) == "Client o podanym ID juz istnieje");
        }
        BOOST_CHECK(clientMenager.findAllClients().size() == 1);
}

BOOST_AUTO_TEST_CASE(UnregisterClientTest) {
        auto client = clientMenager.registerClient("John", "Doe", "123456789", 1000.0, defaultType);
        BOOST_CHECK(client != nullptr);
        clientMenager.unregisterClient(client);
        BOOST_CHECK(clientMenager.findAllClients().size() == 0);
        BOOST_CHECK(clientMenager.findAllArchivedClients()[0] == client);
        BOOST_CHECK(clientMenager.findAllArchivedClients().size() == 1);

        try {
            clientMenager.unregisterClient(client);
        } catch (std::exception& e) {
            BOOST_TEST(std::string(e.what()) == "Client nie istnieje");
        }
}

BOOST_AUTO_TEST_CASE(GetClientTest) {
        auto client = clientMenager.registerClient("John", "Doe", "123456789", 1000.0, defaultType);
        BOOST_CHECK(client != nullptr);
        auto foundClients = clientMenager.getClient("123456789");
        BOOST_CHECK_EQUAL(foundClients->getPersonalID(), "123456789");
        try {
            clientMenager.getClient("1");
        } catch (std::exception& e) {
            BOOST_TEST(std::string(e.what()) == "Nie znaleziono osoby o podanym ID");
        }
}

BOOST_AUTO_TEST_CASE(FindClientsTest) {
    auto client = clientMenager.registerClient("John", "Doe", "123456789", 1000.0, defaultType);
    BOOST_CHECK(client != nullptr);
    BOOST_TEST(clientMenager.findClients([](const ClientPtr ptr)->bool{
        return ptr->getPersonalID() == "123456789";
    })[0] == client);
}

BOOST_AUTO_TEST_CASE(FindAllClientsTest) {
        auto client1 = clientMenager.registerClient("John", "Doe", "123456789", 1000.0, defaultType);
        auto client2 = clientMenager.registerClient("Jane", "Doe", "987654321", 2000.0, defaultType);
        BOOST_CHECK(client1 != nullptr);
        BOOST_CHECK(client2 != nullptr);
        auto foundClients = clientMenager.findAllClients();
        BOOST_CHECK_EQUAL(foundClients.size(), 2);
}

BOOST_AUTO_TEST_SUITE_END()
