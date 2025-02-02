#include "Zombie.hpp"

int main(void) {
	Zombie onStack0("onStack0");
	Zombie onStack1 = Zombie("onStack1");
	Zombie onStack2(onStack0);
	Zombie onStack3 = onStack2;
	Zombie *onHeap0 = new Zombie("onHeap0");
	Zombie *onHeap1 = newZombie("onHeap1");

	onStack0.announce();
	onStack1.announce();
	onStack2.announce();
	onStack3.announce();
	return (0);
}