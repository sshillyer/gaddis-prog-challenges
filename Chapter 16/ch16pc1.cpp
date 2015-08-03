/* ch16pc1.cpp
1. String Bound Exceptions
Write a class BCheckString that is derived from the STL string class. This new class will
have two member functions:
A) A BCheckString(string s) constructor that receives a string object passed by
value and passes it on to the base class constructor.
B) An char operator[](int k) function that throws a BoundsException object
if k is negative or is greater than or equal to the length of the string. If k is within
the bounds of the string, this function will return the character at position k in the
string.
You will need to write the definition of the BoundsException class. Test your class with a
main function that attempts to access characters that are within and outside the bounds of
a suitably initialized BCheckString object.
*/


#include <iostream>
#include <string>

class BCheckString : public std::string
{
public:
	BCheckString(std::string s) : std::string(s) { }
	char operator[](int k);
	// Exception handlers
	class BoundsException
	{
	public:
		int index;
		BoundsException(int i) { index = i; }
	};
};

char BCheckString::operator[](int k)
{
	if (k < 0 || k >= length())
		throw BoundsException(k);
	else
		return at(k);
}

// BoundsException


int main()
{
	BCheckString myString = "Short string.";
	int indexToPrint;
	std::cout << "String is: " << myString << std::endl;
	try
	{
		std::cout << "Printing valid element using myString[2]: " << myString[2] << std::endl;
		std::cout << "You can tell me an starting index and I will print the rest of the string." << std::endl;
		std::cout << "Also, I will throw an exception once I read end of string or if you give me a bad index!" << std::endl;
		std::cout << "Index to print from: ";
		std::cin >> indexToPrint;
		std::cout << std::endl;
		for (int i = indexToPrint; i < 1000; i++)
		{
			std::cout << myString[i];
		}
		std::cout << std::endl;
	}
	catch (BCheckString::BoundsException ex)
	{
		std::cout << std::endl << "Error: " << ex.index << " is an invalid index." << std::endl;
	}
	std::cout << "Now we're past the try / catch construct." << std::endl;

	std::cin.ignore(1, '\n');
	std::cin.get();
	return 0;
}