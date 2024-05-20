#include "Client.h"

Client::Client(const std::string &uFirstName, const std::string &uLastName, const std::string &uPersonalId, const double &uBudget, ClientTypePtr uClientType) : firstName(
        uFirstName), lastName(uLastName), personalID(uPersonalId), budget(uBudget), clientType(uClientType) {}

Client::~Client() {
}

std::string Client::getClientInfo() const {
    std::stringstream ss;
    ss << "Imie: " << firstName << "\n";
    ss << "Nazwisko: " << lastName << "\n";
    ss << "PESEL: " << personalID << "\n";
    ss << "Budzet: " << std::fixed << std::setprecision(2) << budget << "zl" << (clientType->getTypeName() == "honorary" ? "  ( mozliwy debet 400zl )" : "") << "\n";

    ss << clientType->getTypeInfo() << "\n";
    return ss.str();
}

const std::string &Client::getLastName() const {
    return lastName;
}

const std::string &Client::getFirstName() const {
    return firstName;
}

const std::string &Client::getPersonalID() const {
    return personalID;
}

void Client::setFirstName(const std::string &uFirstName) {
    if(!uFirstName.empty()) {
        Client::firstName = uFirstName;
    }
}

void Client::setLastName(const std::string &uLastName) {
    if(!uLastName.empty()) {
        Client::lastName = uLastName;
    }
}

void Client::setClientType(const ClientTypePtr &uClientType) {
    clientType = uClientType;
}

double Client::applyDiscount(const double &uPrice) const {
    return clientType->applyDiscount(uPrice);
}

double Client::getBudget() const {
    return budget;
}

void Client::setBudget(const double &uBudget) {
    budget = uBudget;
}

const ClientTypePtr Client::getClientType() const {
    return clientType;
}
