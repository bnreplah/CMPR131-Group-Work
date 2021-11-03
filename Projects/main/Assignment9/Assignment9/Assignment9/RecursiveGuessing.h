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
		std::cout << "\n\tYour number must be " << lowNum << " .";
		std::cout << "\n\tNumber of guesses : " << count << "\n\n";
		return;
	}

	int midpoint = (lowNum + highNum) / 2;
	char answer;
	string message = string();
	message =  "\n\tIs your number " + to_string(midpoint) + " ? (Y - Yes or N - No) : ";
	answer = inputChar(message,char('Y'),char('N'));

	switch (toupper(answer))
	{
	case 'Y':
	{
		std::cout << "\n\tThe number you were thinking of was " << midpoint;
		std::cout << "\n\tNumber of guesses : " << count;
	} break;
	case 'N':
	{
		message = "\n\tIs your number larger than " + to_string(midpoint) + " ?(Y - Yes or N - No) :";
		answer = inputChar(message, char('Y'), char('N'));

		switch (toupper(answer))
		{
		case 'Y': RecursiveGuessing(midpoint + 1, highNum, count); break;
		case 'N': RecursiveGuessing(lowNum, midpoint - 1, count); break;
		default: std::cout << "\n\tError: Invalid Input\n";
		}
	}break;
	default: std::cout << "\n\tError: Invalid Input\n";
	}
} 

/// Precondition:
/// Postcondition:
void runRecursiveGuessing() {

	header("\n\tRecursive Guessing Game ");

	srand(time(NULL));
	int countGuesses = 0;
	int highRange = rand() % 100 + 1;

	std::cout << "\n\tThink of a number from 1 to " << highRange << "...\n\n";
	pause();

	RecursiveGuessing(1, highRange, countGuesses);

}