#pragma once
#ifndef __COMPOSITE_H__
#define __COMPOSITE_H__

#include "common.h"

class Component
{
public:
	virtual void traverse() = 0;
	void setTabs(int ts) { tabs = ts; }
	int getTabs() { return tabs; }
protected:
	int tabs = 0;
};

class Primitive : public Component
{
public:
	Primitive(int v) : value(v) {}
	void traverse() 
	{
		std::cout << std::string(getTabs(), '\t') << value << " " << std::endl;
	}
private:
	int value;
};

class Composite : public Component
{
public:
	Composite(int val) : value(val) {}

	void add(Component* c) 
	{ 
		c->setTabs(this->tabs + 1);
		children.push_back(c); 
	}
	void traverse() 
	{
		std::cout << value << " " << std::endl;
		for (auto c : children)
		{
			c->traverse();
		}			
	}
protected:
	int value;
	std::vector<Component*> children;
};

class Row: public Composite
{
public:
	Row(int val) : Composite(val) {}

	void traverse()
	{
		std::cout << std::string(getTabs(), '\t') << "Row";
		Composite::traverse();
	}
};

class Column : public Composite
{
public:
	Column(int val) : Composite(val) {}

	void traverse()
	{
		std::cout << std::string(getTabs(), '\t') << "Col";
		Composite::traverse();
	}
};

void testComposite();

#endif /* __COMPOSITE_H__ */