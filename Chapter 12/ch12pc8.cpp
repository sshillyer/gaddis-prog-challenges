/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 20, 2015
** Description: ch12pc8.cpp
Problem solution from Gaddis C++

8. replaceSubstring Function
Write a function named replaceSubstring. The function should accept three C-string or
string object arguments. Let’s call them string1, string2, and string3. It should
search string1 for all occurrences of string2. When it finds an occurrence of string2, it
should replace it with string3. For example, suppose the three arguments have the
following values:
string1: "the dog jumped over the fence"
string2: "the"
string3: "that"
With these three arguments, the function would return a string object with the value
“that dog jumped over that fence”. Demonstrate the function in a complete program.

*********************************************************************/
#include <string>
#include <iostream>


std::string replaceAll(const std::string& startStr, const std::string& searchStr, const std::string& replaceStr)
{
	std::string str = startStr;
	int searchStrIndex = 0;
	int searchStrLength = searchStr.length(); // used to offset to correct position for next pass over string
	bool foundMatch = true; // controls execution of while loop
	int p = 0; // position -- when this works, refactor to update its value in the if statement below

	while (foundMatch)
	{
		searchStrIndex = str.find(searchStr, p);
		std::cout << "New value of searchStrIndex: " << searchStrIndex << std::endl;

		if (searchStrIndex && p < str.length()) // I think .find() returns null if it's not found
		{
			str.erase(searchStrIndex, searchStrLength);
			str.insert(searchStrIndex, replaceStr);
			std::cout << str << std::endl;
			std::cout << "Value of searchStrIndex: " << searchStrIndex << std::endl;
			p = searchStrIndex + searchStrLength;
		}

		else // 
		{
			foundMatch = false;
		}
	}
	return str;
}

int main()
{
	std::string string1, searchKey, replace;

	std::cout << "Please type a string to search: " << std::endl;
	std::getline(std::cin, string1);
	std::cout << "Please enter a substring that you will replace: " << std::endl;
	std::getline(std::cin, searchKey);
	std::cout << "Please enter a replacement string: " << std::endl;
	std::getline(std::cin, replace);

	std::string string2 = replaceAll(string1, searchKey, replace);

	std::cout << string2 << std::endl;
	std::cin.get();
}