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
///					Itz		:	11/14/21
///							:

#pragma once
#include <iostream>
#include <time.h>
#include "input.h" 

/// Precondition: Three parameters must be integer values that provide the range and the initial count of guesses 
/// Postcondition: Will use a recursion function to binary search the number the user is thinking of
void RecursiveGuessing(int pLowNum, int pHighNum, int& pCount){
	
	pCount++; //keeps count of the recursive calls
	if (pLowNum >= pHighNum){
		std::cout << "\n\tYour number must be " << pLowNum << " ."; // A guess from the program is given
		std::cout << "\n\tNumber of guesses : " << pCount << "\n\n"; // the number of current guesses is given
		return;
	}

	int midpoint = (pLowNum + pHighNum) / 2; // Will calculate the the midpoint 
	char answer; 

	string message = string();
	message =  "\n\tIs your number " + to_string(midpoint) + " ? (Y - Yes or N - No) : "; // ask the user if the midpoint is the number that they're thinking of
	answer = inputChar(message,char('Y'),char('N')); // User will input whether the the guess is correct,('Y' = yes, 'N' = no)

	switch (answer){
	case 'Y':{ // if the guess is correct this case will output
		std::cout << "\n\tThe number you were thinking of was " << midpoint; 
		std::cout << "\n\tNumber of guesses : " << pCount;
	}//end case 'Y' 
			break;
	case 'N':{// if the guess is incorrect and user inputs 'N', the following will execute
		message = "\n\tIs your number larger than " + to_string(midpoint) + " ?(Y - Yes or N - No) :";
		answer = inputChar(message, char('Y'), char('N'));// User will input whether the the guess is correct,('Y' = yes, 'N' = no)
		
		switch (answer){
		case 'Y': RecursiveGuessing(midpoint + 1, pHighNum, pCount); break;// User will input whether the the guess is larger than the program's guess,('Y' = yes, 'N' = no)
		case 'N': RecursiveGuessing(pLowNum, midpoint - 1, pCount); break; // will call the recursive function with the new parameters
		default: std::cout << "\n\tError: Invalid Input\n"; // to catch any error
		
		}//end switch
	}//end Case 'N'
			break;
	default: std::cout << "\n\tError: Invalid Input\n";// to catch any error
	}// end switch
} 

/// Precondition: N/A
/// Postcondition: Will run a recursive function that will ask a user to think of a number and the program will try to guess in a binary search manner
void runRecursiveGuessing() {

	header("\n\tRecursive Guessing Game ");
	
	srand(time(NULL)); // this will be used to create a random integer used as the maximum range for the user to guess
	int countGuesses = 0; // keep track of the guesses the program has given
	int highRange = rand() % 100 + 1; // will keep the guessing range to maximum of 100 and a minimum of 1

	std::cout << "\n\tThink of a number from 1 to " << highRange << "...\n\n";
	pause();

	RecursiveGuessing(1, highRange, countGuesses); // initial call to the recursive function

}