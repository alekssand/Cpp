#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "IList.h"

template<typename T> 
class LinkedList : public IList<T>
{
private:
	class Node 
	{
	public: 
		T element; 
		Node *next;
		Node(T element){this->element=element; this->next = nullptr;}
		~Node(){};
	};

	Node *first; 
	int nrOfNodes; 

public:
	LinkedList();
	LinkedList(const LinkedList<T> &origList);
	LinkedList<T>& operator=(const LinkedList<T> &origObj);
	virtual ~LinkedList();

	void insertAt(int pos, T element);
	T elementAt(int pos) const;
	T removeAt(int pos);
	int size() const;
};

template<typename T>
LinkedList<T>::LinkedList()
{
	this->nrOfNodes =0;
	this->first = nullptr; 
}
template<typename T>
LinkedList<T>::~LinkedList()
{
	Node *walker = this->first; 
	
	while(walker!=nullptr)
	{
		first = walker->next; 
		delete walker; 
		walker = first; 
	}

	this->first = nullptr; 
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &origList)
{
	this->nrOfNodes= origList.nrOfNodes; 
	this->first = nullptr; 

	if (list.first != nullptr)
	{
		this->first = new Node(list.first->element);
		Node * walker = first;
		Node *listWalker = list.first; 

		while (listWalker->next!=nullptr)
		{
			walker->next = new Node(listWalker->next->element);
			walker = walker->next; 
			listWalker = listWalker->next;
		}
		walker->next = nullptr; 
	}
}

template<typename T> 
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &origObj)
{
	if(this!=&origObj)
	{
		Node *delWalker = first; 
	
		while(delWalker!=nullptr;)
		{
			first = delWalker->next; 
			delete delWalker; 
			delWalker = first; 
		}

		this->nrOfNodes= origList.nrOfNodes; 
		this->first = nullptr; 

		if (origObj.first != nullptr)
		{
			this->first = new Node(origObj.first->element);
			Node * walker = first;
			Node *listWalker = origObj.first;

			while (listWalker->next != nullptr)
			{
				walker->next = new Node(listWalker->next->element);
				walker = walker->next;
				listWalker = listWalker->next;
			}
			walker->next = nullptr;
		}
	}
	return *this; 
}

template<typename T>
void LinkedList<T>::insertAt(int pos, T element)
{
	if(pos> this->nrOfNodes)
	{
		throw "Invalid Position";  
	}
	
	
	if(pos !=0)
	{
		Node * walker = this->first; 

		for(int i =0; i < pos -1; i++)
		{
			walker = walker->next; 
		}

		Node *e = new Node(element); 
		e->next = walker->next;
		walker->next = e;
		this->nrOfNodes++;
	}
	else
	{
		Node *e = new Node(element);
		e->next = this->first;
		this->first = e;
		this->nrOfNodes++;
	}
}
template<typename T>
T LinkedList<T>::elementAt(int pos) const
{
	if(pos>this->nrOfNodes-1)
	{
		throw "Node does not exist!";
	}
	if(this->first == nullptr)
	{
		throw "Listan är tom"; 
	}

	Node *walker= this->first;

	for(int i =0; i < pos; i ++)
	{
		walker = walker->next;
	}

	return walker->element;   
}

template<typename T>
T LinkedList<T>::removeAt(int pos)
{

	if(pos> this->nrOfNodes)
	{
	 throw "Invalid position!";
	}
	if(this->first = nullptr)
	{
		throw "Listan är tom!";
	}

	Node *walker = this->first;
	Node *walker2 = this->first; 

	for (int i = 0; i < pos; i++)
	{
		walker2 = walker; 
		walker = walker->next;
	}

	walker2->next = walker->next; 
	T result = walker->element;

	delete walker; 
	return result; 
}

template<typename T>
int LinkedList<T>::size() const
{
	return this->nrOfNodes;
}


#endif