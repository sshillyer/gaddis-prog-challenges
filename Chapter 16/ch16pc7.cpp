/*7. SimpleVector Modification
Modify the SimpleVector class template, presented in this chapter, to include the
member functions push_back and pop_back. These functions should emulate the STL
vector class member functions of the same name. (See Table 16-4.) The push_back
function should throw an exception if the array is full. The push_back function should
accept an argument and insert its value at the end of the array. The pop_back function
should accept no argument and remove the last element from the array. Test the class
with a driver program.
*/

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <cstdlib>
using namespace std;


template <class T>
class SimpleVector
{
private:
	T *aptr;
	int arraySize;
	int currentPos;
	void subError() const; // Handles subscripts out of range
public:
	SimpleVector(int); // Constructor
	SimpleVector(const SimpleVector &); // Copy constructor
	~SimpleVector(); // Destructor
	int size() const
	{
		return arraySize;
	}
	T &operator[](int); // Overloaded [] operator
	void print() const; // Output array
	void push_back(T); // insert value at end of array
	void pop_back(); // remove last element from array
	// exception handlers
	class ArrayFull { private: int x; };
};

/*******************************************************
// Constructor for SimpleVector class. Sets the size *
// of the array and allocates memory for it. *
//********************************************************/
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
	arraySize = s;
	currentPos = 0;
	aptr = new T[s];
	for (int count = 0; count < arraySize; count++)
		aptr[count] = T();
}
//******************************************************
// Copy Constructor for SimpleVector class. *
//******************************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
	arraySize = obj.arraySize;
	aptr = new T[arraySize];
	for (int count = 0; count < arraySize; count++)
		aptr[count] = obj[count];
}
//*****************************************************
// Destructor for SimpleVector class. *
//*****************************************************
template <class T>
SimpleVector<T>::~SimpleVector()
{
	if (arraySize > 0)
		delete[] aptr;
}

//******************************************************
// subError function. Displays an error message and *
// terminates the program when a subscript is out of *
// range. *
//******************************************************
template <class T>
void SimpleVector<T>::subError() const
{
	cout << "ERROR: Subscript out of range.\n";
	exit(0);
}
//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element *
// in the array indexed by the subscript. *
//*******************************************************
template <class T>
T &SimpleVector<T>::operator[](int sub)
{
	if (sub < 0 || sub >= arraySize)
		subError();
	return aptr[sub];
}
//********************************************************
// prints all the entries in the array. *
//********************************************************
template <class T>
void SimpleVector<T>::print() const
{
	for (int k = 0; k < arraySize; k++)
		cout << aptr[k] << " ";
	cout << endl;
}
//********************************************************
// Add an element to end of the array
//********************************************************
template <class T>
void SimpleVector<T>::push_back(T v)
{
	try
	{
		if (currentPos < arraySize)
		{
			aptr[currentPos] = v;
			++currentPos; // increment current position
		}
		else
		{
			throw ArrayFull();
		}
	}
	catch (ArrayFull)
	{
		cout << "The array is full." << endl;
	}

}


//********************************************************
// remove the last element from array
//********************************************************
template <class T>
void SimpleVector<T>::pop_back()
{
	aptr[--currentPos] = T();
}
#endif

int main()
{
	const int VSIZE = 10;
	SimpleVector<int> v1(VSIZE);
	for (int i = 0; i < VSIZE + 2; i++)
	{
		v1.push_back(i);
	}

	v1.print();

	cin.get();
	return 0;
}