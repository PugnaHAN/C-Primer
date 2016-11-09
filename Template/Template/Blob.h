#pragma once
#ifndef __BLOB_H__
#define __BLOB_H__

#include "common.h"

template<typename T> class Blob
{
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	typedef typename std::vector<T>::iterator Iterator;

	Blob() = default;
	Blob(std::initializer_list<T> il);
	template <typename _Iterator> Blob(_Iterator b, _Iterator e);

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const T &t) { data->push_back(t); }
	void pop_back();

	T& back();
	T& operator[](size_type i);

	Iterator begin() { return data->begin(); }
	Iterator end() { return data->end(); }
	
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
};



template <typename T>
template <typename _Iterator>
Blob<T>::Blob(_Iterator b, _Iterator e) 
	: data(std::make_shared<std::vector<T>>(b, e))
{
}

template<typename T>
inline Blob<T>::Blob(std::initializer_list<T> il) 
	: data(std::make_shared<std::vector<T>>(il))
{
}

template<typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template<typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
void Blob<T>::pop_back()
{
	check(0, "pop back on empty Blob");
	data->pop_back();
}


template<typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

#endif /* __BLOB_H__ */