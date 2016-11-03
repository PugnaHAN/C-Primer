#include "HasPtr.h"

using namespace std;

/* Act as value */
// HasPtr::HasPtr(const HasPtr& hp):p(new string(*hp.p)), i(hp.i) {}

// HasPtr& operator=(const HasPtr& hp)
// {
// 	string* sp = new string(*hp.p);
// 	delete p;
// 	p = sp;
// 	i = hp.i;
// 	return *this;
// }

// HasPtr::~HasPtr() {delete p;}

/* Act as pointer */
HasPtr::HasPtr(const std::string &s):
		ps(new std::string(s)), i(0), use(new std::size_t(1)) {}

HasPtr::HasPtr(const HasPtr& p):
		ps(p.ps), i(p.i), use(p.use) {++*use;}

// Should handle the self evaluated
HasPtr& HasPtr::operator=(const HasPtr& hp)
{
	++*hp.use;
	if(--*use == 0)
	{
		delete ps;
		delete use;
	}
	ps = hp.ps;
	i = hp.i;
	use = hp.use;
	++*use;
	return *this;
}

HasPtr::~HasPtr()
{
	if(--*use == 0)
	{
		delete ps;
		delete use;
	}
}

void swap(HasPtr& hp1, HasPtr& hp2)
{
	using std::swap;
	cout << "swap processing..." << endl;
	swap(hp1.ps, hp2.ps);
	swap(hp1.i, hp2.i);	
}

bool HasPtr::operator<(const HasPtr& hp) const
{
	return *ps < *hp.ps;
}
