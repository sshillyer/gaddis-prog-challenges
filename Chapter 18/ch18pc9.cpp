/*********************************************************************
** Author: Shawn S Hillyer
** Date: August 6, 2015

9. File Reverser
Write a program that opens a text file and reads its contents into a stack of characters. The
program should then pop the characters from the stack and save them in a second text file.
The order of the characters saved in the second file should be the reverse of their order in
the first file.
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <stack>

int main()
{
	std::string inFileName, outFileName;
	// Get input and output file names
	std::cout << "Input filename to read: " << std::endl;
	std::getline(std::cin, inFileName);
	std::cout << "Input filename to write to: " << std::endl;
	std::getline(std::cin, outFileName);

	// Open the files now, check they opened okay
	std::fstream inFile(inFileName.c_str(), std::ios::in);
	if (!inFile) {
		std::cout << "Error opening file \'" << inFileName << "\'" << std::endl;
		exit(1);
	}
	std::fstream outFile(outFileName.c_str(), std::ios::out);
	if (!outFile) {
		std::cout << "Error opening file \'" << outFileName << "\'" << std::endl;
		exit(1);
	}

	// Make a stack to put all of the characters on. Dynamic stack using STL since we don't know file size ahead of time
	char currentChar;
	std::stack< char > chStack;
	currentChar = inFile.get();
	while (currentChar != EOF) // or just do a 
	{
		chStack.push(currentChar);
		std::cout << "Pushing " << currentChar << std::endl;
		currentChar = inFile.get();
	}  // Should have all of the characters stacked up, if we pop them off the will be in reverse order...
	// Close file and start getting them, popping them off stack, and writing to outFile object
	inFile.close();

	
	while (!chStack.empty())
	{
		currentChar = chStack.top();
		chStack.pop();
		outFile.put(currentChar);
	} // Should stop once the stack is empty
	outFile.close();

	std::cout << "Okay, now go check your files to make sure I didn't insert a virus!" << std::endl;

	std::cin.get();
	return 0;
}