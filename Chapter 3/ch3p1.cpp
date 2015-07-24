// Page 150 - Ch3 PC 1
/*
1. Miles per Gallon
Write a program that calculates a car’s gas mileage. The program should ask the user to
enter the number of gallons of gas the car can hold and the number of miles it can be
driven on a full tank. It should then calculate and display the number of miles per gallon
the car gets.
*/

#include <iostream>

using namespace std;

int main()
{
	double gallonsPerTank, milesPerTank, milesPerGallon;

	cout << "Calculates your gas mileage for a vehicle." << endl;
	cout << "How many gallons does the vehicle hold per tank?" << endl;
	cin >> gallonsPerTank;

	cout << "How many miles can vehicle travel with a full tank of gas?" << endl;
	cin >> milesPerTank;

	milesPerGallon = milesPerTank / gallonsPerTank; // "tank" units cancel

	cout << "Vehicle should be able to travel " << milesPerGallon << "miles per gallon." << endl;
	
	return 0;
}