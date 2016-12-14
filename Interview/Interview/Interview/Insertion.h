#pragma once
#ifndef __INSERTION_H__
#define __INSERTION_H__

#include "SortBase.h"

template <typename Type>
class Insertion : public SortBase<Type>
{
public:
	Insertion() :SortBase("Insertion") {}
	void sort(std::vector<Type>&) override;
};

template <typename Type>
void Insertion<Type>::sort(std::vector<Type>& elements)
{
	int len = elements.size();
	for (auto i = 0; i < len; ++i)
		for (auto j = i; j > 0 && less(elements[j], elements[j - 1]); --j)
			swap(elements[j], elements[j - 1]);	
}

#endif /* __INSERTION_H__ */