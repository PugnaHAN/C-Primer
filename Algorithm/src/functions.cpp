#include "functions.h"

using namespace std;

int count(vector<int>::iterator b, vector<int>::iterator e, int value)
{
	int result = 0;
	for(auto it = b; it != e; ++it)
	{
		result = (value == *it)? result + 1 : result;
	}
	return result;
}

int sum(const vector<int>& nums)
{
	return accumulate(nums.cbegin(), nums.cend(), 0);	
}

void fill_zero(list<int>& nums)
{
	fill_n(begin(nums), nums.size(), 0);
}

void copy_case()
{
	cout << "Please input numbers: ";
	vector<int> vec;
	list<int> lst;
	int number;
	// The principle of stop this loop is: Ener->Ctrl-D/Ctrl-Z
	while(cin >> number)
		lst.push_back(number);
	vec.resize(lst.size());
	copy(lst.cbegin(), lst.cend(), vec.begin());
	// After copy
	display(vec.cbegin(), vec.cend(), cout);
}

void elim_dups(vector<string>& words, istream& is, bool isDisplay)
{
// 	if(is != nullptr)
// 	{
// 		string word;
// 		while(is >> word)
// 			words.push_back(word);
// 	}

	// Use the istream_iterator to get all words
	if(is != nullptr)
	{
		istream_iterator<string> is_iter(is), eof;
		while(is_iter != eof)
			words.push_back(*is_iter++);
	}

	sort(words.begin(), words.end());
	sort(words.begin(), words.end(), is_shorter);
	if(isDisplay) display(words.cbegin(), words.cend(), cout);
	
	auto end_unique = unique(words.begin(), words.end());
	if(isDisplay) display(words.cbegin(), words.cend(), cout);

	words.erase(end_unique, words.end());
	if(isDisplay) display(words.cbegin(), words.cend(), cout);
}

bool is_shorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

bool check_size(string& s, int len)
{
	return s.size() > static_cast<unsigned int>(len);
}

void partition_n(vector<string>::iterator begin,
				 vector<string>::iterator end,
				 int len)
{
	// lambda
	/*
	auto last = partition(begin, end,
						  [len](const string& s) mutable->bool {
							  return s.size() > (unsigned int)len;
						  });
	*/
	// Use bind
	auto last = partition(begin, end, bind(check_size, placeholders::_1, len));
	display(begin, last, cout);
}

void biggies(vector<string> &words, vector<string>::size_type sz, istream& is)
{
	elim_dups(words, is, false);
	stable_sort(words.begin(), words.end(),
				[](const string& s1, const string& s2) {return s1.size() > s2.size();});
	auto wc = partition(words.begin(), words.end(),
						[sz](const string& s) {return s.size() >= sz;});
	display(wc, words.end(), cout);
}

void insert_container(const std::vector<int> &vec, std::list<int> &output)
{
	copy(vec.cbegin(), vec.cend(), inserter(output, output.end()));
}

void insert_container(const std::vector<int> &vec, std::vector<int> &output)
{	
	copy(vec.cbegin(), vec.cend(), back_inserter(output));
}

void insert_container(const std::vector<int> &vec, std::deque<int> &output)
{	
	copy(vec.cbegin(), vec.cend(), front_inserter(output));
}

