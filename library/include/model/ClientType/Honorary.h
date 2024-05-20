#ifndef APTEKA_HONORARY_H
#define APTEKA_HONORARY_H
#include "ClientType.h"

class ClientType;

class Honorary : public ClientType {
public:
    double applyDiscount(const double &uPrice) const override;
    std::string getTypeInfo() const override;
    std::string getTypeName() const override;

    Honorary();
    ~Honorary() override;
};


#endif //APTEKA_HONORARY_H
