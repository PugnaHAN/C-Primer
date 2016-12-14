#pragma once
#ifndef __ROOM_H__
#define __ROOM_H__

#include <string>
#include <iostream>

class Base
{
public:
	Base() = default;
	Base(const std::string& n) : name(n) {}
	~Base() { std::cout << "~Base()" << std::endl; }

	const std::string& getName() const { return name; }
	
protected:
	std::string name = "base";
};

class Window : public Base
{
public:
	Window() = default;
	Window(const std::string& n) : Base(n) {}
	~Window() { std::cout << "~Window()" << std::endl; }
};

class Floor :public Base
{
public:
	Floor() = default;
	Floor(const std::string& n) : Base(n) {}
	~Floor() { std::cout << "~Floor()" << std::endl; }
};

class Room
{
public:
	Room();
	~Room();

	Window getWindow() { return window; }
	void setWindow(const Window& w) { window = w; }
	Floor getFloor() { return floor; }
	void setFloor(const Floor& f) { floor = f; }

private:
	Window window;
	Floor floor;
};

#endif /* __ROOM_H__ */