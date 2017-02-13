#pragma once
#include "CircularDoublyLinkedList.h"
#include <iostream>
#ifndef CIRCULARDOUBLYLINKEDLIST_CPP
#define CIRCULARDOUBLYLINKEDLIST_CPP

//Default constructor 
template <class T>
CDLinkedList<T>::CDLinkedList()
{
	head = nullptr;
	tail = nullptr;
	checker = nullptr;
	size = 0;
}

//Destructor
template <class T>
CDLinkedList<T>::~CDLinkedList()
{
	Node * here = head, *nextNode;
	(*head).previous = nullptr;
	for (unsigned int i = 0; i != this->size; i++)
	{
		nextNode = here->next;
		delete here;
		here = nextNode;
	}
	this->head = nullptr;
	this->tail = nullptr;
	size = 0;
}

//Define addHead function
template <class T>
void CDLinkedList<T>::addHead(T item)
{
	//Adds a new node, defaults its item value to the value passed in and then sends in head and previous
	//so the constructor sets them appropriately
	head = new Node(item, head);
	if (tail == nullptr) tail = head;
	if (size == 1)
		head->previous = head;
	else
		head->previous = tail;
	size++;
}

//Define isEmpty function
template <class T>
bool CDLinkedList<T>::isEmpty() const
{
	return (size == 0);
}

//Define addTail function
template <class T>
void CDLinkedList<T>::addTail(T item)
{
	if (isEmpty()) addHead(item);
	else
	{
		Node * prevTemp = tail;
		tail->next = new Node(item);
		tail = tail->next;
		tail->previous = prevTemp;
		tail->next = head;
		head->previous = tail;
		size++;
		prevTemp = nullptr;
	}
}

//Extra functions to extend the versatility of the CDLinkedList
template <class T>
T CDLinkedList<T>::replace(unsigned int pos, T item)
{
	T value;
	Node *replacer = head;
	for (int i = 1; i < pos; i++)
	{
		replacer = replacer->next;
	}
	value = replacer->next.value;
	replacer->next.value = item;
	replacer = nullptr;
	return value;
}

template <class T>
void CDLinkedList<T>::insert(unsigned int pos, T item)
{
	if (pos == 1)
		addHead(item);
	else if (pos == (size + 1))
		addTail(item);
	else
	{
		//Create an intermediate node and set the element before pointing to it and have it point to the element after
		Node *inserter = head;
		for (int i = 1; i < (pos - 1); i++)
		{
			inserter = inserter->next;
		}
		inserter->next = new Node(item, inserter->next);
		newNode->previous = inserter;
		inserter = inserter->next;
		inserter->next->previous = inserter;
		size++;
	}
}

template <class T>
T CDLinkedList<T>::getHead()
{
	return head->value;
}

template <class T>
T CDLinkedList<T>::getTail()
{
	return tail->value;
}

template <class T>
unsigned int CDLinkedList<T>::getSize()
{
	return size;
}

template <class T>
T CDLinkedList<T>::remove(unsigned int pos)
{
	Node *remover = head;
	T value;
	for (int i = 1; i < pos; i++)
	{
		remover = remover->next;
	}
	value = remover->value;
	remover->previous->next = remover->next;
	remover = nullptr;
	return value;
}

//Define retrieve function
template <class T>
T CDLinkedList<T>::retrieve(unsigned int n) const
{
	Node * here = head;
	for (unsigned int k = 1; k < n; k++)
		here = here->next;
	return here->value;
}

//Copy constructor
template <class T>
CDLinkedList<T>::CDLinkedList(const CDLinkedList &other)
{
	if (other.size == 0) 
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	else 
	{
		size = other.size;
		head = new Node(other.head->value, nullptr);
		if (other.tail == nullptr) 
		{
			tail = head;
		}
		else {
			Node *copyFrom = other.head->next;
			Node *nextNode = head;

			while (copyFrom != nullptr) {
				nextNode->next = new Node(copyFrom->value);
				nextNode->previous = copyFrom->previous;
				copyFrom = copyFrom->next;
				nextNode = nextNode->next;
			}
			tail = nextNode;
		}
	}
}

template <class T>
T CDLinkedList<T>::operator[](int i)
{
	T * returnItemPointer = head;
	for (int j = 0; j < i; j++)
	{
		returnItemPointer = returnItemPointer.next;
	}
	return &returnItemPointer;
}

#endif
