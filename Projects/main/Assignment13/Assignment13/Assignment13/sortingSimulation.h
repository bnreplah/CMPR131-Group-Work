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
#include <algorithm>

template <class T>
class SortedArray {
private:
    vector<T> sorted = vector<T>();
    int swapRoutines = int();

public:

    //default constructor
    SortedArray() {
        swapRoutines = 0;
    }

    //precondition: SortedArray class object must be initialized and it must have elements stored
    //postcondition: Will reset the swap routines to zero
    void resetSwap() {
        swapRoutines = 0;
    }
    
    //precondition: SortedArray class object must be initialized and it must have elements stored
    //postcondition: Will add to the swap count
    void addSwap() {
        swapRoutines++;
    }

    //precondition: SortedArray class object must be initialized and it must have elements stored, the parameters passed in must be integer and double
    //postcondition: will set the value in the vector at the index position given 
    void setValueAtIndex(int index, double value) {
        sorted[index] = value;
    }

    //precondition: SortedArray must be initialized 
    //postcondition: will return the size
    int getSize() {

        return sorted.size();
    }

    //precondition: SortedArray must be initialized
    //postcondition: will display all the elements in the array
    void displayAll() {
        cout << "\n\t\t";
        for (int i = 0; i < sorted.size(); i++) {
           
            if (i == 0){
                cout << " " << sorted[i];
            }
            else {
                cout << ", " << sorted[i];
            }
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

    //precondition: SortedArray must be initialized and must be populated
    //postcondition: will return the value at he given index value
    T elementAt(int index) {
        return sorted.at(index);
    }

    //precondition: SortedArray must be initialized 
    //postcondition: will return the value of swapRoutines
    int getSwaps() {
        return swapRoutines;
    }
};



//precondition: class object must be initialized and passed as a parameter of double type
//postcondition: will allocate the size of the array and populate the array with random doubles
void optionA(SortedArray<double> &arr) {

    arr.clearArray();
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

//precondition: SortedArray object must be initialized and passed as a parameter of double type
//postcondition: will display all the elements
void optionB(SortedArray<double> arr) {
   
    if (arr.getSize() == 0)
    {
        cout << "\n\t\tArray is empty.\n";
    }
    arr.displayAll();
}

//precondition: SortedArray object must be initialized and passed as a parameter of double type
//postcondition: will bubble sort the array by using recursion
void optionC(SortedArray<double> arr) {


}

//precondition: SortedArray object must be initialized and parameters must be integer types
//postcondition: will return the highest value position
int selectiveMax(SortedArray<double>& arr, int traversePos, int valuePos) {
    int maxPosition;

    if (traversePos == valuePos){
        return valuePos;
    }

    maxPosition = selectiveMax(arr, traversePos + 1, valuePos);

    if (arr.elementAt(traversePos) > arr.elementAt(maxPosition))
    {
        maxPosition = traversePos;
    }
    return maxPosition;

}


//precondition: SortedArray object must be initialized and parameters must be integer types
//postcondition: will return the lowest value position
int selectiveMin(SortedArray<double>& arr, int traversePos, int valuePos) {
    int minPosition;

    if (traversePos == valuePos){
        return valuePos;
    }

    minPosition = selectiveMin(arr, traversePos + 1, valuePos);

    if (arr.elementAt(traversePos) < arr.elementAt(minPosition))
    {
        minPosition = traversePos;
    }
    return minPosition;
}

//precondition: SortedArray object must be initialized and parameters must be integer types
//postcondition: will sort by using selection sort in descending order recursively
void selectionSortDes(SortedArray<double> &arr, int n, int index ) {
   // index = arr.getSize() - 1;

    double temp;
    int maxPos;

    if (index == n){
        return;
    }

    maxPos = selectiveMax(arr, index, n - 1);

    if (maxPos != index) {
        arr.addSwap();
        temp = arr.elementAt(index);
        arr.setValueAtIndex(index, arr.elementAt(maxPos));
        arr.setValueAtIndex(maxPos, temp);
    }
    selectionSortDes(arr, n, index + 1);
}

//precondition: SortedArray object must be initialized and parameters must be integer types
//postcondition: will sort by using selection sort in ascending order recursively
void selectionSortAsc(SortedArray<double> &arr, int n, int index ) {

    double temp;
    int minPos;

    //stop case once it reaches the last element
    if (index == n){
        return;
    }

    minPos = selectiveMin(arr, index, n - 1);

    if (minPos != index){
        arr.addSwap();
        temp = arr.elementAt(index);
        arr.setValueAtIndex(index, arr.elementAt(minPos));
        arr.setValueAtIndex(minPos, temp);
    }
    selectionSortAsc(arr, n, index + 1);
}

//precondition: SortedArray object must be initialized and parameters must be integer types
//postcondition: will sort by using insertion sort in descending order recursively
void insertionSortDes(SortedArray<double> &arr, int size) {

    if (size <= 1){
        return;
    }

    insertionSortDes(arr, size - 1);
    double value = arr.elementAt(size - 1);
    int position = size - 2;

    while (position >= 0 && arr.elementAt(position)<value)
    {
        arr.addSwap();
        arr.setValueAtIndex(position + 1, arr.elementAt(position));
        position--;
    }

    arr.setValueAtIndex(position + 1, value);
}

//precondition: SortedArray object must be initialized and parameters must be integer types
//postcondition: will sort by using insertion sort in ascending order recursively
void insertionSortAsc(SortedArray<double> &arr, int size) {

    if (size <= 1){
        return;
    }

    insertionSortAsc(arr, size - 1);
    double value = arr.elementAt(size - 1);
    int position = size - 2;

    while (position >= 0 && arr.elementAt(position)>value)
    {
        arr.addSwap();
        arr.setValueAtIndex(position + 1, arr.elementAt(position));
        position--;
    }

    arr.setValueAtIndex(position + 1, value);
}

//precondition: SortedArray object must be initialized and passed as a parameter of double type
//postcondition: will selection sort the array by using recursion
void optionD(SortedArray<double> arr) {

    if (arr.getSize() == 0)
    {
        cout << "\n\t\tArray is empty.\n";
    }
    char decOrAsc = inputChar("Choose sort in (A)scending or (D)escending order:", string("ad"));

    switch (decOrAsc)
    {
    case 'A': {
        selectionSortAsc(arr, arr.getSize(), 0);
        cout << "\n\t\tAscending: \n";
        break;
    }
    case 'D': {
        selectionSortDes(arr, arr.getSize(),0);
        cout << "\n\t\tDescending: \n";
        break;
    }
    }

    cout << "\n\t\t number of swapping routines = " << arr.getSwaps();
    arr.displayAll();
}


//precondition: SortedArray object must be initialized and passed as a parameter of double type
//postcondition: will insertion sort the array by using recursion
void optionE(SortedArray<double> arr) {

    if (arr.getSize() == 0)
    {
        cout << "\n\t\tArray is empty.\n";
    }

    char decOrAsc = inputChar("Choose sort in (A)scending or (D)escending order:", string("ad"));

    switch (decOrAsc)
    {
    case 'A': {
        insertionSortAsc(arr,(arr.getSize()));
        cout << "\n\t\tAscending: \n";
        break;
    }
    case 'D': {
        
        cout << "\n\t\tDescending: \n";
        insertionSortDes(arr,(arr.getSize()));
        break;
    }
    }

    cout << "\n\t\t number of swapping routines = " << arr.getSwaps();
    arr.displayAll();

}

//precondition: SortedArray object must be initialized and passed as a parameter of double type
//postcondition: will quick sort the array by using recursion
void optionF(SortedArray<double> arr) {

}

//precondition: SortedArray object must be initialized and passed as a parameter of double type
//postcondition: will merge sort the array by using recursion
void optionG(SortedArray<double> arr) {

}


//precondition: SortedArray object must be initialized and passed as a parameter of double type
//postcondition: will heap sort the array by using recursion
void optionH(SortedArray<double> arr) {

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
    SortedArray <double> myArray = SortedArray<double>();
    clrScrn();

    do
    {
        switch (sortOption())
        {
        case ('0'): return; break;
        case ('A'):optionA(myArray); break;
        case ('B'):optionB(myArray); break;
        case ('C'):optionC(myArray); break;
        case ('D'):optionD(myArray); break;
        case ('E'):optionE(myArray); break;
        case ('F'):optionF(myArray); break;
        case ('G'):optionG(myArray); break;
        case ('H'):optionH(myArray); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    std::cout << "\n";
    pause();
    clrScrn();
}





