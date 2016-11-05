#include "String.h"

using namespace std;

allocator<char> String::alloc;

String::size_type String::strlen(const char* str)
{
	int length = 0;
	while(*(str + length) != '\0')
		++length;
	return length;
}

void String::free()
{
	if(use)
	{
		--*use;
		if(*use == 0)
		{
			for(auto i = start; i != end_point; ++i)
			{
			
				alloc.destroy(i);
			}
		
		
			alloc.destroy(end_point);
			len = 0;
		
			delete use;
			use = nullptr;
		}
	}	
}

String::String()
{
	start = alloc.allocate(1);
	end_point = start;
	*start = '\0';
	use = new size_type(1);
	len = 0;
}

String::String(const char* str)
{
	use = new size_type(1);
	len = strlen(str);	

	start = alloc.allocate(len + 1);
	for(auto i = 0; i <= len; i++)
		*(start + i) = *(str + i);
	end_point = start + len + 1;
	*end_point = '\0';
	cout << "copy " << *use << endl;
}

String::String(const String& str) : start(str.start),
									end_point(str.end_point),
									use(str.use),
									len(str.len)
{
	++*use;
	cout << "copy constructor " << *use << endl;
}

String::String(String&& str): start(str.start), 
							  end_point(str.end_point),
							  use(str.use),
							  len(str.len)
{
	++*use;
	cout << "copy constructor right " << *use << endl;
// 	str.use = nullptr;
// 	str.start = str.end_point = nullptr;
// 	str.len = 0;
}


String& String::operator=(const String& str)
{	
	++*str.use;
	if(--*use == 0)
	{
		delete use;
		for(auto i = start; i != end_point; ++i)
			delete i;
	}
	start = str.start;
	end_point = str.end_point;
	use = str.use;
	++*use;
	cout << "copy " << *use << endl;
	return *this;
}

String& String::operator=(String&& str)
{	
	++*str.use;
	if(--*use == 0)
	{
		delete use;
		for(auto i = start; i != end_point; ++i)
			delete i;
	}
	start = str.start;
	end_point = str.end_point;
	use = str.use;
	++*use;
	cout << "copy right " << *use << endl;
	// str.use = nullptr;
	// str.start = str.end_point = nullptr;
	// str.len = 0;
	return *this;
}

String& String::operator+(const String& str)
{
	char* start_point = alloc.allocate(len + str.len + 1);
	char* temp = start_point;

	for(auto i = 0; i < len + str.len + 1; i++)
	{
		if(i < len)
		{
			*temp++ = *(start + i);
			alloc.destroy(start + i);
		}
		else
			*temp++ = *(str.start + i - len);

	}

	start = start_point;
	len += str.len;
	end_point = start + len + 1;	
	*end_point = '\0';
	
	return *this;
}

String::~String()
{
	cout << "free the string" << endl;
	free();
}

ostream& operator<<(ostream& os, const String& str)
{
	for(auto i = str.start; i != str.end_point; ++i)
		os << *i;
	return os;
}
