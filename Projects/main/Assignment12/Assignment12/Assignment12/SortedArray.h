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
#include "input.h"
#include "myContainers.h"
template<class T> 
class SortedArray
{
private:
    LinkTList<T> sortedArray = LinkTList<T>();//can use vector if desired, this link list however does an insertion sort

    size_t operations = size_t();
public:

    SortedArray(){}
    void addElement(T element) {//insertion sort
        sortedArray.insertNode(element);
    }
    void display() {
        std::cout << sortedArray;
    }
    void clear() {
        sortedArray.clear();
    }

    size_t getOperations() {
        return operations;
    }

    size_t getSize() const {
        return sortedArray.getSize();
    }

    int serialSearch(T searchValue, size_t pos) {
        //linear search
        if (pos == 0) {
            operations = 0;
        }
        if (pos == (sortedArray.getSize() )) {
            return -1;
        }
        if (sortedArray[pos] == searchValue) {
            operations++;
            return pos;
        }
        else
            return searchElements(searchValue, ++pos);
    }//end searchElements recursive

    bool binarySearch(T value,size_t first, size_t pSize,size_t& pos, int depth, int opCount = 0) {
        bool found = false;
        operations = opCount;
        size_t middle = size_t();
        if (depth < 0 || pSize == 0)
            return false;
        else {
            middle = first + pSize / 2;
            if (value == sortedArray[middle]) {
                pos = middle;
                return true;
            }
            else if(value < sortedArray[middle])
            {
                return binarySearch(value, first, pSize / 2, pos, depth / 2, opCount + 1);
            }
            else {
                return binarySearch(value, middle + 1, (pSize - 1)/ 2, pos, depth/ 2, opCount +1);
            }
        }
    }

    T getFirst() {
        return sortedArray[0];
    }
   
    T operator [] (size_t index) {
        return sortedArray[index];
    }

    bool operator < (SortedArray<T> &rhs) {
        return this->getFirst() < rhs.getFirst();
    }

};




char sortedArrayOption()
{
    header("\n\t2> Searching sorted dynamic arrays");
    std::cout << "\n\t\tA> Read data file and store into the array";
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



void optionA(SortedArray<string>& arr) {//populate array with random elements
    clrScrn();
    size_t elements = inputInteger("Enter the size of the dynamic array: ", true);
    arr.clear();
    for (int i = 0; i < elements; i++) {
        int randomNum = (rand() % 100);//0-99
        arr.addElement(("String#" + to_string(randomNum)));

        cout << "\n\tNumber of operations: " << arr.getOperations() << "\n";
    }

}

void optionB(SortedArray<string>& arr) {//add an element to the array
    clrScrn();
    string elem = "String#" + to_string(rand() % 100);//0-99//comment out next line to add random string element
    elem = inputString("\n\tEnter a string element: ", false);
    arr.addElement((elem));

    cout << "\n\tNumber of comparisons: " << arr.getOperations() << "\n";

}

void optionC(SortedArray<string>& arr) {//Display all elements in the array
    clrScrn();
    cout << "\n\tElements of unsorted array:\n";
    arr.display();

}

void optionD(SortedArray<string>& arr) {//search for an element in the array
    clrScrn();
    string searchValue = inputString("\n\tPlease enter a string element to search for: ", false);
    size_t index = size_t();
    bool found = arr.binarySearch(searchValue, 0, arr.getSize(),index,arr.getSize() );
    if (found) {
        std::cout << "\n\tFound the element: " << searchValue << " within the array";
    }
    else
        std::cout << "\n\tElement " << searchValue << " not found in the array";

    cout << "\n\tNumber of comparisons: " << arr.getOperations() << "\n";
}




//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runSortedArray()
{
    clrScrn();
    SortedArray<string> sorted = SortedArray<string>();
    do
    {
        switch (sortedArrayOption())
        {
        case ('0'): return; break;
        case ('A'): optionA(sorted); break;
        case ('B'): optionB(sorted); break;
        case ('C'): optionC(sorted); break;
        case ('D'): optionD(sorted); break;
        case ('E'): sorted.clear(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    std::cout << "\n";
    pause();
    clrScrn();
}
