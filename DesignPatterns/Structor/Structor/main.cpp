#include "common.h"
// Adapter
#include "Adapter.h"

// Bridge
#include "Bridge.h"

// Composite
#include "Composite.h"

// Decorator
#include "Decorator.h"

// Facade
#include "Facade.h"

// Flyweight
#include "Flyweight.h"

// Proxy
#include "Proxy.h"

using namespace std;

int main(int argc, char* argv[])
{
	// Adapter
	Pattern("Adapter");
	ExecuteInterface **objs = initialize();
	for (int i = 0; i < 3; ++i)
	{
		objs[i]->execute();
	}
	for (auto i = 0; i < 3; ++i)
	{
		delete objs[i];
	}
	delete objs;

	// Bridge
	Pattern("Bridge");
	showTime();

	// Composite
	Pattern("Composite");
	testComposite();

	// Decorator
	Pattern("Decorator");
	testDecorator();

	// Facade
	Pattern("Facade");
	testFacade();

	// Flyweight
	Pattern("Flyweight");
	testFlyweight();

	// Proxy
	Pattern("Proxy");
	testProxy();

	return 0;
}