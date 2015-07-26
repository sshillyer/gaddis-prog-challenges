
/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 23, 2015
** Description: ch13pc8.cpp
Problem solution from Gaddis C++

8. File Decryption Filter
Write a program that decrypts the file produced by the program in Programming Challenge 7.
The decryption program should read the contents of the coded file, restore the information
to its original state, and write it to another file.
9.

*********************************************************************/


/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 23, 2015
** Description: ch13pc7.cpp
Problem solution from Gaddis C++

7. File Encryption Filter
File encryption is the science of writing the contents of a file in a secret code. Your
encryption program should work like a filter, reading the contents of one file, modifying
the information into a code, and then writing the coded contents out to a second file. The
second file will be a version of the first file, but written in a secret code.
Although there are complex encryption techniques, you should come up with a simple one
of your own. For example, you could read the first file one character at a time and add 10
to the ASCII code of each character before it is written to the second file

*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main()
{
	// Get file names for in / out
	std::string inFileName, outFileName;
	std::cout << "Enter file to decrypt name: ";
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
		ch -= 10;
		writeFile.put(ch);
		ch = readFile.get();
	}

	//std::cin.get();
	return 0;
}