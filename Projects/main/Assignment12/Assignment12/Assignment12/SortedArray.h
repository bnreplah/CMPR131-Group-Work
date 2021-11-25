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
#include <algorithm>

template <class T>
class SortedArray {
private:
    vector<T> sorted = vector<T>();
    int operationCount;

public:
    //default constructor
    SortedArray() {
        operationCount = 0;
    }

    //precondition: SortedArray must be initialized
    //postcondition: will return the operation count
    int getOperationCount() {
        return operationCount;
    }

    //precondition: SortedArray must be initialized
    //postcondition: will return the size
    int getSize() {
        return sorted.size();
    }


    //precondition: SortedArray must be initialized
    //postcondition: will clear the array
    void clearArray() {
        sorted.clear();
    }

    //precondition: SortedArray must be initialized
    //postcondition: will sort the array
    void sortArray() {
        sort(sorted.begin(),sorted.end());
    }

    //precondition: SortedArray must be initialized
    //postcondition: will add an element to the array
    void addElement(string value) {
        sorted.push_back(value);
    }

    //precondition: SortedArray must be initialized
    //postcondition: will display all the elements in the array
    void displayAll() {
        for (int i = 0; i < sorted.size(); i++){
            cout << "\n\t" << sorted[i] ;
        }//end for
    }

    //precondition: SortedArray must be initialized
    //postcondition: will recursively binary search for the ID given
    bool binarySearch(string value, size_t first, size_t pSize, size_t& pos, int depth, int opCount =0) {
        bool found = false;
        operationCount = opCount;
        size_t middle = size_t();
        if (depth < 0 || pSize == 0)
            return false;
        else {
            middle = first + pSize / 2;
            if (value == sorted[middle]) {
                pos = middle;
                operationCount++;
                return true;
            }
            else if (value < sorted[middle])
            {
                return binarySearch(value, first, pSize / 2, pos, depth / 2, opCount + 1);
            }
            else {
                return binarySearch(value, middle + 1, (pSize - 1) / 2, pos, depth / 2, opCount + 1);
            }
        }
    }
    //precondition: SortedArray must be initialized
    //postcondition: Recursive serial search
    bool searchElement(string searchValue, int index) {
        //linear search
        if (index == 0) {
            operationCount = 0; //resets the operation count every time it calls the function
        }
        operationCount++;

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

//precondition: SortedArray must be initialized
//postcondition: will allocate the size of the array
void optionA(SortedArray<string>& arr) {//populate array with random elements
    clrScrn();
    int elements = inputInteger("Enter the size of the dynamic array: ", true);
    arr.clearArray();
    for (int i = 0; i < elements; i++) {
        int randomNum = (rand() % 100);//0-99
        arr.addElement(("String#" + to_string(randomNum)));
    }
    arr.sortArray();
}

//precondition: SortedArray must be initialized
//postcondition: will add an element to the array
void optionB(SortedArray<string>& arr) {//add element
    clrScrn();
    size_t pos = size_t();
    int operations = int();
    bool found = false;
    string elem = "String#" + to_string(rand() % 100);//0-99//comment out next line to add random string element
    elem = inputString("\n\tEnter a string element: ", false);
    arr.sortArray();
    found = arr.binarySearch(elem, 0, arr.getSize(), pos, arr.getSize());
    if (found) {
        std::cout << "\n\tNumber of comparisons: " << arr.getOperationCount() << "\n";
        std::cout << "\n\tAlready exists ";
    }
    else {
        arr.addElement(elem);
        arr.sortArray();
        arr.binarySearch(elem, 0, arr.getSize(), pos, arr.getSize());
        std::cout << "\n\tNumber of comparisons: " << arr.getOperationCount() << "\n";
    }
}

//precondition: SortedArray must be initialized
//postcondition: will display all the elements of the array
void optionC(SortedArray<string>& arr) {//Display all elements in the array
    clrScrn();
    if (arr.getSize() <= 0) {
        std::cout << "\n\tThe array is empty\n";
    }
    else
    {
        std::cout << "\n\tElements of sorted array:\n";
        arr.sortArray();
        arr.displayAll();
    }
}

//precondition: SortedArray must be initialized
//postcondition: will search the array for a given value  either binary or serial
void optionD(SortedArray<string>& arr) {//search for an element in the array
    clrScrn();
    if (arr.getSize() <= 0) {
        std::cout << "\n\tThe array is empty\n";
    }
    else
    {

        size_t position;

        //add option whether binary or serial
        char serOrBin = inputChar("Choose search type (S)erial or (B)inary: ", string("sb"));
        string searchValue = inputString("\n\tPlease enter a string element to search for: ", false);
        bool found = bool(false);
        switch (serOrBin)
        {
        case 'S':found = arr.searchElement(searchValue, 0); break;
        case 'B': {
            arr.sortArray();
            found = arr.binarySearch(searchValue, 0, arr.getSize(), position, arr.getSize()); break;
        }
        }

        if (found) {
            std::cout << "\n\tFound the element: " << searchValue << " within the array";
        }
        else
            std::cout << "\n\tElement " << searchValue << " not found in the array";
        std::cout << "\n\tNumber of comparisons: " << arr.getOperationCount() << "\n";
    }
    
}

//precondition: N/A
//postcondition: will output the menu options
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


//
//void optionA(SortedArray<string>& arr) {//populate array with random elements
//    clrScrn();
//    size_t elements = inputInteger("Enter the size of the dynamic array: ", true);
//    arr.clear();
//    for (int i = 0; i < elements; i++) {
//        int randomNum = (rand() % 100);//0-99
//        arr.addElement(("String#" + to_string(randomNum)));
//
//        cout << "\n\tNumber of operations: " << arr.getOperations() << "\n";
//    }
//
//}
//
//void optionB(SortedArray<string>& arr) {//add an element to the array
//    clrScrn();
//    string elem = "String#" + to_string(rand() % 100);//0-99//comment out next line to add random string element
//    elem = inputString("\n\tEnter a string element: ", false);
//    arr.addElement((elem));
//
//    cout << "\n\tNumber of comparisons: " << arr.getOperations() << "\n";
//
//}
//
//void optionC(SortedArray<string>& arr) {//Display all elements in the array
//    clrScrn();
//    cout << "\n\tElements of sorted array:\n";
//    arr.display();
//
//}
//
//void optionD(SortedArray<string>& arr) {//search for an element in the array
//    clrScrn();
//    string searchValue = inputString("\n\tPlease enter a string element to search for: ", false);
//    size_t index = size_t();
//    bool found = arr.binarySearch(searchValue, 0, arr.getSize(),index,arr.getSize() );
//    if (found) {
//        std::cout << "\n\tFound the element: " << searchValue << " within the array";
//    }
//    else
//        std::cout << "\n\tElement " << searchValue << " not found in the array";
//
//    cout << "\n\tNumber of comparisons: " << arr.getOperations() << "\n";
//}
//
//


//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runSortedArray()
{
    SortedArray<string> sArray = SortedArray<string>();
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




