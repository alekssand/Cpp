#ifndef VECTOR_H
#define VECTOR_H
#include <cstdlib>

template<typename T>
class Vector
{
private:
	T *items;
	int nrOfItems;
	int capacity;
	int capacityIncrement;
	void expand();
public:
	Vector(int capacity = 10, int capacityIncrements = 10);
	virtual ~Vector();
	Vector(const Vector<T> &origObj);
	void operator=(const Vector<T> &origObj);
	Vector<T> operator+(const Vector<T> &addObj);
	T operator[](int index) throw(...);

	void addLast(T item);
	void addFirst(T item);
	void addAt(int index, T item) throw(...);
	T getFirst() const throw(...);
	T getLast() const throw(...);
	T getAt(int index) const throw(...);
	T removeFirst() throw(...);
	T removeLast() throw(...);
	T removeAt(int index) throw(...);
	void removeBetween(int start, int end) throw(...);
	int size()const;
	void clear();
	
};

//konstruktor
template<typename T>
Vector<T>::Vector(int capacity, int capacityIncrements)
{
	this->capacity = capacity;
	this->capacityIncrement = capacityIncrement;
	this->items = new T[this->capacity];
	this->nrOfItems = 0;
}

//destruktor
template<typename T>
Vector<T>::~Vector()
{
	delete[] this->items;
}

//Kopieringskonstruktorn 
template <typename T>
Vector<T>::Vector(const Vector<T> &origObj)
{
	this->capacity = origObj.capacity;
	this->capacityIncrement = origObj.capacityIncrement;
	this->nrOfItems = origObj.nrOfItems;
	this->items = new T[origObj.capacity];

	for (int i = 0; i<origObj.nrOfItems; i++)
	{
		this->items[i] = origObj.items[i];
	}
}

//Tilldelnignsoperatorn 
template <typename T>
void Vector<T>::operator=(const Vector<T> &origObj)
{
	if (this != &origObj)
	{

		delete[]this->items;
		this->capacity = origObj.capacity;
		this->capacityIncrement = origObj.capacityIncrement;
		this->nrOfItems = origObj.nrOfItems;
		this->items = new T[origObj.capacity];

		for (int i = 0; i < origObj.nrOfItems; i++)
		{
			this->items[i] = origObj.items[i];
		}
	}
}

//expandera
template <typename T>
void Vector<T>::expand()
{
	T *temp;

	this->capacity = capacity + 10;
	temp = new T[this->capacity];

	for (int i = 0; i<this->nrOfItems; i++)
	{
		temp[i] = this->items[i];
	}
	delete[]this->items;
	items = temp;
}

//l�gg till p� f�sta positionen
template <typename T>
void Vector<T>::addFirst(T item)
{
	if (this->capacity == this->nrOfItems)
	{
		this->expand();
	}

	this->items[++this->nrOfItems] = this->items[0];
	this->items[0] = item;
}

//l�gg till p� sista positionen
template <typename T>
void Vector<T>::addLast(T item)
{
	if (this->capacity == this->nrOfItems)
	{
		this->expand();
	}
	this->items[this->nrOfItems++] = item;
}

//l�gg till p� best�md position
template <typename T>
void Vector<T>::addAt(int index, T item)throw(...)
{
	if (index <0 || index >this->nrOfItems)
	{
		throw "Index not allowed!";
	}

	if (this->nrOfItems == this->capacity)
	{
		expand();
	}
	this->items[this->nrOfItems++] = this->items[index];
	this->items[index] = item;
}

//retunerar storleken
template <typename T>
int Vector<T>::size()const
{
	return this->nrOfItems;
}

//tar bort och ers�tter arrayen. 
template <typename T>
void Vector<T>::clear()
{
	delete[] this->items;
	this->capacity = this->capacityIncrement;
	this->nrOfItems = 0;
	this->items = new T[this->capacity];
}

//plusoperatorn
template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &addObj)
{
	Vector<T> temp;

	for (int i = 0; i<this->nrOfItems; i++)
	{
		temp.addLast(this->items[i]);
	}

	for (int i = 0; i<addObj.nrOfItems; i++)
	{
		temp.addLast(addObj.items[i]);
	}

	return temp;
}

//hakoperatorn 
template<typename T>
T Vector<T>::operator[](int index) throw(...)
{
	if (index < 0 || index > this->nrOfItems - 1)
	{
		throw "Index is not allowed!";
	}
	if (this->nrOfItems == 0)
	{
		throw "Empty vector";
	}

	return this->items[index];

}

template<typename T>
T Vector<T>::getFirst() const throw(...)
{
	if (this->nrOfItems == 0)
	{
		throw "No items!";
	}
	return this->items[0];
}

template<typename T>
T Vector<T>::getLast() const throw(...)
{
	if (this->nrOfItems == 0)
	{
		throw "No items!";
	}
	return this->items[this->nrOfItems-1];
}

template<typename T>
T Vector<T>::getAt(int index) const throw(...)
{
	if (this->nrOfItems == 0)
	{
		throw "No items!";
	}
	return this->items[index];
}

template<typename T>
T Vector<T>::removeFirst() throw(...)
{
	T temp;

	if (this->nrOfItems == 0)
	{
		throw "Can't remove!";
	}
	temp = this->items[0];
	this->items[0] = this->items[--this->nrOfItems];
	return temp;
}

template<typename T>
T Vector<T>::removeLast() throw(...)
{
	T temp;
	if (this->nrOfItems == 0)
	{
		throw "Can't remove!";
	}

	temp = this->items[--this->nrOfItems];
	return temp;
}

template<typename T>
T Vector<T>::removeAt(int index) throw(...)
{
	T temp;
	if (this->nrOfItems == 0 || index >nrOfItems || index <0)
	{
		throw "Can't remove!";
	}

	if (index != nrOfItems)
	{
		temp = this->items[index];
		this->items[index] = items[--this->nrOfItems];
	}
	else
	{
		temp = this->items[--this->nrOfItems];
	}

	return temp;
}

template<typename T>
void Vector<T>::removeBetween(int start, int end) throw(...)
{
	if (start<0 || end<0 || end < start || end>this->nrOfItems - 1)
	{
		throw "Can't remove!";
	}
	if (this->nrOfItems == 0)
	{
		throw "No vectors";
	}

	for (int i = start; i < end; i++)
	{
		this->items[i] = this->items[--this->nrOfItems];
	}
}
#endif