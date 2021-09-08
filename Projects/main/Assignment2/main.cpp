// Team Members:
//
//
//
//





#pragma once
#include "input.h"
#include "Pseudorandom.h"
#include "EmployeeList.h"
#include <iostream>
using namespace std;




int main() {

    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;

        case 1: runEmployeeList(); break;
        case 2: runPseudorandom(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
    } while (true);






	return EXIT_SUCCESS;
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
