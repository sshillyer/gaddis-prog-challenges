/*************************************************************************************************
** Author: Shawn S. Hillyer
** Date:   07.14.2015
** Description:  CH11_P7.cpp

7. Corporate Sales

A corporation has six divisions, each responsible for sales to different geographic
locations. Design a DivSales class that keeps sales data for a division, with the following
members:
• An array with four elements for holding four quarters of sales figures for the division
• A private static variable for holding the total corporate sales for all divisions for the
entire year.
• A member function that takes four arguments, each assumed to be the sales for a
quarter. The value of the arguments should be copied into the array that holds the
sales data. The total of the four arguments should be added to the static variable that
holds the total yearly corporate sales.
• A function that takes an integer argument within the range of 0 to 3. The argument is
to be used as a subscript into the division quarterly sales array. The function should
return the value of the array element with that subscript.

Write a program that creates an array of six DivSales objects. The program should ask
the user to enter the sales for four quarters for each division. After the data is entered, the
program should display a table showing the division sales for each quarter. The program
should then display the total corporate sales for the year.
/*************************************************************************************************/

class DivSales
{
private:
	double quarterlySales[4]; // holds sales for a given quarter
public:
	static double totalCorpSales;
	void setQuarterlySales(double q1, double q2, double q3, double q4);
	double getQuarterlySales(int i);
	static double getTotalCorpSales() { return totalCorpSales; }
};

double DivSales::totalCorpSales = 0; // static member variable


void DivSales::setQuarterlySales(double q1, double q2, double q3, double q4)
{
	quarterlySales[0] = q1;
	quarterlySales[1] = q2;
	quarterlySales[2] = q3;
	quarterlySales[3] = q4;
	totalCorpSales += (q1 + q2 + q3 + q4);
}

double DivSales::getQuarterlySales(int i)
{
	return quarterlySales[i];
}

// Test client

#include <iostream>
#include <iomanip>

int main()
{
	// Create 6 divisions
	DivSales division[6];
	double sales[4]; // to store sales for each quarter before passing into objects

	for (int i = 0; i < 6; i++)
	{
		std::cout << "Enter quarterly sales for division " << (i + 1) << "..." << std::endl;
		for (int j = 0; j < 4; j++)
		{
			std::cout << "Quarter " << (j + 1) << ": $";
			std::cin >> sales[j];
		}
		division[i].setQuarterlySales(sales[0], sales[1], sales[2], sales[3]);
	}

	std::cout << "That's all of the data. Now printing a report." << std::endl;

	for (int i = 0; i < 6; i++)
	{
		std::cout << "Division " << (i + 1) << " Sales" << std::endl;
		for (int j = 0; j < 4; j++)
		{
			std::cout << "Q" << j << ": $"
				<< std::setw(14) << std::fixed << std::showpoint << std::setprecision(2) << division[i].getQuarterlySales(j)
				<< std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "Total Corporate Sales: " << ": $"
		<< std::setw(14) << std::fixed << std::showpoint << std::setprecision(2) << DivSales::getTotalCorpSales() << std::endl;

	return 0;
}