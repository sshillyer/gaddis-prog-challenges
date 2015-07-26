
/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 23, 2015
** Description: ch13pc9.cpp
Problem solution from Gaddis C++

9. Letter Frequencies
The letter e is the most frequently used letter in English prose, and the letter z is the least
frequently used. A friend of yours doing a sociology experiment believes that this may not
necessarily be true of the writings of first-year college students. To test his theory, he asks
you to write a program that will take a text file and print, for each letter of the English
alphabet, the number of times the letter appears in the file.
Hint: Use an integer array of size 128, and use the ASCII values of letters to index into the
array to store and retrieve counts for the letters.

*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
int main()
{
	// Get File Names
	std::string inFileName, outFileName;
	std::cout << "Enter file name to count vowels: " << std::endl;
	std::getline(std::cin, inFileName);
	std::cout << "Enter file name to store results: " << std::endl;
	std::getline(std::cin, outFileName);

	// Set up array to store counts of each ascii value
	const int INDEX_SIZE = 127;
	int charCounter[INDEX_SIZE] = {0};
	/***********
	verify the string is initialized
	for (int i = 0; i < INDEX_SIZE; i++)
	{
		std::cout << charCounter[i] << " ";
	}
	std::cout << std::endl;
	**************/

	// Open read file
	std::fstream readFile(inFileName.c_str(), std::ios::in);

	if (!readFile) {
		std::cout << "Error opening file " << inFileName << ". Terminating." << std::endl;
		return 1;
	}

	char ch;
	int i;
	ch = readFile.get();
	while (ch != EOF)
	{
		i = ch;
		charCounter[i]++;
		ch = readFile.get();
	}


	std::fstream outFile(outFileName.c_str(), std::ios::out);

	// DEBUG COUT:
	for (int i = 32; i < INDEX_SIZE; i++)
	{
		ch = i;
		outFile << ch << ": " << charCounter[i] << std::endl; // change this to write to the file
	}
	std::cout << std::endl;
	// END DEBUG

	return 0;
}