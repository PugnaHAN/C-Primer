#pragma once
#ifndef __ABSTRACTPRODUCT_H__
#define __ABSTRACTPRODUCT_H__

class AbstractProductA
{
public:
	virtual ~AbstractProductA() = 0;

protected:
	AbstractProductA();
};

class AbstractProductB
{
public:
	virtual ~AbstractProductB() = 0;

protected:
	AbstractProductB();
};

class ProductA1 : public AbstractProductA
{
public:
	ProductA1();
	~ProductA1();
};

class ProductA2 : public AbstractProductA
{
public:
	ProductA2();
	~ProductA2();
};

class ProductB1 : public AbstractProductB
{
public:
	ProductB1();
	~ProductB1();
};

class ProductB2 : public AbstractProductB
{
public:
	ProductB2();
	~ProductB2();
};

#endif /* __ABSTRACTPRODUCT_H__ */