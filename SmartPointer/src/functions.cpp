#include "functions.h"
#include "StrBlob.h"

using namespace std;

vector<int>* dynamic_alloc(initializer_list<int> data)
{
	return new vector<int>(data);
}

vector<int>* get_more_data(istream& is, vector<int>* v)
{
	int data;
	while(is >> data)
		v->push_back(data);

	return v;
}

void display(ostream& os, vector<int>* v)
{
	for(auto it = v->begin(); it != v->end(); ++it)
		os << *it << " ";

	os << endl;

	delete v;
	v = nullptr;
}


shared_ptr<vector<int>> dynamic_alloc_sp(initializer_list<int> data)
{
	return make_shared<vector<int>>(data);
}

shared_ptr<vector<int>> get_more_data_sp(istream& is,
										 shared_ptr<vector<int>> sp)
{
	int data;
	// istream_iterator<int> iter(is), eof;
	// while(iter != eof)
	// {
	// 	data = *iter++;
	// 	sp->push_back(data);
	// }
	while(is >> data)
		sp -> push_back(data);
	return sp;
}

void display(ostream& os, shared_ptr<vector<int>> sp)
{
	for(auto it = sp->begin(); it != sp->end(); ++it)
		os << *it << " ";
	os << endl;
}

void display(ostream& os, istream& is)
{
	string line;
	StrBlob blob;
	while(getline(is, line))
		blob.push_back(line);

	for(auto sbp = blob.begin(); sbp.current() != blob.end().current(); sbp.incr())
	{
		os << sbp.deref() << endl;
	}
}
