/* 2. Recursive Conversion
Convert the following function to one that uses recursion.
void sign(int n)
{
while (n > 0)
{
cout << "No Parking\n";
n--;
}
}
Demonstrate the function with a driver program. */
#include <iostream>

void recursiveSign(int n)
{
	if (n == 0)
	{
		return;
	}
	else
	{
		recursiveSign(n - 1);
		std::cout << "No Parking " << n << std::endl;
	}

}

void sign(int n)
{
	while (n > 0)
	{
		std::cout << "No Parking" << n << std::endl;
		n--;
	}
}

int main()
{
	int n;
	std::cout << "Enter number: ";
	std::cin >> n;

	std::cout << "Executing iterative sign(n): " << std::endl;
	sign(n);
	std::cout << "Executing recursiveSign(n): " << std::endl;
	recursiveSign(n);

	std::cin.ignore();
	std::cin.get();
	return 0;
}