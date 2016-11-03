#include "Employee.h"
#include "HasPtr.h"
#include "Message.h"
#include "Folder.h"

using namespace std;

int main(int argc, char* argv[])
{
	Employee e1, e2("Jack");
	Employee e3 = e2, e4(e2);

	display(cout, e1);
	display(cout, e2);
	display(cout, e3);
	display(cout, e4);

	vector<HasPtr> hps;
	HasPtr hp2("Allen"), hp3("Black"), hp1("Crack"), hp4("David");
	hps.push_back(hp1);
	hps.push_back(hp2);
	hps.push_back(hp3);
	hps.push_back(hp4);
	
	sort(hps.begin(), hps.end());

	Message m1("do homework"), m2("buy some food");
	Message m3("Have a rest");
	Message m4(m3);

	Folder f1("Todo"), f2("Enjoy"), f3("Nothing");

	m1.save(f1);
	m2.save(f3);
	m3.save(f2);
	m4.save(f1);

	swap(m1, m2);

	return 0;
}
