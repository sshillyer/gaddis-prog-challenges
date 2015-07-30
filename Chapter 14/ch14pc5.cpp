/* 5. Recursive Multiplication
Write a recursive function that accepts two arguments into the parameters x and y. The
function should return the value of x times y. Remember, multiplication can be performed
as repeated addition:
7 * 4 = 4 + 4 + 4 + 4 + 4 + 4 + 4

*/
// This program works as long as y is not negative. Could switch the negative over to the x
// if only y is negative, or make both positive if both are negative, and itwould probably work
// for any int pair
#include <iostream>

int recMult(int x, int y)
{
	if (x == 0 || y == 0)
	{
		return 0; // AnyI number multiplied by 0 is zero
	}
	else if (y == 1)
	{
		return x; // Identity property states that any number times 1 is == to itself
	}
	else if (x == 1)
	{
		return y; // identity property for the other input
	}
	else
	{
		return x + recMult(x, y - 1); // this is the recursive call
	}
}

int main()
{
	int xVal = 0, yVal = 4;
	int product = recMult(xVal, yVal);
	std::cout << "Product of " << xVal << " and " << yVal << ": " << product << std::endl;

	std::cin.get();
	return 0;
}