#include <iostream>
#include "HumanB.hpp"

using std::string;
using std::cout;
using std::endl;

HumanB::HumanB() : name(""), weapon(nullptr) {
}

HumanB::HumanB(const HumanB& other) : name(other.name), weapon(other.weapon) {
}

HumanB& HumanB::operator=(const HumanB& other) {
	// impossible: we can't manage weapon memory
	(void)other;
	return (*this);
}

HumanB& HumanB::setName(string nName) {
	name = nName;
	return (*this);
}

const string& HumanB::getName() const {
	return (name);
}

Weapon* HumanB::getWeapon() const {
	return (weapon);
}

HumanB::HumanB(string nName, Weapon nWeapon) : name(nName) {
	// impossible: we can't manage weapon memory
	(void)nName;
	(void)nWeapon;
}

HumanB::HumanB(string nName) : name(nName), weapon(nullptr) {
}

HumanB& HumanB::setWeapon(Weapon& nWeapon) {
	weapon = &nWeapon;
	return (*this);
}

void HumanB::attack() const {
	if (getWeapon() == nullptr) {
		cout << getName() << " stares angrily but helplessly" << endl;
		return ;
	}
	cout << getName() << " attacks with their " << getWeapon()->getType() << endl; 
}

HumanB::~HumanB() {
}