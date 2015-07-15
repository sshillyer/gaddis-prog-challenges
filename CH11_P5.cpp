/*************************************************************************************************
** Author: Shawn S. Hillyer
** Date:   07.11.2015
** Description:  CH11_P5.cpp

5. Palindrome Testing
A palindrome is a string that reads the same backward as forward. For example, the words
mom, dad, madam and radar are all palindromes. Write a class Pstring that is derived
from the STL string class. The Pstring class adds a member function
bool isPalindrome( )
that determines whether the string is a palindrome. Include a constructor that takes an STL
string object as parameter and passes it to the string base class constructor. Test your
class by having a main program that asks the user to enter a string. The program uses the
string to initialize a Pstring object and then calls isPalindrome() to determine whether
the string entered is a palindrome.
You may find it useful to use the subscript operator [] of the string class: if str is a string
object and k is an integer, then str[k] returns the character at position k in the string.
**************************************************************************************************/

#include <string>
#include <iostream>

// derived class - superclass is string, hence the #include directive
class Pstring : public std::string
{
private:
	std::string s;
public:
	// Constructor
	Pstring(std::string s);

	// checks to see if a string is a palindrome
	bool isPalindrome();
};


// Pstring.cpp

// Constructor -- not sure if this is invoked the way the problem desription describes....
Pstring::Pstring(std::string s)
{
	this->s = s;
}


bool Pstring::isPalindrome()
{
	bool isAPalindrome = true;
	int k = 0;
	int lastStrIndex = s.length() - 1;
	// Debugging
	std::cout << "isAPalindrome is currently " << isAPalindrome << std::endl;
	// End Debugging
	while (isAPalindrome && (k <= lastStrIndex))
	{
		std::cout << "Comparing s.at(" << k << ") != s.at(lastStrIndex) - k: " << std::endl;
		std::cout << s.at(k) << " vs " << s.at(lastStrIndex - k) << std::endl;
		if (s.at(k) != ((s.at(lastStrIndex - k))))
		{
			isAPalindrome = false;

		}
		k++;
	}
	return isAPalindrome;
}



int main()
{
	std::string notAPal = "notaracecar";
	std::string yesAPal = "racecar";

	Pstring noPal(notAPal);
	Pstring pal(yesAPal);

	std::cout << "noPal object - isPalindrome true or false: " << noPal.isPalindrome() << std::endl;
	std::cout << "pal object - isPalindrome true or false: " << pal.isPalindrome() << std::endl;

	return 0;
}