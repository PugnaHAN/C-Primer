// Factory 
#include "Factory.h"
#include "Product.h"

// AbstractFactory 
#include "AbstractFactory.h"
#include "AbstractProduct.h"

// Singleton
#include "Singleton.h"

// Builder
#include "Client.h"

// Prototype
#include "Prototype.h"

#include <iostream>

using namespace std;

void Pattern(const char* pattern) 
{
	string ptn(pattern);
	auto l = (60 - ptn.size()) >> 1;
	cout << string(l, '-') << ptn << string(l, '-');
	if (ptn.size())
		cout << '-';
	cout << endl;
}

int main(int argc, char* argv[])
{
	// Factory 
	Pattern("Factory");
	Factory* fac = new ConcreteFactory();
	Product* pro = fac->CreateProduct();

	delete fac;
	delete pro;
	fac = nullptr;
	pro = nullptr;

	// Abstract Factory
	Pattern("Abstract Factory");
	AbstractFactory* af1 = new ConcreteFactory1();
	af1->CreateProductA();
	af1->CreateProductB();

	AbstractFactory* af2 = new ConcreteFactory2();
	af2->CreateProductA();
	af2->CreateProductB();

	delete af1;
	delete af2;
	af1 = nullptr;
	af2 = nullptr;

	// Singleton
	Pattern("Singleton");
	Singleton* sgt = Singleton::getInstance();
	delete sgt;
	sgt = nullptr;

	// Builder
	Pattern("Builder");
	Client c;
	c.process();
	Room* r = new Room();
	cout << "Room's window: " << r->getWindow().getName() << "\n"
		<< "\t" << "floor: " << r->getFloor().getName() << endl;
	delete r;
	r = nullptr;

	// Prototype
	Pattern("Prototype");
	Prototype* proto = new ConcretePrototype();
	Prototype* proto_copy = proto->Clone();
	delete proto_copy;
	delete proto;
	proto_copy = nullptr;
	proto = nullptr;

	return 0;
}