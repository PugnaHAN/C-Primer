#include <iostream>
#include <fstream>

#include "functions.h"

using namespace std;

int main(int argc, char* argv[])
{
	vector<int> numbers_vec = {1, 3, 5, 3, 4, 7, 9, 2, 4, 6, 8, 0};
	cout << count(begin(numbers_vec), end(numbers_vec), 4) << endl;

	list<int> numbers_lst;
	numbers_lst.assign(numbers_vec.begin(), numbers_vec.end());

	cout << "Befor fill_n:" << endl;
	display(numbers_lst.cbegin(), numbers_lst.cend(), cout);

	fill_zero(numbers_lst);

	cout << "After fill_n:" << endl;
	display(numbers_lst.cbegin(), numbers_lst.cend(), cout);

	vector<string> words;
	ifstream infile("assets/test_str");
	if(!infile)
		cerr << "Invalid file!" << endl;
	elim_dups(words, infile, true);
	infile.close();

	// partition_n(words.begin(), words.end(), 5);
	biggies(words, 5, infile);

	vector<int> vec_copy;
	list<int> lst_copy;
	deque<int> deque_copy;
	insert_container(numbers_vec, vec_copy);
	insert_container(numbers_vec, deque_copy);
	insert_container(numbers_vec, lst_copy);

	cout << "BACK INSERTER: " << endl;
	display(vec_copy.begin(), vec_copy.end(), cout);
	cout << "FRONT INSERTER: " << endl;
	display(deque_copy.begin(), deque_copy.end(), cout);
	cout << "INSERTER: " << endl;
	display(lst_copy.begin(), lst_copy.end(), cout);
}	
