//
//
//
//

#pragma once

#include <iostream>
#include "input.h"

using namespace std;

class myBag
{
private:



public:



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