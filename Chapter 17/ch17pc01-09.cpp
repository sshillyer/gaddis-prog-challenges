/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 30, 2015
** Description: ch17pc1.cpp (Includes pc1 through pc
Problem solution from Gaddis C++

1. Simple Linked List Class
Using an appropriate definition of ListNode, design a simple linked list class with only two
member functions and a default constructor:
void add(double x);
boolean isMember(double x);
LinkedList( );
The add function adds a new node containing x to the front (head) of the list, while the
isMember function tests to see if the list contains a node with the value x. Test your linked
list class by adding various numbers to the list and then testing for membership.
*********************************************************************/
#include <iostream>

class LinkedList
{
protected:
	class ListNode
	{
	public:
		double x;
		ListNode* next;
		ListNode(double x, ListNode* next = NULL)
		{
			this->x = x;
			this->next = next;
		}
	};

	ListNode* head; // Points to the first ListNode node
	//  Helper functions
	bool isMemberRec(double x, ListNode* listHead); // recursive isMemberRec function

public:
	/* Constructors and Destructor(s) */
	LinkedList() { head = NULL; } 			// constructor
	~LinkedList(); 							// Destructor
	LinkedList(const LinkedList &);			// Copy constructor
	ListNode* copyList(ListNode* aList);	// copies a list by returning a pointer to itself. Used by copy constructor

	/* Mutators */
	void add(double x);
	void remove(double x);
	void remove(int pos);
	void insert(double x, int pos);
	void reverse();

	/* Accessors */
	bool isMember(double x);
	bool isMemberRec(double x) { return isMemberRec(x, head); } // recursive isMember - initial call takes only 1 arg to get chain going
	void print();
	int search(double x);
	void sort();
};

/***********************************************************************
** Destructor. Deletes entire list. cout statements for demo purposes
***********************************************************************/
LinkedList::~LinkedList()
{
	ListNode* nodePtr = head;
	/* traverse the list with nodePtr; garbage follows in wake and deletes */
	while (nodePtr != NULL)
	{
		ListNode* garbage = nodePtr;
		nodePtr = nodePtr->next;
		std::cout << "Deleting node: " << garbage->x << std::endl;
		delete garbage;
	}
	std::cout << "List deleted." << std::endl;
	std::cin.get();
}

/***********************************************************************
** Copy constructor. Makes a copy of the list by calling copyList()
***********************************************************************/
LinkedList::LinkedList(const LinkedList & original)
{
	head = copyList(original.head);
}

/***********************************************************************
** Returns a pointer to a copy of a list. Used by copy constructor.
***********************************************************************/
LinkedList::ListNode* LinkedList::copyList(ListNode* aList)
{
	// Base case
	if (aList == NULL)
		return NULL;
	else
	{
		// First copy the tail
		ListNode* tailCopy = copyList(aList->next);
		// Return copy of head attached to copy of tail
		return new ListNode(aList->x, tailCopy);
	}
}

/***********************************************************************
** Add an element to the end (tail) of the list
***********************************************************************/
void LinkedList::add(double x)
{
	// If list has no head (empty list) then point the head to a newly allocated ListNode, passing x to ListNode constructor
	if (head == NULL)
	{
		head = new ListNode(x);
	}
	// Otherwise, add the list to the tail
	else
	{
		// Traverse the list
		ListNode* ptr = head;
		while (ptr->next != NULL)	// don't move forward unless we know the next pointer points to another node
		{
			ptr = ptr->next; 		// if it does, then move our iterator there
		}
		// Update the next pointer at the tail to point to new memory and pass the value x to its constructor
		ptr->next = new ListNode(x);
	}
}

/***********************************************************************
** Remove the first instance of x from the listNode.
***********************************************************************/
void LinkedList::remove(double x)
{
	if (head == NULL)
		return;
	ListNode* nodePtr = head, *previousNodePtr = head;
	// handle case of head containing value x first
	if (head->x == x)
	{
		nodePtr = head;
		head = head->next;
		delete nodePtr;
	}
	else // or it might be in rest of list
	{
		nodePtr = head;
		// Traverse the list until end or find value
		while (nodePtr != NULL && nodePtr->x != x)
		{
			previousNodePtr = nodePtr;
			nodePtr = nodePtr->next;
		}
		/* 	If nodePtr is not pointing to Null, then re-link the previous node
		to point to whatever soon-to-be-deleted node once pointed to, restablishing the link */
		if (nodePtr)
		{
			previousNodePtr->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

/***********************************************************************
** Remove the first instance of x from the listNode.
***********************************************************************/
void LinkedList::remove(int pos)
{
	int position = 0;
	if (head == NULL)
		return;
	ListNode* nodePtr = head, *previousNodePtr = head;
	// handle case of deleting head b/c we need to point LinkedList::head to the next value
	if (pos == 0)
	{
		head = head->next;
		delete nodePtr;
	}
	else
	{
		// Traverse the list until end or find position
		while (nodePtr != NULL && position != pos)
		{
			previousNodePtr = nodePtr;
			nodePtr = nodePtr->next;
			position++;
		}
		/* 	If nodePtr is not pointing to Null, then re-link the previous node
		to point to whatever soon-to-be-deleted node once pointed to, restablishing the link */
		if (nodePtr)
		{
			previousNodePtr->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

/***********************************************************************
** Add the value x into the position in the list indicated by pos
***********************************************************************/
void LinkedList::insert(double x, int pos)
{
	// If list has no head (empty list) then point the head to newly allocated ListNode, passing x
	if (head == NULL)
	{
		head = new ListNode(x);
	}

	// Otherwise, add the list to the correct position
	else
	{
		int position = 0;
		// Traverse the list
		ListNode* nodePtr = head, *priorNodePtr = NULL;

		// move forward in the list until we find the correct position or we've reached the end
		while (pos != position && nodePtr->next != NULL)
		{
			priorNodePtr = nodePtr; // remember where the last node was so we can update its next pointer
			nodePtr = nodePtr->next; // move up
			position++; // increment our position counter
		}
		// Now that we're in the right spot, need to repoint everything and allocate space for new node
		priorNodePtr->next = new ListNode(x);
		priorNodePtr = priorNodePtr->next;
		priorNodePtr->next = nodePtr;
	}
}

/***********************************************************************
** Reverse all of the nodes in the list.
***********************************************************************/
void LinkedList::reverse()
{
	ListNode* priorNodePtr, *nextNodePtr, *nodePtr;
	nodePtr = head;
	priorNodePtr = NULL;


	// Now have three pointers external to the list itself we can use to reconnect each position
	while (nodePtr != NULL) // stops when the nodePtr is pointing at NULL
	{
		nextNodePtr = nodePtr->next; // this is the only way we'll know where to move our nodePtr to next
		nodePtr->next = priorNodePtr; // point current node's next value backwards to last node, or null if it was the head
		priorNodePtr = nodePtr; // shift the prior node up one position
		nodePtr = nextNodePtr; // move current node up one --> we have to use the nextNodePtr instead of current node's ->next because it's been pointed elsewhere already
	}
	// Now we have to tell the head of our list where the new head is... which should be wherever priorNodePtr is pointing (last element of the list)
	head = priorNodePtr;
}



/***********************************************************************
** This function is borked... I can't figure out how to do this without having a million
** pointers pointing to every damn node. Do some research
***********************************************************************/
void LinkedList::sort()
{
	ListNode* nodePtr = head, * minNode = head, minNodeLess1 = NULL, startScan = head, startScanLess1 = NULL;
	
	// For each index, we find the smallest value in the rest of the array and relink it
	while (startScan != NULL)
	{
		// nodePtr = startScan->next; -- this might be needed, but if it is, maybe before either while loop
		// On each pass, traverse the list and point minNode to the node with smallest value
		while (nodePtr != NULL)
		{
			// If the value at any given node is less than the current min, repoint minNode
			if (nodePtr->x < minNode->x)
			{
				minNode = nodePtr;
			}
			// Check next node
			nodePtr = nodePtr->next;
		}
		// minNode now points to the smallest node, nodePtr points to Null, and startScan points to the element pos we want the min node to be located at
		// point the node prior to start scan to the min node
		startScanLess1->next = minNode; 
		nodePtr = minNode->next; // remember where minNode used to point
		minNode->next = startScan; // then point the minNode->next to the value that we were at

		startScanLess1 = startScan;
		startScan = startScan->next;
		nodePtr = startScan;
	}
	

	int minVal = nodePtr->x, minIndex = 0, position = 0;

	while (/*condition*/)
	{
		position++;
		nodePtr = nodePtr->next;
		if (nodePtr->x < minVal)
		{
			minVal = nodePtr->x;
			minIndex = position;
		}
	}
}

/***********************************************************************
** Returns true of x is found in the list
***********************************************************************/
bool LinkedList::isMember(double x)
{
	// if list is empty, x is not a member of the list
	if (head == NULL)
	{
		return false;
	}
	// Otherwise, start searching
	else
	{
		ListNode* ptr = head;
		while (ptr != NULL)
		{
			if (ptr->x == x)
			{
				return true; // value found
			}
			else
			{
				ptr = ptr->next;
			}
		}
		// If we've reached end of list and value not found then it must not be a member.
		return false;
	}
}

/***********************************************************************
** Returns true if x is found in the list - recursive version of isMember
***********************************************************************/
bool LinkedList::isMemberRec(double x, ListNode* listHead)
{
	if (listHead == NULL)
		return false;
	ListNode* ptr = listHead;
	if (ptr->x == x)
	{
		return true;
	}
	else
	{
		return isMemberRec(x, ptr->next);
	}
}

/***********************************************************************
** Prints the elements in the list with a space as padding between values
***********************************************************************/
void LinkedList::print()
{
	if (head == NULL)
		return; // do nothing if list empty
	else
	{
		ListNode* ptr = head;
		std::cout << "List values: ";
		while (ptr != NULL)
		{
			std::cout << ptr->x << " ";
			ptr = ptr->next;
		}
		std::cout << std::endl;
	}
}

/***********************************************************************
** Returns true if x is found in the list - recursive version of isMember
***********************************************************************/
int LinkedList::search(double x)
{
	int position = 0; // track the position that the value x is found, if any.
	// if list is empty, x is not a member of the list
	if (head == NULL)
	{
		return -1; // if list is empty, return -1 to signal list is empty
	}
	// Otherwise, start searching
	else
	{
		ListNode* ptr = head;
		while (ptr != NULL)
		{
			if (ptr->x == x)
			{
				return position;
			}
			else
			{
				ptr = ptr->next;
				position++;
			}
		}
		// If we've reached end of list and value not found then it must not be a member
		return -1; // signal not a member
	}
}

/***********************************************************************
** Test client
***********************************************************************/
int main()
{
	LinkedList l;

	// Try adding a member
	l.print();
	l.add(5);
	l.print();
	l.add(10);
	l.add(15);
	l.print();
	l.remove(10);
	l.print();
	l.remove(15);
	l.remove(5);
	l.print();

	for (int i = 0; i < 15; i++)
	{
		l.add(i + 10);
	}
	l.print();

	std::cout << "calling l.isMember(11): " << l.isMember(11) << std::endl;
	std::cout << "calling l.isMemberRec(12): " << l.isMemberRec(12) << std::endl;
	std::cout << "calling l.isMemberRec(1200): " << l.isMemberRec(1200) << std::endl;

	LinkedList l2 = l;
	l2.print();
	std::cout << "Reversing l2 using l2.reverse()." << std::endl;
	l2.reverse();
	l2.print();

	std::cout << "List item 15 is in position: " << l2.search(15) << std::endl;

	std::cout << "Inserting 99 into position of 15..." << std::endl;

	l2.insert(99, 9);

	l2.print();

	std::cin.get();
	return 0;
}