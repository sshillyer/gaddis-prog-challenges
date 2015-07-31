/*********************************************************************
** Author: 	Shawn S Hillyer
** Date:	July 30, 2015
** Description: ch15pc3.cpp
Problem solution from Gaddis C++

WORKING

3. Sequence Sum
A sequence of integers such as 1, 3, 5, 7, … can be represented by a function that takes a
nonnegative integer as parameter and returns the corresponding term of the sequence. For
example, the sequence of odd numbers just cited can be represented by the function

int odd(int k) {return 2 * k + 1;}

Write an abstract class AbstractSeq that has a pure virtual member function

virtual int fun(int k) = 0;

as a stand-in for an actual sequence, and two member functions

void printSeq(int k, int m);
int sumSeq(int k, int m)

that are passed two integer parameters k and m, where k < m. The function printSeq will
print all the terms fun(k) through fun(m) of the sequence, and likewise, the function
sumSeq will return the sum of those terms. Demonstrate your AbstractSeq class by
creating subclasses that you use to sum the terms of at least two different sequences.
Determine what kind of output best shows off the operation of these classes, and write a
program that produces that kind of output.

*********************************************************************/


/*********************
**  AbstractSeq.hpp
*********************/
class AbstractSeq
{
public:
	virtual int fun(int k) = 0;
	void printSeq(int k, int m);
	int sumSeq(int k, int m);
};


/*********************
**  AbstractSeq.cpp
*********************/
#include <iostream>

void AbstractSeq::printSeq(int k, int m)
{
	while (k <= m)
	{
		std::cout << fun(k) << " ";
		k++;
	}
}

int AbstractSeq::sumSeq(int k, int m)
{
	int total = 0;
	while (k <= m)
	{
		total += fun(k);
		k++;
	}
	return total;
}

/*********************
**  OddSequence.hpp
*********************/
class OddSequence : public AbstractSeq
{
public:
	virtual int fun(int k);
};

/*********************
**  OddSequence.cpp
*********************/
int OddSequence::fun(int k)
{
	return (2 * k + 1);
}

/**********************
**  SquaresSequence.hpp
**********************/
class SquaresSequence : public AbstractSeq
{
public:
	virtual int fun(int k);
};

/**********************
**  SquaresSequence.cpp
**********************/
int SquaresSequence::fun(int k)
{
	return (k*k);
}

/*********************
**  SequenceTest.cpp
*********************/

#include <iostream>

int main()
{
	int k, m;
	std::cout << "Enter the sequence position to start at: ";
	std::cin >> k;
	std::cout << "Enter the sequence position to end at: ";
	std::cin >> m;
	OddSequence odds;
	SquaresSequence squares;
	std::cout << "Printing odds from sequence " << k << " to sequence " << m << std::endl;
	odds.printSeq(k, m);
	std::cout << std::endl << "Sum is: " << odds.sumSeq(k, m) << std::endl;
	std::cout << "Printing squares from sequence " << k << " to sequence " << m << std::endl;
	squares.printSeq(k, m);
	std::cout << std::endl << "Sum is: " << squares.sumSeq(k, m) << std::endl;


	std::cin.ignore(10, '\n');
	std::cin.get();
	return 0;
}