/*
6. Template Reversal
Write a template function that takes as parameter a vector of a generic type and
reverses the order of elements in the vector, and then add the function to the program
you wrote for Programming Challenge 5. Modify the driver program to test the new
function by reversing and outputting vectors whose element types are char, int, double,
and string.
*/

#include <iostream>
#include <vector>
#include <string>

template <class T>
void rotateLeft(std::vector<T>& v)
{
	T tempVal;
	tempVal = v.at(0); // store the first element in a variable tempVal
	v.erase(v.begin()); // erase the value stored in first element
	v.push_back(tempVal); // push the value that was at the front onto the back of the vector
}


template <class T>
void output(std::vector <T> v)
{
	int numElements = v.size();

	std::cout << std::endl;
	for (int i = 0; i < numElements; i++)
	{
		for (int j = 0; j < numElements; j++)
		{
			std::cout << v.at(j) << " ";
		}
		rotateLeft(v);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template <class T>
void reverse(std::vector <T>& v)
{
	std::vector<T> temp;
	int lastIndex = v.size() - 1;
	for (int i = 0; i < v.size(); i++)
	{
		temp.push_back(v.at(lastIndex - i));
	}
	v.swap(temp);
}


int main()
{
	// Create int vector
	const int SIZE = 6;
	std::vector<int> intVect;
	std::cout << "Vector of integers contains: " << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		intVect.push_back(i);
		std::cout << intVect.at(i) << " ";
	}
	std::cout << std::endl;

	// Create char vector

	std::vector<char> charVect;
	std::cout << "Vector of chars contains: " << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		char ch = i + 65; // Start at capital 'A'
		charVect.push_back(ch);
		std::cout << charVect.at(i) << " ";
	}
	std::cout << std::endl;

	// Make a few strings
	std::vector<std::string> stringVect;
	std::string str1 = "ROW ROW ROW YOUR BOAT";
	std::string str2 = "GENTLY DOWN THE STREAM";
	std::string str3 = "PROGRAMMING IN C++ IS A DREAM";
	stringVect.push_back(str1);
	stringVect.push_back(str2);
	stringVect.push_back(str3);
	// stringVect should now hold those three strings.

	// Now let's try rotating them...
	/*	rotateLeft(intVect);
	rotateLeft(charVect);
	rotateLeft(stringVect); */
	output(intVect);
	output(charVect);
	output(stringVect);
	reverse(intVect);
	reverse(charVect);
	reverse(stringVect);
	output(intVect);
	output(charVect);
	output(stringVect);

	std::cin.get();
	return 0;
}