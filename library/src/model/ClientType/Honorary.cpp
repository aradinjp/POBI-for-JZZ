#include "Honorary.h"
#include "sstream"

Honorary::Honorary() {
}

Honorary::~Honorary() {
}

double Honorary::applyDiscount(const double &uPrice) const {
    return uPrice * 0.2;
}

std::string Honorary::getTypeInfo() const {
    std::stringstream ss;
    ss << ClientType::getTypeInfo() << "Typ: Honorary" << "\n";
    return ss.str();
}

std::string Honorary::getTypeName() const {
    return "honorary";
}