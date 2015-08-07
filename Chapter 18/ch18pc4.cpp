/*********************************************************************
** Author: Shawn S Hillyer
** Date: August 6, 2015

4. Dynamic Queue Template
In this chapter you studied DynIntQueue, a class that implements a dynamic queue of
integers. Write a template that will create a dynamic queue of any data type. Demonstrate
the class with a driver program.
*********************************************************************/

template <class T>
class DynQueue
{
private:
	template <class T>
	class QueueNode
	{
		friend class DynQueue;
		T value;
		QueueNode<T>* next;
		QueueNode(T value, QueueNode<T>* next = NULL)
		{
			this->value = value;
			this->next = next;
		}
	};

	// Trackers for fron and rear of the queue
	QueueNode<T> *front;
	QueueNode<T> *rear;
public:
	// Constructor and destructor
	DynQueue();
	~DynQueue();

	// Member functions
	void enqueue(T);
	void dequeue(T &);
	bool isEmpty() const;
	void clear();
};

// implementation

// constructor
template <class T>
DynQueue<T>::DynQueue()
{
	front = NULL;
	rear = NULL;
}

// deconstructor
template <class T>
DynQueue<T>::~DynQueue()
{
	clear();
}

// enqueue
template <class T>
void DynQueue<T>::enqueue(T value)
{
	try 
	{
		// If the queue is empty, make a new node and point rear to this node as well
		if (isEmpty())
		{
			front = new QueueNode<T>(value);
			rear = front;
		}
		// Otherwise make a node at the end
		else
		{
			rear->next = new QueueNode<T>(value);
			rear = rear->next;
		}
	}
	catch(bad_alloc)
	{
		std::cout << "Unable to allocate memory. Terminating..." << std::endl;
		exit(1);
	}
}

// dequeue - remove value from front and copy it into the ref variable
template <class T>
void DynQueue<T>::dequeue(T &value)
{
	QueueNode<T>* temp;
	if (isEmpty())
	{
		std::cout << "The queue is empty." << std::endl;
		exit(1);
	}
	else
	{
		value = front->value; // copy the value in front node to the reference variable
		temp = front; // point a temporary to front so we can delete it soon
		front = front->next; // point front to the next node in list
		delete temp;
	}
}

// isEmpty
template <class T>
bool DynQueue<T>::isEmpty() const
{
	if (front == NULL)
		return true;
	else
		return false;
}

// clear() deques all elements in queue
template class <T>
void DynQueue<T>::clear()
{
	T value; // dummy variable for dequeue

	while(!isEmpty())
		dequeue(value);
}