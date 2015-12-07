/*Written by Aleksander Sandström*/

#ifndef IPRIORITYQUEUE_H
#define IPRIORITYQUEUE_H

template<typename T>
class IPriorityQueue
{
public: 
	virtual ~IPriorityQueue() {};
	virtual void enqueue(const T& element) = 0; 
	virtual T dequeue() = 0; 
	virtual T peek() const = 0; 
	virtual int size() const = 0; 
};
#endif