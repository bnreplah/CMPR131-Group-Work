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

#pragma once

#include <iostream>
#include <list>
#include <vector>
#include "input.h"

//prototypes
/*
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