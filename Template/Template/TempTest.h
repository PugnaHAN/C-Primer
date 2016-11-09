#pragma once
#ifndef __TEMPTEST_H__
#define __TEMPTEST_H__

#include "common.h"

template <typename Type> 
class TempTest
{
public:
	typedef typename std::vector<Type>::iterator _Iter;
	TempTest(const std::initializer_list<Type>&);
	_Iter begin() { return data->begin(); };
	_Iter end() { return data->end(); };
private:
	std::shared_ptr<std::vector<Type>> data;
};

#endif /* __TEMPTEST_H__ */