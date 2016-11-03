#ifndef __HASPTR_H__
#define __HASPTR_H__

#include "common.h"

class HasPtr
{
	friend void swap(HasPtr&, HasPtr&);
  public:
	HasPtr(const std::string &s = std::string());
	HasPtr(const HasPtr&);
	HasPtr& operator=(const HasPtr&);
	~HasPtr();

	bool operator<(const HasPtr&) const;
  private:
	std::string *ps;
	int i;
	std::size_t *use;
};

void swap(HasPtr&, HasPtr&);

#endif /* __HASPTR_H__ */
