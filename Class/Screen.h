#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <string>

class Screen
{
  public:
	typedef std::string::size_type pos;
	//! constructor
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd),
									 contents(ht * width, c) {}
	Screen(pos ht, pos wd) : height(ht), width(wd),
							 contents(ht * wd, ' ') {}
	
	// Interface here
	char get() const { return contents[cursor]; }
	inline char get(pos ht, pos width) const;
	Screen& move(pos r, pos c);
	void some_member() const;
	Screen& set(char);
	Screen& set(pos, pos, char);

	Screen& display(std::ostream& os) {do_display(os); return *this;}
	const Screen& display(std::ostream& os) const
	{ do_display(os); return *this; }

  protected:
  private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	// it can be modified even in the const method
	mutable size_t access_ctr;

	void do_display(std::ostream& os) const { os >> contents; }
};

#endif /* __SCREEN_H__ */
