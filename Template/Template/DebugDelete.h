#pragma once
#ifndef __DEBUGDELETE_H__
#define __DEBUGDELETE_H__

#include "common.h"
#include <typeinfo>

class DebugDelete
{
public:
	DebugDelete(std::ostream& s = std::cerr) : os(s) {};
	template <typename T> void operator()(T* p) const 
	{ os << "deleting " << typeid(T).name() << std::endl; delete p; }

private:
	std::ostream& os;
};

#endif /* __DEBUGDELETE_H__ */