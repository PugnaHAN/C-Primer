#include "Singleton.h"

#include <iostream>

using namespace std;

Singleton* Singleton::_instance = nullptr;

Singleton::Singleton()
{
	cout << "Singleton()" << endl;
}

Singleton::~Singleton()
{
	cout << "~Singleton()" << endl;
}

Singleton* Singleton::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Singleton();
	}
	return _instance;
}