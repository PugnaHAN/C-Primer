#include "common.h"
#include "reg_functions.h"
#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool spell_checker(const string& src, const string& rule) {
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]";

	regex r(pattern);

	smatch results;

	if (regex_search(src, results, r)) {
		cout << results.str() << endl;
		return true;
	}
	else {
		return false;
	}
		
}