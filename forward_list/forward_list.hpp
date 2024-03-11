#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include "forward_list.h"

//constructor - destructor implementation


template <class T>
forward_list<T>::Node::Node(const_referance data) 
	: data{data}
	, next {nullptr} {}

template <class T>
forward_list<T>::forward_list()
	: head{nullptr} {}

template <class T>
forward_list<T>::~forward_list() {
	while (head) {
		Node* temp = head;
		head = head -> next;
		delete temp;
	}
}

//member functions implementation


template <class T>
void forward_list<T>::push_front(const T& data)
{
	Node* newNode = new Node(data);
	newNode -> next = head;
	head = newNode;
}

template <class T>
void forward_list<T>::pop_front()
{
	if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
	}
}

template <class T>
const T& forward_list<T>::front() const
{
	if (!head) {
		throw std::out_of_range("List is empty");
	}
	return head->data;
}

template <class T>
bool forward_list<T>::empty() const
{
	return head == nullptr;
}

#endif




