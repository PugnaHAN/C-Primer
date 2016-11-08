#include "common.h"
#include "functions.h"
#include "DebugDelete.h"
#include "Blob.h"
#include "TemplateDecl.h"
#include "shared_ptr.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout << compare("hello", "world") << endl;

	double *p = new double;
	DebugDelete d;
	d(p);

	int* ip = new int;
	DebugDelete()(ip);

	// shared_ptr<string> ptr(new string, DebugDelete());

	vector<string> names = { "Allen", "Black", "Cell", "David", "Emma" };
	Blob<string> b({ "Allen", "Black", "Cell", "David", "Emma" });

	display(cout, b.begin(), b.end());

	TempTest<string> temp({ "Allen", "Black", "Cell", "David", "Emma", "Floor" });
	display(cout, temp.begin(), temp.end());

	han::shared_ptr<string> ptr("hello");
	auto ptr1 = ptr;
	cout << *ptr << endl;
}