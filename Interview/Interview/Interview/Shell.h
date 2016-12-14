#pragma once
#ifndef __SHELL_H__
#define __SHELL_H__

#include "SortBase.h"

template <typename Type>
class Shell : public SortBase<Type>
{
public:
	Shell() :SortBase("Shell") {}

	void sort(std::vector<Type>&);
	void sort(std::vector<Type>&, std::function<int(const Type, const Type)>);
};

template <typename Type>
void Shell<Type>::sort(std::vector<Type>& elements)
{
	int h = 1, len = elements.size();
	while (3 * h < len)
		h = 3 * h + 1;
	while (h > 0)
	{
		for (int i = h; i < len; ++i)
			for (int j = i; j >= h && less(elements[j], elements[j - h]); j -= h)
				swap(elements[j], elements[j - h]);
		h /= 3;
	}
}

template <typename Type>
void Shell<Type>::sort(std::vector<Type>& elements, std::function<int(const Type, const Type)> compareTo)
{
	int h = 1, len = elements.size();
	while (3 * h < len)
		h = 3 * h + 1;
	while (h > 0)
	{
		for (int i = h; i < len; ++i)
			for (int j = i; j >= h && less(elements[j], elements[j - h], compareTo); j -= h)
				swap(elements[j], elements[j - h]);
		h /= 3;
	}
}

#endif /* __SHELL_H__ */