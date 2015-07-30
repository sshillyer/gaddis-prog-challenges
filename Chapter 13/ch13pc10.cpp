
/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 28, 2015
** Description: ch13pc10.cpp
Problem solution from Gaddis C++

10. Put It Back
C++ input stream classes have two member functions, unget() and putback(), that can
be used to “undo” an operation performed by the get() function. Research these
functions on the Internet, and then use one of them to rewrite Program 13-9 without using
the peek() function.

*********************************************************************/



#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	// Variables needed to read characters and numbers
	char ch;
	int number;

	// Variables for file handling
	string fileName;
	fstream inFile, outFile;
	
	// Open the file to be modified
	cout << "Enter a file name: ";
	cin >> fileName;
	inFile.open(fileName.c_str(), ios::in);
	if (!inFile)
	{
		cout << "Cannot open file " << fileName;
		return 1;
	}
	
	// Open the file to receive the modified copy
	outFile.open("modified.txt", ios::out);
	if (!outFile)
	{
	cout << "Cannot open the output file.";
	return 2;
	}
	// Copy the input file one character at a time
	// except numbers in the input file must have 1
	// added to them
	// Peek at the first character
	ch = inFile.get();
	while (ch != EOF)
	{
	// Examine current character
	if (isdigit(ch))
	{
		 // Numbers should be read with >>
		inFile.unget();
		inFile >> number;
		outFile << number + 1;
	}
	else
	{
	// Just a simple character, read it and copy it
	outFile << ch;
	}
	// Peek at the next character from input file
	ch = inFile.get();
	}
	// Close the files
	inFile.close();
	outFile.close();
	return 0;
}