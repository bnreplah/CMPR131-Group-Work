#pragma once
#include "costco.h"
#include "EmergencyRoom.h"
#include "War.h"
#include "Patient.h"
#include "input.h"
#include <iostream>
using namespace std;

void option2();


int main() {
    do
    {
        switch (mainMenuOption())
        {
        case 0: exit(1); break;
        case (1): runWar(); break;
        case (2): runEmergencyRoom(); break;
        case (3): runCostcoLine(); break;
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






