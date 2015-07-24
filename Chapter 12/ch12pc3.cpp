/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 16, 2015
** Description: ch12pc3.cpp
Problem solution from Gaddis C++

  BONUS: Also includes a capWords function that will capitalize first
  letter of all words in string.
  
3. Sentence Capitalizer
Write a function that accepts a C-string as an argument and capitalizes the first character of
each sentence in the string. For instance, if the string argument is “hello. my name is Joe.
what is your name?” the function should manipulate the string so it contains “Hello. My
name is Joe. What is your name?” Demonstrate the function in a program that asks the
user to input a string and then passes it to the function. The modified string should be
displayed on the screen.
*********************************************************************/

#include <iostream>
#include <cctype>

// Function Prototype(s)
void capWords(char*);
void capSentences(char*);

int main()
{
	const int STR_LENGTH = 80;
	char cString[STR_LENGTH];

	std::cout << "Enter a string of no more than " << STR_LENGTH - 1 << " characters: " << std::endl;
	std::cin.getline(cString, STR_LENGTH);

	capSentences(cString);

	std::cout << "There new string is: " << std::endl;
	std::cout << cString;

//	std::cin.get();

	return 0;
}

void capWords(char inputString[])
{
	int pos = 0; // start at first index of the c string
	char lastChar = ' '; // ensures we capitalize first letter

	// iterate over the string until we reach null terminator
	while (inputString[pos] != '\0')
	{
		//finds letters preceded by a space or punctuation.
		if ((isspace(lastChar) || ispunct(lastChar)) && isalpha(inputString[pos]))
		{
			inputString[pos] = toupper(inputString[pos]);
		}
		// set lastChar to char at current index, increment index
		lastChar = inputString[pos];
		pos++;
	}
	std::cout << std::endl;
	// return newString;  // I think char array is passed by reference automatically like a normal array...
}

void capSentences(char inputString[])
{
	int pos = 0; // start at first index of the c string
	bool capNext = true;

	// iterate over the string until we reach null terminator
	while (inputString[pos] != '\0')
	{
		if (capNext && isalpha(inputString[pos]))
		{
			inputString[pos] = toupper(inputString[pos]);
			capNext = false;
		}
		else if (inputString[pos] == '.') // if curent character is a period
		{
			capNext = true;
		}
		// during each loop, it will capitalize the next character encountered after a period.
		// once it does that, nothing should be capitalized again until another period is found

		pos++;
	}
	std::cout << std::endl;
	// return newString;  // I think char array is passed by reference automatically like a normal array...
}