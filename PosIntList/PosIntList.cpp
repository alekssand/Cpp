//Written by Aleksander Sandström

#include "PosIntList.h"

PosIntList::PosIntList()
{
	this->first = nullptr;
	this->nrOfNodes = 0;
}

PosIntList::~PosIntList()
{
	Node *walker = this->first;

	while (walker != nullptr) 
	{
		Node* next = walker->next;
		delete walker;
		walker = next;
	}

	this->first = nullptr;
}

PosIntList::PosIntList(const PosIntList& list)
{
	this->nrOfNodes = list.nrOfNodes;
	this->first = nullptr; 

	if (list.first != nullptr)
	{
		this->first = new Node(list.first->value);
		Node * walker = first;
		Node *listWalker = list.first; 

		while (listWalker->next!=nullptr)
		{
			walker->next = new Node(listWalker->next->value);
			walker = walker->next; 
			listWalker = listWalker->next;
		}
		walker->next = nullptr; 
	}

}

PosIntList& PosIntList::operator=(const PosIntList& list)
{

	Node *delWalker = this->first;

	while (delWalker != nullptr)
	{
		Node* next = delWalker->next;
		delete delWalker;
		delWalker = next;
	}

	this->first = nullptr;

	this->nrOfNodes = list.nrOfNodes;
	if (list.first != nullptr)
	{

		this->first = new Node(list.first->value);
		Node * walker = first;
		Node *listWalker = list.first;

		while (listWalker->next != nullptr)
		{
			walker->next = new Node(listWalker->next->value);
			walker = walker->next;
			listWalker = listWalker->next;
		}
		walker->next = nullptr;

		return *this;
	}
}
void PosIntList::insertFirst(int value)
{
	Node *e = new Node(value);
	e->next = this->first;
	this->first = e;
	this->nrOfNodes++;
}

void PosIntList::insertLast(int value)
{
	if (this->first == nullptr)
	{
		this->insertFirst(value);
	}

	else
	{
		Node *walker = this->first;

		while (walker->next != nullptr)
		{
			walker = walker->next;
		}

		Node *e = new Node(value);
		walker->next = e;
		this->nrOfNodes++;
	}
}

void PosIntList::insertAt(int pos, int value)
{
	if (pos>this->nrOfNodes || pos<0)
	{
		throw "Position not allowed!";
	}

	if (pos == 0)
	{
		this->insertFirst(value);
	}
	else
	{
		Node *walker = this->first;

		for (int i = 0; i < pos - 1; i++)
		{
			walker = walker->next;
		}
		Node *e = new Node(value);

		e->next = walker->next;
		walker->next = e;
		this->nrOfNodes++;
	}
}

int PosIntList::elementAt(int pos) const
{
	
	if (this->first == nullptr)
	{
		throw "The list is empty!";
	}

	if (pos > this->nrOfNodes-1 || pos < 0)
	{
		throw "Object does not exist!";
	}
	
	Node *walker = this->first;

	for (int i = 0; i < pos; i++)
	{
		walker = walker->next;
	}

	return walker->value;
}

int PosIntList::removeFirst()
{
	int result = -1;

	if (this->first == nullptr)
	{
		throw "The list is empty!";
	}

	Node *walker = this->first;
	this->first = walker->next;
	result = walker->value;
	delete walker;
	this->nrOfNodes--;

	return result;
}

int PosIntList::removeLast()
{
	int result = -1;

	if (this->first == nullptr)
	{
		throw "The list is empty!";
	}

	Node *walker = this->first;
	if (walker->next == nullptr)
	{
		this->removeFirst();
	}
	else
	{
		while (walker->next->next != nullptr)
		{
			walker = walker->next;
		}
		result = walker->next->value;
		delete walker->next;
		walker->next = nullptr;
	}
	return result;
}

int PosIntList::removeAt(int pos)
{
	int result = -1;

	if (this->first == nullptr)
	{
		throw"The list is empty!"; 
	}
	if (pos >= this->nrOfNodes)
	{
		throw "The object does not exist!";
	}
	if (pos == 0)
	{
		this->removeFirst(); 
	}
	if (pos == this->nrOfNodes--)
	{
		this->removeLast(); 
	}

	Node *walker = this->first; 
	
	Node *walker2 = this->first; 

	for (int i = 0; i < pos; i++) //pos för 0123, pos-- för 123
	{
		walker2 = walker; 
		walker = walker->next;
	}
	walker2->next = walker->next; 
	delete walker; 
	return result; 
}
