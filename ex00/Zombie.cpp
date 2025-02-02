#include "Zombie.hpp"

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
	cout << name << ": <dies>";
}

Zombie::Zombie(string p_name)
	: name(p_name)
{
}

void Zombie::announce(void) {
	cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}

const Zombie &Zombie::setName(string p_name) {
	name = p_name;
	return (*this);
}