// Assignment 4
// Professor Q
// CMPR 131 09/20/21
// Team members:
// 
//	
// 
// 
// Description: 
//		All the terms, polynomial, complex, and rational should all be stored within a dynamic datastructure
// 
// sample dataset:
//	Rational:		3/4,	4/8,	7/9,	6/12
//	Polynomial:		x^2 + 3x,	x^3 - 3x,	3x^5 + 3x^3 - 3x
//	Complex:		2 + i,	3 - i^2,	4x - i






#include <iostream>
#include "Polynomials.h"
#include "Complex.h"
#include "Rational.h"
#include "input.h"
//#include "myContainers.h"
using namespace std;


//prototypes
void Option1();
void Option2();
void Option3();

//main driver
int main() {


	do {
		
		//menu


		//end menu
		int option = int();
		option = inputInteger("\tOption: ", 0, 2);
		
		switch (option) {
		case (0): return;
		case (1): Option1(); break;
		case (2): Option2(); break;

		}//end



	} while (true);





}//end main



/// Precondition:
/// Postcondition:
void Option1() {
	runPoly();


}//end Option1()

/// Precondition:
/// Postcondition:
void Option2() {
	runComplex();



}//end Option2()

/// 
/// 
void Option3() {
	runRational();


}//