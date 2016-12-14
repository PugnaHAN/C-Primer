#pragma once
#ifndef __FACTORY_H__
#define __FACTORY_H__

class Product;

class Factory
{
public:
	virtual ~Factory() = 0;
	virtual Product* CreateProduct() = 0;

protected:
	Factory();
};

class ConcreteFactory : public Factory
{
public:
	~ConcreteFactory();
	ConcreteFactory();
	Product* CreateProduct();

protected:
private:
};

#endif /* __FACTORY_H__ */