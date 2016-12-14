#pragma once
#ifndef __ISORT_H__
#define __ISORT_H__

#include <vector>

template <typename CompareElement>
class ISort
{
public:
	virtual ~ISort() = default;
	virtual bool less(const CompareElement&, const CompareElement&) = 0;
	virtual void swap(CompareElement& l, CompareElement& r)
	{
		auto tmp = l;
		l = r;
		r = tmp;
	}
	virtual bool isSorted(const std::vector<CompareElement>&) = 0;
	virtual void sort(std::vector<CompareElement>&) = 0;
};

#endif /* __ISORT_H__ */