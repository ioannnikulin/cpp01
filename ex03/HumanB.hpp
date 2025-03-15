#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>

#include "Weapon.hpp"

using std::string;

class HumanB {
private:
	string name;
	Weapon* weapon;
	HumanB();
	HumanB(const HumanB& other);
	HumanB(string nName, Weapon nWeapon);
	HumanB& operator=(const HumanB& other);
	HumanB& setName(string nName);
	const string& getName() const;
	Weapon* getWeapon() const;
public:
	HumanB(string nName);
	HumanB& setWeapon(Weapon& nWeapon);
	void attack() const;
	~HumanB();
};

#endif