#pragma once
#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include "common.h"

class Stack
{
public:
	friend class StackIter;
	Stack() : sp(-1) {}

	void push(int in) { items[++sp] = in; }
	int pop() { return items[sp--]; }
	bool empty() { return sp == -1; }
private:
	int items[10];
	int sp;
};

class StackIter
{
public:
	StackIter(const Stack &s) : stk(s), index(0) {}
	void operator++() { index++; }
	bool operator()() { return index != stk.sp + 1; }
	int operator*() { return stk.items[index]; }
private:
	const Stack &stk;
	int index;
};

bool operator==(const Stack &l, const Stack &r);

void testIterator();

#endif /* __ITERATOR_H__ */