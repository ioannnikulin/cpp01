#include "Zombie.hpp"
#include <ctime>
#include <cstdlib>

Zombie::Zombie() 
	: name("")
{
}

Zombie::Zombie(const Zombie &other)
	: name(other.name)
{
}

Zombie &Zombie::operator=(const Zombie &other) {
	if (this != &other) {
		name = other.name;
	}
	return (*this);
}

Zombie::~Zombie() {
	cout << name << ": <dies>" << endl;
}

Zombie::Zombie(string p_name)
	: name(p_name)
{
}

void Zombie::announce(void) const {
	cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}

const Zombie &Zombie::setName(string p_name) {
	name = p_name;
	return (*this);
}

string Zombie::getName() const {
	return (name);
}

const Zombie& Zombie::retire() {
	const int SZ = 14;
	string prefix[] = {
		"ex-"
		, "deceased "
		, "late "
		, "ceased-to-be-"
		, "bereft of life "
		, "resting in peace "
		, "partaker of choir invisible "
		, "expired "
		, "gone to meet its maker "
		, "stiff "
		, "pushing up the daisies "
		, "kicked the bucket"
		, "shuffled off the mortal coil "
		, "run down the curtain "
	};
	setName(prefix[rand() % SZ] + getName());
	return (*this);
}