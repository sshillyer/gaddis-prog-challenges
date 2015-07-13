// Page 150 - Ch3 PC 2
/*
2. Stadium Seating
There are three seating categories at a stadium. For a softball game, Class A seats cost $15,
Class B seats cost $12, and Class C seats cost $9. Write a program that asks how many
tickets for each class of seats were sold, then displays the amount of income generated
from ticket sales. Format your dollar amount in a fixed-point notation with two decimal
points and make sure the decimal point is always displayed.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// Variables
	double 	ticketPriceA = 15, ticketsSoldA, incomeA,
			ticketPriceB = 12, ticketsSoldB, incomeB,
			ticketPriceC = 9, ticketsSoldC, incomeC,
			totalIncome;

	// Prompt and get input
	cout << "How many class A tickets were sold?" << endl;
	cin >> ticketsSoldA;
	cout << "How many class B tickets were sold?" << endl;
	cin >> ticketsSoldB;	
	cout << "How many class C tickets were sold?" << endl;
	cin >> ticketsSoldC;	

	// Calculations
	incomeA = ticketPriceA * ticketsSoldA;
	incomeB = ticketPriceB * ticketsSoldB;
	incomeC = ticketPriceC * ticketsSoldC;
	totalIncome = incomeA + incomeB + incomeC;

	// Print results
	cout << "Total income from ticket sales: " << endl << "$ ";
	cout << fixed << showpoint << setprecision(2) << totalIncome;

	cout << "Press any key to exit." << endl;
	cin.get();

	return 0;
}