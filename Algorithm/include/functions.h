#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <iostream>
#include <iterator>

#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <deque>

#include <functional>

#include <typeinfo>
#include <cstdlib>

// common
template<typename _Iterator>
inline void display(const _Iterator __begin,
					const _Iterator __end,
					std::ostream& os)
{
	// for_each(__begin, __end, [&](decltype(*__begin) v)->std::ostream&{os<<v<<" "; return os;});
	// Another method to display
	std::ostream_iterator<decltype(*__begin)> out_iter(os, " ");
	copy(__begin, __end, out_iter);
	os << std::endl;
}

template<typename _Iterator, typename _Condition>
void display(const _Iterator __begin, const _Iterator __end,
			 std::ostream& os, _Condition con)
{
	for_each(__begin, __end, [&](decltype(*__begin) v)->std::ostream&{
			if(con(v)) os<< v <<" ";
			return os;}
		);
	os << std::endl;
}


// 10.1
int count(std::vector<int>::iterator, std::vector<int>::iterator, int value);

// 10.2
int sum(const std::vector<int>&);
void fill_zero(std::list<int>&);
void copy_case();

// 10.3
void elim_dups(std::vector<std::string>& words, std::istream& is, bool isDisoplay);
bool is_shorter(const std::string &s1, const std::string &s2);
void partition_n(std::vector<std::string>::iterator,
				 std::vector<std::string>::iterator,
				 int);
void biggies(std::vector<std::string> &words,
			 std::vector<std::string>::size_type sz,
			 std::istream& is);
bool check_size(std::string&, int);

// 10.4
void insert_container(const std::vector<int> &vec, std::list<int> &output);
void insert_container(const std::vector<int> &vec, std::vector<int> &output);
void insert_container(const std::vector<int> &vec, std::deque<int> &output);

#endif /* __FUNCTIONS_H__ */
