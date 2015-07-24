/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 21, 2015
** Description: ch12pc15.cpp
Problem solution from Gaddis C++

15. Word Separator
Write a program that accepts as input a sentence in which all of the words are run together, but
the first character of each word is uppercase. Convert the sentence to a string in which the words
are separated by spaces and only the first word starts with an uppercase letter. For example the
string “StopAndSmellTheRoses.” would be converted to “Stop and smell the roses.”
*********************************************************************/

#include <cctype>
#include <string>
#include <iostream>

std::string camelBreaker(const std::string& camelStr)
{
	int strLength = camelStr.length();
	std::string newStr = "";

	if (strLength != 0)
	{
		newStr.append(1, toupper(camelStr[0]));
		for (int i = 1; i < strLength; i++)
		{
			if (isupper(camelStr[i]))
			{
				newStr.append(" ");
				newStr.append(1, tolower(camelStr[i]));
			}
			else
			{
				newStr.append(1, camelStr[i]);
			}
		}
	}
	return newStr;
}

int main()
{
	std::string aCamelString = "ThisIsAStringInCamelCase.WhatDoYouThink?";
	std::cout << "Testing a camelcase string: " << std::endl << aCamelString << std::endl;
	std::string aSentenceString = camelBreaker(aCamelString);
	std::cout << "Now in sentence form: " << std::endl << aSentenceString << std::endl;

	std::cin.get();
	return 0;
}