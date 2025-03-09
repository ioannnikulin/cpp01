#include "Zombie.hpp"

int main(void) {
	Zombie onStack0("onStack0");

	Zombie onStack1 = Zombie("onStack1");

	Zombie onStack2(onStack0);
	onStack2.setName("onStack2");

	Zombie onStack3 = onStack2;
	onStack3.setName("onStack3");

	Zombie onStack4 = Zombie("unused");

	Zombie *onHeap0 = new Zombie("onHeap0");

	Zombie *onHeap1 = newZombie("onHeap1");

	Zombie *onHeap2 = new Zombie(onStack0);
	onHeap2->setName("onHeap2");

	Zombie *onHeap3 = new Zombie(onStack1);

	Zombie *onHeap4 = new Zombie(onStack2);

	onStack4 = onStack3;
	onStack4.setName("onStack4");

	delete onHeap3;
	onHeap3 = onHeap2;

	*onHeap4 = onStack3;
	onHeap4->setName("onHeap4");

	onStack0.announce();
	onStack1.announce();
	onStack2.announce();
	onStack3.announce();
	onStack4.announce();
	onHeap0->announce();
	onHeap1->announce();
	onHeap2->announce();
	onHeap3->announce();
	onHeap4->announce();

	randomChump("onStack5");

	delete onHeap0;
	delete onHeap1;
	delete onHeap2;
	delete onHeap4;
	return (0);
}