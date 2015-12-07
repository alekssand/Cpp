/*Written by Aleksander Sandström*/


#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H
#include "IPriorityQueue.h" 

template<typename T>
class PrioQueue:public IPriorityQueue<T>
{
private:
	class Node
	{
	public:
		T element;
		Node *next;
		Node(T element){ this->element = element; this->next = nullptr; };
		~Node() {};
	};

	int nrOfNodes;
	Node *first;

public:
	PrioQueue();
	~PrioQueue();
	PrioQueue(const PrioQueue& element);
	void enqueue(const T& element);
	T dequeue();
	T peek() const;
	int size() const;

};

template<typename T>
PrioQueue<T>::PrioQueue()
{
	this->nrOfNodes = 0;
	this->first = nullptr;

}
template <typename T>
PrioQueue<T>::~PrioQueue()
{
	Node *walker = this->first;

	while(walker != nullptr)
	{
		first = walker->next;
		delete walker;
		walker = first;
	}
	this->first = nullptr;
}

template<typename T>
PrioQueue<T>::PrioQueue(const PrioQueue& element)
{
	this->first = nullptr;
	this->nrOfNodes = element.nrOfNodes;
	if(element.first != nullptr)
	{
		Node * listWalker = element.first;
		this->first = new Node(listWalker->element);
		Node * tail = this->first;

		while(listWalker->next != nullptr)
		{
			listWalker = listWalker->next;
			tail->next = new Node(listWalker->element);
			tail = tail->next;
		}
	}
}

template<typename T>
void PrioQueue<T>::enqueue(const T& element)
{
	if(this->first == nullptr)
	{
		this->first = new Node(element);
		
	}
	else if(this->first->element < element)
	{
		Node *e = new Node(element);
		e->next = this->first; 
		this->first = e; 
	}
	else
	{
		bool keepGoing = true;
		Node * walker = this->first;
		while (walker->next != nullptr && keepGoing ==true)
		{
			if (walker->next->element < element)
			{
				Node * e = new Node(element);
				e->next = walker->next;
				walker->next = e; 
				keepGoing = false;
			}
			walker = walker->next;
		}
		
		if (walker->next == nullptr)
		{
			Node * e = new Node(element);
			walker->next = e;
		}
	}
	this->nrOfNodes++;
}


template<typename T>
T PrioQueue<T>::dequeue()
{
	if(this->first == nullptr)
	{
		throw "The queue is empty";
	}
	T result = this->first->element;
	Node * walker = this->first;
	this->first = walker->next; 
	delete walker;

	return result;
}

template<typename T>
T PrioQueue<T>::peek() const
{
	if(this->first == nullptr)
	{
		throw "the queue is empty!";
	}
	return this->first->element; 
}

template<typename T>
int PrioQueue<T>::size() const
{
	return this->nrOfNodes; 
}

#endif