#pragma once
#ifndef __DECORATOR_H__
#define __DECORATOR_H__

#include "common.h"

class Interface
{
public:
	virtual ~Interface() = default;
	virtual void write(std::string&) = 0;
	virtual void read(std::string&) = 0;
};

class Core : public Interface
{
public:
	~Core() { std::cout << "~Core()" << std::endl; }
	
	void write(std::string& b) { b += "Message"; }
	void read(std::string& b) { std::cout << "Core(): Message" << std::endl; }
};

class Decorator : public Interface
{
public:
	Decorator(Interface* c) : inner(c) {}
	~Decorator() { delete inner; }
	
	void write(std::string& b) { inner->write(b); }
	void read(std::string& b) { inner->read(b); }
private:
	Interface* inner;
};

class Wrapper : public Decorator
{
public:
	Wrapper(Interface* c, std::string str) :Decorator(c),
		forward(str)
	{
		for (auto it = str.rbegin(); it != str.rend(); ++it)
			backward += *it;
	}
	~Wrapper() { std::cout << "~Wrapper()" << std::endl; }

	void write(std::string& b) { b = forward + "]" + b; Decorator::write(b); b += "[" + backward; }
	void read(std::string& b) { std::cout << "Wapper(): " << forward << std::endl; Decorator::read(b); std::cout << "Wrapper(): " << backward << std::endl; }
private:
	std::string forward, backward;
};

void testDecorator();

#endif /* __DECORATOR_H__ */