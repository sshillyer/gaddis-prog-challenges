/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 17, 2015
** Description: ch12pc7.cpp
Problem solution from Gaddis C++

7. Most Frequent Character
Write a function that accepts either a pointer to a C-string, or a string object, as its
argument. The function should return the character that appears most frequently in the
string. Demonstrate the function in a complete program.
*********************************************************************/
#include <iostream>
#include <cctype>


char mostCommonChar(char* cString);


int main()
{
	char myString[100];

	std::cout << "Enter a string and I will tell you the most common character (case sensitive): " << std::endl;
	std::cin.getline(myString, 100);

	char mostCommon;

	mostCommon = mostCommonChar(myString);

	std::cout << "Most common character is \'" << mostCommon << "\'" << std::endl;

	std::cin.get();

	return 0;
}



char mostCommonChar(char* cString)
{
	int length = strlen(cString);
	int maxCount = 0;
	char result = cString[0];

	// initialize the new array with 0... is there a better way to do this?
	int* charCount = new int [length]; // used to count number of times a character occurs
	for (int i = 0; i < length; ++i)
	{
		charCount[i] = 0;
	}

	// check every element of the string to grab its character, see if its already
	// been counted by checking the paralell array for a val greater than 0, and 
	// then searching the rest of the array if it has not been counted already
	for (int i = 0; i < length; ++i)
	{
		// if the current character hasn't been counted, then we will search rest of the array
		if (charCount[i] == 0)
		{
			// set the value we're going to search for and set counter to 1 to count the first element
			char searchValue = cString[i]; /* if want non-case sentive, change to    
			char searchValue = toupper(cString[i]); */
			int counter = 1;  

			// only need to search from current index + 1 to end - we know cString[i] == cString[i]
			for (int j = i + 1; j < length; j++)
			{
				if (cString[j] == searchValue) /* if want non-case sentive, change to    
				if (toupper(cString[j] == searchValue) */
				{
					counter++;
					charCount[j] = -1; // to indicate that it's been counted
				}
			}
			charCount[i] = counter;
			if (charCount[i] > maxCount)
			{
				maxCount = charCount[i];
				result = searchValue;
			}
		}
	}
	std::cout << "Debug: " << std::endl;
	for (int i = 0; i < length; i++)
	{
		std::cout << charCount[i] << " ";
	}
	return result;
}