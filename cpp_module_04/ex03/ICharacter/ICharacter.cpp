#include "ICharacter.hpp"

ICharacter::ICharacter() {
}

ICharacter::ICharacter(const ICharacter &other) {
    *this = other;
}

ICharacter & ICharacter::operator=(const ICharacter &other) {
    if (this != &other) {
        // copy members
    }
    return *this;
}

ICharacter::~ICharacter() {
}
