// File:
// Assignment:
// Professor:
// Team Members:
// 
// 
// 
// 
// Description:
//
//
//
//
//
#pragma once

#include <iostream>
#include <vector>
#include "input.h"
#include "TowerOfHanoi.h"
using namespace std;


//prototypes
int menuOption();




int main() {


    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;

        case 1: ; break;
        case 2:; break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
    } while (true);






    return EXIT_SUCCESS;


}


int menuOption() {

    header("CMPR131 Chapter 3 -  by Thien , Itz, Tony, Jose, and Ben");
    string options[] = { "\n\t\t1> List of Employees ",
                        "\n\t\t2> Pseudorandom",
                        "\n" + string(100 , char(196)) +
                        "\n\t\t0> exit "

    };
    for (string option : options)
        cout << option;
    header("");

    int optionInteger = inputInteger("\nOption: ", 0, 2);
    clrScrn();
    return optionInteger;

}//end menuOptions

