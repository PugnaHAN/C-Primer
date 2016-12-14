#pragma once
#ifndef __SELECTION_H__
#define __SELECTION_H__

#include "SortBase.h"

template <class Type>
class Selection : public SortBase<Type>
{
public:
	Selection() :SortBase("Selection") {};
	void sort(std::vector<Type>& elements)
	{
		int len = elements.size();
		for (auto i = 0; i < len; ++i)
		{
			auto min = i;
			for (auto j = i + 1; j < len; ++j)
			{
				if (less(elements[j], elements[min]))
					min = j;
			}
			swap(elements[i], elements[min]);
		}					
	}
};

#endif /* __SELECTION_H__ */