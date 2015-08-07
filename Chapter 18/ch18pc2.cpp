/*********************************************************************
** Author: Shawn S Hillyer
** Date: August 6, 2015
TESTING: COMPLETE. Functional. Maybe double check all methods working later.

2. Dynamic Stack Template
In this chapter you studied DynIntStack, a class that implements a dynamic stack of
integers. Write a template that will create a dynamic stack of any data type. Demonstrate
the class with a driver program.
*********************************************************************/
#include <iostream>

template <class T>
class DynStack
{
private:
	template <class T>   // might need this line?? See if compiles without
	class StackNode
	{
		friend class DynStack; // maybe drop the <T> ??
		T value;
		StackNode<T>* next;
		StackNode<T>(T value, StackNode<T>* next = NULL)
		{
			this->value = value;
			this->next = next;
		}
	};

	StackNode<T>* top;

public:
	DynStack() { top = NULL; }
	void push(T);
	void pop(T&);
	bool isEmpty() const;
	void print();
};

template <class T>
void DynStack<T>::push(T value)
{
	top = new StackNode<T>(value, top);
}

template <class T>
void DynStack<T>::pop(T& value)
{
	StackNode<T>* temp, *head;
	head = top;

	if (isEmpty())
	{
		// error handling
		exit(1);
	}
	else
	{
		value = head->value;
		temp = head;
		top = head->next;
		delete temp;
	}

}

template <class T>
bool DynStack<T>::isEmpty() const
{
	if (!top)
		return true;
	else
		return false;
}


template <class T>
void DynStack<T>::print()
{
	StackNode<T>* node = top;
	while (node)
	{
		std::cout << node->value << " ";
		node = node->next;
	}
}

/*********************************************************************
 TEST CLIENT
*********************************************************************/
#include <iostream>

int main()
{
	DynStack<int> myStack;
	int holder;

	for (int i = 0; i < 20; i++)
	{
		myStack.push(i);
	}

	myStack.print();

	myStack.pop(holder);
	std::cout << "Popping value from top. Popped off: " << holder << std::endl;
	myStack.print();

	std::cin.get();
	return 0;
}