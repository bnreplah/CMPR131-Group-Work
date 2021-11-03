/// File:    RecursiveGuessing.h
/// Completed: 10/27/21
/// Team Members:
///          Itz Rodrigez 
///          Tony Cheng
///          Ben Halpern
///          Jose Chavez
///          Thien Nguyen
///          Jesus Sierra
/// Professor Q
/// CMPR 131
/// Assignment 9
/// 11/1/21
/// Description:
///
/// 
/// Reviewed by:	[Name]	:	[Date]
///					Ben		:	11/2/21
///							:
///							:

#pragma once
#include <iostream>
#include <time.h>
#include "input.h" 



/// Precondition:
/// Postcondition:
void RecursiveGuessing(int lowNum, int highNum, int& count)
{
	count++;
	if (lowNum >= highNum)
	{
		std::cout << "\nYour number must be " << lowNum << " .";
		std::cout << "\nNumber of guesses : " << count << "\n\n";
		return;
	}

	int midpoint = (lowNum + highNum) / 2;
	char answer;
	std::cout << "\nIs your number " << midpoint << " ?  ";
	answer = inputChar("(Y - Yes or N - No) :",char('Y'),char('N'));

	switch (toupper(answer))
	{
	case 'Y':
	{
		std::cout << "\nThe number you were thinking of was " << midpoint;
		std::cout << "\nNumber of guesses : " << count;
	} break;
	case 'N':
	{
		std::cout << "\nIs your number larger than " << midpoint << " ?";
		answer = inputChar("(Y - Yes or N - No) :", char('Y'), char('N'));

		switch (toupper(answer))
		{
		case 'Y': RecursiveGuessing(midpoint + 1, highNum, count); break;
		case 'N': RecursiveGuessing(lowNum, midpoint - 1, count); break;
		default: std::cout << "\nError: Invalid Input\n";
		}
	}break;
	default: std::cout << "\nError: Invalid Input\n";
	}
} 

/// Precondition:
/// Postcondition:
void runRecursiveGuessing() {

	header("\n\tRecursive Guessing Game ");

	srand(time(NULL));
	int countGuesses = 0;
	int highRange = rand() % 100 + 1;

	std::cout << "\nThink of a number from 1 to " << highRange << "...\n\n";
	system("pause"); 

	RecursiveGuessing(1, highRange, countGuesses);

}