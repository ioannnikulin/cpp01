#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

using std::string;

class Weapon {
private:
	string type;
	Weapon();
	Weapon &operator=(const Weapon &other);
public:
	Weapon(const Weapon &other);
	const string& getType() const;
	Weapon& setType(string nType);
	~Weapon();
	Weapon(string nType);
	void swap(Weapon& other);
};

#endif