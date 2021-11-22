/// File:    SortedArray.h
/// Team Members:
///          Itz Rodrigez 
///          Tony Cheng
///          Ben Halpern
///          Jose Chavez
///          Thien Nguyen
///          Jesus Sierra
/// Professor Q
/// CMPR 131
/// Assignment 12
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
#include <vector>
#include "input.h"
#include <string>

template <class T>
class sortedArray {
private:
    vector<T> sorted = vector<T>();
    int operationCount;

public:
    sortedArray() {

        operationCount = 0;
    }

    int getOperationCount() {
        return operationCount;
    }

    void clearArray() {
        sorted.clear();
    }

    void addElement(string value) {
        sorted.push_back(value);
    }

    void displayAll() {
        for (int i = 0; i < sorted.size(); i++)
        {
            cout << sorted[i] << " ";
        }
    }

    bool binarySearch() {


    }

    /// Recursive serial search
    bool searchElement(string searchValue, int index) {
        //linear search
        operationCount++;
        if (index == 0) {
            operationCount = 0; //resets the operation count every time it calls the function
        }

        if (sorted[index] == searchValue) { // once found returns true
            return true;
        }

        if (index== sorted.size()-1 && sorted[index] != searchValue) { //if at the last index and not found return false
            
            return false;
        }
        else
            return searchElement(searchValue, ++index); //calls recursively
    }

};


void optionA(sortedArray<string>& arr) {//populate array with random elements
    clrScrn();
    int elements = inputInteger("Enter the size of the dynamic array: ", true);
    arr.clearArray();
    for (int i = 0; i < elements; i++) {
        int randomNum = (rand() % 100);//0-99
        arr.addElement(("String#" + to_string(randomNum)));
    }
}

void optionB(sortedArray<string>& arr) {
    clrScrn();
    string elem = "String#" + to_string(rand() % 100);//0-99//comment out next line to add random string element
    elem = inputString("\n\tEnter a string element: ", false);
    arr.addElement((elem));

}

void optionC(sortedArray<string>& arr) {//Display all elements in the array
    clrScrn();
    cout << "\n\tElements of unsorted array:\n";
    arr.displayAll();
}

void optionD(sortedArray<string>& arr) {//search for an element in the array
    
    clrScrn();
    //add option whether binary or serial
    char serOrBin = inputChar("Choose search type (S)erial or (B)inary: ","sb");
    string searchValue = inputString("\n\tPlease enter a string element to search for: ", false);
    bool found;
    switch (serOrBin)
    {
    case 'S':found = arr.searchElement(searchValue, 0); break;
    case 'B': found = arr.binarySearch(); break;
    }

    
    if (found) {
        std::cout << "\n\tFound the element: " << searchValue << " within the array";
    }
    else
        std::cout << "\n\tElement " << searchValue << " not found in the array";

    cout << "\n\tNumber of comparisons: " << arr.getOperationCount() << "\n";
}

char sortedArrayOption()
{
    header("\n\t2> Searching sorted dynamic arrays");
    std::cout << "\n\t\tA> Read random string data and store into the dynamic array";
    std::cout << "\n\t\tB> Add an element to the dynamic array";
    std::cout << "\n\t\tC> Display elements from the array";
    std::cout << "\n\t\tD> Search for an element from the array";
    std::cout << "\n\t\tE> Clear the array";
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
void runSortedArray()
{
    sortedArray<string> sArray = sortedArray<string>();
    clrScrn();

    do
    {
        switch (sortedArrayOption())
        {
        case ('0'): return; break;
        case ('A'):optionA(sArray) ; break;
        case ('B'):optionB(sArray) ; break;
        case ('C'):optionC(sArray) ; break;
        case ('D'):optionD(sArray) ; break;
        case ('E'):sArray.clearArray() ; break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    std::cout << "\n";
    pause();
    clrScrn();
}

//    T* cache = nullptr;
//    //T *found = nullptr;
//public:


//    /// Recursive serial search
//    typename vector<T>::iterator searchElements(T searchValue, typename vector<T>::iterator it) {
//        //linear search
//        if (it == sorted.begin()) {
//            operationCount = 0;
//        }
//
//        if (*it == searchValue) {
//            operationCount++;
//            return it;
//        }

//        if (it == sorted.end()) {
//
//            *cache = *it;
//            return it;
//        }
//        else
//            return searchElements(searchValue, ++it);
//    }//end searchElements recursive
//
//    /// Precondition: T searchValue is the value to search for
//    /// Postcondition: searches using a serial search
//    bool searchElements(T searchValue) {
//        //linear search
//        bool found = bool(false);
//        operationCount = 0;
//        if (cache != nullptr) {
//            if (searchValue == *cache) {
//                operationCount++;
//                found = true;
//                std::cout << "\n\tFound in cache\n";
//            }
//        }
//        for (int i = 0; i < sorted.size() && (found != true); i++) {
//            operationCount++;
//            *cache = sorted[i];
//            if (sorted[i] == searchValue)
//                found = true;
//        }
//
//        return found;
//    }//end searchElements
//


