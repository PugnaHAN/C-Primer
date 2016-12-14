#include "Decorator.h"

using namespace std;

void testDecorator()
{
	Interface *obj = new Wrapper(new Wrapper(new Wrapper(new Core(), "123"), "abc"), "987");
	string buf;
	obj->write(buf);
	cout << "main: " << buf << endl;
	obj->read(buf);
	delete obj;
	obj = nullptr;
}