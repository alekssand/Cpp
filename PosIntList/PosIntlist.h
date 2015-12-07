#ifndef POSINTLIST_H
#define POSINTLIST_H
#include <cstdlib>
#include <iostream>

class PosIntList
{
private: 
	class Node
	{
	public: 
		int value; 
		Node *next; 
		Node(int value){ this->value; this->next = nullptr}
		~Node(){}
	};
public: 
	PosIntList(); 
	PosIntList(const PosIntList& list);
	virtual ~PosIntList();
	PosIntList& opeartor)=(const PosIntList& list);
	void insertLast(int value);
	void insertAt(int pos, int value);
	void insertFirst(int value); 
	int elementAt(int pos) const; 
	int removeFirst(); 
	int remiveLast(); 
	int removeAt(int pos);
	int size() const; 
};

#endif