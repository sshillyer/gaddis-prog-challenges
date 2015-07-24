/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 16, 2015
** Description: ch12pc1.cpp
Problem solution from Gaddis C++

1. Word Counter
Write a function that accepts a C-string as an argument and returns the number of words
contained in the string. For instance, if the string argument is “Four score and seven years
ago” the function should return the number 6. Demonstrate the function in a program that
asks the user to input a string and then passes it to the function. The number of words in
the string should be displayed on the screen.

2. Average Number of Letters
Modify the program you wrote for problem 1 (Word Counter), so it also displays the
average number of letters in each word.
*********************************************************************/

#include <iostream>
#include <cctype>

// Function Prototype(s)
int countWords(char*);

int main()
{
	const int STR_LENGTH = 80;
	char cString[STR_LENGTH];

	std::cout << "Enter a string of no more than " << STR_LENGTH - 1 << " characters: " << std::endl;
	std::cin.getline(cString, STR_LENGTH);

	int wordCount = countWords(cString);

	std::cout << "There are " << wordCount << " words in the string you entered." << std::endl;

	std::cin.get();

	return 0;
}

int countWords(char* inputString)
{
	int wordCount = 0, pos = 0, letterCount = 0;
	double lettersPerWord;
	char lastChar = ' '; // use of inputString[pos-1] would be error for pos = 0, so used this as easy error-proofing

	while (inputString[pos] != '\0')
	{
		if ((isspace(lastChar) || ispunct(lastChar)) && isalpha(inputString[pos]))
		{
			// If prior character is space or punctuation and current character is alphabetic, we have reached a new word
			wordCount++;
		}

		if (isalpha(inputString[pos]))
		{
			// For #3, we need to count how many letters occur to get average letters per word
			letterCount++;
		}

		lastChar = inputString[pos];
		pos++; // move to nextz position
	} // ends when we reach the null terminator

	std::cout << "Letters counted: " << letterCount << std::endl;
	lettersPerWord = static_cast<double>(letterCount) / wordCount;
	std::cout << "Letters per word: " << lettersPerWord << std::endl;
	return wordCount;
}