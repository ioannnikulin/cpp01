#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>

#include "Weapon.hpp"

using std::string;

class HumanA {
private:
	string name;
	Weapon& weapon;
	HumanA();
	HumanA(const HumanA& other);
	HumanA& operator=(const HumanA& other);
	HumanA& setName(string nName);
	const string& getName() const;
	const Weapon& getWeapon() const;
	static Weapon defaultWeapon;
public:
	HumanA(string nName, Weapon& nWeapon);
	HumanA& setWeapon(Weapon& nWeapon);
	void attack() const;
};

#endif