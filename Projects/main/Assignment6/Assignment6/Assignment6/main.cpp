//	Team Members:
//      Ben Halpern
//      Itz Rodriquez
//      Tony Cheng
//      Jose Chavez
//      Thien Nguyen
//      Jesus Sierra
//	Professor Q
//	CMPR 131
//	Assignment 6
//	10/7/21
//
//
//
//
//

#include <iostream>
#include <vector>
#include <list>
#include "input.h"
#include "mybag.h"
#include "templateMyBag.h"
#include "application.h"
using namespace std;

int main_menuOption();

int main()
{
    do
    {
        switch (main_menuOption())
        {
        case 0: exit(1); break;
        case (1): runMyBag(); break;
        case (2): runtemplateMyBag(); break;
        case (3): runApplication(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
        clrScrn();
    } while (true);

    return EXIT_SUCCESS;

}//end main

int main_menuOption()
{
    header("CMPR131 Chapter 6 - Assignmnet 6 by  Ben, Thien , Itz, Tony, Jose, and Jesus");
    string options[] = { "\n\t\t1> Non-template MyBag container of int",
                         "\n\t\t2> Template MyBag<double> container",
                         "\n\t\t3> Application using MyBag container",
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