#include "common.h"
// Template
#include "Template.h"
// Responsibility of Chain
#include "RespChain.h"
// Command
#include "Command.h"
// Interpreter
#include "Interpreter.h"
// Iterator
#include "Iterator.h"

using namespace std;

int main(int argc, char* argv[])
{
	// Tempalte
	Pattern("Template");
	testTemplate();

	// Responsibility of Chian
	Pattern("Response Chain");
	testRespChain();

	// Command
	Pattern("Command");
	testCommand();

	// Interpreter
	Pattern("Interpreter");
	// testInterpreter();

	// Iterator
	Pattern("Iterator");
	testIterator();
}