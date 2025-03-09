#include <iostream>
#include "HumanA.hpp"

using std::string;
using std::cout;
using std::endl;

Weapon HumanA::defaultWeapon("confidence");

HumanA::HumanA() : name(""), weapon(defaultWeapon) {
}

HumanA::HumanA(const HumanA& other) : name(other.name), weapon(other.weapon) {
}

HumanA& HumanA::operator=(const HumanA& other) {
	if (this == &other) return (*this);
	setName(other.getName());
	HumanA tmp(other);
	weapon.swap(tmp.weapon);
	return (*this);
}

HumanA& HumanA::setName(string nName) {
	name = nName;
	return (*this);
}

const string& HumanA::getName() const {
	return (name);
}

const Weapon& HumanA::getWeapon() const {
	return (weapon);
}

HumanA::HumanA(string nName, Weapon& nWeapon) : name(nName), weapon(nWeapon) {
}

HumanA& HumanA::setWeapon(Weapon& nWeapon) {
	HumanA tmp("", nWeapon);
	weapon.swap(tmp.weapon);
	return (*this);
}

void HumanA::attack() const {
	cout << getName() << " attacks with their " << getWeapon().getType() << endl; 
}