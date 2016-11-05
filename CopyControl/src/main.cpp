#include "Employee.h"
#include "HasPtr.h"
#include "Message.h"
#include "Folder.h"
#include "StrVec.h"
#include "String.h"
#include "X.h"

using namespace std;

String get(const String& s)
{
	return s;
}

int main(int argc, char* argv[])
{
	/*
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
	*/


	/*
	Message m1("do homework"), m2("buy some food");
	Message m3("Have a rest");
	Message m4(m3);

	Folder f1("Todo"), f2("Enjoy"), f3("Nothing");

	m1.save(f1);
	m2.save(f3);
	m3.save(f2);
	m4.save(f1);

	swap(m1, m2);
	*/

	StrVec sv1, sv2({"I", "am", "a", "hero"});
	sv1 = sv2;
	// cout << sv2.size() << " " << sv2.reserve() << " " << sv2.capacity() << endl;
	for_each(sv1.begin(), sv1.end(), [](const string& s) {cout << s << " ";});
	// for(auto it = sv1.begin(); it != sv1.end(); ++it)
	// 	cout << *it << " ";
	cout << endl;

	X x1, x2("x2");
	X* xp = &x1;
	// vector<X> xs(initializer_list<X>({"xs1", "xs2", "xs3"}));
	X x4 = X("x4");

	// vector<X> xs({x1, x2, x4});
	
	auto x3 = make_shared<X>(x4);

	String s1("I am a hero"), s2(" who has a big pig");
	// cout << s1 + s2 << endl;

	vector<String> strings;
	strings.push_back(s1);
	strings.push_back(s2);
	strings.push_back(get(s1));

	return 0;
}
