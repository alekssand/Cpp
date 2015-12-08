//Aleksander Sandström Toimi


#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "IStack.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

template<typename T>
class LinkedStack :public IStack<T>
{
private: 
	class Node
	{
	public: 
		T element; 
		Node *next;
		Node(T element){ this->element = element; this->next = nullptr; };
		~Node() { };
	};
	Node *first; 
	int nrOfNodes; 

public: 
	LinkedStack();
	LinkedStack(const LinkedStack<T> & origStack);
	
	LinkedStack<T> operator=(const LinkedStack<T> &origStack);
	virtual ~LinkedStack();
	void push(T element) ;
	T pop() ;
	int size();
	T peak() ;

};

template<typename T>
LinkedStack<T>::LinkedStack()
{
	this->first = nullptr; 
}

template<typename T>
LinkedStack<T>::~LinkedStack()
{
	for (int i = 0; i < this->nrOfNodes; i++)
	{
		this->pop();
	}
}

template<typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T> &origStack)
{
	this->nrOfNodes = origStack->nrOfNodes;
	this->first = nullptr;

	if (origStack->first != nullptr)
	{
		this->first = new Node(origStack->first->element);
		Node * walker = this->first; 
		Node *stackWalker = origStack->first; 
		while (stackWalker->next != nullptr)
		{
			stackWalker = stackwalker->next;
			walker->next = new Node(stackWalker->element);
			walker = walker->next
		}
		walker->next = nullptr;
	}
}



template<typename T>
void LinkedStack<T>::push(T element)
{
	Node *e = new Node(element);
	e->next = this->first; 
	this->first = e;
	this->nrOfNodes++; 
}

template<typename T>
T LinkedStack<T>::pop()
{
	if (this->first == nullptr)
	{
		throw "Stack is empty!";
	}

	T removed; 
	Node *toBeRemoved = this->first;
	this->first = this->first->next; 
	removed = toBeRemoved->element;
	delete toBeRemoved;
	this->nrOfNodes--;
	return removed; 
}
template<typename T>
int LinkedStack<T>::size()
{
	return this->nrOfNodes;
}

template<typename T>
T LinkedStack<T>::peak()
{
	if (this->first == nullptr)
	{
		throw "Stack is empty!";
	}
	return this->first->element;
}

template<typename T>
LinkedStack<T> LinkedStack<T>::operator=(const LinkedStack &origStack)
{
	if (this != &list)
	{
		for (int i = 0; i < this->nrOfNodes; i++)
		{
			this->pop();
		}

		this->first = nullptr;

		this->nrOfNodes = origStack->nrOfNodes;
		if (origStack.nrOfNodes != 0)
		{
			this->first = new Node(origStack->first->element);
			Node * walker = first;
			Node *listWalker = origStack->first;

			while (listWalker->next != nullptr)
			{
				walker->next = new Node(listWalker->next->value);
				walker = walker->next;
				listWalker = listWalker->next;
			}
			walker->next = nullptr;

		}
	}
	
	return *this;
}

#endif