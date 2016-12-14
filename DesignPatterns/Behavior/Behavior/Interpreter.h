#pragma once
#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__

#include "common.h"

class Thousand;
class Hundred;
class Ten;
class One;

class RNInterpreter
{
public:
	RNInterpreter();
	RNInterpreter(int) {}

	int interpret(char*);
	virtual void interpret(char* input, int &total);
protected:
	// cannot be pure virtual because client asks for instance
	virtual char one() { return ' '; }
	virtual char *four() { return " "; }
	virtual char five() { return ' '; }
	virtual char *nine() { return " "; }
	virtual int multiplier() { return 0; }

private:
	RNInterpreter* thousands;
	RNInterpreter* hundreds;
	RNInterpreter* tens;
	RNInterpreter* ones;
};


class Thousand : public RNInterpreter
{
public:
	// provide 1-arg ctor to avoid infinite loop in base class ctor
	Thousand(int) : RNInterpreter(1) {}
protected:
	char one()
	{
		return 'M';
	}
	char *four()
	{
		return "";
	}
	char five()
	{
		return '\0';
	}
	char *nine()
	{
		return "";
	}
	int multiplier()
	{
		return 1000;
	}
};

class Hundred : public RNInterpreter
{
public:
	Hundred(int) : RNInterpreter(1) {}
protected:
	char one()
	{
		return 'C';
	}
	char *four()
	{
		return "CD";
	}
	char five()
	{
		return 'D';
	}
	char *nine()
	{
		return "CM";
	}
	int multiplier()
	{
		return 100;
	}
};

class Ten : public RNInterpreter
{
public:
	Ten(int) : RNInterpreter(1) {}
protected:
	char one()
	{
		return 'X';
	}
	char *four()
	{
		return "XL";
	}
	char five()
	{
		return 'L';
	}
	char *nine()
	{
		return "XC";
	}
	int multiplier()
	{
		return 10;
	}
};

class One : public RNInterpreter
{
public:
	One(int) : RNInterpreter(1) {}
protected:
	char one()
	{
		return 'I';
	}
	char *four()
	{
		return "IV";
	}
	char five()
	{
		return 'V';
	}
	char *nine()
	{
		return "IX";
	}
	int multiplier()
	{
		return 1;
	}
};

void testInterpreter();

#endif /* __INTERPRETER_H__ */