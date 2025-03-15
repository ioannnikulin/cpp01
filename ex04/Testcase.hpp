#ifndef TESTCASE_HPP
#define TESTCASE_HPP

#include <iostream>

using std::string;

struct TestCase {
	public:
	string _input;
	string _what;
	string _with;
	string _exp;
	int _flags;
	int _expRet;

	TestCase(
		string input
		, string what
		, string with
		, string exp
		, int flags
		, int expRet
	);
	~TestCase();
	static const int NO_INPUT_FILE = 1;
	static const int NO_ARGS = 2;
	static const int ONE_ARG = 4;
	static const int TWO_ARGS = 8;
	static const int FOUR_ARGS = 16;
	static const int OUT_FILE_EXISTS = 32;
};

#endif