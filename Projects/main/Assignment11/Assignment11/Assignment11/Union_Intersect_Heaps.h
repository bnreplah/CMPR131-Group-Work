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

//prototypes:
char UnionHeapOption();



void runUnionAndIntersect()
{
    clrScrn();
    std::cout << "\n\t2> Union and intersect heap";

    do
    {
        switch (UnionHeapOption())
        {
        case ('0'): return; break;
        case ('A'):; break;
        case ('B'):; break;
        case ('D'):; break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    cout << "\n";
    pause();
    clrScrn();
}

char UnionHeapOption()
{
    header("");
    cout << "\n\t\t  A> Union two max Heaps";
    cout << "\n\t\t  B> Intersect two max Heaps";
    cout << "\n\t\t  C> Union two min Heaps";
    cout << "\n\t\t  D> Intersect two min Heaps";
    cout << "\n\t\t  0> return\n";
    header("");

    int optionChar = inputChar("\n\t\tOption: ", string("abcd0"));
    clrScrn();

    return optionChar;
}