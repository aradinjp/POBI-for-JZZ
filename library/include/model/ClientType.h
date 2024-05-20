#ifndef APTEKA_CLIENTTYPE_H
#define APTEKA_CLIENTTYPE_H
#include <string>

class ClientType {
public:
    virtual double applyDiscount(const double &uPrice) const;
    virtual std::string getTypeInfo() const;
    virtual std::string getTypeName() const;

    ClientType();
    virtual ~ClientType();
};



#endif //APTEKA_CLIENTTYPE_H
