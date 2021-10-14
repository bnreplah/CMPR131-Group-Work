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
/**
* Assignment description:
*   Design, develop, and test classes as follow:
*
*   1) Create a regular non-template class called MyBag for dynamic array of integers. The class is based from a list class and must have the follow members:
*
*       Private attributes:
*       A pointer variable to a dynamic array of integers.
*       A size variable to keep track the number of elements in the array.
*       A capacity variable keep track the capacity of the dynamic array for growth and reduction. 
*       constructor(s) and destructor
*       accessors and mutators
*       friend functions
*   2) Create a template class called MyBag (same name) for dynamic array of double. The class is based from step #1.
*   
*   3) Create a class called Course that have the following requirements:
*   
*   variables (attributes):
*       A string stores the name of course
*       myBag of integers stores a collection of registered student IDs
*       myBag of strings stores a collection of registered student names
*       myBag of doubles stores a collection of registered student scores
*       myBag of chars stores a collection of registered student grades
*       constructor(s) and destructor
*       accessors and mutators
*       friend function(s) 
*   Write a driven-menu program that performs the following options:
*   
*   0. Exit the program.
*   1. Non-template MyBag 
*   2. Template MyBag
*   3. Application using MyBag
*   
*   Option1 utilizes the non-template MyBag of integers to:
*       clear
*       insert
*       search
*       remove
*       sort
*       display
*   Option2 utilizes the template MyBag of doubles to perform the same operations from option#1.
*   Option3 utilizes the Course class and performs:
*       create a dynamic array of courses
*       read data from text files and insert into the courses structures
*       search for student's ID or name from a course
*       remove a student record from a course
*       display courses' information
*/

#include <iostream>
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
        case (1): runMyBag_int(); break;
        case (2): break;//runtemplateMyBag(); break;
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