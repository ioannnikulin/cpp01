#include "Weapon.hpp"

Weapon::Weapon() : type("") {
}

Weapon::Weapon(const Weapon &other) {
	setType(other.getType());
}

Weapon& Weapon::operator=(const Weapon &other) {
	if (this == &other) return (*this);
	setType(other.getType());
	return (*this);
}

const string& Weapon::getType() const {
	return (type);
}

Weapon& Weapon::setType(string nType) {
	type = nType;
	return (*this);
}

Weapon::~Weapon() {
}

Weapon::Weapon(string nType) : type(nType) {
}

void Weapon::swap(Weapon &other) {
	std::swap(type, other.type);
}