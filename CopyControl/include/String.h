#ifndef __STRING_H__
#define __STRING_H__

#include "common.h"

class String
{
	friend std::ostream& operator<<(std::ostream& os, const String& str);
  public:
	typedef unsigned int size_type;
	String();
	String(const char*);
	String(const String&);
	~String();
	String& operator=(const String&);
	String& operator+(const String&);

	char* begin() const {return start;}
	char* end() const {return end_point;}

	size_type size() const {return len;}

  private:
	static std::allocator<char> alloc;
	size_type len = 0;

	unsigned int *use = 0;

	char* start;
	char* end_point;

	void free();
	size_type strlen(const char*);
};

std::ostream& operator<<(std::ostream&, const String&);

#endif /* __STRING_H__ */
