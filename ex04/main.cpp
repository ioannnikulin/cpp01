#include <fstream>
#include <iostream>
#include <sstream>

using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::endl;
using std::cout;
using std::clog;
using std::cerr;

int usage(int ret) {
	cout << "Usage: ./notsed <infile> <what> <with>\n"
		<< "\t<infile> - read-acessible file\n"
		<< "\t<what> - what text to search for in <infile>'s contents\n"
		<< "\t<with> - what text to replace the <what> with\n"
		<< "Replacement result goes to file named <infile>.replace\n"
		<< endl;
	return (ret);
}

int simple(ifstream& ifs, ofstream& ofs, string what, string with) {
	string curline;
	while (getline(ifs, curline)) {
		size_t lastEnd = 0;
		while (lastEnd != string::npos) {
			clog << "searching from " << lastEnd << endl;
			size_t thisStart = curline.find(what, lastEnd);
			clog << "found at " << thisStart << endl;
			ofs << curline.substr(lastEnd, thisStart - lastEnd);
			clog << "[" << curline.substr(lastEnd, thisStart - lastEnd) << "]" << endl;
			if (thisStart != string::npos) {
				ofs << with;
				clog << "[" << with << "]" << endl;
			}
			lastEnd = 
				thisStart == string::npos 
				|| curline.length() - thisStart < what.length() 
				? string::npos 
				: thisStart + what.length();
		}
		if (ifs.peek() != EOF) {
			ofs << "\n";
			clog << "{\n}" << endl;
		}
	}
	return (0);
}

int buffered(ifstream& ifs, ofstream& ofs, string what, string with) {
	string curline = "";
	string rdbuffer;
	while (getline(ifs, rdbuffer)) {
		curline += rdbuffer;
		if (ifs.peek() != EOF) {
			curline += "\n";
		}
		clog << "buffer: [" << curline << "]" << endl;
		size_t lastEnd = 0;
		bool enough = false;
		size_t thisStart;
		while (!enough) {
			clog << "searching from " << lastEnd << endl;
			thisStart = curline.find(what, lastEnd);
			clog << "found at " << thisStart << endl;
			if (thisStart != string::npos) {
				ofs << curline.substr(lastEnd, thisStart - lastEnd);
				clog << "[" << curline.substr(lastEnd, thisStart - lastEnd) << "]" << endl;
				ofs << with;
				clog << "[" << with << "]" << endl;
				lastEnd = thisStart + what.length();
			}
			enough = 
				thisStart == string::npos 
				|| curline.length() - thisStart < what.length();
		}
		if (what.size() < curline.size()) {
			ofs << curline.substr(lastEnd, curline.size() - lastEnd - what.size());
			clog << "finally [" << curline.substr(lastEnd, curline.size() - lastEnd - what.size() + 1) << "]" << endl;
			curline = curline.substr(curline.size() - what.size() + 1, curline.size());
		}
		clog << "buffer: [" << curline << "]" << endl;
	}
	return (0);
}

int go(ifstream& ifs, ofstream& ofs, string what, string with) {
	if (what.length() == 0) {
		while (ifs) {
			string curline;
			getline(ifs, curline);
			ofs << curline;
			if (ifs.peek() != EOF) {
				ofs << "\n";
				clog << "{\n}" << endl;
			}
		}
		return (0);
	}
	if (string::npos == what.find("\n")) {
		return (simple(ifs, ofs, what, with));
	}
	return (buffered(ifs, ofs, what, with));
}

int main(int argc, char **argv) {
	if (argc != 4) {
		return (usage(1));
	}
	ifstream ifs(argv[1]);
	if (!ifs.is_open()) {
		cout << "Error opening input file" << endl;
		return (2);
	}
	stringstream ss;
	ss << argv[1] << ".replace";
	ofstream ofs(ss.str().c_str());
	if (!ofs.is_open()) {
		cout << "Error opening output file" << endl;
		return (3);
	}
	int ret = go(ifs, ofs, argv[2], argv[3]);
	ifs.close();
	ofs.close();
	return (ret);
}