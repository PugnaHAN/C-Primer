#include "smart_pointer.h"

using namespace std;

int main(int argc, char* argv[])
{
	// display(cout, get_more_data(cin, dynamic_alloc({1, 2, 3, 4})));
	// cin.clear();
	// display(cout, get_more_data_sp(cin, dynamic_alloc_sp({5, 6, 7, 8})));
	ifstream infile("test");
	if(!infile)
		cerr << "Can't open file test" << endl;
	display(cout, infile);
	infile.close();
}

