/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 17, 2015
** Description: ch12pc6.cpp
Problem solution from Gaddis C++

6. Sum of Digits in a String
Write a program that asks the user to enter a series of single-digit numbers with nothing
separating them. Read the input as a C-string or a string object. The program should
display the sum of all the single-digit numbers in the string. For example, if the user enters
2514, the program should display 12, which is the sum of 2, 5, 1, and 4. The program
should also display the highest and lowest digits in the string.

*********************************************************************/

#include <iostream>
#include <string>
#include <cctype>

// Function Prototypes
void numStrToNumArray(char charString[], int numArray[]);
int sumArray(int numArray[], int size);
int maxArray(int numArray[], int size);
int minArray(int numArray[], int size);

int main()
{
	// Declare c string
	const int STR_LENGTH = 80;
	char myString[STR_LENGTH];

	// read in a string or c-string from user
	std::cout << "Input a sequence of numbers with no spaces: " << std::endl;
	std::cin.getline(myString, STR_LENGTH);
	int myStringSize = strlen(myString);

	// create an array of same length as string and pass both arrays for processing
	int* numbers = new int[myStringSize];
	numStrToNumArray(myString, numbers);

	std::cout << "numbers are: " << std::endl;

	for (int i = 0; i < myStringSize; i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl << "Sum of those integers is: " << sumArray(numbers, myStringSize) << std::endl;
	std::cout << "Max: " << maxArray(numbers, myStringSize) << std::endl;
	std::cout << "Min: " << minArray(numbers, myStringSize) << std::endl;

	delete [] numbers;
	std::cin.get();

	return 0;
}

void numStrToNumArray(char charString[], int numbers[])
{
	// Copy the values from the strign into the integer array, offsetting value by 48 to get correct ascii val
	for (int i = 0; charString[i] != '\0'; i++)
	{
		numbers[i] = charString[i] - 48;
	}
}

int sumArray(int numArray[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += numArray[i];
	}
	return sum;
}

int maxArray(int numArray[], int size)
{
	int max = numArray[0];
	for (int i = 1; i < size; i++)
	{
		if (numArray[i] > max)
			max = numArray[i];
	}
	return max;
}


int minArray(int numArray[], int size)
{
	int min = numArray[0];
	for (int i = 1; i < size; i++)
	{
		if (numArray[i] < min)
			min = numArray[i];
	}
	return min;
}