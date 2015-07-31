/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 30, 2015
** Description: ch15pc4.cpp
Problem solution from Gaddis C++

-- I've implemented this to succesfully encrypt and decrypt the files.... 
to decrypt, you'd want to enter the same integer with opposite sign as your original.
I've only tested it on plain-text files. I'm sure it could be modified very easily
with additional subclasses designed to do more complex decryption and encryption
or possibly used to adapt for a binary decryption methodology.

4. Flexible Encryption
Write a modification of the encryption program of Section 15.5 whose transform function
uses an integer key to transform the character passed to it. The function transforms the
character by adding the key to it. The key should be represented as a member of the
Encryption class, and the class should be modified so that it has a member function that
sets the encryption key. When the program runs, the main function should ask the user for
the input file, the output file, and an encryption key.
Show that with these modifications, the same program can be used for both encryption and
decryption.
*********************************************************************/

#include <iostream>
#include <fstream>

class Encryption
{
protected:
	std::ifstream inFile;
	std::ofstream outFile;
	int key;
public:
	void setKey(int key = 0);
	Encryption(char *inFileName, char *outFileName);
	~Encryption();
	virtual char transform(char ch) = 0;
	void encrypt();
};

// Encryption.cpp
void Encryption::setKey(int key)
{
	this->key = key;
}

Encryption::Encryption(char *inFileName, char *outFileName)
{
	inFile.open(inFileName);
	outFile.open(outFileName);
	if (!inFile)
	{
		std::cout << "Error opening file " << inFileName << ".";
		exit(1);
	}
	if (!outFile)
	{
		std::cout << "Error opening file " << outFileName << ".";
		exit(1);
	}
}

Encryption::~Encryption()
{
	inFile.close();
	outFile.close();
}


void Encryption::encrypt()
{
	char ch;
	char transCh;
	inFile.get(ch);
	while (!inFile.fail())
	{
		transCh = transform(ch);
		outFile.put(transCh);
		inFile.get(ch);
	}
}

class IntCryption : public Encryption
{
public:
	char transform(char ch);
	IntCryption(char *inFileName, char *outFileName) : Encryption(inFileName, outFileName)
	{}
};

char IntCryption::transform(char ch)
{
	return ch + key;
}




int main()
{
	char inFileName[80], outFileName[80];
	int key;
	std::cout << "Enter name of file to encrypt: ";
	std::cin >> inFileName;
	std::cout << "Enter name of file to receive the encrypted text: ";
	std::cin >> outFileName;
	std::cout << "Enter an integer to use as the key (if decrypting use the negative key):";
	std::cin >> key;

	IntCryption obfuscate(inFileName, outFileName);

	obfuscate.setKey(key);
	obfuscate.encrypt();
	return 0;
}