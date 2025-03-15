#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

#define HARL_LVL_COUNT 4

class Harl {
	private:
	void nothing(void) const;
	void debug(void) const;
	void info(void) const;
	void warning(void) const;
	void error(void) const;
	Harl(const Harl& other);
	Harl& operator=(const Harl& other);
	string _lvl_names[HARL_LVL_COUNT];
	void (Harl::*_lvl_methods[HARL_LVL_COUNT])(void) const;
	string _attention_lvl;

	public:
	Harl(void);
	~Harl(void);
	void complain(string fromLevel) const;
};

#endif