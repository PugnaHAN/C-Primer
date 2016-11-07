#include "text_search.h"

using namespace std;

int main(int argc, char* argv[])
{
	ifstream infile("words.txt");
	if (!infile)
		cerr << "Can't open file!" << endl;

	TextQuery tq(infile);

	Query q = Query("fiery") & Query("bird") | ~Query("wind");
	auto qr = q.eval(tq);
	print(cout, qr);

	infile.close();
}