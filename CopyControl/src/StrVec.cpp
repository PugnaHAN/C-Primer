#include "StrVec.h"

using namespace std;

// allocator<string> StrVec::alloc =

StrVec::StrVec(initializer_list<string> l)
{
	auto len = l.size();
	int count = 0;
	while(len >> count)
		++count;
	elements = alloc.allocate(--count);
	first_free = elements + len;
	cap = elements + (1 << count);
	for(int i = 0; i < count; ++i)
		alloc.construct((elements + i), *(l.begin() + i));
}

void StrVec::push_back(const string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e)
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
	if(elements)
	{
		for_each(first_free, elements, [](string& s){alloc.destroy(&s);});
		// for(auto p = first_free; p != elements;)
		// 	alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
	free();
}

StrVec& StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate()
{
	auto newcapacity = size()? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for(size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elements));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
