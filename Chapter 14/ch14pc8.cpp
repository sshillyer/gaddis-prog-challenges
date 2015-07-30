/*
Ackermann's function

tested and working just need to document the code fully... assignment pretty much gives answer
*/
#include <iostream>

long long A(int m, int n)
{
	if (m == 0)
	{
		return n + 1;
	}
	if (n == 0)
	{
		return A(m - 1, 1);
	}
	else
	{
		return A(m - 1, A(m, n - 1));
	}
}

// Print is used to quickly format the output from the function given any input; since A(m,n) returns an int, can just plug it into print

void print(long long num)
{
	std::cout << "Result is " << num << std::endl;
}

int main()
{
	print(A(0, 0));
	print(A(0, 1));
	print(A(1, 1));
	print(A(1, 2));
	print(A(1, 3));
	print(A(2, 2));
	print(A(3, 2));
	print(A(3, 3));
	print(A(3, 4));
	print(A(3, 0));
//	print(A(4, 4)); crashes the program... seems anything higher than 3,4, or anything with 4,1->infinity
	std::cin.get();
	return 0;
}