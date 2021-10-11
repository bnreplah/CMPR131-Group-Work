//  File: application.h
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
#include "input.h"

using namespace std;



/**[application class invariant]
*/
class Application
{
private:



public:



};

/// Precondition: N/A
/// Postcondition: displays list main menu
char applicationMenuOption()
{
	string options[] = { "\n\t3) Courses using MyBags of integers, strings, doubles, and chars",
						"\n\t" + string(100, char(205)) +
						"\n\t\t1> Specify the number of courses",
						"\n\t\t2> Read in data file and insert into courses",
						"\n\t\t3> Search for a student record from a course",
						"\n\t\t4> Remove a student record from a course",
						"\n\t\t5> Display course(s)",
						"\n\t" + string(100 , char(196)) +
						"\n\t\t0> return "
						"\n\t" + string(100, char(205))
	};
	for (string option : options)
		cout << option;

	int optionChar = inputInteger("\n\t\toption ", 0, 5);
	clrScrn();

	return optionChar;
}

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runApplication()
{
	do
	{
		switch (applicationMenuOption())
		{
		case 0: return; break;
		case 1:; break;
		case 2:; break;
		case 3:; break;
		case 4:; break;
		case 5:; break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
		clrScrn();
	} while (true);
}