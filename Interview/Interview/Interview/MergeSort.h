#pragma once
#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include "common.h"

template <typename Type>
class MergeSort : public SortBase<Type>
{
public:
	typedef unsigned int size_type;
	MergeSort() : SortBase("MergeSort") {}

	void sort(std::vector<Type>&);
private:
	void merge(std::vector<Type>& nums, size_type low, size_type middle, size_type high);
	void sort(std::vector<Type>&, size_type, size_type);
};

template <typename Type>
void MergeSort<Type>::merge(std::vector<Type>& nums, size_type low, size_type middle, size_type high)
{
	auto iter_begin = nums.begin();
	auto left = low, right = middle + 1;
	std::vector<Type> aux = nums;
	for (auto k = low; k <= high; ++k)
		if (right > high)
			nums[k] = aux[left++];
		else if (left > middle)
			nums[k] = aux[right++];
		else if (less(aux[right], aux[left]))
			nums[k] = aux[right++];
		else
			nums[k] = aux[left++];
}

template <typename Type>
void MergeSort<Type>::sort(std::vector<Type>& nums)
{
	sort(nums, 0, nums.size() - 1);
}

template <typename Type>
void MergeSort<Type>::sort(std::vector<Type>& nums, size_type low, size_type high)
{
	if (low >= high)
		return;
	auto middle = (low + high) / 2;
	sort(nums, low, middle);
	sort(nums, middle + 1, high);
	merge(nums, low, middle, high);
}

#endif /* __MERGESORT_H__ */