//	Team Members:
//      Ben Halpern
//      Itz Rodriquez
//      Tony Cheng
//      Jose Chavez
//      Thien Nguyen
//      Jesus Sierra
//	Professor Q
//	CMPR 131
//	Assignment 7
//	10/19/21
//

/*
*
*
*
*
*
*/

#include <iostream>
#include "input.h"
#include "SimpleCalculator.h"
#include"Translation.h"
#include "NQueensProblem.h"
using namespace std;

int mainMenuOption();

int main()
{
    do
    {
        switch (mainMenuOption())
        {
        case 0: exit(1); break;
        case (1): runSimpleCalculator(); break;
        case (2): runTranslation(); break;
        case (3): runNQueenProblem(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
        clrScrn();
    } while (true);

    return EXIT_SUCCESS;

}//end main

int mainMenuOption()
{
    header("CMPR131 Chapter 7 - Assignmnet 7 by  Ben, Thien , Itz, Tony, Jose, and Jesus");
    string options[] = { "\n\t\t1> Simple Calculator (problem 10, pg 391)",
                         "\n\t\t2> Translation of arithmetic expression (problem 9, pg 391)",
                         "\n\t\t3> n-Queens Problem (problem 11, pg 391-292)",
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