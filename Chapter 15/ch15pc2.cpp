/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 30, 2015
** Description: ch15pc2.cpp (Includes pc1 as well)
Problem solution from Gaddis C++

1. Analysis of Sorting Algorithms
Design a class AbstractSort that can be used to analyze the number of comparisons performed
by a sorting algorithm. The class should have a member function compare that is capable of
comparing two array elements, and a means of keeping track of the number of comparisons
performed. The class should be an abstract class with a pure virtual member function
void sort(int arr[ ], int size)
which, when overridden, will sort the array by calling the compare function to determine
the relative order of pairs of numbers. Create a subclass of AbstractSort that uses a
simple sorting algorithm to implement the sort function. The class should have a member
function that can be called after the sorting is done to retrieve the number of comparisons
performed.

2. Analysis of Quicksort
Create a subclass of the AbstractSort class of Programming Challenge 1 that uses the
Quicksort algorithm to implement the sort function.

*********************************************************************/

/*********************
**  AbstractSort.hpp
*********************/
class AbstractSort
{
protected:
	int comparisonCount;
public:
	AbstractSort(int = 0);
	virtual void sort(int arra[], int size) = 0; // pure virtual function
	void setComparisonCount(int);
	int getComparisonCount();
	bool compare(int, int);
};


/*********************
**  AbstractSort.cpp
*********************/

AbstractSort::AbstractSort(int c)
{
	setComparisonCount(c);
}

void AbstractSort::setComparisonCount(int comparisonCount)
{
	this->comparisonCount = comparisonCount;
}

int AbstractSort::getComparisonCount()
{
	return comparisonCount;
}

bool AbstractSort::compare(int a, int b)
{
	setComparisonCount(++comparisonCount);
	// std::cout << std::endl << "comparisonCount incremented to: " << comparisonCount; // debugg only
	return (a > b); // true if a greater than b, false otherwise
}

/*********************
** BubbleSort.hpp
*********************/
class BubbleSort : public AbstractSort
{
public:
	virtual void sort(int arr[], int size);
};

/*********************
**  BubbleSort.cpp
*********************/
void BubbleSort::sort(int arr[], int size)
{
	int temp;
	bool swap;
	do
	{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (compare(arr[count], arr[count + 1]))
			{
				temp = arr[count];
				arr[count] = arr[count + 1];
				arr[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

/*********************
**  QuickSort.hpp
*********************/
class QuickSort : public AbstractSort
{
public:
	void sort(int arr[], int size);
	void quickSort(int arr[], int start, int end);
	int partition(int arr[], int start, int end);
};


/*********************
**  QuickSort.cpp
*********************/
#include <algorithm>

void QuickSort::sort(int arr[], int size)
{
	quickSort(arr, 0, (size - 1));
}

void QuickSort::quickSort(int arr[], int start, int end)
{
	if (start < end)
	{
		// Partition the array and get the pivot point
		int p = partition(arr, start, end);

		// Sort the portion before the pivot point
		quickSort(arr, start, p - 1);

		// Sort the portion after the pivot point
		quickSort(arr, p + 1, end);
	}
}

int QuickSort::partition(int arr[], int start, int end)
{
	// The pivot element is taken to be the element at the start of the subrange to be partitioned
	int pivotValue = arr[start];
	int pivotPosition = start;

	// Rearrange the rest of the array elements to partition the subrange from start to end
	for (int pos = start + 1; pos <= end; pos++)
	{
		if (compare(pivotValue, arr[pos])) // if array[pos] < pivotValue
		{
			// arr[scan] is the "current" item. Swap the current item with the item to the right of the pivot element
			std::swap(arr[pivotPosition + 1], arr[pos]);
			// Swap the current item with the pivot element
			std::swap(arr[pivotPosition], arr[pivotPosition + 1]);
			// Adjust the pivot position so it stays with the pivot element
			pivotPosition++;
		}
	}
	return pivotPosition;
}

/*********************
** SortTest.cpp
*********************/

#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	srand(time(0));
	const int SIZE = 30;
	const int MAX_RANGE = 9;
	int times, totalBubComps = 0, totalQckComps = 0;

	std::cout << "How many times would you like to generate and sort arrays?";
	std::cin >> times;
	for (int t = 0; t < times; t++)
	{
		// make a BubbleSort object and QuickSort object
		BubbleSort bsort;
		QuickSort quicksort;

		// Make an array and print it to screen so we can verify that it sorted
		int myArray[SIZE];
		std::cout << "Making array with values: " << std::endl;
		for (int i = 0; i < SIZE; ++i)
		{
			myArray[i] = ((rand() % MAX_RANGE) + 1);
			std::cout << myArray[i] << " ";
		}
		std::cout << std::endl;

		// Sort the array using the bsort object
		bsort.sort(myArray, SIZE);

		// Print array again and how many comparisons were made
		std::cout << std::endl << "Sorted array:" << std::endl;
		for (int i = 0; i < SIZE; ++i)
		{
			std::cout << myArray[i] << " ";
		}
		std::cout << std::endl << "bsort.sort() made " << bsort.getComparisonCount() << " comparisons." << std::endl << std::endl;
		totalBubComps += bsort.getComparisonCount();
		bsort.setComparisonCount(0);

		// Now do the same thing with the quicksort

		std::cout << "Making array with values: " << std::endl;
		for (int i = 0; i < SIZE; ++i)
		{
			myArray[i] = ((rand() % MAX_RANGE) + 1);
			std::cout << myArray[i] << " ";
		}
		std::cout << std::endl;

		// Sort the array using the bsort object
		quicksort.sort(myArray, SIZE);

		// Print array again and how many comparisons were made
		std::cout << std::endl << "Sorted array:" << std::endl;
		for (int i = 0; i < SIZE; ++i)
		{
			std::cout << myArray[i] << " ";
		}
		std::cout << std::endl << "quick.sort() made " << quicksort.getComparisonCount() << " comparisons." << std::endl << std::endl;
		totalQckComps += quicksort.getComparisonCount();
		quicksort.setComparisonCount(0);

	//	std::cout << "Total comparisons made by bubble sort: " << totalBubComps << ". Average: " << totalBubComps / static_cast<double>(times) << std::endl;
	//	std::cout << "Total comparisons made by quick sort: " << totalQckComps << ". Average: " << totalQckComps / static_cast<double>(times) << std::endl;
	}
	std::cout << std::endl << std::endl;
	std::cout << "Total comparisons made by bubble sort: " << totalBubComps << ". Average: " << totalBubComps / static_cast<double>(times) << std::endl;
	std::cout << "Total comparisons made by quick sort: " << totalQckComps << ". Average: " << totalQckComps / static_cast<double>(times) << std::endl;

	std::cin.ignore();
	std::cin.get(); // to force console to stay open in VS
	return 0;
}