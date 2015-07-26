
/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 23, 2015
** Description: ch13pc6.cpp
Problem solution from Gaddis C++

6. Sentence Filter
A program that processes an input file and produces an output file is called a filter.
Write a program that asks the user for two file names. The first file will be opened for
input, and the second file will be opened for output. (It will be assumed that the first file
contains sentences that end with a period.) The program will read the contents of the
first file and change all the letters other than the first letter of sentences to lowercase.
First letter of sentences should be made uppercase. The revised contents should be
stored in the second file.

*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main()
{
	// Get file names for in / out
	std::string inFileName, outFileName;
	std::cout << "Enter file input name: ";
	std::getline(std::cin, inFileName);
	std::cout << "Enter file output name: ";
	std::getline(std::cin, outFileName);

	// Open the files for input and output

	std::fstream readFile(inFileName.c_str(), std::ios::in);
	std::fstream writeFile(outFileName.c_str(), std::ios::out);

	// Verify opened okay
	if (!readFile) {
		std::cout << "Error opening file \'" << inFileName << "\' for reading." << std::endl;
		return 1;
	}
	if (!writeFile) {
		std::cout << "Error opening file \'" << inFileName << "\' for writing." << std::endl;
		return 1;
	}

	// Assume first alpha character is the first word of a sentence
	bool capNextWord = true;
	// Now process rest of the file until EOF is reached, getting each char from readFile and putting it to writeFile
	char ch = readFile.get();
	while (ch != EOF)
	{
		if (capNextWord && isalpha(ch)) {
			if (islower(ch)) {
				ch = toupper(ch);
			}
			writeFile.put(ch);
			capNextWord = false;
		}
		else {
			if (isupper(ch)) {
				ch = tolower(ch);
			}
			writeFile.put(ch);
		}
		if (ch == '.') {
			capNextWord = true;
		}
		ch = readFile.get();
	}

	//std::cin.get();
	return 0;
}