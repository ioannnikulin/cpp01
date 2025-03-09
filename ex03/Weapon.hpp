#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

using std::string;

class Weapon {
private:
	string type;
	Weapon();
	Weapon(const Weapon &other);
	Weapon &operator=(const Weapon &other);
public:
	const string& getType() const;
	Weapon& setType(string nType);
	~Weapon();
	Weapon(string nType);
	void swap(Weapon& other);
};

#endif