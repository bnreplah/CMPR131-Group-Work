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
//
#include "input.h"
#include "TreeStrings.h"
#include "AnimalGuess.h"
#include "BinTree.h"
#include <iostream>
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
        case 2: runBinTree(); break;
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
    //testing bTree
    Tree<int> testingTree = Tree<int>();
    std::cout << "\ninitial size of the tree: " << testingTree.getSize(testingTree.nodePtr);
    std::cout << "\nadding items to the tree: (1)"; testingTree.insertNode(1);
    std::cout << "\nadding items to the tree: (2)"; testingTree.insertNode(2);
    std::cout << "\nadding items to the tree: (3)"; testingTree.insertNode(3);
    std::cout << "\nadding items to the tree: (4)"; testingTree.insertNode(4);
    std::cout << "\nadding items to the tree: (5)"; testingTree.insertNode(5);
    std::cout << "\nadding items to the tree: (0)"; testingTree.insertNode(0);
    std::cout << "\nadding items to the tree: (-1)"; testingTree.insertNode(-1);
    std::cout << "\nadding items to the tree: (-2)"; testingTree.insertNode(-2);
    std::cout << "\nadding items to the tree: (-5)"; testingTree.insertNode(-5);
    testingTree.resetNodePtr();
    std::cout << "\n";
    printTree("",testingTree.nodePtr, false, true, false);

    testingTree.resetNodePtr();
    if (testingTree.leftLast())
        std::cout << "\nleft last " << testingTree.leftLast()->getValue();
    //testingTree.leftLastParent();

    testingTree.resetNodePtr();
    if (testingTree.rightLast())
        std::cout << "\nright last " << testingTree.rightLast()->getValue();
    
    testingTree.resetNodePtr();
    if (testingTree.rightLastParent())
        std::cout << "\nright last parent: " << testingTree.rightLastParent()->getValue();
    
    testingTree.resetNodePtr();
    if (testingTree.leftLastParent())
        std::cout << "\nleft last parent: " << testingTree.leftLastParent()->getValue();




    testingTree.inOrder(testingTree.nodePtr);
    std::cout << "\n";
    testingTree.preOrder(testingTree.nodePtr);
    std::cout << "\n";
    testingTree.postOrder(testingTree.nodePtr);
    
    pause();
}