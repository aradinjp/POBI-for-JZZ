#ifndef APTEKA_CLIENT_H
#define APTEKA_CLIENT_H
#include "ClientType.h"
#include "typedefs.h"
#include <vector>
#include <string>
#include <sstream>

class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    double budget;
    ClientTypePtr clientType;

public:
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getPersonalID() const;
    double getBudget() const;

    const ClientTypePtr getClientType() const;

    std::string getClientInfo() const;
    double applyDiscount(const double &uPrice) const;

    void setBudget(const double &uBudget);
    void setFirstName(const std::string &uFirstName);
    void setLastName(const std::string &uLastName);
    void setClientType(const ClientTypePtr &uClientType);

    Client(const std::string &uFirstName, const std::string &uLastName, const std::string &uPersonalId, const double &uBudget, ClientTypePtr uClientType);
    virtual ~Client();
};


#endif //APTEKA_CLIENT_H

