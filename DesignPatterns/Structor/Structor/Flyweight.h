#pragma once
#ifndef __FLYWEIGHT_H__
#define __FLYWEIGHT_H__

#include "common.h"

class Icon
{
public:
	Icon(const std::string&);
	
	const std::string getName() const { return _name; }
	void draw(int x, int y);
private:
	std::string _name;
	int _width;
	int _height;
};

class FlyweightFactory
{
public:
	static Icon* getIcon(const std::string name);
	static void reportTheIcons();
private:
	enum { MAX_ICONS = 5 };
	static int _numIcons;
	static Icon* _icons[MAX_ICONS];
};

class DialogBox
{
public:
	DialogBox(int x, int y, int incr) : _iconsOriginX(x),
		_iconsOriginY(y), _iconsXIncrement(incr) {}
	virtual void draw() = 0;
protected:
	Icon* _icons[3];
	int _iconsOriginX;
	int _iconsOriginY;
	int _iconsXIncrement;
};

class FileSelection : public DialogBox
{
public:
	FileSelection(Icon *first, Icon *second, Icon *third): 
		DialogBox(100, 100, 100)
	{
		_icons[0] = first;
		_icons[1] = second;
		_icons[2] = third;
	};
	void draw();
};

class CommitTransaction : public DialogBox
{
public:
	CommitTransaction(Icon *first, Icon *second, Icon *third): 
		DialogBox(150, 150, 150)
	{
		_icons[0] = first;
		_icons[1] = second;
		_icons[2] = third;
	}
	void draw();
};

void testFlyweight();

#endif /* __FLYWEIGHT_H__ */
