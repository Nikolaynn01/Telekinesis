#include <iostream>
#include <cstdlib>

void operator delete(void* p)
{
	if (p) {
		free(p);
	}
}

template <class T>

void delete(T* p)
{
	if(p) {
		T::~T{p};
		::operator delete(p);
	}
}


