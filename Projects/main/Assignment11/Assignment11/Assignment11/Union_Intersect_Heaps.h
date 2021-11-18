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
#include <ctime>


using namespace std;

/// Precondition: 
/// Postcondition: 
char UnionHeapOption()
{
    header("\n\t2> Union and intersect heap");
    cout << "\n\t\tA> Union two max Heaps";
    cout << "\n\t\tB> Intersect two max Heaps";
    cout << "\n\t\tC> Union two min Heaps";
    cout << "\n\t\tD> Intersect two min Heaps";
    cout << "\n\t" + string(100, char(196));
    cout << "\n\t\t0> return\n";
    header("");

    int optionChar = inputChar("\n\t\tOption: ", string("abcd0"));
    clrScrn();

    return optionChar;
}

void unionTwoMaxHeaps(heap<int> heapOne, heap<int> heapTwo){

    heap<int> unionMaxHeap = heap<int>(false);





}


void interceptTwoMaxHeaps(heap<int> heapOne, heap<int> heapTwo) {

    heap<int> interMaxHeap = heap<int>(false);

}


void unionTwoMinHeaps(heap<int> heapOne, heap<int> heapTwo) {

    heap<int> unionMinHeap = heap<int>(true);


}

void interceptTwoMinHeaps(heap<int> heapOne, heap<int> heapTwo) {

    heap<int> interMinHeap = heap<int>(true);


}

void removeEntry(){


}

void populateHeap( heap<int> &myHeap){
   
    srand(time(0));
    for (int i = 0; i < 12; i++){
        int temp = rand() % 10+1;
        myHeap.push(temp);
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

    populateHeap(myMinHeapOne);
    populateHeap(myMinHeapTwo);
    populateHeap(myMaxHeapOne);
    populateHeap(myMaxHeapTwo);


    do
    {
        switch (UnionHeapOption())
        {
        case ('0'): return; break;
        case ('A'):unionTwoMaxHeaps(myMaxHeapOne,myMaxHeapTwo); break;
        case ('B'):interceptTwoMaxHeaps(myMaxHeapOne,myMaxHeapTwo) ; break;
        case ('C'):unionTwoMinHeaps(myMinHeapOne,myMinHeapTwo) ; break;
        case ('D'):interceptTwoMinHeaps(myMinHeapOne,myMinHeapTwo); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    cout << "\n";
    pause();
    clrScrn();
}