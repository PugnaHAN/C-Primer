#pragma once
#ifndef __RESPCHAIN_H__
#define __RESPCHAIN_H__

#include "common.h"

class Component
{
public:
	Component(int v, Component* n) : value(v), next(n) {}
	// ~Component() { if (next) { delete next; next = nullptr; } }
	
	void setNext(Component* n) { next = n; }
	virtual void traverse() { std::cout << value << ' '; }
	virtual void volunteer() { if(next) next->volunteer(); }
private:
	int value;
	Component* next;
};

class Primitive : public Component
{
public:
	Primitive(int val, Component *n = nullptr) : Component(val, n) {}
	void volunteer()
	{
		Component::traverse();
		if (rand() * 100 % 6 != 0)
			Component::traverse();
	}
};

class Composite : public Component
{
public:
	Composite(int val, Component* n = nullptr) : Component(val, n) {}
	
	void add(Component *c) { children.push_back(c); }
	void traverse() 
	{
		Component::traverse();
		for_each(children.begin(), children.end(), [](Component* c) { c->traverse(); });
	}
	void volunteer() { Component::volunteer(); }
private:
	std::vector<Component *> children;
};

void testRespChain();

#endif /* __RESPCHAIN_H__ */