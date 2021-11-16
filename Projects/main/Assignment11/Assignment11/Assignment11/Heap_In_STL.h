/// File:    Heap_In_STL.h
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

char HeapSTLOption()
{
    header("\n\t3> Heap in C++ STL");
    cout << "\n\t\tA> create a dynamic array";
    cout << "\n\t\tB> push_back() an element";
    cout << "\n\t\tC> make_heap()";
    cout << "\n\t\tD> front";
    cout << "\n\t\tE> push_heap()";
    cout << "\n\t\tF> pop_heap()";
    cout << "\n\t\tG> sort_heap()";
    cout << "\n\t\tH> is_heap()";
    cout << "\n\t\tI> is_heap_until()";
    cout << "\n\t\tJ> display";
    cout << "\n\t" + string(100, char(196));
    cout << "\n\t\t0> return\n";
    header("");

    int optionChar = inputChar("\n\t\tOption: ", string("abcdefghij0"));
    clrScrn();

    return optionChar;
}

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runHeapInSTL()
{
    clrScrn();

    do
    {
        switch (HeapSTLOption())
        {
        case ('0'): return; break;
        case ('A'): ; break;
        case ('B'): ; break;
        case ('D'): ; break;
        case ('E'): ; break;
        case ('F'): ; break;
        case ('G'): ; break;
        case ('H'): ; break;
        case ('I'): ; break;
        case ('J'): ; break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    cout << "\n";
    pause();
    clrScrn();
}