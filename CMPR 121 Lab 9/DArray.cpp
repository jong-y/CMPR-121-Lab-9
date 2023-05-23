
#include "DArray.h"

DArray::DArray()
{
	capacity = 50;
	numOfElements = 0;
	a = new int[capacity];
}

DArray::DArray(int newCapacity)
{
	capacity = newCapacity;
	numOfElements = 0;
	a = new int[newCapacity];
}

int DArray::getCapacity() const
{
	return capacity;
}

int DArray::getNumberOfElements() const
{
	return numOfElements;
}

void DArray::setCapacity(int newCapacity)
{
	if (newCapacity <= 0) {
		std::cout << "Invalid capacity. Capacity should be greater than zero." << std::endl;
		return;
	}

	int* newArray = new int[newCapacity];
	for (int i = 0; i < numOfElements; i++)
	{
		newArray[i] = a[i];
	}

	delete[] a;
	a = newArray;
	capacity = newCapacity;

}


void DArray::addElement(int newElement)
{
	if (numOfElements < capacity)
	{
		a[numOfElements] = newElement;
		++numOfElements;
	}
	else
	{
		throw std::runtime_error("Array is full. Cannot add more elements.");
	}
}

void DArray::insetElementAtIndex(int newElement, int index)
{
	if (index >= 0 && index < numOfElements)
	{
		a[index] = newElement;
	}
	else
	{
		std::cout << "Invald Index." << std::endl;
	}
}

void DArray::print() const
{
	for (int i = 0; i < numOfElements; i++)
	{
		std::cout << a[i] << " ";
	}

	std::cout << std::endl;
}

bool DArray::compareArrays(const DArray& otherArray) const
{
	if (numOfElements != otherArray.numOfElements)
	{
		return false;
	}
	for (int i = 0; i < numOfElements; i++)
	{
		if (a[i] != otherArray.a[i])
		{
			return false;
		}
	}
	return true;
}
//new stuff

DArray::DArray(const DArray& otherArray) : a(nullptr), capacity(otherArray.capacity), numOfElements(otherArray.numOfElements)
{
	a = new int[otherArray.numOfElements];
	for (int i = 0; i < numOfElements; i++)
	{
		a[i] = otherArray.a[i];
	}
}

DArray& DArray::operator=(const DArray& rightside)
{
	if (this == &rightside)
	{
		return *this;
	}

	delete[] a;
	capacity = rightside.capacity;
	numOfElements = rightside.numOfElements;

	a = new int[capacity];
	for (int i = 0; i < numOfElements; i++)
	{
		a[i] = rightside.a[i];
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const DArray& myArray)
{
	for (int i = 0; i < myArray.numOfElements; i++)
	{
		out << myArray.a[i] << " ";
	}
	return out;
}

int DArray::findElement(const int& key) const
{
	for (int i = 0; i < numOfElements; i++)
	{
		if (a[i] == key)
		{
			return i;
		}
	}
	return -1;
}

DArray::~DArray()
{
	delete[] a;
	a = nullptr;
}