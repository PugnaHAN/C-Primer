#pragma once
#ifndef __SHARED_PTR_H__
#define __SHARED_PTR_H__

#include "common.h"
#include "DebugDelete.h"

namespace han 
{
	template<typename> class shared_ptr;
	template<typename T> void swap(shared_ptr<T>& lhs, shared_ptr<T>& rhs);

	template <typename Type> 
	class shared_ptr
	{
		friend void swap<Type>(shared_ptr<Type>& lhs, shared_ptr<Type>& rhs);
	public:	
		// Constructors
		shared_ptr() = default;
		shared_ptr(const Type& v);
		shared_ptr(Type* ptr);
		explicit shared_ptr(Type* ptr, std::function<void(Type *)> d = DebugDelete()) :
			pointer(ptr), ref_count(new std::size_t(1)), deleter(d) {}

		shared_ptr(const shared_ptr& sp) : pointer(sp.pointer),
			ref_count(sp.ref_count) {
			++*ref_count;
		}
		shared_ptr(const shared_ptr&& sp) noexcept;

		// Move constructor
		shared_ptr(shared_ptr&& sp) noexcept;

		// Operators
		shared_ptr& operator=(const shared_ptr& sp);
		// shared_ptr& operator=(shared_ptr&& sp);
		Type& operator*() const { return *(this->pointer); }
		Type* operator->() const { return pointer; }

		operator bool() const { return pointer ? true : false; }

		// Interfaces
		std::size_t count() const { return *ref_count; }
		void swap(shared_ptr& rhs) { ::swap(*this, rhs); }
		void reset() noexcept { decrement_n_desctroy(); }
		void reset(Type* p) {
			if (pointer != p) {
				decrement_n_descroy();
				pointer = p;
				ref_count = new std::size_t(1);
			}
		}
		void reset(Type* p, const std::function<void(Type*)> d) {
			reset(p);
			deleter = d;
		}

		~shared_ptr() { decrement_n_descroty(); }

	private:
		std::size_t* ref_count = new std::size_t(0);
		std::function<void(Type *)> deleter{ DebugDelete() };
		Type* pointer = nullptr;

		void decrement_n_descroty();
	};
}


template <typename Type>
void han::swap(han::shared_ptr<Type>& lhs,
	han::shared_ptr<Type>& rhs) {
	using std::swap;
	swap(lhs.pointer, rhs.pointer);
	swap(lhs.ref_count, rhs.ref_count);
	swap(lhs.deleter, rhs.deleter);
}

template <typename Type>
han::shared_ptr<Type>::shared_ptr(const Type& v) :
	pointer(new Type(v)), ref_count(new std::size_t(1)) { }

template <typename Type>
han::shared_ptr<Type>::shared_ptr(Type* ptr) :
	pointer(ptr), ref_count(new std::size_t(1)) {}

template <typename Type>
inline 
han::shared_ptr<Type>::shared_ptr(han::shared_ptr<Type>&& sp) noexcept :
	pointer(sp.pointer), ref_count(sp.ref_count), deleter(sp.deleter)
{
	sp.pointer = nullptr;
	sp.ref_count = nullptr;
}

template <typename Type>
han::shared_ptr<Type>& han::shared_ptr<Type>::operator=(
	const han::shared_ptr<Type>& rhs) {
	++*rhs.ref_count;
	decrement_n_descroty();
	pointer = rhs.pointer;
	ref_count = rhs.ref_count;
	deleter = rhs.deleter;

	return *this;
}

//template <typename Type>
//han::shared_ptr<Type>& han::shared_ptr<Type>::operator=(
//	han::shared_ptr<Type>&& rhs) noexcept {
//	decrement_n_descroty();
//	han::swap(*this, rhs);
//	std::cout << "han::shared_ptr::move\n";
//	return *this;
//}

template <typename Type>
void han::shared_ptr<Type>::decrement_n_descroty() {
	if (pointer) {
		if (--*ref_count == 0) {
			delete ref_count;
			deleter(pointer);
		}
		ref_count = nullptr;
		pointer = nullptr;
	}
}

#endif /* __SHARED_PTR_H__ */