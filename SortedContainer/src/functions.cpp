#include "functions.h"

using namespace std;

bool find(vector<int>::iterator b, vector<int>::iterator e, int v)
{
	for(auto it = b; it != e; ++it)
	{
		if(*it == v)
			return true;
	}
	return false;
}

vector<int>::iterator find_value(vector<int>::iterator b,
								 vector<int>::iterator e,
								 int v)
{
	for(auto it = b; it != e; ++it)
	{
		if(*it == v)
			return it;
	}
	return e;
}	

void init_value(vector<string>& strs, list<char *>& chs)
{
	strs.assgin(chs.cbegin(), chs.cend());
}

bool is_equal(const vector<int>& vec1, const vector<int>& vec2)
{
	return vec1 == vec2;
}

bool is_equal(const vector<int>& vec, const list<int>& lst)
{
	if(vec.size() != lst.size())
		return false;

	int count = 0;
	for(auto it = lst.begin(); it != lst.end(); ++it)
	{
		if(*it != vec[count])
			return false;
		++count;
	}
	return true;
}

void print_input(ostream& os)
{
	deque<string> strs;
	string word;
	while(cin >> word)
	{
		strs.push_back(word);
	}

	for(auto it = strs.begin(); it != strs.end(); ++it)
	{
		os << strs.pop_front() << " ";
	}
	os << endl;
}
