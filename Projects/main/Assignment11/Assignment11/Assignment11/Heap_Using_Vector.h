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
/// 1) Simulate the creation of  a heap (minimum and maximum). Create two template classes of a minHeap and a maxHeap using a vector. Each heap will have the following operations:
///
/// return the size
/// check if empty
/// push a new element
/// returns the value of the front
/// pop an element
/// display all elements
///
/// 
/// 



#include <iostream>
#include <vector>
#include "input.h"
#include <iterator>
#include <algorithm>
using namespace std;

//class minC {
//    bool operator()(const long int &lhs,const long int &rhs) const{
//        return (lhs > rhs);//max heap uses <
//    }
//    bool operator()(const long int &lhs,const long int &rhs) {
//        return (lhs > rhs);//max heap uses <
//    }
//};


template <typename T>
class heap {

private:

    bool minMax = bool();//true min, false max
    size_t _size = size_t();
    size_t cap = size_t();
    bool empty = bool();
    vector<T> heapSet = vector<T>();


    void display(typename vector<T>::iterator itt) {

        if (itt == heapSet.end())
            return;
        else {
            std::cout << *itt << "\n";
            ++itt;
            display(itt);
        }
    }

public:


    heap(bool pMinMax, size_t capacity = 100)  {
        minMax = pMinMax;
        cap = capacity;
        _size = 0;
        empty = true;
        heapSet = vector<T>();
    }

    //heap(const heap& rhs) {
    //    this->cap = rhs->cap;
    //    this->_size = rhs->_size;
    //    this->heapSet = rhs->heapSet;
    //}

    T pop() {

        if (size == 0) {
            std::cout << "\n\t\tHeap is empty";
            return T();
        }
        //move into respective option below
        T popValue;
        typename vector<T>::iterator begItt = heapSet.begin();
        typename vector<T>::iterator lastItt = heapSet.end();


        if (minMax) {//true: min | false: max
            make_heap(begItt, lastItt);//, minC());
            if (heapSet.size() != 0)
                typename vector<T>::iterator lastItt = heapSet.end();


            popValue = (*lastItt);
            pop_heap(begItt, lastItt);//, minC());
            _size--;
            return popValue;
        }
        else {// if (!minMax) {//false: max
            make_heap(begItt, lastItt);
            if (heapSet.size() != 0)
                typename vector<T>::iterator lastItt = heapSet.end();


            popValue = *lastItt;
            pop_heap(begItt, lastItt);
            _size--;
            return popValue;
        }
    }

    void push(T value) {

        //move into respective option below
        if (_size == cap) {
            std::cout << "\n\t\tHeap has reached capacity";
            return;
        }

        typename vector<T>::iterator begItt = heapSet.begin();
        typename vector<T>::iterator lastItt = heapSet.end();



        if (minMax) {//true: min | false: max
            if (heapSet.size() != 0)
                typename vector<T>::iterator lastItt = heapSet.end();

            if (is_heap(begItt, lastItt)) {
                heapSet.push_back(value);

                push_heap(begItt, lastItt);
                _size++;
                return;
            }
            else {
                make_heap(begItt, lastItt);//, minC());
                push_heap(begItt, lastItt);
                _size++;
                return;
            }

        }
        else {// if (!minMax) {//false: max
            if (heapSet.size() != 0)
                typename vector<T>::iterator lastItt = heapSet.end();

            if (is_heap(begItt, lastItt)) {
                heapSet.push_back(value);

                push_heap(begItt, lastItt);
                _size++;
                return;
            }
            else {
                make_heap(begItt, lastItt);
                push_heap(begItt, lastItt);
                _size++;
                return;
            }

        }
    }



    size_t getSize() {
        _size = heapSet.size();
        return heapSet.size();
    }

    bool isEmpty() const {
        return heapSet.empty();
    }


    void displayAll() {
        if (_size == 0) {
            std::cout << "\n\t\tHeap is empty";
            return;
        }
        typename vector<T>::iterator itt = heapSet.begin();
        display(itt);
    }

    T getFront() {
        if (_size == 0) {
            std::cout << "\n\t\tHeap is empty";
            return T();
        }
        return heapSet.front();
    }

    bool isHeap() {

        //move into respective option below
        typename vector<T>::iterator begItt = heapSet.begin();
        typename vector<T>::iterator lastItt = heapSet.end();


        if (minMax) {//true: min | false: max
            if (heapSet.size() != 0)
                typename vector<T>::iterator lastItt = heapSet.end();

            return is_heap(begItt, lastItt);// , minC());


        }
        else { //if (!minMax) {//false: max
            if (heapSet.size() != 0)
                typename vector<T>::iterator lastItt = heapSet.end();
            return is_heap(begItt, lastItt);


        }


    }

    /*void operator=( const heap& rhs) {
        this->cap = rhs->cap;
        this->_size = rhs->_size;
        this->heapSet = rhs->heapSet;
    }*/

 };





/// Precondition: 
/// Postcondition: 
int minHeapOption()
{
    header("\n\tA> Min Heap");
    cout << "\n\t\t1. size";
    cout << "\n\t\t2. empty";
    cout << "\n\t\t3. push";
    cout << "\n\t\t4. front";
    cout << "\n\t\t5. pop";//need to fix pop
    cout << "\n\t\t6. display";
    cout << "\n\t\t7. isHeap";
    cout << "\n\t" + string(100, char(196));
    cout << "\n\t\t0. return";
    header("");

    int option = inputInteger("\n\t\tOption: ", 0, 7);
    clrScrn();

    return option;
}

/// Precondition: 
/// Postcondition: 
void runMinHeap()
{
    clrScrn();
    heap<int> minHeap = heap<int>(true);
    do
    {
        switch (minHeapOption())
        {
        case 0: return; break;
        case 1: std::cout << "\n\t\tsize: " << minHeap.getSize(); break;
        case 2: std::cout << boolalpha << "\n\t\tisEmpty: " <<minHeap.isEmpty(); break;
        case 3: minHeap.push(inputInteger("Please input a number: ")); break;
        case 4: std::cout << "\n\t\t" << minHeap.getFront(); break;
        case 5: std::cout << "\n\t\t Popped " << minHeap.pop();; break;
        case 6: minHeap.displayAll(); break;
        case 7: std::cout << boolalpha << minHeap.isHeap(); break;
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
    cout << "\n\t\t5. pop";//need to fix pop
    cout << "\n\t\t6. display";
    cout << "\n\t\t7. isHeap";
    cout << "\n\t" + string(100, char(196));
    cout << "\n\t\t0. return";
    header("");

    int option = inputInteger("\n\t\tOption: ", 0, 7);
    clrScrn();

    return option;
}

/// Precondition: 
/// Postcondition: 
void runMaxHeap()
{
    clrScrn();
    heap<int> maxHeap = heap<int>(false);
    do
    {
        switch (minHeapOption())
        {
        case 0: return; break;
        case 1: maxHeap.getSize(); break;
        case 2: maxHeap.isEmpty(); break;
        case 3: maxHeap.push(inputInteger("Please input a number: ")); break;
        case 4: std::cout << "\n\t\t" << maxHeap.getFront(); break;
        case 5: std::cout << "\n\t\t Popped " << maxHeap.pop(); break;
        case 6: maxHeap.displayAll(); break;
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