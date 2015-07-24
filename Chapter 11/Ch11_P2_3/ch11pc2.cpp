#include <iostream>
#include <string>
#include "DayOfYear.h"

int main()
{
	std::string month;
	int day, dayOfMonth;

	std::cout << "This program can tell you the month and day of the year " << std::endl;
	std::cout << "given a number between 1 and 365 (inclusive)." << std::endl;
	std::cout << "It can also accept an month (expressed as a string - e.g. January)" << std::endl;
	std::cout << "and a day and will store the appropriate integer in the object." << std::endl;

	std::cout << "Please enter a day of the year between 1 and 365: ";
	std::cin >> day;

	DayOfYear dayOfYear(day); // calls constructor accepting int

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
		std::cout << "Day in dayOfYear: " << dayOfYear.getDay() << std::endl;
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
		std::cout << "Day in dayOfYear: " << dayOfYear.getDay() << std::endl;
		std::cout << "String: " << dayOfYear.toString() << std::endl;
	}

	std::cin.get();
	return 0;
}