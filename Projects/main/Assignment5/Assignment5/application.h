// File: Application.h
//	Team Members:
//      Ben Halpern
//      Itz Rodriquez
//      Tony Cheng
//      Jose Chavez
//      Thien Nguyen
//      Jesus Sierra
//	Professor Q
//	CMPR 131
//	Assignment 5
//	10/1/21


/***[Description]
*	Application.h Formal Description and Use:
* 
* 
* 
* 
*	Naming Conventions:
*       [tags] are used to define design element comments such as this one and those of [const] for constant members and accesors, and [mutator] for mutator methods
*           When the tag is lower case the design element is a local comment, when the first letter is capitalized the design element is a gloabl tag relating to a comment with a scope pertaining to
*           the document as a whole.
*       The names of classses are capitalized following the CamelHump naming convention
*       'm' is used as a prefix to defined private members of a class following the CamelHump naming convention
*       'p' is used as a prefix to define formal paramters of methods following the CamelHump naming convention
*
*   Condition Documentation:
*       prior to functions, the documentation of the precondition and postcondition are described with three brackets so that the descriptions would work with Microsoft Visual Studio InteliSense,
*           which produces would then display the precondition and postcondition when as a tip when the function is being implemented in the various parts of the program.
*
*   Class Invarients:
*       Class invarients provide a list of the various methods in each classes and provide a short description outlining the use and implimentation notes for that class. The methods in the class invariant don't provide formal parameters
*           but instead they show the datatype of each formal parameter in a similiar format and style that might be seen in a protoype declaration.
*
*   Flow, Structural, and Document comments are seen throughout the code and are noted by the use of only two forward slashes '//' when defining the comments
*       A series of '###' may be used to denote flow indicator to help the programmer navigate the various classes
*/


#pragma once

#include <iostream>
#include <list>
#include <vector>
#include "input.h"


/** [Class Invarient]
*	Class: IntContainer
*	Private Member Variables:
*	
*	Public Member Methods:
* 
* 
*/
class IntContainer
{
private:
	list<vector<int>> mListVector = list<vector<int>>();

public:

	//######################################################################################
	// Constructors
	//######################################################################################
	
	/// [Default Constructor]
	/// Precondition: N/A
	/// Postcondition: initializes default list
	IntContainer() {}

	//######################################################################################
	// Mutators
	//######################################################################################

	/// Precondition: list initiated
	/// Postcondition: pushs an int inside a vector
	void addNumber()
	{
		int num = inputInteger("\n\tAdd an integer: ");
		if (mListVector.size() == 0)
		{
			vector<int> freq;
			freq.push_back(num);			//adding the value
			freq.push_back(1);				//adding the frequency
			mListVector.push_back(freq);
		}
		else
		{
			bool newAdd = false;
			for (list<vector<int>>::iterator itt = mListVector.begin(); itt != mListVector.end(); ++itt)    //cycle through the list
			{
				if (itt->at(0) == num)
				{
					++(itt->at(1));
					std::cout << "\n\tNew frequency : " << itt->at(1);
					newAdd = true;
					break;
				}
				/*	for (int i = 0; i < 2; i++)
					{
						std::cout << "\n\tindex " << i << ": " << itt->at(i);
					}*/
			}
			if (!newAdd)
			{
				vector<int> freq;
				freq.push_back(num);			//adding the value
				freq.push_back(1);				//adding the frequency
				mListVector.push_back(freq);
			}
		}
	}

	/// Precondition: a value inside vector
	/// Postcondition: deletes inputted value
	void removeNumber()
	{
		bool found = false;
		int num = inputInteger("\n\tDelete number: ");
		for (list<vector<int>>::iterator itt = mListVector.begin(); itt != mListVector.end(); ++itt)
		{
			if (itt->at(0) == num)
			{
				--(itt->at(1));
				std::cout << "\n\tNew frequency : " << itt->at(1);
				if (itt->at(1) <= 0)
				{
					mListVector.erase(itt);
				}
				found = true;
				break;
			}
		}//end for
		if (!found)
		{
			std::cout << "\n\tThe value is not contained in the container\n";
		}
	}

	//######################################################################################
	// Accessors
	//######################################################################################

	/// Precondition: a value inside vector
	/// Postcondition: displays values in container
	void displaySet()
	{
		std::cout << "\n\t\tContainer: ";
		for (list<vector<int>>::iterator itt = mListVector.begin(); itt != mListVector.end(); ++itt)
		{

			for (int i = 0; i < itt->at(1); i++)
			{
				std::cout << itt->at(0) << " ";//prints the value out if frequency greater than 1
			}

		}//end for
		std::cout << "\n";
	}

	/// Precondition: a value inside vector
	/// Postcondition: displays frequencies of values inputted
	void displayFrequencies()
	{
		std::cout << "\n\tContainer value : Frequencies\n";
		for (list<vector<int>>::iterator itt = mListVector.begin(); itt != mListVector.end(); ++itt)
		{
			std::cout << "\n\t" << itt->at(0) << " : " << itt->at(1);
		}//end for
	}
};

/// Precondition:
/// Postcondition: displays application main menu
char appMenuOption()
{
	clrScrn();
	header("3 > Application using Vector and /or List container");
	string options[] = { "\n\t\tA> Add an integer",
						 "\n\t\tB> Delete an integer",
						 "\n\t\tC> Display input integers",
						 "\n\t\tD> Display Frequencies of integers",
						 "\n\t" + string(100 , char(196)) +
						 "\n\t\t0> return "
						 "\n\t" + string(100, char(205))
	};
	for (string option : options)
		cout << option;

	char optionChar = inputChar("\n\t\tOption: ", string("abcd0"));
	clrScrn();

	return optionChar;
}

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
/// Precondition:
/// Postcondition: main driver, runs selected function
void runApplication()
{
	IntContainer container = IntContainer();
	while (true)
	{
		switch (appMenuOption())
		{
		case('0'):return;
		case('A'):container.addNumber(); break;
		case('B'):container.removeNumber(); break;
		case('C'):container.displaySet(); break;
		case('D'):container.displayFrequencies(); break;
		default:
			std::cout << "\nInvalid option";
		}
		pause();
	}
}