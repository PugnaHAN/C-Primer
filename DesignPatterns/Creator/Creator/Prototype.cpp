#include "Prototype.h"

#include <iostream>

using namespace std;

Prototype::~Prototype()
{
	cout << "~Prototype()" << endl;
}

Prototype* Prototype::Clone() const
{
	return nullptr;
}

ConcretePrototype::ConcretePrototype()
{
	cout << "ConcretPrototype()" << endl;
}

ConcretePrototype::~ConcretePrototype()
{
	cout << "~ConcreteProtype()" << endl;
}

ConcretePrototype::ConcretePrototype(const ConcretePrototype& cp)
{
	cout << "ConcretPrototype(const ConcretPrototype&)" << endl;
}

Prototype* ConcretePrototype::Clone() const 
{
	return new ConcretePrototype(*this);
}