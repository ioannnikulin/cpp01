#include "Zombie.hpp"

Zombie* zombieHorde(int N, string name) {
	Zombie* res = new Zombie[N];
	for (int i = 0; i < N; i ++) {
		res[i] = Zombie(name);
	}
	return (res);
}