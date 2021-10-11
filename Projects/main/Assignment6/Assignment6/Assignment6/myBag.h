//	File: myBag.h
//	Team Members:
//      Ben Halpern
//      Itz Rodriquez
//      Tony Cheng
//      Jose Chavez
//      Thien Nguyen
//      Jesus Sierra
//	Professor Q
//	CMPR 131
//	Assignment 6
//	10/7/21
//

#pragma once

#include <iostream>
#include <vector>
#include "input.h"

using namespace std;



/**[MyBag class invariant]
* 1) Create a regular non-template class called MyBag for dynamic array of integers. The class is based from a list class and must have the follow members:
*
*       Private attributes:
*       A pointer variable to a dynamic array of integers.
*       A size variable to keep track the number of elements in the array.
*       A capacity variable keep track the capacity of the dynamic array for growth and reduction. 
*       constructor(s) and destructor
*       accessors and mutators
*       friend functions
* 
*	   Option1 utilizes the non-template MyBag of integers to:
*       clear
*       insert
*       search
*       remove
*       sort
*       display
*
* 
*/




/**
* 
* 
* 
*/
class myIntBag
{
private:
	int stub;
public:
	myIntBag() {}
	//~myBag() {}

	//accessors

	/// [stub]
	/// Precondition:
	/// Postcondition:
	int search() const { return stub; }


	//mutators:

	/// [stub]
	/// Precondition:
	/// Postcondition:
	void clear(){}

	/// [stub]
	/// Precondition:
	/// Postcondition:
	void insert(){}


	/// [stub]
	/// Precondition:
	/// Postcondition:
	void sort(){}

	/// [stub]
	/// Precondition:
	/// Postcondition:
	void display(){}

};

/// Precondition: N/A
/// Postcondition: displays list main menu
char myBagMenuOption()
{
	string options[] = { "\n\t1> Non-template MyBag of integers",
						"\n\t" + string(100, char(205)) +
						"\n\t\tA> clear",
						"\n\t\tB> insert",
						"\n\t\tC> search",
						"\n\t\tD> remove",
						"\n\t\tE> sort",
						"\n\t\tF> display",
						"\n\t" + string(100 , char(196)) +
						"\n\t\t0> return "
						"\n\t" + string(100, char(205))
	};
	for (string option : options)
		cout << option;

	char optionChar = inputChar("\n\t\toption ", static_cast<string>("abcdef0"));
	clrScrn();

	return optionChar;
}

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runMyBag()
{
	do
	{
		switch (myBagMenuOption())
		{
		case '0': return; break;
		case 'A':; break;
		case 'B':; break;
		case 'C':; break;
		case 'D':; break;
		case 'E':; break;
		case 'F':; break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
		clrScrn();
	} while (true);
}