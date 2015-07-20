/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 17, 2015
** Description: ch12pc5.cpp
Problem solution from Gaddis C++
 **Need to test with a non-MS Visual Studio compiler, says strcat is deprecated

5. Name Arranger
Write a program that asks for the user’s first, middle, and last names. The names should be
stored in three different character arrays. The program should then store in a fourth array
the name arranged in the following manner: the last name followed by a comma and a
space, followed by the first name and a space, followed by the middle name. For example,
if the user entered “Carol Lynn Smith”, it should store “Smith, Carol Lynn” in the
fourth array. Display the contents of the fourth array on the screen.
*********************************************************************/

#include <iostream>
#include <cctype>

int main()
{
	const int FIRSTN_SIZE = 18, LASTN_SIZE = 25, MIDDLEN_SIZE = 25, FULLNAME_SIZE = 72;
	char firstName[FIRSTN_SIZE], middleName[MIDDLEN_SIZE], lastName[LASTN_SIZE], fullName[FULLNAME_SIZE];

	std::cout << "Enter your first name (" << FIRSTN_SIZE - 1 << " characters or less): " << std::endl;
	std::cin.getline(firstName, FIRSTN_SIZE);

	std::cout << "Enter your middle name (" << MIDDLEN_SIZE - 1 << " characters or less): " << std::endl;
	//std::cin.ignore(20, '\n');
	std::cin.getline(middleName, MIDDLEN_SIZE);

	std::cout << "Enter your last name (" << LASTN_SIZE - 1 << " characters or less): " << std::endl;
	//std::cin.ignore(20, '\n');
	std::cin.getline(lastName, LASTN_SIZE);

	std::cout << "Your name is: " << firstName << " " << middleName << " " << lastName << std::endl; // output test

	strcat(fullName, lastName);
	strcat(fullName, ", ");
	strcat(fullName, firstName);
	strcat(fullName, " ");
	strcat(fullName, middleName);

	std::cout << "Your formatted name is: " << fullName << std::endl;

	std::cin.get();

	return 0;
}