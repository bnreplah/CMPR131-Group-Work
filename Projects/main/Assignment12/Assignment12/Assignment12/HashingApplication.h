/// File:    HashingApplication.h
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
/// 11/24/21
/// Description:
///
/// 
///
/// 
/// Reviewed:
///  

#pragma once

#include <iostream>
#include "input.h"
#include "Student.h"
#include <fstream>
#include"SortedArray.h"
#include "UnsortedArray.h"

void optionA(vector<Student> &arr,int size) {
    
    ifstream file = ifstream();

    if (file.good()){
        file.open("Students.dat");
        if (file.is_open() && file.good())
        {
            while (!file.eof())
            {
                Student tempStudent;
                file >> tempStudent;
                cout << "\nTemp Student #: " << tempStudent.getID() % size;
                cout << " Temp Student ID: " << tempStudent.getID();
            }

        }
        else {
            cout << "\n\t\tERROR: File does not exists.\n";
        }
        file.close();
    }

}

char hashingOption()
{
    
    header("\n\t3> Application using hashing");
    std::cout << "\n\t\tA> Read data file, hash and insert into the dynamic array";
    std::cout << "\n\t\tB> Search an element from the dynamic array";
    std::cout << "\n\t\tC> Insert an element from the dynamic array";
    std::cout << "\n\t\tD> Remove an element from the dynamic array";
    std::cout << "\n\t\tE> Display all records from the array";
    std::cout << "\n\t" + string(100, char(196));
    std::cout << "\n\t\t0> return\n";
    header("");

    int optionChar = inputChar("\n\t\tOption: ", string("abcde0"));
    clrScrn();

    return optionChar;
}

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runHashingApplication()
{
    clrScrn();
    vector<Student> myArray;

    do
    {
        switch (hashingOption())
        {
        case ('0'): return; break;
        case ('A'):optionA(myArray, 10); break;
        case ('B'):break;
        case ('C'):break;
        case ('D'):break;
        case ('E'):break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    std::cout << "\n";
    pause();
    clrScrn();
}