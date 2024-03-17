#include <iostream>
#include <cstdlib>

void operator delete[](void* p)
{
	if (p) {
		free(p);
	}
}

template <class T>

void delete(T* p, std::size_t size)
{
	if(p) {
		for (std::size_t i = size - 1; i != -1; --i) {
			T::~T(p + i);
		}
		::operator delete[];
	}
}

