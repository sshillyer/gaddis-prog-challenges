
/*********************************************************************
** Author: Shawn S. Hillyer
** Date:   07.11.2015
** Description:  fallDistance.cpp (4.a)
** Chapter 11, Programming Challenge 2 & 3 (Combined)
** Day of the Year
** Assuming that a year has 365 days, write a class named DayOfYear that takes an integer
** representing a day of the year and translates it to a string consisting of the month followed
** by day of the month. For example,
** 		Day 2 would be January 2
** 		Day 32 would be February 1
** 		Day 365 would be December 31.
** The constructor for the class should take as parameter an integer representing the day of
** the year, and the class should have a member function print() that prints the day in the
** month-day format. The class should have an integer member variable to represent the day
** and should have static member variables of type string to assist in the translation from
** the integer format to the month–day format.
** Test your class by inputting various integers representing days and printing out their
** representation in the month–day format.
** ///////////////////////////////////////////////
** 3. Day of the Year Modification
** Modify the DayOfYear class, written in an earlier Programming Challenge, to add a
** constructor that takes two parameters: a string representing a month and an integer in the
** range 0 through 31 representing the day of the month. The constructor should then initialize
** the integer member of the class to represent the day specified by the month and day of month
** parameters. The constructor should terminate the program with an appropriate error
** message if the number entered for a day is outside the range of days for the month given.
** Add the following overloaded operators:
** ++ prefix and postfix increment operators. These operators should modify the DayOfYear
** object so that it represents the next day. If the day is already the end of the year, the
** ** new value of the object will represent the first day of the year.
** -- prefix and postfix decrement operators. These operators should modify the DayOfYear
** object so that it represents the previous day. If the day is already the first day of the
** year, the new value of the object will represent the last day of the year.
*********************************************************************/

// DayOfYear.h

#include <string>
using std::string;

class DayOfYear
{
private:
	int day;
	static int daysInMonth[13]; // holds number of days in a given month
	static string nameOfMonth[13]; // holds the names of the months
	// could make the following function instead of using itoa(tempDay) in the conversion
	/*
	static string dayAsStr[31] = {"1", "2", ... "30", "31"};
	*/
public:
	// Constructors
	DayOfYear(int day);
	DayOfYear(string month, int day);
	// increment and decrement operator overloads
	DayOfYear operator++();
	DayOfYear operator++(int);
	DayOfYear operator--();
	DayOfYear operator--(int);
	// Output functions
	void print();
	string toString();
	// testing functions
	int getDay() { return day; };
};

// Static variables. These static arrays are used to convert the int into a string obj later
int DayOfYear::daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string DayOfYear::nameOfMonth[13] = { "", // first array element empty
"January", "February", "March", "April", "May", "June",
"July", "August", "September", "October", "November", "December" };

/***************************************************************************************
Constructor: accepts a day between 1 and 365.
***************************************************************************************/
DayOfYear::DayOfYear(int day)
{
	if (day > 0 && day <= 365) {
		this->day = day;
	}
	else
	{
		std::cout << "Houston, we have a problem! Day must be between 0 and 365." << std::endl;
		exit(EXIT_FAILURE);
	}
}
/***************************************************************************************
From Problem 3:
Overloaded constructor. Accepts a string (a month name) and an int and initializes the
static int member variable. Terminats if given an int outside the range of days in the
month that is passed as an argument.
***************************************************************************************/
DayOfYear::DayOfYear(string monthString, int dayOfMonth)
{
	int i = 1;
	int totalDays = dayOfMonth;
	while (monthString != nameOfMonth[i]) // search array for the month we're in
	{
		totalDays += daysInMonth[i]; // add days from each month prior to current month
		i++;
	}
	if (totalDays > daysInMonth[i])
	{
		std::cout<<"Day exceeds bounds of month. Terminating program." << std::endl;
		exit(EXIT_FAILURE);
	}
	// now just store the totalDays in the member variable day
	day = totalDays;
}
/*
++ prefix and postfix increment operators. These operators should modify the DayOfYear
object so that it represents the next day. If the day is already the end of the year, the
new value of the object will represent the first day of the year.
*/
DayOfYear DayOfYear::operator++() // prefix ++
{
	if (day == 365) {
		day = 1;
	}
	else {
		day += 1;
	}
	return *this;
}

