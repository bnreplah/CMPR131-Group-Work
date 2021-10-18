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
//	Program Specification:
// 
//		3 main menu options:
//			1> Vector Container
//			2> List Container
//			3> Application using Vector and/or List container
// 
//      Option 1 and 2 demonstrate the various functions of the vector and the list, demonstrating that we are knowledgeable of their application and use
//      Option 3 you need to apply, asks for a driver function to act as a driver module of a single container ( Option d seems to be using both vectors and lists together )

/***[Description]
*	Naming Conventions:
*       [tags] are used to define design element comments such as this one and those of [const] for constant members and accesors, and [mutator] for mutator methods
*           When the tag is lower case the design element is a local comment, when the first letter is capitalized the design element is a gloabl tag relating to a comment with a scope pertaining to 
*           the document as a whole.
*       The names of classses are capitalized following the CamelHump naming convention
*       'm' is used as a prefix to defined private members of a class following the CamelHump naming convention
*       'p' is used as a prefix to define formal paramters of methods following the CamelHump naming convention
*   
*   Condition Documentation:    
*       prior to functions, the documentation of the precondition and postcondition are described with three brackets so that the descriptions would work with Microsoft Visual Studio InteliSense,
*           which produces would then display the precondition and postcondition when as a tip when the function is being implemented in the various parts of the program.
*
*   Class Invarients:
*       Class invarients provide a list of the various methods in each classes and provide a short description outlining the use and implimentation notes for that class. The methods in the class invariant don't provide formal parameters
*           but instead they show the datatype of each formal parameter in a similiar format and style that might be seen in a protoype declaration.
*       
*   Flow, Structural, and Document comments are seen throughout the code and are noted by the use of only two forward slashes '//' when defining the comments 
*       A series of '###' may be used to denote flow indicator to help the programmer navigate the various classes
* 
*/


#include <iostream>
#include <vector>
#include <list>
#include "input.h"
#include "Vector.h"
#include "List.h"
#include "Application.h"
using namespace std;


//prototypes
int main_menuOption();

/// Precondition: N/A
/// Postcondition: The main menu driver, driving the VectorDriver Class, the ListDriver Class, and the IntContainer Class. 
int main()
{
    do
    {
        switch (main_menuOption())
        {
        case (0): exit(1);                                                  break;
        case (1): runVector();                                              break;
        case (2): runLinkedList();                                          break;
        case (3): runApplication();                                         break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter.";    break;
        }
        cout << "\n";
        pause();
        clrScrn();
    } while (true);

    return EXIT_SUCCESS;

}//end main

int main_menuOption()
{
    //start instantiation
    int optionInteger = int();
    //end instantiation and initialization

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

    optionInteger = inputInteger("\n\t\tOption: ", 0, 3);
    return optionInteger;

}//end menuOptions