#include "Zombie.hpp"

int main(void) {
	srand(time(0));
	const int SZ = 5;
	Zombie* horde = zombieHorde(SZ, "John");
	for (int i = 0; i < SZ; i ++) {
		horde[i].announce();
	}
	for (int i = 0; i < SZ; i ++) {
		horde[i].retire();
	}
	for (int i = 0; i < SZ; i ++) {
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}