#ifndef APTEKA_CLIENTREPOSITORY_H
#define APTEKA_CLIENTREPOSITORY_H
#include "typedefs.h"
#include "Client.h"
#include <vector>

class Client;

class ClientRepository {
private:
    std::vector<ClientPtr> clients;

public:
    const ClientPtr getClientByIndex(const unsigned int &uId) const;
    void addClient(const ClientPtr uClient);
    void removeClient(const ClientPtr uClient);

    unsigned int getSize() const;
    std::vector<ClientPtr> findBy(ClientPredicate predicate) const;

    ClientRepository();
    virtual ~ClientRepository();

};


#endif //APTEKA_CLIENTREPOSITORY_H
