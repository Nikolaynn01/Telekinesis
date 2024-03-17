#include <iostream>
#include <cstdlib>

void* operator new(std::size_t size)
{
	void* p = malloc(size);
	if (!p) {
		throw std::bad_alloc();
	}
	return p;
}

template <class T>

T* new(std::size_t size)
{
	void* p = ::operator new(size);
	T* p1 = stztic_cast<T*>(P);
	T::T(p1);
	return p1;
}


