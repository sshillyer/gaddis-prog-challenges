/*********************************************************************
** Author: Shawn S. Hillyer
** Date:   07.11.2015
** Description:  DayOfYear.h
** Chapter 11, Programming Challenge 2 & 3 (Combined)
*********************************************************************/
#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include <string>

class DayOfYear
{
private:
	int day;
	static int daysInMonth[13]; // holds number of days in a given month
	static std::string nameOfMonth[13]; // holds the names of the months
	static std::string numberString[32]; // holds conversion table for days of month
public:
	// Constructors
	DayOfYear(int day);
	DayOfYear(std::string month, int day);
	// increment and decrement operator overloads
	DayOfYear operator++();
	DayOfYear operator++(int);
	DayOfYear operator--();
	DayOfYear operator--(int);
	// Output functions
	void print();
	std::string toString();
	// testing functions
	int getDay() { return day; };
};
#endif