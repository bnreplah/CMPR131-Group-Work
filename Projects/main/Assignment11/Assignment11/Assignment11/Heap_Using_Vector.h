/// File:    Heap_Using_Vector.h
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
/// 11/15/21
/// Description:
///
/// 
/// 

#pragma once

#include <iostream>
#include <vector>
#include "input.h"

using namespace std;

/// Precondition: 
/// Postcondition: 
int minHeapOption()
{
    header("\n\tA> Min Heap");
    cout << "\n\t\t1. size";
    cout << "\n\t\t2. empty";
    cout << "\n\t\t3. push";
    cout << "\n\t\t4. front";
    cout << "\n\t\t5. pop";
    cout << "\n\t\t6. display";
    cout << "\n\t" + string(100, char(196));
    cout << "\n\t\t0. return";
    header("");

    int option = inputInteger("\n\t\tOption: ", 1, 6);
    clrScrn();

    return option;
}

/// Precondition: 
/// Postcondition: 
void runMinHeap()
{
    clrScrn();

    do
    {
        switch (minHeapOption())
        {
        case 0: return; break;
        case 1: ; break;
        case 2: ; break;
        case 3: ; break;
        case 4: ; break; 
        case 5: ; break;
        case 6: ; break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    cout << "\n";
    pause();
    clrScrn();
}

/// Precondition: 
/// Postcondition: 
int maxHeapOption()
{
    header("\n\tB> Max Heap");
    cout << "\n\t\t1. size";
    cout << "\n\t\t2. empty";
    cout << "\n\t\t3. push";
    cout << "\n\t\t4. front";
    cout << "\n\t\t5. pop";
    cout << "\n\t\t6. display";
    cout << "\n\t" + string(100, char(196));
    cout << "\n\t\t0. return";
    header("");

    int option = inputInteger("\n\t\tOption: ", 1, 6);
    clrScrn();

    return option;
}

/// Precondition: 
/// Postcondition: 
void runMaxHeap()
{
    clrScrn();

    do
    {
        switch (minHeapOption())
        {
        case 0: return; break;
        case 1: ; break;
        case 2: ; break;
        case 3: ; break;
        case 4: ; break;
        case 5: ; break;
        case 6: ; break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    cout << "\n";
    pause();
    clrScrn();
}

/// Precondition: 
/// Postcondition: 
char HeapVectorOption()
{
    header("\n\t1> Heap using vector");
    cout << "\n\t\tA> Min heap";
    cout << "\n\t\tB> Max heap";
    cout << "\n\t" + string(100, char(196));
    cout << "\n\t\t0> return";
    header("");

    int optionChar = inputChar("\n\t\tOption: ", string("ab0"));
    clrScrn();

    return optionChar;
}

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runHeapUsingVector()
{
    clrScrn();

    do
    {
        switch (HeapVectorOption())
        {
        case ('0'): return; break;
        case ('A'): runMinHeap(); break;
        case ('B'): runMaxHeap(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    cout << "\n";
    pause();
    clrScrn();
}









///////////////////////////////////////////////////////////////////////////////////////////
//  FOR REFERENCE/CHEATING PURPOSE ONLY                             ERASE BEFORE TURN IN
///////////////////////////////////////////////////////////////////////////////////////////

//#include <vector>
//#include <algorithm>
//#include <iostream>
//#include <stdlib.h>
//#include <math.h>
//
//using namespace std;
//
//// Class for a minimum heap implementation
//class minHeap {
//private:
//    // Current size of the heap
//    int size;
//    // Max size of heap
//    int capacity;
//    // Store elements as a vector
//    vector<int> heap;
//    // Returns the parent index
//    int parent(int i) { return (i - 1) / 2; }
//    // Returns the left child
//    int left(int i) { return 2 * i + 1; }
//    // Returns the right child
//    int right(int i) { return 2 * i + 2; }
//
//public:
//    // Constructor
//    minHeap(int capacity);
//    // Insert a key into the min heap
//    void insert(int k);
//    // Extracts the minumum element
//    int extractMin();
//    // Recursively heapify a sub-tree
//    void heapify(int i);
//    // Print the heap
//    void printHeap();
//};
//
//// Consturctor that sets the heap size and capacity
//minHeap::minHeap(int capacity) {
//    size = 0;
//    this->capacity = capacity;
//    heap.resize(capacity);
//}
//
//// Insert key into the minHeap
//void minHeap::insert(int k) {
//    // Make sure there is still space in the heap
//    if (size == capacity) {
//        cout << "MIN HEAP FULL!" << endl;
//        return;
//    }
//
//    // Increse the amount of elements in the heap
//    size++;
//
//    // Insert the new key at the end
//    int i = size - 1;
//    heap[i] = k;
//
//    // Fix the min heap property
//    // Moves the element up until i >= parent or root
//    while (i != 0 && heap[parent(i)] > heap[i]) {
//        swap(heap[i], heap[parent(i)]);
//        i = parent(i);
//    }
//}
//
//// Recursive function to maintain structure
//void minHeap::heapify(int i) {
//    // Set initial conditions
//    int l = left(i);
//    int r = right(i);
//    int smallest = i;
//
//    // Find the smallest element of the three
//    if ((l < size) && (heap[l] < heap[smallest])) {
//        smallest = l;
//    }if ((r < size) && (heap[r] < heap[smallest])) {
//        smallest = r;
//    }
//
//    // If the smallest of l or r, continue heapify
//    if (smallest != i) {
//        swap(heap[i], heap[smallest]);
//        heapify(smallest);
//    }
//}
//
//// Removes the smallest element and fixes the order
//int minHeap::extractMin() {
//    // Check if the heap is empty
//    if (size == 0) {
//        cout << "EMPTY HEAP" << endl;
//        return -1;
//        // Check if there is only 1 element
//    }
//    else if (size == 1) {
//        size--;
//        return heap[0];
//        // Normal extraction
//    }
//    else {
//        // Store the root
//        int root = heap[0];
//
//        // Maintain heap shape and then order
//        heap[0] = heap[size - 1];
//        size--;
//        heapify(0);
//
//        // Return min element
//        return root;
//    }
//}
//
//// Print the heap in a pretty format
//void minHeap::printHeap() {
//    int power = 0;
//    int value = 1;
//    for (int i = 0; i < size; i++) {
//        if (i == value) {
//            cout << endl;
//            power += 1;
//            value += (1 << power);
//        }
//        cout << heap[i] << "  ";
//    }
//    cout << endl;
//}
//
//int main() {
//    // Number of elements for our minHeap
//    int N = 15;
//
//    // Declare a heap with space for 10 elements
//    minHeap heap(N);
//
//    // Insert N random numbers
//    for (int i = 0; i < N; i++) {
//        cout << "Inserting element " << i + 1 << endl;
//        heap.insert(rand() % 100);
//        heap.printHeap();
//        cout << endl;
//    }
//
//    return 0;
//}