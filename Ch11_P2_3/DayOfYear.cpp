/*********************************************************************
** Author: Shawn S. Hillyer
** Date:   07.11.2015
** Description:  DayOfYear.cpp
** Chapter 11, Programming Challenge 2 & 3 (Combined)
*********************************************************************/
#include "DayOfYear.h"
#include <iostream>
#include <stdlib.h>

/***************************************************************************************
** Static variables. These static arrays are used to convert the int into a string obj later
***************************************************************************************/
int DayOfYear::daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
std::string DayOfYear::nameOfMonth[13] = { "", // first array element empty
	"January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December" };
std::string DayOfYear::numberString[32] = {"", "1", "2", "3", "4", "5", "6", "7", "8", "9", 
	"10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", 
	"24", "25", "26", "27", "28", "29", "30", "31"};

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
DayOfYear::DayOfYear(std::string monthString, int dayOfMonth)
{
	int i = 1;
	int totalDays = dayOfMonth;
	
	if (dayOfMonth > daysInMonth[i])
	{
		std::cout<<"Day exceeds bounds of month. Terminating program." << std::endl;
		exit(EXIT_FAILURE);
	}
	while (monthString != nameOfMonth[i]) // search array for the month we're in
	{
		totalDays += daysInMonth[i]; // add days from each month prior to current month
		i++;
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

std::string DayOfYear::toString()
{
	int index = 1; 				// start in january index. update and will return at end to give us correct index
	int tempDay = this->day; 	// holding value to calculate the month and day remainder
	std::string monthDayString = ""; // hold string to return; init to null string beginning of each call
	
	while (tempDay > DayOfYear::daysInMonth[index])
	{
		tempDay -= DayOfYear::daysInMonth[index]; // subtract the # of days in current month from value 
		index++; // check the next month... as long as we didn't allow a # greater than 365 should terminate eventually!
	}

		// Append the name of the current month, then a space, then the days leftover
	monthDayString.append(DayOfYear::nameOfMonth[index] + " " +  DayOfYear::numberString[tempDay]);

	return monthDayString;
}