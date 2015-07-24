/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 14, 2015
** Description: CH11_P6.cpp
Problem solution from Gaddis C++

6. String Encryption
Write a class EncryptableString that is derived from the STL string class. The
Encryptable string class adds a member function
void encrypt( )
That encrypts the string contained in the object by replacing each letter with its successor
in the ASCII ordering. For example, the string baa would be encrypted to cbb. Assume that
all characters that are part of an EncryptableString object are letters a, .., z and A, .., Z,
and that the successor of z is a and the successor of Z is A. Test your class with a program
that asks the user to enter strings that are then encrypted and printed.

*********************************************************************/
#include <string>

class EncryptableString : public std::string
{
private:
	std::string s;
	char incrementChar(int);
public:
	EncryptableString(std::string s) { this->s = s; }
	void encrypt();
	std::string getString() { return s; }
};

void EncryptableString::encrypt()
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		s[i] = incrementChar(i);
	}
}

// 
char EncryptableString::incrementChar(int i)
{
	char newChar = s[i];
	if (s[i] == 90) { // if char is capital letter 'Z'
		newChar = 65; // return to 'A'
	}
	else if (s[i] == 122) { // if 'z'
		newChar = 97;		 // return to 'a'
	}
	else if (s[i] < 65 || ((s[i] > 90) && (s[i] < 97)) || (s[i] > 122)) { // if outside range of letters in table
		newChar = s[i]; // no change
	}
	else {	// default case is it's a letter from 'A' to 'Y' || 'a' to 'y' and we should increase its ASCII value by 1
		newChar += 1;
	}
	return newChar;
}

// Client to test the derived class

#include <iostream>
#include <string>

int main()
{
	//declare atest string
	std::string myString = "The quick brown fox jumped over the lazy dogs...!";

	// pass string to object constructor
	EncryptableString encryptObject(myString);

	std::cout << "String Before: " << encryptObject.getString() << std::endl;
	encryptObject.encrypt();
	std::cout << "String After: " << encryptObject.getString() << std::endl;

	std::cin.get();

	return 0;
}