// Team Members:
//
//              Ben Halpern
//
//  Description:
//      
//      
#pragma once
#include <iostream>
#include "EmployeeList.h"
#include "Pseudorandom.h"
#include "input.h"

using namespace std;
int menuOption();


int main() {
    Pseudorandom test;
    //end intialization

    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;

        case 1: runEmployeeList(); break;
        case 2: runPseudorandom(test); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
    } while (true);






	return 0;
}



int menuOption() {

    header("CMPR131 Chapter2 - ADT Assignments by Thien , Itz, Tony, Jose, and Ben");
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
