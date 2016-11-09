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

template <typename T> std::string debug_rep(const T& t) {
	std::ostringstream ret;
	ret << t;
	return ret.str();
}

template <typename  T> std::string debug_rep(T* p) {
	std::ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

template <typename Type> void func(Type&& val) {
	Type t = val;
	t += 1;
	std::cout << "t = " << t << "; val = " << val << std::endl;
}

template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2) {
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

template <typename ... Args> void foo(Args ... rest) {
	std::cout << "Args: " << sizeof...(Args) << std::endl;
	std::cout << "Rest: " << sizeof...(rest) << std::endl;
}

template <typename T>
std::ostream& print(std::ostream &os, const T &t) {
	return os << t;
}

template <typename T, typename... Args>
std::ostream& print(std::ostream& os, const T& t, Args... rest) {
	os << t << ", ";
	return print(os, rest...);
}

#endif /* __FUNCTIONS_H__ */