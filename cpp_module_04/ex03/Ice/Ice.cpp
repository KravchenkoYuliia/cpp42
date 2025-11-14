#include "Ice.hpp"

Ice::Ice() {
}

Ice::Ice(const Ice &other) {
    *this = other;
}

Ice & Ice::operator=(const Ice &other) {
    if (this != &other) {
        // copy members
    }
    return *this;
}

Ice::~Ice() {
}
