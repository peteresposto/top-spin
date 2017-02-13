#pragma once
#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H
#include <iostream>
#include <assert.h>

template <class T>
class CDLinkedList   //circular doubly linked 
{
public:
	class Node
	{ // doubly-linked nodes
	public:
		Node(T val, Node * nx = nullptr) : value(val), next(nx) { }
		T  value;
		Node * next;
		Node * previous;
	};
	
	CDLinkedList();
	CDLinkedList(const CDLinkedList &other);
	~CDLinkedList(); 
	bool isEmpty() const;
	void addHead(T item);
	unsigned int getSize();
	void addTail(T item);
	void insert(unsigned int pos, T item);
	T retrieve(unsigned int n) const;
	T replace(unsigned int pos, T item);
	T remove(unsigned int pos);
	T operator[](int i);
	T getHead();
	T getTail();

	//Iterator class
	class Iterator 
	{
	private:
		Node* i_ptr;    // an iterator hides a pointer to node
	public:
		Iterator()
		{
			i_ptr = nullptr;
		}
		Iterator(Node* ptr)
		{
			i_ptr = ptr;
		}
		void operator++(int) // for forward traversing, e,g, Iterator i=begin(); ... ++i;
		{
			i_ptr = i_ptr->next;
		}
		void operator--(int)
		{
			i_ptr = i_ptr->previous;
		}
		bool operator != (const Iterator& b)
		{
			return i_ptr != b.i_ptr;
		}
		T operator *()
		{
			return i_ptr->value;
		}
		T getValue()
		{
			return i_ptr->value;
		}
		void setValue(T val)
		{
			i_ptr->value = val;
		}
	};

	Iterator begin() 
	{ 
		return Iterator(head);
	}
	Iterator end() 
	{ 
		return Iterator(tail);
	}

	//Since we are using an iterator we can make our nodes private
public:
	Node *head;
	Node *tail;
	Node *checker;
	unsigned int size;
};

#endif
#include "CircularDoublyLinkedList.cpp"