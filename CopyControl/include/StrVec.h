#ifndef __STRVEC_H__
#define __STRVEC_H__

#include "common.h"

class StrVec
{
  public:
	StrVec():elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(std::initializer_list<std::string> l);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();

	void push_back(const std::string&);
	size_t size() const {return first_free - elements;}
	size_t capacity() const {return cap - elements;}
	size_t reallocate() const {return cap - first_free;} 

	std::string* begin() const {return elements;}
	std::string* end() const {return first_free;}

  private:
	static std::allocator<std::string> alloc;
	void chk_n_alloc() {if(size() == capacity()) reallocate();}
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*,
													   const std::string*);
	void free();
	void reallocate();

	std::string *elements;
	std::string *first_free;
	std::string *cap;
};

#endif /* __STRVEC_H__ */
