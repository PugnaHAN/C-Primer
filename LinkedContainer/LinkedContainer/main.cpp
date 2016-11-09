#include "linked_container.h"

using namespace std;

int main(int argc, char* argv[]) {
	// word_cout("hello", cin, cout);

	ifstream in("words.txt");

	if (!in)
		cerr << "Invalid file" << endl;

	vector<pair<string, int>> vecs = store_pairs(in);

	display_pairs(vecs.begin(), vecs.end(), cout);
}