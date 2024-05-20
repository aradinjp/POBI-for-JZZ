#include "Default.h"
#include "sstream"

Default::Default() {
}

Default::~Default() {
}

double Default::applyDiscount(const double &uPrice) const {
    return 0;
}

std::string Default::getTypeInfo() const {
    std::stringstream ss;
    ss << ClientType::getTypeInfo() << "Typ: Default" << "\n";
    return ss.str();
}

std::string Default::getTypeName() const {
    return "default";
}