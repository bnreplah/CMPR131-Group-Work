/// File:    sortingSimulation.h
/// Team Members:
///          Itz Rodrigez 
///          Tony Cheng
///          Ben Halpern
///          Jose Chavez
///          Thien Nguyen
///          Jesus Sierra
/// Professor Q
/// CMPR 131
/// Assignment 13
/// 12/2/21
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

void readDataFile() {

}

void displayRecords() {


}

void insertRecord() {

}

void removeRecord() {

}

void sortRecords() {


}

void writeDataFile() {


}

//precondition: N/A
//postcondition: will output the menu options
char sortStudentOption()
{
    header("\n\t2> Application of sorting student records");
    std::cout << "\n\t\tA> Read in data file";
    std::cout << "\n\t\tB> Display records";
    std::cout << "\n\t\tC> Insert a record";
    std::cout << "\n\t\tD> Remove a record";
    std::cout << "\n\t\tE> Sort records by ID, name, major or GPA";
    std::cout << "\n\t\tF> Write out data file";
    std::cout << "\n\t" + string(100, char(196));
    std::cout << "\n\t\t0> return\n";
    header("");

    int optionChar = inputChar("\n\t\tOption: ", string("abcdef0"));
    clrScrn();

    return optionChar;
}


//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runStudentSimulation()
{
    clrScrn();

    do
    {
        switch (sortStudentOption())
        {
        case ('0'): return; break;
        case ('A'):readDataFile(); break;
        case ('B'):displayRecords(); break;
        case ('C'):insertRecord(); break;
        case ('D'):removeRecord(); break;
        case ('E'):sortRecords(); break;
        case ('F'):writeDataFile(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    std::cout << "\n";
    pause();
    clrScrn();
}





