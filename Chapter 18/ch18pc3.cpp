/*********************************************************************
** Author: Shawn S Hillyer
** Date: August 6, 2015

TESTING: Need to test other types. The print function is bugged....

3. Static Queue Template
In this chapter you studied IntQueue, a class that implements a static queue of integers.
Write a template that will create a static queue of any data type. Demonstrate the class
with a driver program.
*********************************************************************/

#include <iostream>

template <class T>
class StaticQueue
{
private:
	T *queueArray;
	int queueSize;
	int front;
	int rear;
	int numItems;
public:
	StaticQueue(int);
	~StaticQueue();
	void enqueue(T);
	void dequeue(T &);
	bool isEmpty() const;
	bool isFull() const;
	void clear();
	void print() const;
};


/***********************
// Constructor
//*********************/
template <class T>
StaticQueue<T>::StaticQueue(int s)
{
	queueArray = new T[s];
	queueSize = s;
	front = -1;
	rear = -1;
	numItems = 0;
}

/***********************
// Destructor
//*********************/
template <class T>
StaticQueue<T>::~StaticQueue()
{
	delete[] queueArray;
}

/***********************
// enqueue. add an item to rear of array, unless full
//*********************/
template <class T>
void StaticQueue<T>::enqueue(T value)
{
	if (isFull())
	{
		std::cout << "The queue is full." << std::endl;
		exit(1);
	}
	else
	{
		rear = (rear + 1) % queueSize;
		queueArray[rear] = value;
		numItems++;
	}
}

/***********************
// Removes an item from the front of the queue and updates the value passed into function by reference
//*********************/
template <class T>
void StaticQueue<T>::dequeue(T &value)
{
	if (isEmpty())
	{
		std::cout << "The queue is empty." << std::endl;
		exit(1);
	}
	else
	{
		front = (front + 1) % queueSize;
		value = queueArray[front];
		numItems--;
	}
}

/***********************
// isEmpty returns true of the queue is empty
//*********************/
template <class T>
bool StaticQueue<T>::isEmpty() const
{
	if (numItems > 0)
		return false;
	else
		return true;
}

/***********************
// isFull returns true if the queue is full, otherwise false
//*********************/
template <class T>
bool StaticQueue<T>::isFull() const
{
	if (numItems < queueSize)
		return false;
	else
		return true;
}

/***********************
// clear() clears the queue by resetting the markers and setting numItems to 0.
//*********************/
template <class T>
void StaticQueue<T>::clear()
{
	front = -1;
	rear = -1;
	numItems = 0;
}

/***********************
// Prints the queue from front to back.
//*********************/
template <class T>
void StaticQueue<T>::print() const
{
	if (!isEmpty())
	{
		int i = front + 1;
		for (int j = 0; j < numItems; j++)
		{
			std::cout << queueArray[i] << " ";
			i = ((i + 1) % queueSize);
		}
		std::cout << std::endl;
	}

}

int main()
{
	// Make a queue
	const int MAX_SIZE = 10;
	StaticQueue<double> myQueue(MAX_SIZE);
	std::cout << "Made a StaticQueue object of size " << MAX_SIZE << std::endl;

	for (int i = 0; i < MAX_SIZE; ++i)
	{
		std::cout << "enqueue(" << i * 1.1 << ") to queue. Queue contains: ";
		myQueue.enqueue(i * 1.1);
		myQueue.print();
	}
	myQueue.print();
	double item;
	myQueue.dequeue(item);
	std::cout << "Dequeued value: " << item << std::endl;
	myQueue.dequeue(item);
	std::cout << "Dequeued value: " << item << std::endl;
	myQueue.print();
	myQueue.clear();
	std::cout << "Should have a clear array now. isEmpty returns:" << myQueue.isEmpty() << std::endl;
	myQueue.print();
	myQueue.enqueue(99.99);
	std::cout << "Should have only 99.99 and 100.00..." << std::endl;
	myQueue.enqueue(100);
	myQueue.print();
	std::cin.get();
	return 0;
}