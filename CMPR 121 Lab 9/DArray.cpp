
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
	if (newCapacity <= capacity)
	{
		std::cout << "New capacity should be greater than current capcity: " << capacity << std::endl;
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
		std::cout << "ERROR: Array is Full\n";
	}
}

void DArray::insetElementAtIndex(int index, int newElement)
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

DArray::~DArray()
{
	delete[] a;
	a = nullptr;
}