#pragma once
#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "common.h"

class Person;

class Command
{
public:
	Command(Person* per = nullptr, void(Person::*m)() = 0)
		: person(per), method(m) {}

	void execute() { (person->*method)(); }
private:
	Person *person;
	void(Person::*method)();
};

class Person
{
public:
	Person(const std::string &n, const Command c) :
		name(n), cmd(c) {}

	void talk() { std::cout << name << " is talking" << std::endl; cmd.execute(); }
	void passOn() { std::cout << name << " is passing on" << std::endl; cmd.execute(); }
	void gossip() { std::cout << name << " is gossiping" << std::endl; cmd.execute(); }
	void listen() { std::cout << name << " is listening" << std::endl; }
private:
	std::string name;
	Command cmd;
};

void testCommand();

#endif /* __COMMAND_H__ */