#include "StrBlob.h"

using namespace std;

shared_ptr<vector<string>>
StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
	auto ret = wptr.lock();
	if(!ret)
		throw runtime_error("Unbounded StrBlobPtr");
	if(i >= ret->size())
		throw out_of_range(msg);

	return ret;
}

string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}
