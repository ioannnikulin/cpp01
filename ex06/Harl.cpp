
 #include "Harl.hpp"

void Harl::nothing(void) const {
	cout << "[NOTHING]\n..." << endl;
}

void Harl::debug(void) const {
	cout << "[DEBUG]\nI love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
		<< "I really do!" << endl;
}

void Harl::info(void) const {
	cout << "[INFO]\nI cannot believe adding extra bacon costs more money. "
		<< "You didn’t put enough bacon in my burger! "
		<< "If you did, I wouldn’t be asking for more!" << endl;
}

void Harl::warning(void) const {
	cout << "[WARNING]\nI think I deserve to have some extra bacon for free. "
		<< "I’ve been coming for years, "
		<< "whereas you started working here just last month." << endl;
}

void Harl::error(void) const {
	cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << endl;
}

Harl::Harl(const Harl& other) {
	(void)other;
}

Harl& Harl::operator=(const Harl& other) {
	(void)other;
	return (*this);
}

Harl::Harl(void) {
	_lvl_names[0] = "DEBUG";
	_lvl_names[1] = "INFO";
	_lvl_names[2] = "WARNING";
	_lvl_names[3] = "ERROR";

	_lvl_methods[0] = &Harl::debug;
	_lvl_methods[1] = &Harl::info;
	_lvl_methods[2] = &Harl::warning;
	_lvl_methods[3] = &Harl::error;
}

Harl::~Harl(void) {
}

void Harl::complain(string fromLevel) const {
	int requestedLvl = -1;
	for (int i = 0; i < HARL_LVL_COUNT; i ++) {
		if (_lvl_names[i] == fromLevel) {
			requestedLvl = i;
			break;
		}
	}
	switch (requestedLvl) {
		case 0:
			debug();
			__attribute__((fallthrough));
		case 1:
			info();
			__attribute__((fallthrough));
		case 2:
			warning();
			__attribute__((fallthrough));
		case 3:
			error();
			break;
		default:
			nothing();
	}
}