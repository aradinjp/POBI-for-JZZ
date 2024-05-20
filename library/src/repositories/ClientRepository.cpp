#include "repositories/ClientRepository.h"

const ClientPtr ClientRepository::getClientByIndex(const unsigned int &uId) const {
    if(clients[uId] != nullptr) {
        return clients[uId];
    }
    return nullptr;
}

void ClientRepository::addClient(const ClientPtr uClient) {
    if(uClient != nullptr) {
        clients.push_back(uClient);
    }
}

void ClientRepository::removeClient(const ClientPtr uClient) {
    if(uClient != nullptr) {
        for (int i = 0; i < clients.size(); i++) {
            if (clients[i] == uClient) {
                clients.erase(clients.begin() + i);
            }
        }
    }
}

unsigned int ClientRepository::getSize() const {
    return clients.size();
}

ClientRepository::ClientRepository() {}

ClientRepository::~ClientRepository() {
}

std::vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate) const {
    std::vector<ClientPtr> found;
    for (unsigned int i = 0; i < clients.size(); i++) {
        if (clients[i] != nullptr && predicate(clients[i])) {
            found.push_back(clients[i]);
        }
    }
    return found;
}
