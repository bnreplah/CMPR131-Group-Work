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
///							:
///							:
///							:




#pragma once
#include <iostream>
#include "input.h"


/// Precondition:
/// Postcondition:
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
	* 
	* 
	* 
	*/

	for (int i = 0; i < left; i++)
		std::cout << "  ";

	for (int i = 0; i < length; i++)
		std::cout << "* ";
	
	std::cout << "\n";
	//bottom half of the pattern

	/*if(debug == 1)*/ starPattern(left + length / 2, length / 2 );
	

}//end starPattern

/// Precondition: 
/// Postcondition:
void runStars() {
	header("\n\t1> Pattern of astricks and blanks");
	int num = inputInteger("\n\nEnter a postive number for the pattern: ",true);
	std::cout << "\n";//blank line for visibility
	starPattern(0, num);
	
}//end runStars