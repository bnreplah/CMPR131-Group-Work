/// File:    Stars.h
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
///					Itz		:	11/14/2021
///							:
///							:

#pragma once
#include <iostream>
#include "input.h"

/// Precondition: Both parameters must be integer values
/// Postcondition: A recursive function tha will print out a diagram of stars relative to the values in the parameter
void starPattern(int left, int length) {
	//identify the stop case
	//int debug = 1;
	if (length == 0) return;//stop case
	//need spaces

	//case 1
	/*if(debug == 0)*/ starPattern(left, length / 2);//first half ( top part )
	std::cout << "\t";
	/*
	* Recursive thinking: 
	* 
	*/
	for (int i = 0; i < left; i++) // this will give the indentation between each stars
		std::cout << "  ";  
	for (int i = 0; i < length; i++) // this will print out the stars and an indentation to the right of the star
		std::cout << "* ";
	
	std::cout << "\n";
	//bottom half of the pattern

	/*if(debug == 1)*/ //Debugging Purposes
	 starPattern(left + length / 2, length / 2 ); //the recursive call

}//end starPattern
//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////

/// Precondition: N/A 
/// Postcondition: Will call a recursive function to print out a visual diagram of stars, in reference to the value given by the user
void runStars() {
	header("\n\t1> Pattern of astericks and blanks");
	int num = inputInteger("\n\nEnter a postive number for the pattern: ",true); //value input from the user
	std::cout << "\n";//blank line for visibility
	
	starPattern(0, num); // 
	
}//end runStars