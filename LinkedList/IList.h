#ifndef ILIST_H
#define ILIST_H
#include <cstdlib>

using namespace std;

template <typename T>
class IList
{
public:
	virtual ~IList() = 0 {};
	virtual void insertAt(int pos, T element) = 0;
	virtual T elementAt(int pos) const  = 0;
	virtual T removeAt(int pos) = 0;
	virtual int size() const = 0;
};

#endif