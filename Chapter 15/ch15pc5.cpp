/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 30, 2015
** Description: ch15pc5.cpp
Problem solution from Gaddis C++

5. File Filter
A file filter reads an input file, transforms it in some way, and writes the results to an
output file. Write an abstract file filter class that defines a pure virtual function for
transforming a character. Create one subclass of your file filter class that performs
encryption, another that transforms a file to all uppercase, and another that creates an
unchanged copy of the original file.

The class should have a member function
void doFilter(ifstream &in, ofstream &out)
that is called to perform the actual filtering. The member function for transforming a single
character should have the prototype
char transform(char ch)
The encryption class should have a constructor that takes an integer as an argument and
uses it as the encrytion key.

**********************************************************************************************/
#include <cctype>
#include <iostream>
#include <fstream>

/***************************
**  AbstractFileFilter.hpp
***************************/
//#include <fstream>
class AbstractFileFilter
{
public:
	virtual char transform(char ch) = 0;
	void doFilter(std::ifstream &in, std::ofstream &out);
};

/***************************
**  AbstractFileFilter.cpp
***************************/
void AbstractFileFilter::doFilter(std::ifstream &in, std::ofstream &out)
{
	char ch;
	char transCh;
	in.get(ch);
	while (!in.fail())
	{
		transCh = transform(ch);
		out.put(transCh);
		in.get(ch);
	}
}

/***************************
**  ToUpperFilter.hpp
***************************/

class ToUpperFilter : public AbstractFileFilter
{
public:
	char transform(char ch);
};

/***************************
**  ToUpperFilter.cpp
***************************/
// #include <cctype>
char ToUpperFilter::transform(char ch)
{
	return toupper(ch);
}

/***************************
**  IntCryption.hpp
***************************/
class IntCryption : public AbstractFileFilter
{
private:
	int key;
public:
	IntCryption(int k) { setKey(k); }
	char transform(char ch);
	void setKey(int k = 1) { key = k; }
};

/***************************
**  IntCryption.cpp
***************************/
char IntCryption::transform(char ch)
{
	return (ch + key);
}



/***************************
**  FileFilter.cpp
***************************/
// include <iostream>

int main()
{
	char inFileName[80], outFileName[80], encryptFileName[80];
	int key;
	std::cout << "Enter name of file to filter: ";
	std::cin >> inFileName;
	std::cout << "Enter name of file to receive the filtered text: ";
	std::cin >> outFileName;
	std::cout << "Enter name of file to receive the encrypted text: ";
	std::cin >> encryptFileName;
	std::cout << "Enter an integer to use as the key (if decrypting use the negative key):";
	std::cin >> key;

	// open the files ... the are passed as arguments to the class' public functions in this implementation
	std::ifstream inFile(inFileName);
	std::ofstream outFile(outFileName);
	std::ofstream encryptFile(encryptFileName);

	// Create a ToUpperFilter object
	ToUpperFilter upperCaseIt;
	upperCaseIt.doFilter(inFile, outFile);
	inFile.clear();
	inFile.seekg(0L, std::ios::beg);

	// Create an IntCryption object
	IntCryption encryptIt(key);
	encryptIt.doFilter(inFile, encryptFile);
	inFile.clear();

	std::cout << "Okay we should be good!";

	inFile.close();
	outFile.close();
	encryptFile.close();

	std::cin.ignore(10, '\n');
	std::cin.get();

	return 0;
}