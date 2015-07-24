// Page 150 - Ch4 PC 1
/*
1. Minimum/Maximum
Write a program that asks the user to enter two numbers. The program should use the
conditional operator to determine which number is the smaller and which is the larger.
*/
#include <iostream>

int main()
{
	double num1, num2, max, min;
	std::cout << "Enter two numbers separated by a space and press enter." << std::endl;

	std::cin >> num1 >> num2;

	if (num1 > num2) {
		max = num1;
		min = num2;
	}
	else {
		max = num2;
		min = num1;
	}

	std::cout << "Bigger number is " << max << " and lesser number is " << min << "." << std::endl;

	return 0;
}