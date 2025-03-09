
# include <iostream>
# include <stdlib.h>
# include <string.h>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main(void) {
	string s = "HI THIS IS BRAIN";
	string* stringPTR = &s;
	string& stringREF = s;
	
	cout << "address of string: " << &s << endl;
	cout << "address in stringPTR: " << stringPTR << endl;
	cout << "address in stringREF: " << &stringREF << endl;

	cout << "value of string: " << s << endl;
	cout << "value on the address pointed to by stringPTR: " << *stringPTR << endl;
	cout << "value on the address pointed to by stringREF: " << stringREF << endl;

	return (0);
}