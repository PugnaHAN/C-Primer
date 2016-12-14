#pragma once
#ifndef __EXECUTEADAPTER_H__
#define __EXECUTEADAPTER_H__

#include "ExecuteInterface.h"

template <class Type>
class ExecuteAdapter : public ExecuteInterface
{
public:
	ExecuteAdapter(Type *obj, void(Type::*m)()) :
		object(obj), method(m) {}
	~ExecuteAdapter() { delete object; }

	void execute() { (object->*method)(); }

private:
	Type* object; // ptr-to-object attribute

	void (Type:: *method)(); // ptr-to-member-function attribute
};

#endif /* __EXECUTEADAPTER_H__ */