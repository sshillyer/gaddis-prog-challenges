/*
6. Recursive Member Test
Write a recursive Boolean function named isMember. The function should accept three
parameters: an array of integers, an integer indicating the number of elements in the
array, and an integer value to be searched for. The function should return true if the
value is found in the array, or false if the value is not found. Demonstrate the use of
the function in a program that asks the user to enter an array of numbers and a value
to be searched for.
*/

#include <iostream>

bool isMember(int array[], int size, int key)
{
	int pos = 0;
	if (size == 0)
	{
		return false; // base case - key not found
	}
	else if (array[pos] == key)
	{
		return true; // second base case - key found
	}
	else // non-base recursion
	{
		return isMember(array + 1, size - 1, key); // search the array starting at next element, reduce size by 1
	}
}

int main()
{
	int myArray[] = { 1, 2, 3, 4, 37, 402 };
	int searchFor;
	std::cout << "Testing search of array holding 1 2 3 4, 37, 402. What value would you like to check?" << std::endl;
	std::cin >> searchFor;

	bool wasFound = isMember(myArray, 6, searchFor);
	std::cout << "isMember(" << searchFor << ") returns " << wasFound << std::endl;

	std::cin.ignore();
	std::cin.get();
	return 0;
}