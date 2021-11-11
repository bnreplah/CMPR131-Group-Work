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
/// Assignment 10
/// 11/6/21
/// Description:
///
/// 
//

#include <iostream>
#include "input.h"
#include "TreeStrings.h"
#include "AnimalGuess.h"
;
using namespace std;
int mainMenuOption();
void test();


int main()
{

    test();
    pause();
    do
    {
        switch (mainMenuOption())
        {
        case 0: exit(0); break;
        case 1: runTreeStrings(); break;
        case 2:; break;
        case 3: runAnimalGuess(); break;
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

    header("CMPR131 Chapter 10 - Assignmnet 10 by  Ben, Thien , Itz, Tony, Jose, and Jesus");
    string options[] = { "\n\t\t1> Tree of Strings",
                         "\n\t\t2> Tree container of integers",
                         "\n\t\t3> Animal Gussing Game",
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


void test() {
    Tree<int> myTree = Tree<int>();
    myTree.insertNode(5);
    std::cout << "\n" << myTree.nodePtr << "\n";
    myTree.insertNode(9);
    myTree.resetNodePtr();
    std::cout << "\n" << myTree.nodePtr->getRight()->getValue() << "\n";
    std::cout << myTree[0]->getValue();
    
    pause();
}