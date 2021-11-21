/// File:    UnsortedArray.h
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
/// A> Read random string data and store into the dynamic array
/// B > Add an element to the dynamic array
/// C > Display elements from the dynamic array
/// D > Search for an element from the dynamic array
/// E > Clear the dynamic array
/// 
/// Reviewed:
///  

#pragma once

#include <iostream>
#include <vector>
#include "input.h"


template <class T>
class unsortedArray {
private:
    vector<T> unsorted = vector<T>();
    time_t* startTime = nullptr;
    time_t* timePtr = nullptr;
    double timeDiff = double();
    size_t operationCount = size_t();
    T* cache = nullptr;
    //T *found = nullptr;
public:
    unsortedArray() {
        startTime = new time_t();
        timePtr = new time_t();
        cache = new T();
    }//end default constructor

    //copy constructor
    unsortedArray(const unsortedArray<T>& copy) {
        this->startTime = copy.startTime;
        this->timePtr = copy.timePtr;
        this->timeDiff = copy.timeDiff;
        this->operationCount = copy.operationCount;
        cache = nullptr;
        unsorted.clear();
        this->unsorted = copy.unsorted;

    }//end copy constructor

    //returns the begin iterator to be used for the functions that require an iterator
    typename vector<T>::iterator begin() {
        return unsorted.begin();
    }

    //adds an element to the array
    void addElement(T element) {
        time(startTime);
        unsorted.emplace(unsorted.begin(), element);
        *timePtr = (time(0) - *startTime);
    }//end addElement

    //displays element held by iterator position it
    void displayElement(typename vector<T>::iterator it) {
        std::cout << "\n\t" << *it;
    }//end displayElement

    //uses display and recursion to print out all the elements of the arrray
    void displayAllElements(typename vector<T>::iterator it) {
        if (it != unsorted.end()) {
            displayElement(it);
            std::cout << " ";
            displayAllElements(++it);
        }//end if
        else if (it == unsorted.end())
            return;

    }//end displayAllElements

    //get the operation count
    size_t getOperations() {
        return operationCount;
    }

    //gets the time difference stored in the private member variables as a time_t type
    time_t getTime() {
        return *timePtr;
    }

    //gets the time difference stored in the private member variables
    double getTimeDiff() {
        return timeDiff;
    }

    /// Recursive serial search
    typename vector<T>::iterator searchElements(T searchValue, typename vector<T>::iterator it) {
        //linear search
        if (it == unsorted.begin()) {
            operationCount = 0;

        }

        if (*it == searchValue) {
            operationCount++;
            return it;
        }
        if (it == unsorted.end()) {

            *cache = *it;
            return it;
        }
        else
            return searchElements(searchValue, ++it);
    }//end searchElements recursive

    /// Precondition: T searchValue is the value to search for
    /// Postcondition: searches using a serial search
    bool searchElements(T searchValue) {
        //linear search
        bool found = bool(false);
        operationCount = 0;
        if (cache != nullptr) {
            if (searchValue == *cache) {
                operationCount++;
                found = true;
                std::cout << "\n\tFound in cache\n";
            }
        }
        for (int i = 0; i < unsorted.size() && (found != true); i++) {
            operationCount++;
            *cache = unsorted[i];
            if (unsorted[i] == searchValue)
                found = true;
        }

        return found;
    }//end searchElements


    void clear() {
        unsorted.clear();
        *cache = T();
    }

    /// Precondition: rhs is a unsortedArray of type T object
    /// Postcondition: initializes the object with the object from the right hand side of the operator
    void operator = (unsortedArray<T>& rhs) {
        this->startTime = rhs.startTime;
        this->timePtr = rhs.timePtr;
        this->timeDiff = rhs.timeDiff;
        this->operationCount = rhs.operationCount;
        cache = rhs.cache;
        this->unsorted.clear();
        this->unsorted = rhs.unsorted;

    }//end default constructor



    ~unsortedArray() {
        delete timePtr;
        delete startTime;
        delete cache;
    }

};


void optionA(unsortedArray<string>& arr) {//populate array with random elements
    clrScrn();
    size_t elements = inputInteger("Enter the size of the dynamic array: ", true);
    arr.clear();
    for (int i = 0; i < elements; i++) {
        int randomNum = (rand() % 100);//0-99
        arr.addElement(("String#" + to_string(randomNum)));

        cout << "\n\tNumber of operations: " << arr.getOperations() << "\n";
    }

}

void optionB(unsortedArray<string>& arr) {//add an element to the array
    clrScrn();
    string elem = "String#" + to_string(rand() % 100);//0-99//comment out next line to add random string element
    elem = inputString("\n\tEnter a string element: ", false);
    arr.addElement((elem));

    cout << "\n\tNumber of comparisons: " << arr.getOperations() << "\n";

}

void optionC(unsortedArray<string>& arr) {//Display all elements in the array
    clrScrn();
    cout << "\n\tElements of unsorted array:\n";
    arr.displayAllElements(arr.begin());

}

void optionD(unsortedArray<string>& arr) {//search for an element in the array
    clrScrn();
    string searchValue = inputString("\n\tPlease enter a string element to search for: ", false);
    bool found = arr.searchElements(searchValue);
    if (found) {
        std::cout << "\n\tFound the element: " << searchValue << " within the array";
    }
    else
        std::cout << "\n\tElement " << searchValue << " not found in the array";

    cout << "\n\tNumber of comparisons: " << arr.getOperations() << "\n";
}




char unsortedArrayOption()
{
    header("\n\t1> Searching unsorted dynamic arrays");
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



//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runUnsortedArray()
{
    unsortedArray<string> uArray = unsortedArray<string>();


    do
    {
        clrScrn();
        switch (unsortedArrayOption())
        {
        case ('0'): return; break;
        case ('A'): optionA(uArray); break;
        case ('B'): optionB(uArray); break;
        case ('C'): optionC(uArray); break;
        case ('D'): optionD(uArray); break;
        case ('E'): uArray.clear(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();

    } while (true);
    std::cout << "\n";
    pause();
    clrScrn();
}
