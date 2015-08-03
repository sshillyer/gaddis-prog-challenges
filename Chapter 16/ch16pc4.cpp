/*
4. Sequence Accumulation
Write a function
T accum(vector <T> v)
that forms and returns the “sum” of all items in the vector v passed to it. For example, if T is
a numeric type such as int or double, the numeric sum will be returned, and if T represents
the STL string type, then the result of concatenation is returned.
NOTE: For any type T, the expression T() yields the value or object created by the
default constructor. For example, T() yields the empty string object if T is the string
class. If T represents a numeric type such as int, then T() yields 0. Use this fact to
initialize your “accumulator.”

Test your function with a driver program that asks the user to enter 3 integers, uses accum
to compute the sum, and prints out the sum. The program than asks the user to enter
3 strings, uses accum to concatenate the strings, and prints the result.


*/

#include <vector>
#include <iostream>
#include <string>

template <class T>
T accum(std::vector <T> v)
{
	T accumulator = T();
	for (int i = 0; i < v.size(); ++i)
	{
		accumulator += v[i];
	}
	return accumulator;
}

int main()
{
	// Create int vector
	const int SIZE = 30;
	std::vector<int> intVect;
	std::cout << "Vector of integers contains: " << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		intVect.push_back(i);
		std::cout << intVect.at(i) << " ";
	}
	std::cout << std::endl;

	// Create double vector
	const int size = 30;
	std::vector<double> doubleVect;
	std::cout << "Vector of doubles contains: " << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		doubleVect.push_back(i*0.2);
		std::cout << doubleVect.at(i) << " ";
	}
	std::cout << std::endl;

	// Make a few strings
	std::vector<std::string> stringVect;
	std::string str1 = "This is a sentence...";
	std::string str2 = "...and this is not...";
	std::string str3 = "... the end of the world?";
	stringVect.push_back(str1);
	stringVect.push_back(str2);
	stringVect.push_back(str3);
	// stringVect should now hold those three strings.

	// Variables to hold the return values:
	int intSum = accum(intVect);
	double doubleSum = accum(doubleVect);
	std::string stringSum = accum(stringVect);

	std::cout << "intSum is " << intSum << std::endl;
	std::cout << "doubleSum is " << doubleSum << std::endl;
	std::cout << "stringSum is: " << stringSum << std::endl;

	std::cin.get();
	return 0;
}