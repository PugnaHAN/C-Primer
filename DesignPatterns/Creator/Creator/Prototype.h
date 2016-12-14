#pragma once
#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

class Prototype
{
public:
	virtual ~Prototype() = 0;
	virtual Prototype* Clone() const = 0;

protected:
	Prototype() = default;
};

class ConcretePrototype : public Prototype
{
public:
	ConcretePrototype();
	ConcretePrototype(const ConcretePrototype& cp);
	~ConcretePrototype();

	Prototype* Clone() const;
};

#endif /* __PROTOTYPE_H__ */