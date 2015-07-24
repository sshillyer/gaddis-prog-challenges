/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 20, 2015
** Description: ch12pc8.cpp
Problem solution from Gaddis C++

9. Case Manipulator
Write a program with three functions: upper, lower, and flip. The upper function
should accept a C-string as an argument. It should step through all the characters in the
string, converting each to uppercase. The lower function, too, should accept a pointer to
a C-string as an argument. It should step through all the characters in the string,
converting each to lowercase. Like upper and lower, flip should also accept a C-string.
As it steps through the string, it should test each character to determine whether it is
upper- or lowercase. If a character is uppercase, it should be converted to lowercase. If a
character is lowercase, it should be converted to uppercase.
Test the functions by asking for a string in function main, then passing it to them in the
following order: flip, lower, and upper.

*********************************************************************/

#include <cctype>
#include <iostream>

void flip(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (isupper(str[i])) {
			str[i] = tolower(str[i]);
		}
		else if (islower(str[i])){
			str[i] = toupper(str[i]);
		}
		i++;
	}
}

void lower(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		str[i] = tolower(str[i]);
		i++;
	}
}

void upper(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		str[i] = toupper(str[i]);
		i++;
	}
}

int main()
{
	const int STR_LENGTH = 100;
	char myString[STR_LENGTH];
	std::cout << "Input a string of no more than " << STR_LENGTH - 1 << " characters: " << std::endl;
	std::cin.getline(myString, STR_LENGTH);

	std::cout << "Your string is: " << std::endl << myString << std::endl;

	flip(myString);
	std::cout << "Cases flipped: " << std::endl << myString << std::endl;
	upper(myString);
	std::cout << "Upper case: " << std::endl << myString << std::endl;
	lower(myString);
	std::cout << "Lower: " << std::endl << myString << std::endl;
	std::cin.ignore();
	std::cin.get();

	return 0;
}