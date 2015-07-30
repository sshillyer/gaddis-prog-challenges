/*
7. String Reverser
Write a recursive function that accepts a string as its argument and prints the string in
reverse order. Demonstrate the function in a driver program.
*/

#include <iostream>
#include <string>

void gnirtStnirp(std::string str)
{
	if (str.length() == 0)
	{
		return;
	}
	else
	{
		std::string newStr = "";
		newStr.assign(str, 1, str.length() - 1);
		gnirtStnirp(newStr);
	}
	std::cout << str.at(0);
}

int main()
{
	std::string test;
	std::cout << "Please enter a string, and I will reverse it!" << std::endl;
	std::getline(std::cin, test);

	gnirtStnirp(test);

	std::cin.get();
	return 0;
}