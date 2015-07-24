
/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 23, 2015
** Description: ch13pc4.cpp
Problem solution from Gaddis C++

4. Tail of a File
Write a program that asks the user for the name of a text file. The program should display
the last 10 lines of the file on the screen (the “tail” of the file). If the file has less than 10
lines, the entire file is displayed, with a message that the entire file has been displayed. The
program should do this by seeking to the end of the file and then backing up to the tenth
line from the end.

*********************************************************************/
#include <iostream>
#include <string>
#include <fstream>

void printTail(const std::string& fileName, const int tailsize);

int main()
{
	std::string fileName;
	std::getline(std::cin, fileName);

	printTail(fileName, 10);


	std::cin.get();
	return 0;
}

void printTail(const std::string& fileName, const int tailsize)
{
	// open the file
	std::fstream file(fileName.c_str(), std::ios::in);
	std::cout << "File opening..." << std::endl;
	if (!file) std::cout << "Error opening flie!" << std::endl;
	// go to the end of the file
	file.seekg(-1L, std::ios::end);
	std::cout << "Seeking to end of file..." << std::endl;
	// read backwards one byte at a time until we reach newline
	char ch = file.peek();
	std::cout << "Peeking at last pos - 1: " << ch << std::endl;
	int lineCount = 0;
	std::string currentLine;
	bool readFullFile = false;
	long int pos = file.tellg();
	std::cout << "Pos holds value: " << pos << std::endl;

	while ((lineCount <= tailsize) && pos > 0) // break out after reading 'tailsize' lines or reaching beginning of file
	{
		while (ch != '\n'  && pos > 0)
		{
			file.seekg(-static_cast<int>((sizeof(char))), std::ios::cur); // move to the previous pos in file
			ch = file.peek();
			std::cout << "Peek during inner while loop: " << ch << std::endl;
			pos = file.tellg();
			std::cout << "Pos: " << pos << std::endl;
		}
		lineCount++;
		// move back one more byte to get off of the \n and move forward in loop?? this might work...
		if (pos > 0)
			file.seekg(-static_cast<int>((sizeof(char))), std::ios::cur);
		ch = file.peek();
	}

	if (lineCount < tailsize)
	{
		readFullFile = true;
	}
	std::cout << "Hi you made it psat the if statement!" << std::endl;
	std::cout << ".tellg() says we're at: " << file.tellg() << std::endl;
	// move forward off the \n one byte and grab the strings until EOF
	lineCount = 0;
	// file.seekg(sizeof(char), std::ios::cur);

	//while (std::getline(file, currentLine))
	for (int i = 0; i < 10; i++)
	{
		std::getline(file, currentLine);
		std::cout << lineCount << ": " << currentLine << std::endl;
		lineCount++;
	}

	if (readFullFile)
		std::cout << "Entire contents of file are displayed." << std::endl;
}