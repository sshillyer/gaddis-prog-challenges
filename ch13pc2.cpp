
/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 23, 2015
** Description: ch13pc2.cpp
Problem solution from Gaddis C++

2. File Display Program
Write a program that asks the user for the name of a file. The program should display the
contents of the file on the screen. If the file’s contents won’t fit on a single screen, the program
should display 24 lines of output at a time, and then pause. Each time the program pauses, it
should wait for the user to type a key before the next 24 lines are displayed.

*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string fileName;
	std::cout << "Enter a filename: (this example is paired with test2.dat): " << std::endl;
	std::getline(std::cin, fileName);
	// Open file for reading
	std::fstream inputFile(fileName.c_str() , std::ios::in);

	std::string currentLine;
	int lineCount = 0;
	while (std::getline(inputFile, currentLine))
	{
		std::cout << currentLine << std::endl;
		lineCount++;
		if (lineCount == 24)
		{
			std::cout << "[Press any key to continue.]";
			std::cin.get();
			lineCount = 0;
		}
	}

	std::cout << "Reached end of file. Closing." << std::endl;
	inputFile.close();

	std::cin.get();

	return 0;
}