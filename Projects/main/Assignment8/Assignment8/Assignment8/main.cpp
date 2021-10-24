#pragma once
#include "costco.h"
#include "EmergencyRoom.h"
#include "War.h"
#include "Patient.h"
#include "input.h"
#include <iostream>
using namespace std;

//void option2();
int mainMenuOption();


int main() {
    do
    {
        switch (mainMenuOption()){
        case (0): exit(0); break;
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
    header("CMPR131 Chapter 8 - Assignmnet 8 by  Ben, Thien , Itz, Tony, Jose, and Jesus");
    string options[] = { "\n\t\t1> War (card game)",
                         "\n\t\t2> Emergency room simulation",
                         "\n\t\t3> Costco queue simulation",
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






