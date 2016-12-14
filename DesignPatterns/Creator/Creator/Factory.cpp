#include "Factory.h"
#include "Product.h"

#include <iostream>

using namespace std;

Factory::Factory() 
{
}

Factory::~Factory()
{
}

ConcreteFactory::ConcreteFactory()
{
	cout << "ConcreteFactory()" << endl;
}

ConcreteFactory::~ConcreteFactory()
{
	cout << "~ConcreteFactory()" << endl;
}

Product* ConcreteFactory::CreateProduct()
{
	return new ConcreteProduct();
}