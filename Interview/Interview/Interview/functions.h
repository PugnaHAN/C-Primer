#pragma once
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "common.h"

template <typename Type>
void print(std::vector<Type> elements, std::ostream &os = std::cout)
{
	for_each(elements.begin(), elements.end(), [&os](const Type e) { os << e << " "; });
	os << std::endl;
}

template <typename Type, class Func>
void print(std::vector<Type> elements, Func display, std::ostream& os = std::cout)
{
	for_each(elements.begin(), elements.end(), [display, &os](const Type t) { display(t, os); });
	os << std::endl;
}

#endif /* __FUNCTIONS_H__ */