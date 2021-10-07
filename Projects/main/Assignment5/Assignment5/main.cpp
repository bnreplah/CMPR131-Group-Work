//	Team Members:
//      Ben Halpern
//      Itz Rodriquez
//      Tony Cheng
//      Jose Chavez
//      Thien Nguyen
//      Jesus Sierra
//	Professor Q
//	CMPR 131
//	Assignment 5
//	10/1/21
// 
//	Description:
// 
//		3 main menu options:
//			1> Vector
//			2> LinkedList
//			3> Application using Vector and/or List container
// 
// Option 1 and 2 demonstrate the various functions of th vector and the list, demonstrating that we are knowledgable of their application an duse
//
// Option 3 you need to apply, asks for a driver function to act as a driver module of a single container ( Option d seems to be using both vectors and lists togther )
// 
//  __________________________________________________________
//  |              Main Menu                                 |
//  |________________________________________________________|
//	______________|______  ________________|____   ________|_____________
//  |	Option 1		|  |	Option 2	   |   |	Option 3		|
//  |___________________|  |___________________|   |____________________|
//    ______|________		 ____|___________		 _____|__________
//	  | Vector Drvr |        |	LinkedList  |        |	Both	    |
//    |_____________|        |______________|        |______________|

#include <iostream>
#include <vector>
#include <list>
#include "input.h"
#include "vector.h"
#include "list.h"

using namespace std;

int main_menuOption();

int main()
{
    do
    {
        switch (main_menuOption())
        {
        case 0: exit(1); break;
        case (1): runVector(); break;
        case (2): runLinkedList(); break;
        case (3): testing(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
    } while (true);

    return EXIT_SUCCESS;

}//end main

int main_menuOption()
{
    header("CMPR131 Chapter 5 - Assignmnet 5 by  Ben, Thien , Itz, Tony, Jose, and Jesus");
    string options[] = { "\n\t\t1> Vector container ",
                         "\n\t\t2> List container",
                         "\n\t\t3> Application using Vector and/or List container",
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