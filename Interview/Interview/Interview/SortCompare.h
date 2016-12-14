#pragma once
#ifndef __SORTCOMPARE_H__
#define __SORTCOMPARE_H__

#include <ctime>
#include <cstdarg>

#include "SortBase.h"

template <typename Type, typename Sort>
void sortCompare(std::vector<Type> nums, Sort* st)
{
	auto tmp = nums;
	auto start_time = clock();
	st->sort(tmp);
	auto end_time = clock();
	double used_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000;
	std::cout << st->getName() << ": " << used_time << endl;
}

template<class Type = int, typename Sort, typename ... SortFunc>
void sortCompare(std::vector<Type> nums, Sort* st, SortFunc* ... sorts)
{
	sortCompare(nums, st);
	sortCompare(nums, sorts...);
}

#endif /* __SORTCOMPARE_H__ */