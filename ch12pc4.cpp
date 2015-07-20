/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 16, 2015
** Description: ch12pc4.cpp
Problem solution from Gaddis C++

4. Vowels and Consonants
Write a function that accepts a C-string as its argument. The function should count the
number of vowels appearing in the string and return that number.
Write another function that accepts a C-string as its argument. This function should count
the number of consonants appearing in the string and return that number.

Demonstrate the two functions in a program that performs the following steps:
1. The user is asked to enter a string.
2. The program displays the following menu:
A) Count the number of vowels in the string
B) Count the number of consonants in the string
C) Count both the vowels and consonants in the string
D) Enter another string
E) Exit the program
3. The program performs the operation selected by the user and repeats until the user
selects E, to exit the program.
*********************************************************************/

#include <iostream>
#include <cctype>

// Function prototypes
void printMenu();
int countVowels(char*);
bool isVowel(char charValue);
int countConsonants(char*);
bool isConsonant(char charValue);
char getInput();


int main()
{
	const int STR_LENGTH = 81;
	char myString[STR_LENGTH];

	std::cout << "Please enter a string of up to " << STR_LENGTH - 1 << " characters: " << std::endl;
	std::cin.getline(myString, STR_LENGTH);

	char input;
	do
	{
		printMenu();
		input = getInput();
		switch (input)
		{
		case 'A':	std::cout << "Number of vowels: " << countVowels(myString) << std::endl;
			break;
		case 'B':	std::cout << "Number of consonants: " << countConsonants(myString) << std::endl;
			break;
		case 'C':	std::cout << "Vowels: " << countVowels(myString) << std::endl << "Consonants: " << countConsonants(myString) << std::endl;
			break;
		case 'D':	std::cout << "Please enter a new string: " << std::endl;
			std::cin.ignore(80, '\n');
			std::cin.getline(myString, STR_LENGTH);
			std::cout << "The new string is: " << std::endl;
			std::cout << myString << std::endl << std::endl;
			break;
		case 'E':	std::cout << "Exiting..." << std::endl << std::endl;
		}
	} while (input != 'E');
	return 0;
}

void printMenu()
{
	std::cout << "A) Count the number of vowels in the string" << std::endl;
	std::cout << "B) Count the number of consonants in the string" << std::endl;
	std::cout << "C) Count both the vowels and consonants in the string" << std::endl;
	std::cout << "D) Enter another string" << std::endl;
	std::cout << "E) Exit the program" << std::endl;
}

int countVowels(char inputString[])
{
	int pos = 0, vowelCount = 0;

	while (inputString[pos] != '\0')
	{
		if (isVowel(inputString[pos]))
		{
			vowelCount++;
		}
		pos++;
	}
	return vowelCount;
}

bool isVowel(char charValue)
{
	bool isVowel = false;
	char charCheck = toupper(charValue);

	if (charCheck == 'A' || charCheck == 'E' || charCheck == 'I' || charCheck == 'O' || charCheck == 'U')
	{
		isVowel = true;
	}
	return isVowel;
}

int countConsonants(char inputString[])
{
	int pos = 0, consonantCount = 0;

	while (inputString[pos] != '\0')
	{
		if (isConsonant(inputString[pos]))
		{
			consonantCount++;
		}
		pos++;
	}
	return consonantCount;
}

bool isConsonant(char charValue)
{
	bool isConsonant = false;
	if (isalpha(charValue) && !isVowel(charValue))
	{
		isConsonant = true;
	}
	return isConsonant;
}

char getInput()
{
	char input;
	do {
		std::cin.get(input);
		input = toupper(input);
	} while (input < 'A' || input > 'E');
	return input;
}