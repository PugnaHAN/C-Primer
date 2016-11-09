#include "reg_functions.h"
#include "ran_functions.h"

using namespace std;

int main(int argc, char* argv[])
{
	string pattern = "c[^ei]";
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	// spell_checker("hei, can you spell eight?", rule);
	string file = "hei, can you spell eight?";
	regex r(pattern, regex::icase);
	for (sregex_iterator it(file.begin(), file.end(), r), end_it;
	it != end_it; ++it) {
		// cout << it->str() << endl;
		auto pos = it->prefix().length();
		pos = pos > 40 ? pos - 40 : 0;
		cout << it->prefix().str().substr(pos)
			<< "\n\t\t>>> " << it->str() << " <<<\n"
			<< it->suffix().str().substr(0, 40)
			<< endl;
	}
		

	try {
		regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase);
	}
	catch (regex_error e) {
		cout << e.what() << "\ncode: " << e.code() << endl;
	}

	// check_phone(cin);
	for (auto i = 0; i < 10; ++i)
		cout << genRandm_ui() << " ";
	cout << endl;
}