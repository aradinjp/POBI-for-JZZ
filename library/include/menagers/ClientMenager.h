#ifndef APTEKA_CLIENTMENAGER_H
#define APTEKA_CLIENTMENAGER_H

#include "typedefs.h"
#include <string>
#include <vector>


class ClientMenager {
private:
    ClientRepositoryPtr clientRepository;
    ClientRepositoryPtr clientArchive;

public:
    ClientMenager();
    ~ClientMenager();

    ClientPtr registerClient(const std::string &firstName, const std::string &lastName, const std::string &personlID, double budget, ClientTypePtr clientType);
    void unregisterClient(const ClientPtr &client);

    ClientPtr getClient(const std::string &personalId) const;
    std::vector<ClientPtr> findClients(ClientPredicate predicate) const;
    std::vector<ClientPtr> findAllClients() const;
    std::vector<ClientPtr> findAllArchivedClients() const;
};


#endif //APTEKA_CLIENTMENAGER_H
