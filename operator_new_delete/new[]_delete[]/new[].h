#include <iosteram>
#include <cstdlib>

void* operator new[](std::size_t size)
{
	void* p = malloc(size);
	if(!p) {
		throw std::bad_aloc();
	}
	return p;
}



template <class T>

T* new(T, std::size_t size)
{
	void* p = ::operator new[](size * sizeof(T));
	T* p1 = stztic_cast<T>(p);
	for (std::size_t i = 0; i < size; ++i) {
		T::T(p1 + i);
	}
	return p1;
}





