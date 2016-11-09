#include "linked_container.h"

using namespace std;

int word_cout(const string& word, istream& is, ostream& os) {
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

void store_single_word(std::vector<std::string>& vec, istream& is) {
	istream_iterator<string> is_iter(is), eof;
	while (is_iter != eof) {
		vec.push_back(*is_iter++);
	}
	sort(vec.begin(), vec.end());
	auto uni_iter = unique(vec.begin(), vec.end());
	vec.erase(uni_iter, vec.end());
}

vector<pair<string, int>> store_pairs(istream& is) {
	vector<pair<string, int>> pairs;
	string word;
	int count = 0;
	while (is >> word) {
		// pair<string, int> p(word, count++);
		// auto p = make_pair(word, count++);
		pair<string, int> p = { word, count++ };
		pairs.push_back(p);
	}
	return pairs;
}