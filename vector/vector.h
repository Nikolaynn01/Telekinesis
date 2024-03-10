#ifndef VECTOR_H
#define VECTOR_H


#include <iostream>
#include <cstddef>
#include <initializer_list>

template <typename T>

class vector {
	private :
		size_t v_size;
		size_t v_capacity;
		T* arr;

		void recap() 
		{
			if (v_size == v_capacity) {
				v_capacity *= 2;

			}
			value_type* tmp = new value_type[v_capacity];
			for (size_type i = 0; i < v_size; ++i) {
				tmp[i] = arr[i];
			}
			delete [] arr;
			arr = tmp;
		}

	public:

		//member type-names

		using value_type = T;
		using size_type = size_t;
		using referance = value_type&;
		using const_referance = const value_type;
		using pointer = value_type*;
		using const_pointer = const value_type*;


		//constructors/destructor

		vector(std::initializer_list<value_type>);
		vector(size_type size);
		vector(size_type size, const_referance val);
		vector(const vector& rhv);
		vector();
		~vector();

		//member functions

		const vector& operator=(const vector& rvh);
		referance at (value_type index) const;
		referance front() const;
		referance back() const;
		size_type size() const;
		size_type capacity() const;
		void clear();
		void pushback(value_type val);
		void pop_back();
};

#include "vector.hpp"

#endif 




