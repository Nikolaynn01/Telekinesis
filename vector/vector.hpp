#ifndef VECTOR_H
#define VECTOR_H

#include "vector.h"

// constructors & destructor implemetacion
template <class T>
vector<T>::vector(size_type size) 
	: v_size{size}
	, v_capacity{size} 
	, arr{new value_type[size]} {}

template <class T>
vector<T>::vector(size_type size, const_referance val)
	: v_size{size}
	, v_capacity{size}
	, arr{new value_type[size]}
{

	for (size_type i = 0; i < size; ++i) {
		arr[i] = val;
	}
}

template <class T>
vector<T>::vector(const vector& rvh) 
	: v_size{rvh.v_size}
	, v_capacity{rvh.v_capacity}
	, arr{new value_type[rvh.v_capacity]}
{
	for (size_type i = 0; i < rvh.size; ++i) {
		arr[i] = rvh.arr[i];
	}
}

template <class T>
vector<T>::vector()
{
	this -> v_size = 0;
	this -> v_capacity = 0;
	this -> arr = nullptr;
}
template <class T>
vector<T>::~vector()
{
	clear();
}


// member functions implementation


template <typename T>

vector<T>::const vector& operator=(const vector& rvh)
{
	if (this != &rvh) {

		delete [] this -> arr;

		this -> v_size = rvh.v_size;
		this -> v_capacity = rvh.v_capacity;
		this -> arr = new value_type[rvh.v_capacity];

		for (size_type i = 0; i < rvh.v_size; ++i) {
			this -> arr[i] = rvh.arr[i];
		}
	}
	return *this;
}

template <typename T>

vector <T>::referance
	vector<T>::at(size_type index) const
{
	if (index < 0 || index > v_size) {
		throw std::invalid_argument("error");
	}
	return this -> arr[index];
}

template <typename T>

vector<T>::referance
	vector<T>::front() const
{
	return this -> arr[0];
}

template <typename T>

vector<T>::referance
	vector<T>::back() const
{
	return this -> arr[v_size - 1];
}

template <typename T>

vector<T>::size_type
	vector<T>::size() const
{
	return this -> v_size;
}

template <typename T>

vector<T>::size_type
	vector<T>::capacity()
{
	return this -> v_capacity;
}

template <typename T>

void vector<T>::clear()
{
	this -> v_size = 0;
	this -> v_capacity = 0;
	delete [] this -> arr;
	this -> arr = nullptr;
}

template <typename T>

void vector<T>::push_back(value_type val)
{
	recap();
	this -> arr[v_size] = val;
	++(this -> v_size);
}

template <typename T>

void vector<T>::pop_back()
{
	if (v_size != 0) 
		--v_size;
}

#endif


