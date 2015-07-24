/*
10. Password Verifier
Imagine you are developing a software package that requires users to enter their own
passwords. Your software requires that user’s passwords meet the following criteria:
• The password should be at least six characters long.
• The password should contain at least one uppercase and at least one lowercase letter.
• The password should have at least one digit.
Write a program that asks for a password and then verifies that it meets the stated criteria.
If it doesn’t, the program should display a message telling the user why.

*/
#include <iostream>
#include <cctype>

bool checkPassword(const std::string& password);
bool hasMinChars(const std::string& password, const int minLength);
bool hasUpper(const std::string& password);
bool hasLower(const std::string& password);
bool hasDigit(const std::string& password);


int main()
{

	std::string goodString = "tHis1sAgOOdStRiNg";
	std::string badString1 = "thisstringhassixdigits";
	std::string badString2 = "THISSTRINGHASALLCAPS";
	std::string badString3 = "thisstringisalllower";
	std::string badString4 = "2shrt"; // too short
	std::string badString5 = "813837"; // all numbers

	std::cout << "goodString: " <<  checkPassword(goodString) << std::endl;
	std::cout << "badString1: " <<  checkPassword(badString1) << std::endl;
	std::cout << "badString2: " <<  checkPassword(badString2) << std::endl;
	std::cout << "badString3: " <<  checkPassword(badString3) << std::endl;
	std::cout << "badString4: " <<  checkPassword(badString4) << std::endl;
	std::cout << "badString5: " <<  checkPassword(badString5) << std::endl;
	
	std::cin.get();
}

bool checkPassword(const std::string& password)
{
	const int MIN_PASSW_LENGTH = 6;
	bool passAllTests = true;
	/* Below 3 lines work fine for testing all at once... I want to test each individually and prvide an error message though
	if (hasMinChars(password, MIN_PASSW_LENGTH) && hasUpper(password) && hasLower(password) && hasDigit(password)) {
		passAllTests = true;
	}
	*/
	if (!hasMinChars(password, MIN_PASSW_LENGTH)) {
		std::cout << "Your password does not containt the minimum of " << MIN_PASSW_LENGTH << " characters." << std::endl;
		passAllTests = false;
	}
	if (!hasUpper(password)) {
		std::cout << "Your password does not contain at least one uppercase letter." << std::endl;
		passAllTests = false;
	}
	if (!hasLower(password)) {
		std::cout << "Your password does not contain at least one lowercase letter." << std::endl;
		passAllTests = false;
	}
	if (!hasDigit(password)) {
		std::cout << "Your password does not contain at least one digit (number from 0-9)." << std::endl;
		passAllTests = false;
	}
	return passAllTests;
}

bool hasMinChars(const std::string& password, const int minLength)
{
	bool meetRequirements = false;
	if (password.length() >= 6) {
		meetRequirements = true;
	}
	return meetRequirements;
}

bool hasUpper(const std::string& password)
{
	bool hasUpper = false;
	for (unsigned i = 0; i < password.length() && !hasUpper; i++)
	{
		if (isupper(password.at(i))) {
			hasUpper = true;
		}
	}
	return hasUpper;
}

bool hasLower(const std::string& password)
{
	bool hasLower = false;
	for (unsigned i = 0; i < password.length() && !hasLower; i++)
	{
		if (isupper(password.at(i))) {
			hasLower = true;
		}
	}
	return hasLower;
}

bool hasDigit(const std::string& password)
{
	bool hasDigit = false;
	for (unsigned i = 0; i < password.length() && !hasDigit; i++)
	{
		if (isdigit(password.at(i))) {
			hasDigit = true;
		}
	}
	return hasDigit;
}