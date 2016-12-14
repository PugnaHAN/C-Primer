#pragma once
#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__

#include "common.h"

class Beverage
{
public:
	void boilWater() { std::cout << "Boil water..." << std::endl; }
	virtual void brew() = 0;
	void pourInCup() { std::cout << "Pour into cup..." << std::endl; }
	virtual void addCoundiments() = 0;

	void create() 
	{
		boilWater();
		brew();
		pourInCup();
		addCoundiments();
	}
};

class Coffee : public Beverage
{
public:
	void brew() { std::cout << "Brew coffee..." << std::endl; }
	void addCoundiments() { std::cout << "Add suger and milk..." << std::endl; }
};

class Tea : public Beverage
{
public:
	void brew() { std::cout << "Brew tea..." << std::endl; }
	void addCoundiments() { std::cout << "Add honey and milk..." << std::endl; }
};

void testTemplate()
{
	Beverage* coffee = new Coffee();
	Beverage* tea = new Tea();

	coffee->create();
	tea->create();

	delete coffee;
	delete tea;
	coffee = nullptr;
	tea = nullptr;
}

#endif /* __TEMPLATE_H__ */