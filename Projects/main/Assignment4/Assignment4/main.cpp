//	Team Members:
//		Ben Halpern
//		Itz Rodriquez
//		Tony Cheng
//		Jose Chavez
//		Thien Nguyen
//	Professor Q
//	CMPR 131
//	Assignment 4
//	9/23/21
//
// Description: 
//		All the terms, polynomial, complex, and rational should all be stored within a dynamic datastructure
// 
// sample dataset:
//      Rational:		3/4,	4/8,	7/9,	6/12
//	    Polynomial:		x^2 + 3x,	x^3 - 3x,	3x^5 + 3x^3 - 3x
//	    Complex:		2 + i,	3 - i^2,	4x - i

#pragma once

#include <iostream>
#include <vector>
#include "input.h"
#include "Complex.h"
#include "Rational.h"
#include "Polynomials.h"
using namespace std;

//prototypes
int main_menuOption();
void Option1();
void Option2();
void Option3();

int main()
{
    do
    {
        switch (main_menuOption())
        {
        case 0: exit(1); break;
        case (1): Option1(); break;
        case (2): Option2(); break;
        case (3): Option3(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
    } while (true);

    return EXIT_SUCCESS;

}//end main

int main_menuOption()
{
    header("CMPR131 Chapter 4 - Assignmnet 4 by Thien , Itz, Tony, Jose, and Ben");
    string options[] = { "\n\t\t1 > Complex Numbers ",
                         "\n\t\t2 > Rational Numbers",
                         "\n\t\t3 > Polynomials",
                         "\n\t" + string(100 , char(196)) +
                         "\n\t\t0 > exit "
    };
    for (string option : options)
        cout << option;
    header("");

    int optionInteger = inputInteger("\n\t\tOption: ", 0, 3);
    clrScrn();
    return optionInteger;

}//end menuOptions

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Option driver functions
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Option1() 
{
    runComplex();


}

void Option2()
{
    runRational();
}

void Option3()
{
    runPolynomials();

}
