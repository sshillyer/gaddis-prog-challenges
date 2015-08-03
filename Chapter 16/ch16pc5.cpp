
/*
5. Rotate Left
The two sets of output below show the results of successive circular rotations of a vector.
One set of data is for a vector of integers, and the second is for a vector of strings.
1 3 5 7
3 5 7 1
5 7 1 3
7 1 3 5

a b c d e
b c d e a
c d e a b
d e a b c
e a b c d
Write two template functions that can be used to rotate and output a vector of a generic
type:
void rotateLeft(vector <T>& v)
void output(vector <T> v)
The first function performs a single circular left rotation on a vector, and the second
prints out the vector passed to it as parameter. Write a suitable driver program that
will allow you to test the two functions by generating output similar to the above.
Verify that the program works with vectors whose element types are char, int,
double, and string.


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




int main()
{
	// Create int vector
	const int SIZE = 26;
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

	std::cin.get();
	return 0;
}