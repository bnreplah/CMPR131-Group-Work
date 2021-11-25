/// File:    Union_Intersect_Heaps.h
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

#pragma once

#include<iostream>
#include"input.h"
#include "Heap_Using_Vector.h"
#include <random>
#include <vector>

using namespace std;

/// Precondition: N/A
/// Postcondition: Will output the menu options
char UnionHeapOption()
{
    header("\n\t2> Union and intersect heap");
    std::cout << "\n\t\tA> Union two max Heaps";
    std::cout << "\n\t\tB> Intersect two max Heaps";
    std::cout << "\n\t\tC> Union two min Heaps";
    std::cout << "\n\t\tD> Intersect two min Heaps";
    std::cout << "\n\t" + string(100, char(196));
    std::cout << "\n\t\t0> return\n";
    header("");

    int optionChar = inputChar("\n\t\tOption: ", string("abcd0"));
    clrScrn();

    return optionChar;
}
/// Precondition: The two class objects must be initialized
/// Postcondition: Will push unique values from both heaps onto a third heap and display it
void unionTwoMaxHeaps(heap<int> heapOne, heap<int> heapTwo) {

    heap<int> unionMaxHeap = heap<int>(false); //initialize the union heap

    heap<int>* smallHeap = nullptr;     //initialize the union heap pointer for the smaller heap
    heap<int>* bigHeap = nullptr;       //initialize the union heap pointer for the bigger heap

    //determine which heap is bigger and assign the respective pointer
    if (heapOne.getSize() > heapTwo.getSize()) {
        smallHeap = &heapTwo;
        bigHeap = &heapOne;
    }
    else {
        bigHeap = &heapTwo;
        smallHeap = &heapOne;
    }

    //output the two heaps and their values
    std::cout << "bigger Heap\n";
    std::cout << "__________\n";
    (*bigHeap).displayAll();
    std::cout << "smaller Heap\n";
    std::cout << "__________\n";
    (*smallHeap).displayAll();

    //loop through all the values in the small heap
    for (size_t i = 0; i < (*smallHeap).getSize(); i++)
    {

        //checks if the value is the same as the one in the big heap and if it already exists in the unionMaxHeap
        if ((*smallHeap)[i] == (*bigHeap)[i] && !unionMaxHeap.exist((*smallHeap)[i]))
        {
            //will push the value into the unionMaxHeap
            unionMaxHeap.push((*smallHeap)[i]);
            continue;
        }
        //checks if 
        else if ((*smallHeap)[i] != (*bigHeap)[i] && !unionMaxHeap.exist((*smallHeap)[i]))
        {
            unionMaxHeap.push((*smallHeap)[i]);
            unionMaxHeap.push((*bigHeap)[i]);
        }
    }
    //int remaining = (*bigHeap).getSize() - (*smallHeap).getSize();
    int offset = (*smallHeap).getSize();
    for (size_t i = offset; i < (*bigHeap).getSize(); i++)
    {
        if (!unionMaxHeap.exist((*bigHeap)[i]))
        {
            unionMaxHeap.push((*bigHeap)[i]);
            continue;
        }
    }
    cout << "\n\tUnion Heap" << endl;
    cout << "_________________________________" << endl;
    unionMaxHeap.makeHeap();
    unionMaxHeap.displayAll();
}
/// Precondition: The two class objects must be initialized
/// Postcondition: Will push unique values from both heaps onto a third heap and display it
void unionTwoMinHeaps(heap<int> heapOne, heap<int> heapTwo) {

    heap<int> unionMinHeap = heap<int>(true); //initialize the union heap

    heap<int>* smallHeap = nullptr;     //initialize the union heap pointer for the smaller heap
    heap<int>* bigHeap = nullptr;       //initialize the union heap pointer for the bigger heap


    //determine which heap is bigger and assign the respective pointer
    if (heapOne.getSize() > heapTwo.getSize()) {
        smallHeap = &heapTwo;
        bigHeap = &heapOne;
    }
    else {
        bigHeap = &heapTwo;
        smallHeap = &heapOne;
    }

    //output the two heaps and their values
    std::cout << "bigger Heap\n";
    std::cout << "__________\n";
    (*bigHeap).displayAll();
    std::cout << "smaller Heap\n";
    std::cout << "__________\n";
    (*smallHeap).displayAll();

    //loop through all the values in the small heap
    for (size_t i = 0; i < (*smallHeap).getSize(); i++)
    {
        //checks if the value is the same as the one in the big heap and if it already exists in the unionMaxHeap
        if ((*smallHeap)[i] == (*bigHeap)[i] && !unionMinHeap.exist((*smallHeap)[i]))
        {
            //will push the value into the unionMaxHeap
            unionMinHeap.push((*smallHeap)[i]);
            continue;
        }
        //checks if 
        else if ((*smallHeap)[i] != (*bigHeap)[i] && !unionMinHeap.exist((*smallHeap)[i]))
        {
            unionMinHeap.push((*smallHeap)[i]);
            unionMinHeap.push((*bigHeap)[i]);
        }
    }

    //int remaining = (*bigHeap).getSize() - (*smallHeap).getSize();
    int offset = (*smallHeap).getSize();
    for (size_t i = offset; i < (*bigHeap).getSize(); i++)
    {
        if (!unionMinHeap.exist((*bigHeap)[i]))
        {
            unionMinHeap.push((*bigHeap)[i]);
            continue;
        }
    }
    cout << "\n\tUnion Heap" << endl;
    cout << "_________________________________" << endl;
    unionMinHeap.makeHeap();
    unionMinHeap.displayAll();
}

