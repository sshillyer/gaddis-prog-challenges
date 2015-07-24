/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 23, 2015
** Description: ch13pc1.cpp
Problem solution from Gaddis C++

1. File Previewer
Write a program that asks the user for the name of a text file. The program should
display the first 10 lines of the file on the screen. If the file has fewer than 10 lines, the
entire file should be displayed along with a message indicating the entire file has been
displayed.
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string fileName, currentLine;

	std::cout << "Please input a file name to read: " << std::endl;
	std::getline(std::cin, fileName);
	// for testing, forcing override:
	//fileName = "test.dat";

	// Open the filename (passed as a c string) for reading input
	std::fstream readFile(fileName.c_str(), std::ios::in);
	if (!readFile)
	{
		std::cout << "Did not read file." << std::endl;
		return 0;
	}

	// Read input until we reach EOF or 10 lines of data
	int counter = 0;
	while (std::getline(readFile, currentLine) && counter < 10)
	{
		std::cout << currentLine << std::endl;
		counter++;
	}

	if (std::getline(readFile, currentLine)) { // if there are more lines we can read
		std::cout << std::endl << "Read 10 lines. There are more lines in the file." << std::endl;
	}
	else { // otherwise we read 10 or less lines and there is no more data to read
		std::cout << std::endl << "Read entire file." << std::endl;
	}


	// close file
	readFile.close();

	std::cin.get();

	return 0;
}