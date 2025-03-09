#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <stdlib.h>
# include <string.h>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

class Zombie {
private:
	string name;

public:
	~Zombie();
	Zombie(string p_name);
	Zombie(const Zombie &other);
	Zombie &operator=(const Zombie &other);
	Zombie();
	void announce(void) const;
	const Zombie &setName(string p_name);
	string getName() const;
	const Zombie &retire();
};

Zombie* zombieHorde(int N, string name);
#endif