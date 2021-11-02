#pragma once
/// Done in class alongside the professor
/// 10-27-21
/// Author: Ben Halpern
/// Description: need to validate your input 
///
/// 
#include <iostream>
#include "input.h"


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
	

}

void runStars() {
	header("\n\t1> Pattern of astricks and blanks");
	int num = inputInteger("\n\nEnter a postive number for the pattern: ",true);
	starPattern(0, num);
	
}