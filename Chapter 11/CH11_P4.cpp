/*********************************************************************
** Author: Shawn S. Hillyer
** Date:   07.11.2015
** Description:  fallDistance.cpp (4.a)
** Chapter 11, Programming Challenge 2 & 3 (Combined)
4. Number of Days Worked
Design a class called NumDays. The class’s purpose is to store a value that represents a
number of work hours and convert it to a number of days. For example, 8 hours would
be converted to 1 day, 12 hours would be converted to 1.5 days, and 18 hours would be
converted to 2.25 days. The class should have a constructor that accepts a number of
hours, as well as member functions for storing and retrieving the hours and days. The class
should also have the following overloaded operators:
• The addition operator +. The number of hours in the sum of two objects is the sum
of the number of hours in the individual objects.
• The subtraction operator -. The number of hours in the difference of two objects X
and Y is the number of hours in X minus the number of hours in Y.
• Prefix and postfix increment operators ++. The number of hours in an object is
incremented by 1.
• Prefix and postfix decrement operators --. The number of hours in an object is
decremented by 1.
/*********************************************************************/

// NumDays.h
class NumDays
{
private:
	double hours;
public:
	// Constructors
	NumDays(double hours); // should call setHours

	// Setter functions
	void setHours(double hours); // should handle negative values and use default 0
	void setDays(double days); // accepts a day and converts it to equivalent hours, then stores in hours
	double getHours(); // return the hours var
	double getDays(); // calculates the # of days and returns that value

	// Overloaded Operators - note that binary operators implemented as friend functions
	friend NumDays operator+(NumDays a, NumDays b);
	friend NumDays operator-(NumDays a, NumDays b);
	// Overloaded Operators (unary) are not. This is because a binary shouldn't aritarily differentiate between left and right
	NumDays operator++(); // prefix++
	NumDays operator++(int); // postfix++
	NumDays operator--(); // prefix--
	NumDays operator--(int); // postfix--
};

/////////////////
// NumDays.cpp //
/////////////////

// include iostream if needed for testing

// Constructors
NumDays::NumDays(double hours)
{
	setHours(hours); // passes local parameter
}

// Setter functions
// should handle negative values and use default 0
void NumDays::setHours(double hours)
{
	if (hours < 0) {
		this->hours = 0;
	}
	else {
		this->hours = hours;
	}
}

// accepts a day and converts it to equivalent hours, then stores in hours
void NumDays::setDays(double days)
{
	this->hours = (days * 8);
}

double NumDays::getHours()
{
	return this->hours; // use of this-> for style reasons, *this is implied
}

// calculates the # of work-hour-days and returns that value
double NumDays::getDays()
{
	return (this->hours / 8);
}

// Overloaded operators -- friend functions so no scope operator
NumDays operator+(NumDays a, NumDays b)
{
	NumDays result(a.hours + b.hours);
	return result;
}

NumDays operator-(NumDays a, NumDays b)
{
	NumDays result(a.hours - b.hours);
	return result;
}

//prefix++
NumDays NumDays::operator++()
{
	hours++;
	return *this;
}

// postfix++
NumDays NumDays::operator++(int)
{
	NumDays temp = *this;
	hours++;
	return temp;
}

// prefix--
NumDays NumDays::operator--()
{
	hours--;
	return *this;
}

// postfix--
NumDays NumDays::operator--(int)
{
	NumDays temp = *this;
	hours--;
	return temp;
}

// ch11p4.cpp - client program to test

#include <iostream>

int main()
{
	// Create objects using constructor
	NumDays ditchDig(8); // 8 hours
	NumDays buildHouse(1000); // 1k hours

	// Print object value to verify working
	std::cout << "The ditchDig took " << ditchDig.getHours() << " hours, or " << ditchDig.getDays() << " days." << std::endl;
	std::cout << "It takes " << buildHouse.getHours() << " hours, or " << buildHouse.getDays() << " days to build a house. " << std::endl;

	// test increment and decrement
	ditchDig++;
	buildHouse--;

	// Print object value to verify working
	std::cout << "Increase ditchDig one using increment, decrease buildhouse 1 using decrement (postfix)" << std::endl << std::endl;
	std::cout << "The ditchDig took " << ditchDig.getHours() << " hours, or " << ditchDig.getDays() << " days." << std::endl;
	std::cout << "It takes " << buildHouse.getHours() << " hours, or " << buildHouse.getDays() << " days to build a house. " << std::endl;

	// Add the two objects together and return value should pass to the constructor for new ditchHouse
	NumDays ditchHouse(ditchDig + buildHouse);

	std::cout << "ditchHouse takes " << ditchHouse.getHours() << " hours, or " << ditchHouse.getDays() << " days." << std::endl;

	// Subtract 5 from all objects
	ditchDig = ditchDig - 5;
	buildHouse = buildHouse - 5;
	ditchHouse = ditchHouse - 5;

	std::cout << "Subtracting 5 from all: " << std::endl;
	std::cout << "The ditchDig took " << ditchDig.getHours() << " hours, or " << ditchDig.getDays() << " days." << std::endl;
	std::cout << "It takes " << buildHouse.getHours() << " hours, or " << buildHouse.getDays() << " days to build a house. " << std::endl;

	// test alternate setter setDays
	buildHouse.setDays(5.5); // expect to see 5.5 * 8 = 44 hours

	std::cout << "buildHouse was passed 5.5 days, which converted to " << buildHouse.getHours() << " hours." << std::endl;

	return 0;
}