DayOfYear DayOfYear::operator++(int) // postfix operator ++ notice the dummy operator
{
	DayOfYear temp = *this;
	if (day == 365) {
		day = 1;
	}
	else {
		day++;
	}
	return temp; // return the value BEFORE its incremented. Value still updated for the original object though
}

DayOfYear DayOfYear::operator--() // prefix --
{
	if (day == 1) {
		day = 365;
	}
	else {
		day -= 1;
	}
	return *this;
}

DayOfYear DayOfYear::operator--(int) // postfix operator -- notice the dummy operator
{
	DayOfYear temp = *this;
	if (day == 1) {
		day = 365;
	}
	else {
		day -= 1;
	}
	return temp; // return the value BEFORE its incremented. Value still updated for the original object though
}


/*****************
Determines the month and the day of the month and returns string in fomrat "January 13"
*****************/

string DayOfYear::toString()
{
	int index = 1; 				// start in january index. update and will return at end to give us correct index
	int tempDay = this->day; 	// holding value to calculate the month and day remainder
	string monthDayString = ""; // hold string to return; init to null string beginning of each call
	char dayString[3];

	while (tempDay > DayOfYear::daysInMonth[index])
	{
		tempDay -= DayOfYear::daysInMonth[index]; // subtract the # of days in current month from value 
		index++; // check the next month... as long as we didn't allow a # greater than 365 should terminate eventually!
	}
	
	_itoa_s(tempDay, dayString, 10); // Whatever was left should be less than month so should be number of day of month

	// Append the name of the month, then a space, then the days leftover
	monthDayString.append(DayOfYear::nameOfMonth[index] + " " +  dayString);

	return monthDayString;
}



// test client
#include <iostream>
#include <string>
#include "DayOfYear.h"

int main()
{
	std::string month;
	int dayOfYear, int dayOfMonth;
	std::cout << "This program can tell you the month and day of the year " << std::endl;
	std::cout << "given a number between 1 and 365 (inclusive)." << std::endl;
	std::cout << "It can also accept an month (expressed as a string - e.g. \"January\"") << std::endl;
	std::cout << "and a day and will store the appropriate integer in the object." << std::endl;

	std::cout << "Please enter a day of the year between 1 and 365: ";
	std::cin >> dayOfYear;

	DayOfYear dayOfYear(dayOfYear); // calls constructor accepting int

	std::cout << "Now type a full month name: ";
	std::cin >> month;
	std::cout << "And a day of the month: ";
	std::cin >> dayOfMonth;

	DayOfYear monthAndDay(month, dayOfMonth); // calls constructor acceptnig a day and month

	std::cout << "The first dayOfYear object thinks that the month and day is: " << std::endl;
	std::cout << dayOfYear.toString();

	std::cout << "The second dayOfYear object thinks that the day of the year as an int is: " << std::endl;
	std::cout << monthAndDay.getDay();

	std::cout << "Increasing first day using postfix++ 10 times." << std::endl;
	for (int i = 0; i < 10; i++)
	{
		dayOfYear++;
		std::cout << "Day in dayOfYear: " << dayOfYear.getDay() << std::endl;
		std::cout << "String:" << dayOfYear.toString() << std::endl;
	}

	std::cout << "Decreasing first day using postfix-- 10 times." << std::endl;
	for (int i = 0; i < 10; i++)
	{
		dayOfYear--;
		std::cout << "Day in myBirthday: " << dayOfYear.getDay() << std::endl;
		std::cout << "String: " << dayOfYear.toString() << std::endl;
	}

	std::cout << "Increasing first day using ++prefix 10 times." << std::endl;
	for (int i = 0; i < 10; i++)
	{
		++dayOfYear;
		std::cout << "Day in dayOfYear: " << dayOfYear.getDay() << std::endl;
		std::cout << "String:" << dayOfYear.toString() << std::endl;
	}

	std::cout << "Decreasing first day using --prefix 10 times." << std::endl;
	for (int i = 0; i < 10; i++)
	{
		--dayOfYear;
		std::cout << "Day in myBirthday: " << dayOfYear.getDay() << std::endl;
		std::cout << "String: " << dayOfYear.toString() << std::endl;
	}


	std::cin.get();
	return 0;
}