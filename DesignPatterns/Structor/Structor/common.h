#pragma once
#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <iomanip>

#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <functional>

const unsigned int LableLength = 60;

void Pattern(const char*);

template <typename _Index, typename _Func>
inline void switchFunc(std::map<_Index, _Func> handler, _Index param)
{
	handler[param]();
}

#endif /* __COMMON_H__ */