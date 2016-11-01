#ifndef __STRBLOB_H__
#define __STRBLOB_H__

#include "common.h"

class StrBlobPtr;

class StrBlob
{
  public:
	friend class StrBlobPtr;
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const {return data->size();}
	bool empty() const {return data->empty();}
	void push_back(const std::string &t);
	void pop_back();

	std::string& front();
	std::string& back();
	const std::string& front() const;
	const std::string& back() const;

	StrBlobPtr begin();
	StrBlobPtr end();
  private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr
{
  public:
	StrBlobPtr():curr(0) {};
	StrBlobPtr(StrBlob& a, std::size_t sz = 0) : wptr(a.data), curr(sz) {};
	std::string& deref() const;
	StrBlobPtr& incr();
	std::size_t current() const {return curr;}
	
  private:
	std::shared_ptr<std::vector<std::string>> 
	check(std::size_t, const std::string&) const;

	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

#endif /* __STRBLOB_H__ */
