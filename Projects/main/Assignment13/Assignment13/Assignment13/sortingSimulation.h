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
#include <cstdlib>
#include <string>

template <class T>
class SortedArray {
private:
    vector<T> sorted = vector<T>();
    int sortCount = int();

public:

    //default constructor
    SortedArray() {
        sortCount = 0;
    }

    //precondition: SortedArray class object must be initialized and it must have elements stored
    //postcondition: Will reset the swap routines to zero
    void resetSwap() {
        sortCount = 0;
    }
    
    void setSwap(int swaps) {
        sortCount = swaps;
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

    //precondition: SortedArray class object must be initialized and it must have elements stored
    //postcondition: Will add to the swap count
    void addSwap() {
        sortCount++;
    }

    //precondition: SortedArray class object must be initialized and it must have elements stored, the parameters passed in must be integer and double
    //postcondition: will set the value in the vector at the index position given 
    void setValueAtIndex(int index, T value) {
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
    void addElement(T value) {
        sorted.push_back(value);
    } 

    void makeHeap() {

        std::make_heap(sorted.begin(), sorted.end());
    }
    void sortHeap() {
        
        std::sort_heap(sorted.begin(), sorted.end());

     }
    void makeMaxHeap() {
        std::make_heap(sorted.begin(), sorted.end(), greater<int>());
    }
    void sortDescend() {
        std::sort_heap(sorted.begin(), sorted.end(), greater<int>());
    }
    //precondition: SortedArray must be initialized and must be populated
    //postcondition: will return the value at he given index value
    T elementAt(int index) {
        return sorted.at(index);
    }

    //precondition: SortedArray must be initialized 
    //postcondition: will return the value of sortCount
    int getSwaps() {
        return sortCount;
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

  /*  vector<T>& getVector() {
        return sorted;
    }*/

    // arr is an array with the same size of the vector to be populated
    T* getArray(T arr[]) {
        
            
        for (size_t i = 0; (i < sorted.size()); i++) {
            arr[i] = static_cast<T>(sorted[i]);//possible overrun
        }
        return arr;
    }
    //arr is an array with the same size of the vector to be populated
    void loadArray(T* arr, bool debug = false) {
        int pSize = sorted.size();
        sorted.clear();
        sorted.resize(0);

        if (debug) {
            for (size_t i = 0; i < pSize; i++) {
                std::cout << "\n[debug]: ind =>" << i << " :=> " << arr[i];
            }
            std::cout << "\n";
        }

        for (size_t i = 0; i < pSize; i++) {
            if (debug) {
                std::cout << "\n[debug] : arr => " << i << " val => " << arr[i];
                //std::cout << "\t[debug] : sorted => " << i << " val => " << sorted[i];
            }
            sorted.push_back(arr[i]);
            if(debug)std::cout << "\t[debug] : sorted [After] => " << i << " val => " << sorted[i] << "\n";
        }
    }

};

void swap(SortedArray<double>& arr, int a, int b)
{
    double temp = arr.elementAt(a);
    arr.setValueAtIndex(a, arr.elementAt(b));
    arr.setValueAtIndex(b, temp);
}

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

//precondition: SortedArray object must be initialized and passed as a parameter
//postcondition: will recursively swap the elements if the current index is less than the following
bool bubbleDesc(SortedArray<double> &arr, int index)
{
    if (index >= arr.getSize() -1) {
        return false;
    }
   // bool bubbled = arr.elementAt(index) > arr.elementAt(index + 1);
    if (arr.elementAt(index) < arr.elementAt(index +1)) {
        swap(arr, index, index+1);
        return true;
    }
    return bubbleDesc(arr, index +1);
}

//precondition: SortedArray object must be initialized and passed as a parameter
//postcondition: will recursively call the bubbleAsc function through all the elements
void bubbleSortDesc(SortedArray<double> &arr){
    if (bubbleDesc(arr, 0))
        bubbleSortDesc(arr);
}

//precondition: SortedArray object must be initialized and passed as a parameter
//postcondition: will recursively swap the elements if the current index is greater than the following
bool bubbleAsc(SortedArray<double> &arr, int index){
    if (index >= arr.getSize() -1) {
        return false;
    }
    if (arr.elementAt(index) > arr.elementAt(index +1)) {
        swap(arr, index, index +1);
        return true;
    }
    return bubbleAsc(arr, index +1);
}

//precondition: SortedArray object must be initialized and passed as a parameter
//postcondition: will recursively call the bubbleAsc function through all the elements
void bubbleSortAsc(SortedArray<double> &arr){
    if (bubbleAsc(arr, 0)) {
        bubbleSortAsc(arr);
    }
}
//precondition: SortedArray object must be initialized and passed as a parameter of double type
//postcondition: will bubble sort the array by using recursion
void optionC(SortedArray<double> arr) {

    if (arr.getSize() == 0)
    {
        cout << "\n\t\tArray is empty.\n";
    }
    char decOrAsc = inputChar("Choose sort in (A)scending or (D)escending order:", string("ad"));

    switch (decOrAsc)
    {
    case 'A': {
        bubbleSortAsc(arr);
        cout << "\n\t\tAscending: \n";
        break;
    }
    case 'D': {
        cout << "\n\t\tDescending: \n";
        bubbleSortDesc(arr);
        break;
    }
    }

    cout << "\n\t\t number of swapping routines = " << arr.getSwaps();
    arr.displayAll();
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

//selection sort [done]
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

//insertion sort [done]
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

//low is the lower bound in the array, int high is the upper bound in the array



//non recursive
template<class T>
int partitionV1(T arr[], int start, int end) {
    T pivot = T();
    int pivotIndex = int();
    //int midpoint = int();

    //midpoint = (start + end) / 2;//mid point
    swap(arr[start], arr[end]);
    pivotIndex = start;
    pivot = arr[start];

    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < pivot) {
            pivotIndex++;
            swap(arr[pivotIndex], arr[i]);
        }
    }
    swap(arr[start], arr[pivotIndex]);
    return pivotIndex;
}

//non recursive
template<class T>
int partitionV1_descending(T arr[], int start, int end) {
    T pivot = T();
    int pivotIndex = int();
    //int midpoint = int();

    //midpoint = (start + end) / 2;//mid point
    swap(arr[start], arr[end]);
    pivotIndex = start;
    pivot = arr[start];

    for (int i = start + 1; i <= end; i++) {
        if (arr[i] > pivot) {
            pivotIndex++;
            swap(arr[pivotIndex], arr[i]);
        }
    }
    swap(arr[start], arr[pivotIndex]);
    return pivotIndex;
}





//recursive helper
template<class T>
void partSwap(T arr[], int end, int i, int& pivotIndex, T pivot) {
    if (i <= end) {
        if (arr[i] < pivot) {
            pivotIndex++;
            swap(arr[pivotIndex], arr[i]);
        }
        partSwap(arr, end, ++i, pivotIndex, pivot);
    }
}

//recursive partition
//end is the ending index, start is the starting index
template<class T>
int partitionV2(T arr[], int start, int end) {
    T pivot = T();
    int pivotIndex = int();
    //int midpoint = int();

    //midpoint = (start + end) / 2;//mid point
    swap(arr[start], arr[end]);
    pivotIndex = start;
    pivot = arr[start];
    
    partSwap(arr, end, start + 1, pivotIndex, pivot);
  
    swap(arr[start], arr[pivotIndex]);
    return pivotIndex;
}

//recursive helper
template<class T>
void partSwap_descending(T arr[], int end, int i, int& pivotIndex, T pivot) {
    if (i <= end) {
        if (arr[i] > pivot) {
            pivotIndex++;
            swap(arr[pivotIndex], arr[i]);
        }
        partSwap_descending(arr, end, ++i, pivotIndex, pivot);
    }
}

//recursive partition
template<class T>
int partitionV2_descending(T arr[], int start, int end) {
    T pivot = T();
    int pivotIndex = int();
    //int midpoint = int();

    //midpoint = (start + end) / 2;//mid point
    swap(arr[start], arr[end]);
    pivotIndex = start;
    pivot = arr[start];
    
    partSwap_descending(arr, end, start + 1, pivotIndex, pivot);
  
    swap(arr[start], arr[pivotIndex]);
    return pivotIndex;
}

////pivotIndex should be set to end
//template<class T>
//void quickSortV2(T arr[], int start, int end, int(part(T*, int, int))) {
//    
//
//    if (start <= end) {//recursive as long as start < end
//        int pivotIndex = part(arr, start, end);
//        //sort first subarray
//        quickSortV2(arr, start, (pivotIndex - 1), part);
//        //sort second subarray
//        quickSortV2(arr, pivotIndex + 1, end, part);
//    }
//}

// end is the ending index ( not size )
// start is the starting index
template<class T>
void quickSortV1(T arr[], int start, int end, int (part(T*, int, int))) {
    int pivotIndex = int();

    if (start < end) {//recursive as long as start < end
        pivotIndex = part(arr, start, end);
        //sort first subarray
        quickSortV1(arr, start, (pivotIndex - 1), part);
        //sort second subarray
        quickSortV1(arr, pivotIndex + 1, end, part);
    }
}

//precondition: SortedArray object must be initialized and passed as a parameter of double type
//postcondition: will quick sort the array by using recursion
void optionF(SortedArray<double>& arr, bool debug = false) {
    
    //testing();


    if (arr.getSize() == 0)
    {
        cout << "\n\t\tArray is empty.\n";
        return;
    }
    size_t arraySize = arr.getSize();
    
    double* sortArr = new double[arraySize];

    arr.getArray(sortArr);
    if (debug) {
        for (size_t i = 0; i < arraySize; i++) {
            std::cout << "\n[debug]: ind =>" << i << " :=> " << static_cast<long double>(sortArr[i]);
        }
        std::cout << "\n";
    }
    
    if (debug) std::cout << "\nBefore:\n";
    if(debug)arr.displayAll();

    char decOrAsc = inputChar("Choose sort in (A)scending or (D)escending order:", string("ad"));

    switch (decOrAsc)
    {
        case 'A': {
        
            quickSortV1( sortArr, 0, arraySize - 1,partitionV2);
            cout << "\n\t\tAscending: \n";
            if (debug) {
                for (size_t i = 0; i < arr.getSize(); i++) {
                    std::cout << "\n[debug]: ind =>" << i << " :=> " << static_cast<double>(sortArr[i]);
                }
                std::cout << "\n";
            }

            break;
        }
        case 'D': {

            quickSortV1(sortArr, 0, arraySize -1, partitionV2_descending);
            cout << "\n\t\tDescending: \n";
            if (debug) {
                for (size_t i = 0; i < arr.getSize(); i++) {
                    std::cout << "\n[debug]: ind =>" << i << " :=> " << static_cast<double>(sortArr[i]);
                }
                std::cout << "\n";
            }

            break;
        }
    }

    arr.loadArray(sortArr, true);
    cout << "\n\t\t number of swapping routines = " << arr.getSwaps();
    arr.displayAll();
    delete []sortArr;
}


void optionG(SortedArray<double>& arr) {
    if (arr.getVector().empty() == true) {
        std::cout << "\n\t\tEmpty Vector.";
        return;
    }
    bool check = false;
    arr.resetCount();
    while (check == false) {
        char mode = inputChar("\n\t\tChoose sort in (A)scending or (D)escending order:");
        if (mode == 'A' || mode == 'a') {
            check = true;
            arr.copyAll(arr.MergeSort(arr, true));
        }
        else if (mode == 'D' || mode == 'd') {
            check = true;
            arr.copyAll(arr.MergeSort(arr, false));
        }
        else {
            std::cout << "\n\t\tInvalid Option.";
        }
    }
    std::cout << "\n\t\tNumber of comparisons:" << to_string(arr.getCount());
    arr.displayAll();
}



//precondition: SortedArray object must be initialized and passed as a parameter of double type
//postcondition: will heap sort the array by using recursion
void optionH(SortedArray<double> arr) {

    if (arr.getSize() == 0)
    {
        cout << "\n\t\tArray is empty.\n";
    }
  

    char decOrAsc = inputChar("Choose sort in (A)scending or (D)escending order:", string("ad"));

    switch (decOrAsc)
    {
        case 'A': {
        
            arr.makeHeap();
            arr.sortHeap();

            cout << "\nAscending:\n\n ";
            break;
        }
        case 'D': {

            arr.makeMaxHeap();
            arr.sortDescend();

            cout << "\nDescending:\n\n";

            break;
        }
    }

    arr.displayAll();

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


//
//
//void testing() {
//    double arr[] = { 69.5, 25.3, 95, 0.56, 8.56, 7.65 };
//    double arr2[] = { 69.5, 25.3, 95, 0.56, 8.56, 7.65 };
//
//    
//    std::cout << "\nBefore \n";
//    for (int i = 0; i < 6; i++) {
//        std::cout << "\n" << arr[i];
//    }
//    pause();
//    quickSortV1(arr, 0, 5, partitionV1_descending);
//    quickSortV1(arr2, 0, 5, partitionV1);
//    
//    std::cout << "\n\nafter\n";
//    for (int i = 0; i < 6; i++) {
//        std::cout << "\n" << arr[i];
//    }
//    std::cout << "\n\nafter 2:\n";
//    for (int i = 0; i < 6; i++) {
//        std::cout << "\n" << arr2[i];
//    }
//
//}