/// Precondition: The two class objects must be initialized
/// Postcondition: Will push duplicate values from both heaps onto a third heap and display it
void interceptTwoMaxHeaps(heap<int> heapOne, heap<int> heapTwo) {

    heap<int> interceptMaxHeap = heap<int>(false); //initialize the union heap
    heap<int>* smallHeap = nullptr;     //initialize the union heap pointer for the smaller heap
    heap<int>* bigHeap = nullptr;       //initialize the union heap pointer for the bigger heap

    //determine which heap is bigger and assign the respective pointer
    if (heapOne.getSize() > heapTwo.getSize()) {
        smallHeap = &heapTwo;
        bigHeap = &heapOne;
    }
    else {
        bigHeap = &heapTwo;
        smallHeap = &heapOne;
    }
    //output the two heaps and their values
    std::cout << "bigger Heap\n";
    std::cout << "__________\n";
    (*bigHeap).displayAll();
    std::cout << "smaller Heap\n";
    std::cout << "__________\n";
    (*smallHeap).displayAll();

    //loop through all the values in the small heap
    for (size_t i = 0; i < (*smallHeap).getSize(); i++)
    {
        if ((*bigHeap).exist((*smallHeap)[i]) && !interceptMaxHeap.exist((*smallHeap)[i]))
        {
            interceptMaxHeap.push((*smallHeap)[i]);
        }
    }
    cout << "\n\tIntercept Heap" << endl;
    cout << "_________________________________" << endl;
    interceptMaxHeap.makeHeap();
    interceptMaxHeap.displayAll();
}

/// Precondition: The two class objects must be initialized
/// Postcondition: Will push duplicate values from both heaps onto a third heap and display it 
void interceptTwoMinHeaps(heap<int> heapOne, heap<int> heapTwo) {
    heap<int> interceptMinHeap = heap<int>(true); //initialize the union heap

    heap<int>* smallHeap = nullptr;     //initialize the union heap pointer for the smaller heap
    heap<int>* bigHeap = nullptr;       //initialize the union heap pointer for the bigger heap


    //determine which heap is bigger and assign the respective pointer
    if (heapOne.getSize() > heapTwo.getSize()) {
        smallHeap = &heapTwo;
        bigHeap = &heapOne;
    }
    else {
        bigHeap = &heapTwo;
        smallHeap = &heapOne;
    }

    //output the two heaps and their values
    std::cout << "bigger Heap\n";
    std::cout << "__________\n";
    (*bigHeap).displayAll();
    std::cout << "smaller Heap\n";
    std::cout << "__________\n";
    (*smallHeap).displayAll();

    //loop through all the values in the small heap
    for (size_t i = 0; i < (*smallHeap).getSize(); i++)
    {
        if ((*bigHeap).exist((*smallHeap)[i]) && !interceptMinHeap.exist((*smallHeap)[i]))
        {
            interceptMinHeap.push((*smallHeap)[i]);
        }
    }
    cout << "\n\tIntercept Heap" << endl;
    cout << "_________________________________" << endl;
    interceptMinHeap.makeHeap();
    interceptMinHeap.displayAll();
}

/// Precondition: Class object must be initialized
/// Postcondition: Randomly populate the heap with integer values
<<<<<<< HEAD
void populateHeap(heap<int>& myHeap, int size = 12) {

    for (int i = 0; i < size; i++) {
        int temp = static_cast<int>(rand() % 10 + 1);
        myHeap.push(temp);
=======
void populateHeap( heap<int> &myHeap,int size = 12){
   
    for (int i = 0; i < size; i++){
        myHeap.push(randomNum());
>>>>>>> bc6f7e342b6b15209577e22c92c47b15677852a2
    }
}





//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////

// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runUnionAndIntersect()
{
    clrScrn();
    heap<int> myMinHeapOne = heap<int>(true);
    heap<int> myMinHeapTwo = heap<int>(true);
    heap<int> myMaxHeapOne = heap<int>(false);
    heap<int> myMaxHeapTwo = heap<int>(false);

   
    int loopVar = 10;// randomNum();

    populateHeap(myMaxHeapOne);
    myMaxHeapOne.makeHeap();
    populateHeap(myMaxHeapTwo);
    myMaxHeapTwo.makeHeap();
    populateHeap(myMinHeapOne);
    myMinHeapOne.makeHeap();
    populateHeap(myMinHeapTwo);
    myMinHeapTwo.makeHeap();
    do
    {
        switch (UnionHeapOption())
        {
        case ('0'): return; break;
        case ('A'):unionTwoMaxHeaps(myMaxHeapOne, myMaxHeapTwo); break;
        case ('B'):interceptTwoMaxHeaps(myMaxHeapOne, myMaxHeapTwo); break;
        case ('C'):unionTwoMinHeaps(myMinHeapOne, myMinHeapTwo); break;
        case ('D'):interceptTwoMinHeaps(myMinHeapOne, myMinHeapTwo); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    cout << "\n";
    pause();
    clrScrn();
}