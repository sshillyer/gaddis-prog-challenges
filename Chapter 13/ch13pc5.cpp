
/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 24, 2015
** Description: ch13pc5.cpp
Problem solution from Gaddis C++

5. String Search
Write a program that asks the user for the name of a file and a string to search for. The
program will search the file for all occurrences of the specified string and display all lines
that contain the string. After all occurrences have been located, the program should report
the number of times the string appeared in the file.

*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string fileName, searchStr, currentLine;

	// Get file name
	std::cout << "Enter a filename: " << std::endl;
	std::getline(std::cin, fileName);

	// Get search string
	std::cout << "Enter the search string to find in the file: " << std::endl;
	std::getline(std::cin, searchStr);
	/*
	There's a bug here, you have to type the searchStr twice... first input is discarded and not sure why/how.
	*/


	// Open the file for reading
	std::fstream file(fileName.c_str(), std::ios::in);

	// Set up counters
	int totalWordCount = 0, lineNumber = 0;


	std::getline(std::cin, searchStr);

	while (file)
	{
		// Go to the first element of the string, start a counter for this line, and search
		int pos = 0; // ensure the .find() call starts at element 0
		int lineWordCount = 0;
		pos = currentLine.find(searchStr, pos);

		while (pos != std::string::npos)
		{
			lineWordCount++;
			// move past last found occurence as long as it doesn't exceed string boundaries
			int nextPos = pos + searchStr.length();

			if (nextPos < static_cast<int>(currentLine.length()))
			{
				pos = currentLine.find(searchStr, nextPos);
			}
			else
			{
				pos = std::string::npos;
			}
		}

		// print the line if our search was found and add the totla number of times
		if (lineWordCount > 0)
		{
			std::cout << lineNumber << ": " << currentLine << std::endl;
			totalWordCount += lineWordCount;
		}
		lineNumber++;
		// get next line
		std::getline(file, currentLine); // controls the main while loop
	}
	std::cout << "The string \"" << searchStr << "\" was found " << totalWordCount << " time(s) in the file << " << fileName << "." << std::endl;

	std::cin.get();
	return 0;
}