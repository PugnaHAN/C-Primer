#include "linked_container.h"

using namespace std;

int word_count(const string& word, istream& is, ostream& os) {
	os << "Please enter strings: " << endl;

	istream_iterator<string> iter(is), eof;
	map<string, int> words;
	while (iter != eof) {
		string w = *iter++;
		if (ispunct(*(--w.end())))
			w = w.substr(0, w.size() - 1);
		for (auto it = w.begin(); it != w.end(); ++it)
			*it = tolower(*it);
		++words[w];
	}

	for (auto it = words.begin(); it != words.end(); ++it) {
		os << it->first << ": " << it->second << endl;
	}

	return words[word];
}
