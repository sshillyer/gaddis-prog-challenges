
/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 23, 2015
** Description: ch13pc11.cpp
Problem solution from Gaddis C++

11. Insertion Sort on a File I
Write a program that uses an initially empty file to store a sorted list of integers entered by
the user. The integers are stored in binary form. Each time the program is run, it opens the
file and outputs the list of stored integers onto the screen. The program then asks the user to
enter a new integer X. The program then looks at the integer at the end of the file. If that
integer is less or equal to X, the program stores X at the end of the file and closes the file.
Otherwise, the program starts at the end of the file and works toward the beginning, moving
each value in the file that is greater than X up by one until it reaches the position in the file
where X should be stored. The program then writes X at that position and closes the file.

*********************************************************************/

#include <iostream>
#include <fstream>

int main()
{
	std::string outFileName = "integers.dat";
	// Open a file for input, integers.dat, and then read numbers from the user. All in binary...
	std::fstream outFile(outFileName.c_str(), std::ios::out | std::ios::in | std::ios::binary);
	if (!outFile) {
		std::cout << "Error opening " << outFileName << " for output. Terminating."
		return 1;
	}
	const int NUM_COUNT = 10;
	int numbers[NUM_COUNT],
	std::cout << "Enter a series of " << NUM_COUNT << " numbers, seprated by whitespace, to write to file " << outFileName << ": " << std::endl;
	for (int i = 0; i < NUM_COUNT; i++)
	{
		cin >> numbers[i];
	}

	// Print the input to screen before writing it as binary to the file
	std::cout << "You entered: " 
	for (int i = 0; i < NUM_COUNT; i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	// Write the data to the file in a single write() operation.
	long byteSize = sizeof(numbers[0]);
	write(reinterpret_cast<char *>(numbers), sizeof(numbers) );
	outFile.close();

	// Prompt for a new integer
	int newNum;
	std::cout << "Enter another integer to add to file: ";
	std::cin >> newNum;

	//  read last byte of data
	outFile.seekg(-byteSize, std::ios::end);
	int currentNum;
	read(reinterpret_cast<char *>(&currentNum), byteSize);
	
	// as long as the read operation is succesful, keep trying to place the number in the right spot
	while (outFile) 
	{
		if (currentNum > newNum) // if the number at this pos in file is greater than the new number
		{
			// move forward 1 bytesize, write, then move back 2 byteSize
			outFile.seekg(byteSize, std::ios::cur); // move forward one byteSize
			write(reinterpret_cast<char *>(&currentNum); // write the number we just read
			outFile.seekg(-(2*byteSize), std::ios::cur); // move back 2
			read(reinterpret_cast<char *>(&currentNum), byteSize); // read the next number	
		}
		else // the number must be less than or equal to, so we should place the number here
			write(reinterpret_cast<char*>(&newNum), sizeof(newNum)); // I'm not sure if this overwrites the data or "inserts" it here?
	}


	read(reinterpret_cast<char*>(numbers), )

	return 0;
}