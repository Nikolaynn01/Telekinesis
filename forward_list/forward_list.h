#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <cstddef>

template <typename T>

class forward_list {
	public :
		//member type-names

		using value_type = T;
		using size_type = size_t;
		using referance = value_type&;
		using const_referance = const value_type&;
		using poiter = value_type*;
		using const_pointer = const value_type*;

	private :
		struct Node {
			value_type data;
			Node* next;

			//constructor for Node

			Node(const_referance data);
		};

		Node* head;

	public :
		//constructor-destructor for forward_list

		forward_list();
		~forward_list();

		//member functions
		
		void push_front(const_referance data);
		void pop_front();
		const_referance front();
		bool empty();

};

#include "forward_list.hpp"

#endif



