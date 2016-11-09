#include "reg_functions.h"

using namespace std;

bool spell_checker(const string& src, const string& rule) {
	//string pattern("[^c]ei");
	//pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]";

	regex r(rule);

	smatch results;

	if (regex_search(src, results, r)) {
		cout << results.str() << endl;
		return true;
	}
	else {
		return false;
	}
}

void check_phone(istream& is) {
	string pattern = "(\\()?(\\{d}{3})(\\))?([.- ])?(\\{d}{3})([.- ])?(\\{d}{4})";
	regex r(pattern);
	string line;
	while (getline(is, line)) {
		for (sregex_iterator it(line.begin(), line.end(), r), end_it;
		it != end_it; ++it) {
			if (valid(*it)) {
				cout << "valid: " << it->str() << endl;
			}
			else
				cout << "Invalid: " << it->str() << endl;
		}
	}
}

bool valid(const smatch &m) {
	if (m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}