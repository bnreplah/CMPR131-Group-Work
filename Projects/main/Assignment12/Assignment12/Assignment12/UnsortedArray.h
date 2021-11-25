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


#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "input.h"
#include "Student.h"


template <class T>
class UnsortedArray {
private:
    vector<T> unsorted = vector<T>();
    
    size_t operationCount = size_t();
    T* cache = nullptr;
    //T *found = nullptr;
public:
    //default constructor
    UnsortedArray() {
        
        cache = new T();
    }//end default constructor

    //copy constructor
    UnsortedArray(const UnsortedArray<T>& copy) {
        
        this->operationCount = copy.operationCount;
        cache = nullptr;
        unsorted.clear();
        this->unsorted = copy.unsorted;

    }//end copy constructor
    
    //precondition: UnsortedArray must be initialized
    //postcondition: will set the size of the array object
    void setSize(size_t size) {
        unsorted.resize(size);
    }

    //precondition: UnsortedArray must be initialized
    //postcondition: will return the size of the array object
    size_t getSize() {
        return unsorted.size();
    }

    //precondition: UnsortedArray must be initialized
    //postcondition: returns the begin iterator to be used for the functions that require an iterator
    typename vector<T>::iterator begin() {
        return unsorted.begin();
    }

    //precondition: UnsortedArray must be initialized
    //postcondition: adds an element to the array
    void addElement(T element) {
        //time(startTime);
        unsorted.emplace(unsorted.begin(), element);
        //*timePtr = (time(0) - *startTime);
    }//end addElement

    //precondition: UnsortedArray must be initialized
    //postcondtion: displays element held by iterator position it
    void displayElement(T element) {
        std::cout <<element;
    }//end displayElement

    //precondition: UnsortedArray must be initialized parameter type must be vector
    //postcondition: uses display and recursion to print out all the elements of the arrray
    void displayAllElements(typename vector<T>::iterator it) {
        if (it != unsorted.end()) {
            std::cout << "\n\t";
            displayElement(*it);
            displayAllElements(++it);
        }//end if
        else if (it == unsorted.end())
            return;

    }//end displayAllElements
    

    //precondition: UnsortedArray must be initialized
    //postcondition: uses display and recursion to print out all the elements of the arrray
    void displayAllElements(typename vector<T>::iterator it, int index) {
        if (it != unsorted.end()) {
            std::cout << "[" << index << "]";
            displayElement(*it);
            displayAllElements(++it, ++index);
        }//end if
        else if (it == unsorted.end())
            return;

    }//end displayAllElements

    //precondition: UnsortedArray must be initialized
    //postcondition: get the operation count
    size_t getOperations() {
        return operationCount;
    }

    //precondition: UnsortedArray must be initialized
    //postcondition:Recursive serial search
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

    //precondition: UnsortedArray must be initialized
    //postcondition: will clear the container object
    void clear() {
        unsorted.clear();
        *cache = T();
    }

    /// Precondition: rhs is a UnsortedArray of type T object
    /// Postcondition: initializes the object with the object from the right hand side of the operator
    void operator = (UnsortedArray<T>& rhs) {
       // this->startTime = rhs.startTime;
       // this->timePtr = rhs.timePtr;
       // this->timeDiff = rhs.timeDiff;
        this->operationCount = rhs.operationCount;
        cache = rhs.cache;
        this->unsorted.clear();
        this->unsorted = rhs.unsorted;

    }//end default constructor

    T& operator [](size_t index){
        return unsorted[index];
    }

    //precondition: UnsortedArray object must be inilitialized, parameters must be T value, size_t, size_t, size_t, and integer
    //postcondition: will search for the element by the given value
    bool binarySearch(T value, size_t first, size_t pSize, size_t& pos, int depth, int opCount = 0) {
        bool found = false;
        operationCount = opCount;
        size_t middle = size_t();
        if (depth < 0 || pSize == 0)
            return false;
        else {
            middle = first + pSize / 2;
            if (value == unsorted[middle]) {
                pos = middle;
                return true;
            }
            else if (value < unsorted[middle])
            {
                return binarySearch(value, first, pSize / 2, pos, depth / 2, opCount + 1);
            }
            else {
                return binarySearch(value, middle + 1, (pSize - 1) / 2, pos, depth / 2, opCount + 1);
            }
        }
    }
    //destructor
    ~UnsortedArray() {
        //delete timePtr;
        //delete startTime;
        delete cache;
    }
};

//precondition: UnsortedArray object must be initialized
//postcondition: will add the size to the array
void optionA(UnsortedArray<string>& arr) {//populate array with random elements
    clrScrn();
    size_t elements = inputInteger("Enter the size of the dynamic array: ", true);
    arr.clear();
    for (int i = 0; i < elements; i++) {
        int randomNum = (rand() % 100);//0-99
        arr.addElement(("String#" + to_string(randomNum)));

        //cout << "\n\tNumber of operations: " << arr.getOperations() << "\n";
    }
}

//precondition: UnsortedArray object must be initialized
//postcondition: will add an element to the array
void optionB(UnsortedArray<string>& arr) {//add an element to the array
    clrScrn();
    string elem = "String#" + to_string(rand() % 100);//0-99//comment out next line to add random string element
    elem = inputString("\n\tEnter a string element: ", false);
    arr.addElement((elem));
}

//precondition: UnsortedArray object must be initialized
//postcondition: will diplay all the elements of the array
void optionC(UnsortedArray<string>& arr) {//Display all elements in the array
    clrScrn();
    cout << "\n\tElements of unsorted array:\n";
    arr.displayAllElements(arr.begin());
}

//precondition: UnsortedArray object must be initialized
//postcondition: will search all the elements of the array either by binary or serial
void optionD(UnsortedArray<string>& arr) {//search for an element in the array
    clrScrn();
    char serOrBin = inputChar("Choose search type (S)erial or (B)inary: ", string("sb"));
    size_t index = size_t();
    string searchValue = inputString("\n\tPlease enter a string element to search for: ", false);
    bool found = bool(false);
        
    switch (serOrBin)
    {
    case 'S':found = 
    found= arr.searchElements(searchValue);
        break;
    case 'B': {
        found = arr.binarySearch(searchValue, 0, arr.getSize(), index, arr.getSize()); break;
        }
    }
    if (found) {
        std::cout << "\n\tFound the element: " << searchValue << " within the array";
    }
    else
        std::cout << "\n\tElement " << searchValue << " not found in the array";

    cout << "\n\tNumber of comparisons: " << arr.getOperations() << "\n";
}


//precondition: N/A
//postcondition: will output all the menu options
char unsortedArrayOption()
{
    header("\n\t1> Searching unsorted dynamic arrays");
    std::cout << "\n\t\tA> Read random string data and store into dynamic array";
    std::cout << "\n\t\tB> Add an element to the dynamic array";
    std::cout << "\n\t\tC> Display elements from the array";
    std::cout << "\n\t\tD> Search for an element from the array";
    std::cout << "\n\t\tE> Clear the dynamic array";
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
    UnsortedArray<string> uArray = UnsortedArray<string>();
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
