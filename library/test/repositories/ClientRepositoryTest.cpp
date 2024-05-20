#include <boost/test/unit_test.hpp>
#include "typedefs.h"

struct TestSuiteClientRepoFixture {
    ClientPtr client1;

    ClientTypePtr defaultType;

    TestSuiteClientRepoFixture() {
        defaultType = std::make_shared<Default>();
        client1 = std::make_shared<Client>("Jon", "Arbuckle", "0123456789", 400, defaultType);
    }

    ~TestSuiteClientRepoFixture() {
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientRepository, TestSuiteClientRepoFixture)

    BOOST_AUTO_TEST_CASE(ClientRepositoryTest){
        ClientRepository clientRepository;
        BOOST_TEST(clientRepository.getSize() == 0);

        clientRepository.addClient(client1);
        BOOST_TEST(clientRepository.getSize() == 1);
        BOOST_TEST(clientRepository.getClientByIndex(0) == client1);

        clientRepository.addClient(nullptr);
        BOOST_TEST(clientRepository.getSize() == 1);

        clientRepository.removeClient(nullptr);
        BOOST_TEST(clientRepository.getSize() == 1);

        BOOST_TEST(clientRepository.findBy([](const ClientPtr ptr)->bool{
            return ptr->getPersonalID() == "0123456789";
        })[0] == client1);

        clientRepository.removeClient(client1);
        BOOST_TEST(clientRepository.getSize() == 0);
    }

BOOST_AUTO_TEST_SUITE_END()