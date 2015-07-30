/*
1. Iterative Factorial
Write an iterative version (using a loop instead of recursion) of the factorial function
shown in this chapter. Demonstrate the use of the function in a program that prints the
factorial of a number entered by the user.

int factorial(int num)
{
if (num == 0) // base case
return 1;
else
return num * factorial(num – 1);
}

*/
#include <iostream>

int factorial(int num)
{
	int factorial = 1;
	for (int i = 1; i <= num; i++)
	{
		factorial = (factorial * i);
	}

	return factorial;
}

int main()
{
	for (int n = 0; n<10; n++)
	{
		std::cout << "Factorial of " << n << ": " << factorial(n) << std::endl;
	}

	std::cin.get();
	return 0;
}