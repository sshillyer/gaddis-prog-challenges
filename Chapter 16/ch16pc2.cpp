/*
2. Arithmetic Exceptions
Write a function that accepts an integer parameter and returns its integer square root. The
function should throw an exception if it is passed an integer that is not a perfect square.
Demonstrate the function with a suitable driver program.
*/
#include <cmath>
#include <iostream>
#include <string>

int sqrRoot(int x)
{
	int squareRoot = sqrt(static_cast<double>(x));
	if ((squareRoot*squareRoot % x) != 0) {
		throw std::string("Not a perfect square.");
	}
	return squareRoot;
}

int main(int argc, char const *argv[])
{
	try
	{
		std::cout << "Square root of 9 is: " << sqrRoot(9) << std::endl;
		std::cout << "Square root of 10 is: " << sqrRoot(10) << std::endl;
		std::cin.get();
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage;
	}


	std::cin.get();
	return 0;
}