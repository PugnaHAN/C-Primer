#pragma once
#ifndef __PRODUCT_H__
#define __PRODUCT_H__

class Product
{
public:
	virtual ~Product() = 0;
protected:
	// ÆÁ±Î¹¹Ôìº¯Êý
	Product();
private:
};

class ConcreteProduct : public Product
{
public:
	~ConcreteProduct();
	ConcreteProduct();

protected:
private:
};

#endif /* __PRODUCT_H__ */