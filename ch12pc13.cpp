/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 21, 2015
** Description: ch12pc13.cpp
Problem solution from Gaddis C++

13. Digit Sums of Squares and Cubes
If you add up all the digits in 468, you get 4 + 6 + 8 = 18. The square and cube of 468 are
219024 and 102503232, respectively. Interestingly, if you add up the digits of the square
or cube, you get 18 again. Are there other integers that share this property? Write a
program that lists all positive integers k less than 1000 such that the three numbers k, k2,
and k3 have digits that add up to the same number.

*********************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

// Function Prototypes
void numStrToNumArray(char charString[], int numArray[]);
int sumArray(int numArray[], int size);


int main()
{
	// First, get a number and calculate its square and cube and store
	int num, numSqr, numCube;
	std::string numStr, numSqrStr, numCubeStr;
	std::cout << "Enter a number: ";
	std::cin >> num;
	numSqr = num * num;
	numCube = numSqr * num;

	// convert to a string so we can use our fancy numStrToNumArray function from other problem
	// no idea how to do this part...

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