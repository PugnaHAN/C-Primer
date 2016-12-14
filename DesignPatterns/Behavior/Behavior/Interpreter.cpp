#include "Interpreter.h"
#include <string.h>

using namespace std;

RNInterpreter::RNInterpreter()
{
	// use 1-arg ctor to avoid infinite loop
	thousands = new Thousand(1);
	hundreds = new Hundred(1);
	tens = new Ten(1);
	ones = new One(1);
}

int RNInterpreter::interpret(char *input)
{
	int total;
	total = 0;
	thousands->interpret(input, total);
	hundreds->interpret(input, total);
	tens->interpret(input, total);
	ones->interpret(input, total);
	if (strcmp(input, ""))
		// if input was invalid, return 0
		return 0;
	return total;
}

void RNInterpreter::interpret(char* input, int &total)
{
	int index;
	index = 0;
	if (!strncmp(input, nine(), 2))
	{
		total += 9 * multiplier();
		index += 2;
	}
	else if(!strncmp(input, four(), 2))
	{
		total += 4 * multiplier();
		index += 2;
	}
	else
	{
		if (input[0] == five())
		{
			total += 5 * multiplier();
			index = 1;
		}
		else
			index = 0;
		for (int end = index + 3; index < end; ++index)
			if (input[index] == one())
				total += 1 * multiplier();
			else
				break;
	}
	strcpy_s(input, strlen(input) + strlen(&input[index]) ,&(input[index]));
}

void testInterpreter()
{
	RNInterpreter interpreter;
	char input[20];
	cout << "Enter Roman Numeral: ";
	while (cin >> input)
	{
		cout << "   interpretation is " << interpreter.interpret(input) << endl;
		cout << "Enter Roman Numeral: ";
	}
}