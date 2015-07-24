/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 22, 2015
** Description: ch12pc16.cpp
Problem solution from Gaddis C++

16. Pig Latin
Write a program that reads a sentence as input and converts each word to “Pig Latin.” In
one version, to convert a word to Pig Latin you remove the first letter and place that letter
at the end of the word. Then you append the string “ay” to the word. Here is an example:
English: I SLEPT MOST OF THE NIGHT
Pig Latin: IAY LEPTSAY OSTMAY FOAY HETAY IGHTNAY

*********************************************************************/

#include <iostream>
#include <string>
#include <cctype>

std::string toPigLatin(const std::string& pigStr)
{
	int pigStrLength = pigStr.length();
	const std::string pigTail = "ay";
	std::string newString = "";
	// declare bool atfirstwordofcar = true ?? not sure if needed..
	char firstCharOfWord = pigStr[0], currentChar = pigStr[0], priorChar = ' ', nextChar = pigStr[1];

	for (int i = 0; i < pigStrLength; i++)
	{
		currentChar = pigStr[i];
		if (i + 1 < pigStrLength) {
			nextChar = pigStr[i + 1];
		}
		else if (i + 1 == pigStrLength) {
			nextChar = ' ';
		}
		if (isalpha(currentChar))
		{
			if (!isalpha(priorChar)) // if prior character is not a letter
			{
				// then it's the first letter of a word
				if (!isalpha(nextChar))
				{
					// if next character is not a letter either, then this is a 1 letter word
					newString.append(1, currentChar);
					newString.append(pigTail);
				}
				else // next character is a letter
				{
					// then this is the first letter of a multiletter word, store it for letter but do not append to newString
					firstCharOfWord = currentChar; // 
				}
			}
			else // priorChar is a letter
			{
				if (isalpha(nextChar))
				{
					// if the next character is a letter, then currentChar is just the middle of a word
					newString.append(1, currentChar);
				}
				else // then next character is not a letter, therefore this is the end of a word
				{
					newString.append(1, currentChar);
					newString.append(1, firstCharOfWord);
					newString.append(pigTail);
				}
			}
		}
		else // current char is not a letter
		{
			// then we just append the non-letter character
			newString.append(1, currentChar);
		}
		priorChar = currentChar;
	} // end of loop through array
	return newString;
}




// TEST CLIENT


int main()
{
	std::string testString = "My master taught me to speak pig latin! What a joy! :)";
	std::cout << testString << std::endl;
	std::string newString = toPigLatin(testString);
	std::cout << newString << std::endl;
	std::cout << "Type some words, press enter, and I shall show you my skills:" << std::endl;
	std::getline(std::cin, testString);
	std::cout << toPigLatin(testString) << std::endl;

	std::cin.get();
}