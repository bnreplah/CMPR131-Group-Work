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

//prototypes:
char HeapSTLOption();



void runHeapInSTL()
{
    clrScrn();
    std::cout << "\n\t3> Heap in C++ STL";

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

char HeapSTLOption()
{
    header("");
    cout << "\n\t\t  A> create a dynamic array";
    cout << "\n\t\t  B> push_back() an element";
    cout << "\n\t\t  C> make_heap()";
    cout << "\n\t\t  D> front";
    cout << "\n\t\t  E> push_heap()";
    cout << "\n\t\t  F> pop_heap()";
    cout << "\n\t\t  G> sort_heap()";
    cout << "\n\t\t  H> is_heap()";
    cout << "\n\t\t  I> is_heap_until()";
    cout << "\n\t\t  J> display";
    cout << "\n\t\t  0> return\n";
    header("");

    int optionChar = inputChar("\n\t\tOption: ", string("abcdefghij0"));
    clrScrn();

    return optionChar;
}