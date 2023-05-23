#pragma once
#ifndef DARRAY_H
#define DARRAY_H
#include <iostream>
class DArray
{
private:

	int  capacity;
	int* a;
	int numOfElements;

public:
	DArray();
	DArray(int newCapacity);
	//new stuff
	DArray(const DArray& otherArray);

	DArray& operator=(const DArray& rightside);

	friend std::ostream& operator<<(std::ostream& out, const DArray& myArray);

	int findElement(const int& key) const;

	int getCapacity() const;
	int getNumberOfElements() const;

	void setCapacity(int newCapacity);

	void addElement(int newElement);

	void insetElementAtIndex(int index, int newElement);

	void print() const;

	bool compareArrays(const DArray& otherArray) const;

	~DArray();

};


#endif
