#pragma once
#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <iterator>

#include <vector>
#include <list>
#include <string>
#include <deque>

#include <map>
#include <set>

#include <functional>

#include <cctype>


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

#endif /* __COMMON_H__ */
