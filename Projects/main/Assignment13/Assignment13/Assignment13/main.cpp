/// File:    main.cpp
/// Team Members:
///          Itz Rodrigez 
///          Tony Cheng
///          Ben Halpern
///          Jose Chavez
///          Thien Nguyen
///          Jesus Sierra
/// Professor Q
/// CMPR 131
/// Assignment 13
/// 12/2/21
/// Description:
///
/// 
/// 
#pragma once
#include <iostream>
#include "input.h"
#include "myContainers.h"
#include "sortingSimulation.h"
#include "studentSort.h"

using namespace std;
int mainMenuOption();

int main()
{
    do
    {
        switch (mainMenuOption())
        {
        case 0: exit(0); break;
        case 1: runSortingSimulation(); break;
        case 2: runStudentSimulation(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
        clrScrn();
    } while (true);

    return EXIT_SUCCESS;
}

int mainMenuOption()
{
    header("CMPR131 Chapter 13 - Assignmnet 13 by  Ben, Thien , Itz, Tony, Jose, and Jesus");
    string options[] = { "\n\t\t1> Sorting simulations",
                         "\n\t\t2> Application of student records",
                         "\n\t" + string(100 , char(196)) +
                         "\n\t\t0 > Exit "
    };
    for (string option : options)
        cout << option;
    header("");

    int optionInteger = inputInteger("\n\t\tOption: ", 0, 2);
    clrScrn();

    return optionInteger;

}//end menuOptions