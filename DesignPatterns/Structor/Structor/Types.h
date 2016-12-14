#pragma once
#ifndef __TYPES_H__
#define __TYPES_H__

#include <iostream>

class Fea
{
public:
	Fea() = default;
	~Fea() { std::cout << "~Fea()" << std::endl; }
	void doThis() { std::cout << "Fea::doThis()" << std::endl; }
};

class Feye
{
public:
	Feye() = default;
	~Feye() { std::cout << "~Feye()" << std::endl; }
	void doThat() { std::cout << "Feye::doThat()" << std::endl; }
};

class Pheau
{
public:
	Pheau() = default;
	~Pheau() { std::cout << "~Pheau()" << std::endl; }
	void doTheOther() { std::cout << "Pheau::doTheOhter()" << std::endl; }
};

#endif /* __TYPES_H__ */