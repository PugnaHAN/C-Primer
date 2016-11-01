#pragma once
#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <fstream>
#include <iterator>

#include <algorithm>

#include <vector>
#include <list>
#include <string>
#include <deque>

#include <map>
#include <set>

#include <functional>

#include <cctype>
#include <typeinfo>


template<typename _Iterator>
void display(const _Iterator __begin,
			 const _Iterator __end,
			 std::ostream& os)
{
	// for_each(__begin, __end, [&](decltype(*__begin) v)->std::ostream&{os<<v<<" "; return os;});
	// Another method to display
	std::ostream_iterator<decltype(*__begin)> out_iter(os, " ");
	copy(__begin, __end, out_iter);
	os << std::endl;
}

template<class _First, class _Second>
inline void disp_pair(std::pair<_First, _Second>& p, std::ostream& os) {
	os << p.first << ":" << p.second << "\n";
}

template<typename _Iterator>
void display_pairs(_Iterator __begin, _Iterator __end, std::ostream& os) {
	for_each(__begin, __end, [&os](decltype(*__begin) v) {disp_pair(v, os); });
	os << endl;
}

#endif /* __COMMON_H__ */
