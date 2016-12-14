#pragma once
#ifndef __SORTBASE_H__
#define __SORTBASE_H__

#include "ISort.h"
#include "common.h"

template <typename Type>
class SortBase : public ISort<Type>
{
public:
	SortBase() : name("SortBase") {}
	SortBase(const SortBase& sb) { name = sb.name; }
	SortBase& operator=(const SortBase& sb) { name = sb.name; return *this; }

	virtual std::string getName() { return name;  }

	bool less(const Type& l, const Type& r) override
	{
		return l < r;
	}
	bool less(const Type& l, const Type& r, std::function<int(const Type, const Type)> compareTo)
	{
		return compareTo(l, r) < 0;
	}

	bool isSorted(const std::vector<Type>& elements) override;
	bool isSorted(const std::vector<Type>&, std::function<int(const Type, const Type)>);
protected:
	SortBase(std::string n) : name(n) {}
	std::string name;
};

template <typename Type>
bool SortBase<Type>::isSorted(const std::vector<Type>& elements, std::function<int(const Type, const Type)> compareTo)
{
	auto s = elements.begin();
	for (auto b = s + 1; b != elements.end(); ++b)
	{
		if (!less(*s, *b, compareTo))
			return false;
	}
	return true;
}

template <typename Type>
bool SortBase<Type>::isSorted(const std::vector<Type>& elements)
{
	auto s = elements.begin();
	for (auto b = s + 1; b != elements.end(); ++b)
	{
		if (!less(*s, *b))
			return false;
	}
	return true;
}

#endif /* __SORTBASE_H__ */