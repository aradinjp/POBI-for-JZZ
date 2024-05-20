#include "menagers/ClientMenager.h"

ClientMenager::ClientMenager() {
    clientRepository = std::make_shared<ClientRepository>();
    clientArchive = std::make_shared<ClientRepository>();
}

ClientMenager::~ClientMenager() = default;

ClientPtr ClientMenager::registerClient(const std::string &firstName, const std::string &lastName, const std::string &personlID, double budget, ClientTypePtr clientType) {
    auto client = std::make_shared<Client>(firstName, lastName, personlID, budget, clientType);

    if(clientRepository->findBy([personlID](const ClientPtr &ptr)->bool{
            return ptr->getPersonalID() == personlID;
        }).empty() && clientArchive->findBy([personlID](const ClientPtr &ptr)->bool{
        return ptr->getPersonalID() == personlID;
    }).empty()) {
        clientRepository->addClient(client);
    } else {
        throw std::logic_error("Client o podanym ID juz istnieje");
    }

    return client;
}

void ClientMenager::unregisterClient(const ClientPtr &client) {
    if(clientRepository->findBy([client](const ClientPtr &ptr)->bool{
        return ptr == client;
    }).empty()) {
        throw std::logic_error("Client nie istnieje");
    } else {
        clientRepository->removeClient(client);
        clientArchive->addClient(client);
    }
}

ClientPtr ClientMenager::getClient(const std::string &personalId) const {
    std::vector<ClientPtr> found = clientRepository->findBy([personalId](const ClientPtr &ptr)->bool{
        return ptr->getPersonalID() == personalId;
    });
    if(found.empty()){
        throw std::logic_error("Nie znaleziono osoby o podanym ID");
    } else {
        return found[0];
    }
}

std::vector<ClientPtr> ClientMenager::findAllClients() const {
    return clientRepository->findBy([](ClientPtr)->bool{
        return true;
    });
}

std::vector<ClientPtr> ClientMenager::findAllArchivedClients() const {
    return clientArchive->findBy([](ClientPtr)->bool{
        return true;
    });
}

std::vector<ClientPtr> ClientMenager::findClients(ClientPredicate predicate) const {
    return clientRepository->findBy(predicate);
}

