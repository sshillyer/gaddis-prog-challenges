/* 1. Check Writing
Design a class Numbers that can be used to translate whole dollar amounts in the range 0
through 9999 into an English description of the number. For example, the number 713
would be translated into the string seven hundred thirteen, and 8203 would be translated
into eight thousand two hundred three.
The class should have a single integer member variable

	int number;

and a collection of static string members that specify how to translate key dollar amounts
into the desired format. For example, you might use static strings such as

string lessThan20[ ] =
	{"zero", "one", …, "eighteen", "nineteen" };
string hundred = "hundred";
string thousand = "thousand";

The class should have a constructor that accepts a nonnegative integer and uses it to initialize
the Numbers object. It should have a member function print() that prints the English
description of the Numbers object. Demonstrate the class by writing a main program that asks
the user to enter a number in the proper range and then prints out its English description.
*/

