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
/// Assignment 11
/// 11/15/21
/// Description:
///
/// 
/// 

#include <iostream>
#include "input.h"
#include "myContainers.h"
#include "Heap_In_STL.h"
#include "Union_Intersect_Heaps.h"
#include "Heap_Using_Vector.h"
using namespace std;
int mainMenuOption();

void runTests() {

}

int main()
{
    runTests();
    pause();

    do
    {
        switch (mainMenuOption())
        {
        case 0: exit(0); break;
        case 1: runHeapUsingVector(); break;
        case 2: runUnionAndIntersect(); break;
        case 3: runHeapInSTL(); break;
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
    header("CMPR131 Chapter 11 - Assignmnet 11 by  Ben, Thien , Itz, Tony, Jose, and Jesus");
    string options[] = { "\n\t\t1> Heap using vector",
                         "\n\t\t2> Union and intersect of heaps",
                         "\n\t\t3> Heap in C++ STL",
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