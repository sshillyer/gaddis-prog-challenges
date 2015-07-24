/****************************************************************************************
11. Phone Number List
Write a program that has an array of at least 10 string objects that hold people’s names
and phone numbers. You may make up your own strings or use the following:
"Becky Warren, 678-1223"
"Joe Looney, 586-0097"
"Geri Palmer, 223-8787"
"Lynn Presnell, 887-1212"
"Holly Gaddis, 223-8878"
"Sam Wiggins, 486-0998"
"Bob Kain, 586-8712"
"Tim Haynes, 586-7676"
"Warren Gaddis, 223-9037"
"Jean James, 678-4939"
"Ron Palmer, 486-2783"
The program should ask the user to enter a name or partial name to search for in the
array. Any entries in the array that match the string entered should be displayed. For
example, if the user enters “Palmer” the program should display the following names
from the list:
Geri Palmer, 223-8787
Ron Palmer, 486-2783
****************************************************************************************/
#include <iostream>
#include <string>

void printStrArray(const std::string* strArray, const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << strArray[i] << std::endl;
	}

}

void printArrayEle(const std::string* strArray, const unsigned index)
{
	std::cout << strArray[index] << std::endl;
}

void searchStrArray(const std::string* strArray, const int size, std::string searchValue)
{
	for (unsigned i = 0; i < static_cast<unsigned>(size); i++)
	{
		int searchResult = strArray[i].find(searchValue);
		std::cout << "Iteration " << i << " find result: " << searchResult << std::endl;
		if (searchResult >= 0 && searchResult < size)
		{
			printArrayEle(strArray, i);
		}
	}
}

int main()
{
	const int ARRAY_SIZE = 11;
	std::string contacts[] = { "Becky Warren, 678-1223",
		"Joe Looney, 586-0097",
		"Geri Palmer, 223-8787",
		"Lynn Presnell, 887-1212",
		"Holly Gaddis, 223-8878",
		"Sam Wiggins, 486-0998",
		"Bob Kain, 586-8712",
		"Tim Haynes, 586-7676",
		"Warren Gaddis, 223-9037",
		"Jean James, 678-4939",
		"Ron Palmer, 486-2783" };
	/*
	printStrArray(contacts, ARRAY_SIZE);
	*/
	std::string findThis = "Palmer";
	searchStrArray(contacts, ARRAY_SIZE, findThis);

	std::cin.get();

	return 0;
}