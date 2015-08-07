/*********************************************************************
** Author: Shawn S Hillyer
** Date: August 6, 2015

TESTING: Complete. Fully functional. Handles underflow just fine as well.
(need to actually try it with different data types from home PC)

Chapter 18
1. Static Stack Template
In this chapter you studied IntStack, a class that implements a static stack of integers.
Write a template that will create a static stack of any data type. Demonstrate the class with
a driver program.
*********************************************************************/

template <class T>
class Stack
{
private:
	T *stackArray;
	int capacity;
	int top;
public:
	Stack(int capacity); // constructor
	~Stack() { delete[] stackArray; } // deconstructor
	void push(T value);
	void pop(T &value);
	bool isEmpty() const;
	void print();

	//stack exceptions
	class Overflow {};
	class Underflow {};
};

// Constructor
template <class T>
Stack<T>::Stack(int capacity)
{
	stackArray = new T[capacity];
	this->capacity = capacity;
	top = 0;
}

template <class T>
void Stack<T>::push(T value)
{
	if (top == capacity)
		throw Stack::Overflow();
	stackArray[top] = value;
	top++;
}

template <class T>
void Stack<T>::pop(T &value)
{
	if (isEmpty())
		throw Stack::Underflow();
	top--; // decrement before popping value because top points to the next element that would be pushed
	value = stackArray[top];
}

template <class T>
bool Stack<T>::isEmpty() const
{
	if (top == 0)
		return true;
	else
		return false;
}

template <class T>
void Stack<T>::print()
{
	for (int i = 0; i < top; i++)
	{
		std::cout << stackArray[i] << " ";
	}
	std::cout << std::endl;
}

/*********************************************************************
 TEST CLIENT
*********************************************************************/
#include <iostream>

int main()
{
	const int MAX_SIZE = 15;
	Stack<int> myStack(MAX_SIZE);
	int holder;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		myStack.push(i);
	}

	myStack.print();

	myStack.pop(holder);
	std::cout << "Popping value from top. Popped off: " << holder << std::endl;
	myStack.print();
	std::cout << "Forcing an underflow... " << std::endl;
	for (int i = 0; i < MAX_SIZE + 1; i++)
	{
		myStack.pop(holder);
		std::cout << "Popping: " << holder << " . " << std::endl;
	}

	std::cin.get();
	return 0;
}