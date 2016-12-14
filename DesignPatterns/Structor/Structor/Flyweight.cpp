#include "Flyweight.h"

using namespace std;

Icon::Icon(const std::string& fileName): _name(fileName)
{
	map<string, function<void()>> nameMap;

	auto _go = [this]() {_width = _height = 20; };
	auto _stop = [this]() {_width = _height = 40; };
	auto _select = [this]() {_width = _height = 60; };
	auto _undo = [this]() {_width = _height = 30; };

	nameMap["go"] = _go;
	nameMap["stop"] = _stop;
	nameMap["select"] = _select;
	nameMap["undo"] = _undo;

	switchFunc(nameMap, fileName);
}

void Icon::draw(int x, int y)
{
	cout << "   drawing " << _name << ": upper left (" << x << "," << y <<
		") - lower right (" << x + _width << "," << y + _height << ")" <<
		endl;
}

int FlyweightFactory::_numIcons = 0;
Icon *FlyweightFactory::_icons[];

Icon* FlyweightFactory::getIcon(const std::string name) 
{
	for (auto icon : _icons)
		if (icon && icon->getName() == name)
			return icon;
	_icons[_numIcons] = new Icon(name);
	return _icons[_numIcons++];
}

void FlyweightFactory::reportTheIcons()
{
	cout << "Active Flyweight: ";
	for (auto _icon : _icons)
		if(_icon)
			cout << _icon->getName() << " ";
		
	cout << endl;
}

void FileSelection::draw()
{
	cout << "drawing FileSelection:" << endl;
	for (int i = 0; i < 3; i++)
		_icons[i]->draw(_iconsOriginX + (i *_iconsXIncrement), _iconsOriginY);
}

void CommitTransaction::draw()
{
	cout << "drawing CommitTransaction:" << endl;
	for (int i = 0; i < 3; i++)
		_icons[i]->draw(_iconsOriginX + (i *_iconsXIncrement), _iconsOriginY);
}

void testFlyweight()
{
	DialogBox *dialogs[2];
	dialogs[0] = new FileSelection(FlyweightFactory::getIcon("go"),
		FlyweightFactory::getIcon("stop"),
		FlyweightFactory::getIcon("select"));
	dialogs[1] = new CommitTransaction(FlyweightFactory::getIcon("select"),
		FlyweightFactory::getIcon("stop"),
		FlyweightFactory::getIcon("undo"));
	for (auto diag : dialogs)
		diag->draw();
	FlyweightFactory::reportTheIcons();
	for (auto diag : dialogs)
	{
		delete diag;
		diag = nullptr;
	}		
}