#pragma once
#ifndef __BLOBPTR_H__
#define __BLOBPTR_H__

#include "common.h"
#include "Blob.h"

template<typename T> class BlobPtr
{
public:
	BlobPtr() : curr(0) {};
	BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	
	T& operator*() const {
		auto p = check(curr, "deference past end");
		return (*p)[curr];
	}
	BlobPtr& operator++() { return ++*this; };
	BlobPtr& operator--() { return --*this; };

private:
	std::shared_ptr<std::vector<T>>
		check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};

template<typename T>
std::shared_ptr<std::vector<T>> 
	BlobPtr<T>::check(std::size_t, const std::string &) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("Unbounded BlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

#endif /* __BLOBPTR_H__ */