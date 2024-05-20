#ifndef APTEKA_DEFAULT_H
#define APTEKA_DEFAULT_H
#include "ClientType.h"

class ClientType;

class Default : public ClientType {
public:
    double applyDiscount(const double &uPrice) const override;
    std::string getTypeInfo() const override;
    std::string getTypeName() const override;

    Default();
    ~Default() override;
};


#endif //APTEKA_DEFAULT_H
