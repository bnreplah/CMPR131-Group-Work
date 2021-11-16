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

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runUnionAndIntersect()
{
    clrScrn();

    do
    {
        switch (UnionHeapOption())
        {
        case ('0'): return; break;
        case ('A'): ; break;
        case ('B'): ; break;
        case ('D'): ; break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    cout << "\n";
    pause();
    clrScrn();
}