#pragma once
#ifndef __PROXY_H__
#define __PROXY_H__

#include "common.h"

class Person
{
public:
	Person() { name = nameList[next++]; }
	const std::string getName() const { return name; }
private:
	std::string name;
	static std::string nameList[];
	static int next;
};

class PettyCashProtected
{
public:
	PettyCashProtected():balance(500) {}

	bool withdraw(int amount) 
	{
		if (amount > balance)
			return false;
		balance -= amount;
		return true;
	}
	const int getBalance() const { return balance; }

private:
	int balance;
};

class PettyCash
{
public:
	bool withdraw(Person& p, int amount);
	const int getBalance() const { return realThing.getBalance(); }
private:
	PettyCashProtected realThing;
};

void testProxy();

#endif /* __PROXY_H__ */