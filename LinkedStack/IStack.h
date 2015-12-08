//Aleksander Sandström Toimi

#ifndef ISTACK_H
#define ISTACK_H
#include <iostream>

template <typename T>
class IStack
{
public: 
	virtual ~IStack() = 0 {};
	virtual void push(T) = 0;
	virtual T pop() = 0;
	virtual int size() = 0; 
	virtual T peak() = 0; 
};
#endif