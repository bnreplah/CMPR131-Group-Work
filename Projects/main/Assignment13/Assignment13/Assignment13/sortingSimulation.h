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
#include <vector>
#include <string>

template <class T>
class SortedArray {
private:
    vector<T> sorted = vector<T>();
    int sortCount = 0;
public:
    SortedArray() {

    }

    void copyAll(SortedArray origin) {
        sorted = origin.getVector();
        sortCount = sortCount + origin.getCount();
    }

    vector<T> getVector() {
        return sorted;
    }

    size_t size() {
        return sorted.size();
    }

    bool empty() {
        return sorted.empty();
    }

    void eraseTop() {
        sorted.erase(sorted.begin());
    }

    void resetCount() {
        sortCount = 0;
    }

    int getCount() {
        return sortCount;
    }

    //precondition: SortedArray must be initialized
    //postcondition: will return the size
    int getSize() {

        return sorted.size();
    }

    //precondition: SortedArray must be initialized
    //postcondition: will display all the elements in the array
    void displayAll() {
        for (int i = 0; i < sorted.size(); i++) {
            std::cout << "\n\t" << sorted[i];
        }//end for
    }

    //precondition: SortedArray must be initialized
    //postcondition: will clear the array
    void clearArray() {
        sorted.clear();
    }

    //precondition: SortedArray must be initialized
    //postcondition: will add an element to the array
    void addElement(double value) {
        sorted.push_back(value);
    }


    T elementAt(int index) {
        
        return sorted.at(index);
    }

    SortedArray<T> MergeSort(SortedArray<T> arr, bool mode) {
        if (arr.size() == 1) {
            return arr;
        }
        SortedArray<T> left;
        SortedArray<T> right;
        if (arr.size() % 2 == 0) {
            for (int i = 0; i <= (arr.size() / 2) - 1; i++) {
                left.addElement(arr.elementAt(i));
            }
            for (int j = (arr.size() / 2); j < arr.size(); j++) {
                right.addElement(arr.elementAt(j));
            }
        }
        else {
            for (int i = 0; i <= (ceil(arr.size() / 2)) - 1; i++) {
                left.addElement(arr.elementAt(i));
            }
            for (int j = (ceil(arr.size() / 2)); j < arr.size(); j++) {
                right.addElement(arr.elementAt(j));
            }
        }
        left.copyAll(MergeSort(left, mode));
        right.copyAll(MergeSort(right, mode));
        SortedArray<T> soln;
        if (mode == true) {
            do {
                if (left.empty() == true) {
                    while (right.empty() == false) {
                        soln.addElement(right.elementAt(0));
                        right.eraseTop();
                    }
                }
                else if (right.empty() == true) {
                    while (left.empty() == false) {
                        soln.addElement(left.elementAt(0));
                        left.eraseTop();
                    }
                }
                else if (left.elementAt(0) > right.elementAt(0)) {
                    soln.addElement(right.elementAt(0));
                    right.eraseTop();
                }
                else if (left.elementAt(0) < right.elementAt(0)) {
                    soln.addElement(left.elementAt(0));
                    left.eraseTop();
                }
                else if (left.elementAt(0) == right.elementAt(0)) {
                    soln.addElement(left.elementAt(0));
                    left.eraseTop();
                    soln.addElement(right.elementAt(0));
                    right.eraseTop();
                }
                else {
                    std::cout << "\n\t\tUnknown Error";
                    return(arr);
                }
                sortCount++;
            } while (left.empty() == false || right.empty() == false);
        }
        else {
            {
                do {
                    if (left.empty() == true) {
                        while (right.empty() == false) {
                            soln.addElement(right.elementAt(0));
                            right.eraseTop();
                        }
                    }
                    else if (right.empty() == true) {
                        while (left.empty() == false) {
                            soln.addElement(left.elementAt(0));
                            left.eraseTop();
                        }
                    }
                    else if (left.elementAt(0) < right.elementAt(0)) {
                        soln.addElement(right.elementAt(0));
                        right.eraseTop();
                    }
                    else if (left.elementAt(0) > right.elementAt(0)) {
                        soln.addElement(left.elementAt(0));
                        left.eraseTop();
                    }
                    else if (left.elementAt(0) == right.elementAt(0)) {
                        soln.addElement(left.elementAt(0));
                        left.eraseTop();
                        soln.addElement(right.elementAt(0));
                        right.eraseTop();
                    }
                    else {
                        std::cout << "\n\t\tUnknown Error";
                        return(arr);
                    }
                    sortCount++;
                } while (left.empty() == false || right.empty() == false);
            }
        }
        return soln;
    }
};




void optionA(SortedArray<double> &arr) {

    clrScrn();
    int elements = inputInteger("Enter the size of the dynamic array: ", true);
    
    arr.clearArray();
   
    for (int i = 0; i < elements; i++) {
        
        double randomNumDecimal = ((rand() % 100));//0-99
        randomNumDecimal = randomNumDecimal / 100;
        randomNumDecimal = randomNumDecimal +(rand() % 100);
        arr.addElement(randomNumDecimal);
    }
}

void optionB(SortedArray<double>& arr) {
 
    for (int i = 0; i < arr.getSize(); i++) {
        cout << "\n\t" << arr.elementAt(i);
    }//end for
}

void optionC() {

}

void optionD() {

}

void optionE() {

}

void optionF() {

}

void optionG(SortedArray<double>& arr) {
    arr.resetCount();
    char mode = inputChar("\n\t\tChoose sort in (A)scending or (D)escending order:", "ad");
    if (mode == 'a') {
        arr.copyAll(arr.MergeSort(arr, true));
    }
    else {
        arr.copyAll(arr.MergeSort(arr, false));
    }
    std::cout << "\n\t\tNumber of comparisons:" << to_string(arr.getCount());
    arr.displayAll();
}


void optionH() {

}



//precondition: N/A
//postcondition: will output the menu options
char sortOption()
{
    header("\n\t2> Sort Simulations");
    std::cout << "\n\t\tA> Create a dynamic array and fill with random elements";
    std::cout << "\n\t\tB> Display the unsorted array";
    std::cout << "\n\t\tC> Perform BubbleSort";
    std::cout << "\n\t\tD> Perform SelectionSort";
    std::cout << "\n\t\tE> Perform InsertionSort";
    std::cout << "\n\t\tF> Perform QuickSort";
    std::cout << "\n\t\tG> Perform MergeSort";
    std::cout << "\n\t\tH> Perform HeapSort";
    std::cout << "\n\t" + string(100, char(196));
    std::cout << "\n\t\t0> return\n";
    header("");

    int optionChar = inputChar("\n\t\tOption: ", string("abcdefgh0"));
    clrScrn();

    return optionChar;
}


//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runSortingSimulation()
{
    SortedArray<double> myArray;
    clrScrn();

    do
    {
        switch (sortOption())
        {
        case ('0'): return; break;
        case ('A'):optionA(myArray); break;
        case ('B'):optionB(myArray); break;
        case ('C'):optionC(); break;
        case ('D'):optionD(); break;
        case ('E'):optionE(); break;
        case ('F'):optionF(); break;
        case ('G'):optionG(myArray); break;
        case ('H'):optionH(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    std::cout << "\n";
    pause();
    clrScrn();
}





