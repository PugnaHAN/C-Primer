#pragma once
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "common.h"

//template<typename Type> int compare(const Type& left, const Type& right)
//{
//	if (left > right)
//		return 1;
//	else if (left < right)
//		return -1;
//	else
//		return 0;
//}

template <typename T, typename F = less<T>>
int compare(const T& v1, const T& v2, F f = F())
{
	if (f(v1, v2)) return -1;
	if (f(v2, v1)) return 1;
	return 0;
}

template <typename _Iter>
void display(std::ostream& os, _Iter b, _Iter e) 
{
	for_each(b, e, [&os](const decltype(*b) &t) {os << t << " "; });
	os << std::endl;
}

// Tail return type
template <typename It>
auto fcn(It beg, It end) -> decltype(*beg) {
	return *beg;
}

#endif /* __FUNCTIONS_H__ */
