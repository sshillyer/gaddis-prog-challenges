/*
3. Min/Max Templates
Write templates for the two functions min and max. min should accept two arguments and
return the value of the argument that is the lesser of the two. max should accept two
arguments and return the value of the argument that is the greater of the two. Design a
simple driver program that demonstrates the templates with various data types.
*/

#include <string>
#include <iostream>

template <class T>
T min(T a, T b)
{
	if (a < b)
		return a;
	if (b < a)
		return b;
	else
		// throw an exception
		return a;
}

template <class T>
T max(T a, T b)
{
	if (a > b)
		return a;
	if (b > a)
		return b;
	else
		// throw an exception
		return a;
}

int main()
{
	int a = -10, b = 215;
	double x = 55.73, y = 56.21;
	std::string alpha = "Alpha", zeta = "Zeta";

	std::cout << "Testing integers " << a << " and " << b << "..." << std::endl;
	std::cout << "Min is: " << min(a, b) << ". Max is: " << max(a, b) << std::endl;

	std::cout << "Testing doubles " << x << " and " << y << "..." << std::endl;
	std::cout << "Min is: " << min(x, y) << ". Max is: " << max(x, y) << std::endl;

	std::cout << "Testing strings " << alpha << " and " << zeta << "..." << std::endl;
	std::cout << "Min is: " << min(alpha, zeta) << ". Max is: " << max(alpha, zeta) << std::endl;

	std::cin.get();
	return 0;
}