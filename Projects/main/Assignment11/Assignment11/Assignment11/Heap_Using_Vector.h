/// File:    Heap_Using_Vector.h
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
char HeapVectorOption();



void runHeapUsingVector()
{
    clrScrn();
    std::cout << "\n\t1> Heap using vector";

    do
    {
        switch (HeapVectorOption())
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

char HeapVectorOption()
{
    header("");
    cout << "\n\t\t  A> Min heap";
    cout << "\n\t\t  B> Max heap";
    cout << "\n\t\t  0> return\n";
    header("");

    int optionChar = inputChar("\n\t\tOption: ", string("ab0"));
    clrScrn();

    return optionChar;
}