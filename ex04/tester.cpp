#include <cassert>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sstream>

#include "Testcase.hpp"

using std::string;
using std::endl;
using std::cout;
using std::cerr;
using std::clog;
using std::stringstream;
using std::ifstream;

TestCase::TestCase(
	string input
	, string what
	, string with
	, string exp
	, int flags
	, int expRet
): 
	_input(input)
	, _what(what)
	, _with(with)
	, _exp(exp)
	, _flags(flags)
	, _expRet(expRet)
{
}

TestCase::~TestCase() {
}

#define SZ 20

#define DEBUG

int main() {
	// \n in the end are not necessarily preserved
	// just end your files with \n please
	// otherwise I'd have to manage files byte-by-byte, which the subject discourages from
	TestCase tests[SZ] = {
		TestCase("abacabadabacaba", "aba", "bab", "babcbabdbabcbab", 0, 0)
		, TestCase("abacabadabacaba", "aba", "e", "ecedece", 0, 0) // shorter
		, TestCase("abacabadabacaba", "aba", "", "cdc", 0, 0) // delete
		, TestCase("\n\nabacabadabacaba\n\n", "aba", "qweqwe", "\n\nqweqwecqweqwedqweqwecqweqwe\n\n", 0, 0) // longer
		, TestCase("abacabadabacaba\n", "e", "aba", "abacabadabacaba\n", 0, 0) // no match
		, TestCase("abacabadabacaba\n\n", "", "aba", "abacabadabacaba\n\n", 0, 0) // replace empty (do nothing)
		, TestCase("abacaba\ndabacaba", "", "aba", "abacaba\ndabacaba", 0, 0) // replace empty (do nothing)
		, TestCase("abacabadabacaba\n", "", "", "abacabadabacaba\n", 0, 0) // empty to empty
		, TestCase("aba\ncaba\ndaba\ncaba\n", "\\n", "q", "abaqcabaqdabaqcabaq", 0, 0) // \n to regular
		, TestCase("aba\ncaba\ndaba\ncaba\n", "\\n", "", "abacabadabacaba", 0, 0) // delete \ns
		, TestCase("aba\ncaba\ndaba\ncaba\n", "bac", "www", "aba\ncaba\ndaba\ncaba\n", 0, 0) // no match because of \n
		, TestCase("aba\ncaba\ndaba\ncaba\n", "ba\\nc", "www", "awwwaba\ndawwwaba\n", 0, 0) // \n in the middle
		, TestCase("aba\ncaba\ndaba\ncaba", "ba\\n", "www", "awwwcawwwdawwwcaba", 0, 0) // \n in the end of token
		, TestCase("a\nb\na\nc\na\nb\na\nd\na\nb\na\nc\na\nb\na\n", "\nb\na\n", "w", "awc\nawd\nawc\naw", 0, 0) // multiple \ns in the token
		, TestCase("abacabadabacaba", "aba", "bab", "", TestCase::NO_INPUT_FILE, 2)
		, TestCase("abacabadabacaba", "aba", "bab", "", TestCase::NO_ARGS, 1)
		, TestCase("abacabadabacaba", "aba", "bab", "", TestCase::ONE_ARG, 1)
		, TestCase("abacabadabacaba", "aba", "bab", "", TestCase::TWO_ARGS, 1)
		, TestCase("abacabadabacaba", "aba", "bab", "", TestCase::FOUR_ARGS, 1)
		, TestCase("abacabadabacaba", "aba", "bab", "babcbabdbabcbab", TestCase::OUT_FILE_EXISTS, 0)
	};
	stringstream ss;
	ifstream ifs;
	for (int i = 0; i < SZ; i++) {
		cout << "#" << i << endl;
		ss << "rm -f out.txt err.txt in.txt ";
		if (!(tests[i]._flags & TestCase::OUT_FILE_EXISTS)) {
			ss << "in.txt.replace ";
		}
		ss << " && echo \"" << tests[i]._input << "\" > in.txt";
		assert(0 == system(ss.str().c_str()));
		if (tests[i]._flags & TestCase::NO_INPUT_FILE) {
			system("rm -f in.txt");
		}
		ss.str("");
		ss << "bash -c \"valgrind --leak-check=full --show-leak-kinds=all ./notsed ";
		if ((tests[i]._flags & TestCase::NO_ARGS) == 0) {
			ss << "in.txt ";
		}
		if ((tests[i]._flags & (TestCase::NO_ARGS | TestCase::ONE_ARG)) == 0) {
			ss << "$'" << tests[i]._what << "' ";
		}
		if ((tests[i]._flags & (TestCase::NO_ARGS | TestCase::ONE_ARG | TestCase::TWO_ARGS)) == 0) {
			ss << "$'" << tests[i]._with << "' ";
		}
		if (tests[i]._flags & TestCase::FOUR_ARGS) {
			ss << "$'" << tests[i]._with << "' ";
		}
		ss << "\" 1> out.txt 2> err.txt";
		#ifdef DEBUG
		clog << ss.str() << endl;
		#endif
		int actRet = system(ss.str().c_str()) >> 8;
		assert(tests[i]._expRet == actRet);
		ss.str("");

		ifs.open("in.txt.replace");
		if (tests[i]._flags != 0 && tests[i]._flags != TestCase::OUT_FILE_EXISTS) {
			assert(!ifs.is_open());
		} else {
			assert(ifs.is_open());
			ss << ifs.rdbuf();
			ifs.close();
			#ifdef DEBUG
			if (0 != ss.str().compare(tests[i]._exp))
				cout << "expected {" << tests[i]._exp << "}" << endl << "got {" << ss.str() << "}" << endl;
			#endif
			assert(0 == ss.str().compare(tests[i]._exp));
		}
		ss.str("");
		
		ifs.open("err.txt");
		ss << ifs.rdbuf();
		ifs.close();
		assert(string::npos != ss.str().find("ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)"));
		ss.str("");
	}
	cout << "test success" << endl;
	return (0);
}