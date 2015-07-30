/* 4. Recursive Array Sum
Write a function that accepts two arguments, an array of integers and a number indicating
the number of elements in the array. The function should recursively calculate the sum of
all the numbers in the array. Demonstrate the use of the function in a program that asks
the user to enter an array of numbers and prints its sum. */

#include <iostream>

int recursiveSumArray(int array[], int size)
{
	int pos = 0;
	if (size == 1)
	{
		std::cout << "val is " << array[pos] << "pos is " << pos << " size is " << size << std::endl;
		return array[pos];
	}
	else
	{
		std::cout << "val is " << array[pos] << "pos is " << pos << " size is " << size << std::endl;

		return array[pos] + recursiveSumArray(array + 1, size - 1);
	}
}

int main()
{
	std::cout << "testing sum of array holding 1 2 3 4" << std::endl;
	int myArray[] = { 1, 2, 3, 4, 37, 402 };
	int sum = recursiveSumArray(myArray, 6);
	std::cout << "Sum is " << sum << std::endl;

	std::cin.get();
	return 0;
}