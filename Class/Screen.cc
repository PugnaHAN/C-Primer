#include "Screen.h"

using namespace std;

inline char Screen::get(pos r, pos c) const
{
	return contents[r * width + c];
}

inline Screen& Screen::move(pos r, pos c)
{
	cursor = r * width + c;
	return *this;
}

void Screen::some_member() const
{
	++access_ctr;
}

inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}


inline Screen& Screen::set(pos r, pos c, char ch)
{
	contents[r * width + c] = ch;
	return *this;
}
