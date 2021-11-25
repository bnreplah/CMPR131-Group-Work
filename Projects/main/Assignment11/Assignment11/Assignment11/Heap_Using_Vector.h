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

#pragma once

#include <iostream>
#include <vector>
#include "input.h"
#include <iterator>
#include <algorithm>
using namespace std;

bool cmp(const long int& a, const long int& b) {
    return a > b;
}

template<class T>
class heap {
private:

    bool minMax = bool();//true min, false max
    size_t size = size_t();
    bool empty = bool();
    vector<T> heapSet = vector<T>();


    /// Precondition: Object must be initialized 
    /// Postcondition: Will output the heap
    void display(typename vector<T>::iterator itt) {

        if (heapSet.size() <= 0)
        {
            std::cout << "\n\t Heap is empty.\n";
        }
        if (itt == heapSet.end())
            return;
        else {
            if (itt != heapSet.end()) {
                std::cout << *itt << "\n";
                itt++;
                display(itt);
            }

        }
    }
public:
    //constructor
    heap(bool pMinMax) :minMax(pMinMax) {
    }

    typename vector<T>::iterator begin() {

        return heapSet.begin();
    }
<<<<<<< HEAD

    auto end() {
=======
    
    typename vector<T>::iterator end() {
>>>>>>> bc6f7e342b6b15209577e22c92c47b15677852a2

        return heapSet.end();
    }

    /// Precondition: Class object must be initialized
    /// Postcondition: Will remove the last element from the heap
    void pop() {
        T popValue = T();
        

        if (minMax == true)
        {
<<<<<<< HEAD

            if (heapSet.size() != 0) {
                lastItt = heapSet.end();
                lastItt--;
                popValue = *lastItt;
=======
      
        
            if (this->heapSet.size() != 0) {
                
                popValue = *(--this->heapSet.end());
                
>>>>>>> bc6f7e342b6b15209577e22c92c47b15677852a2
            }
            if (this->heapSet.size() != 0) {
                pop_heap(this->heapSet.begin(), this->heapSet.end(), cmp);
                this->heapSet.pop_back();
                cout << "Popped: " << popValue;
            }
            else {
                cout << "\n\t\t Heap is empty. \n";
            }
        }
        else
        {
         
            if (heapSet.size() != 0) {
                
                popValue = *(--this->heapSet.end());

                
            }
            if (this->heapSet.size() != 0) {
                pop_heap(this->heapSet.begin(), this->heapSet.end());
                this->heapSet.pop_back();
                cout << "Popped: " << popValue;
            }
            else {
                cout << "\n\t\t Heap is empty. \n";
            }
        }
    }
    /// Precondition: Class object must be initialized
    /// Postcondition: Will store a value onto the class object
    void push(T value) {

        //move into respective option below

      

        if (minMax) {//true: min | false: max
           

            if (is_heap(this->heapSet.begin(), this->heapSet.end())) {
                this->heapSet.push_back(value);

                push_heap(this->heapSet.begin(), this->heapSet.end(), cmp);
            }
            else {
                make_heap(this->heapSet.begin(), this->heapSet.end(), cmp);
                this->heapSet.push_back(value);
                push_heap(this->heapSet.begin(), this->heapSet.end(), cmp);
            }
        }
        else if (!this->minMax) {//false: max
        

            if (is_heap(this->heapSet.begin(), this->heapSet.end())) {
                this->heapSet.push_back(value);

                push_heap(this->heapSet.begin(), this->heapSet.end());
            }
            else {
<<<<<<< HEAD
                make_heap(begItt, lastItt);
                heapSet.push_back(value);
                push_heap(begItt, lastItt);
            }
=======
                make_heap(this->heapSet.begin(), this->heapSet.end());
                this->heapSet.push_back(value);
                push_heap(this->heapSet.begin(), this->heapSet.end());
            }        
>>>>>>> bc6f7e342b6b15209577e22c92c47b15677852a2
        }
    }

    /// Precondition: Class object must be initialized 
    /// Postcondition: Will return the size of the object
    size_t getSize() {
        return this->heapSet.size();
    }

    /// Precondition: Class object must be initialized
    /// Postcondition: Will return true if class is empty
    bool isEmpty() const {
        return this->heapSet.empty();
    }

    /// Precondition: Object must be initialized 
    /// Postcondition: Will output the heap
    void displayAll() {
<<<<<<< HEAD
        typename vector<T>::iterator begItt = heapSet.begin();
        typename vector<T>::iterator lastItt = heapSet.end();
        if (minMax == true)
        {
            if (is_heap(begItt, lastItt, cmp)) {
                display(begItt);
=======
        
        if (this->minMax == true)
            {
        
            if (is_heap(this->heapSet.begin(), this->heapSet.end(),cmp)) {
                display(this->heapSet.begin());
>>>>>>> bc6f7e342b6b15209577e22c92c47b15677852a2
            }
            else {
                make_heap(this->heapSet.begin(), this->heapSet.end(), cmp);
                display(this->heapSet.begin());
            }
        }
        else
        {
           
            if (is_heap(this->heapSet.begin(), this->heapSet.end())) {
                display(this->heapSet.begin());
            }
            else {
                make_heap(this->heapSet.begin(), this->heapSet.end());
                display(this->heapSet.begin());
            }
        }
    }

    /// Precondition: Class object must be initialized and there must be at least one element
    /// Postcondition: Will return the value of the element in the front of the object
    void getFront() {
      

        if (this->minMax == true)
        {
<<<<<<< HEAD
            if (is_heap(begItt, lastItt, cmp)) {
=======

            if (is_heap(this->heapSet.begin(), this->heapSet.end(),cmp)) {
>>>>>>> bc6f7e342b6b15209577e22c92c47b15677852a2
                if (heapSet.size() != 0) {
                    cout << "Front: " << heapSet.front();
                }
                else {
                    cout << "\n\t\t Heap is empty. \n";
                }
            }
            else {

<<<<<<< HEAD
                make_heap(begItt, lastItt, cmp);
=======
                make_heap(this->heapSet.begin(), this->heapSet.end(),cmp);
>>>>>>> bc6f7e342b6b15209577e22c92c47b15677852a2
                if (heapSet.size() != 0) {
                    cout << "Front: " << heapSet.front();
                }
                else {
                    cout << "\n\t\t Heap is empty. \n";
                }
            }
        }
        else {
          
            if (is_heap(this->heapSet.begin(), this->heapSet.end())) {
                if (heapSet.size() != 0) {
                    cout << "Front: " << heapSet.front();
                }
                else {
                    cout << "\n\t\t Heap is empty. \n";
                }
            }
            else {

                make_heap(this->heapSet.begin(), this->heapSet.end());
                if (heapSet.size() != 0) {
                    cout << "Front: " << heapSet.front();
                }
                else {
                    cout << "\n\t\t Heap is empty. \n";
                }
            }
        }
    }

    /// Precondition: Class object must be initialized 
    /// Postcondition: Will return true if object is heap
    bool isHeap() {
        if (isEmpty())
        {
            std::cout << "\n\tHeap is empty.\n";
            return false;
        }
        //move into respective option below
        

        if (minMax) {//true: min | false: max
<<<<<<< HEAD
            return is_heap(begItt, lastItt, cmp);
        }
        else if (!minMax) {//false: max
            return is_heap(begItt, lastItt);
=======
        return is_heap(this->heapSet.begin(), this->heapSet.end(), cmp);
        }
        else if (!minMax) {//false: max
        return is_heap(this->heapSet.begin(), this->heapSet.end());
>>>>>>> bc6f7e342b6b15209577e22c92c47b15677852a2
        }
    }

    T operator[](size_t index) {
        return this->heapSet[index];
    }

    bool exist(T value) {
        for (size_t i = 0; i < this->heapSet.size(); i++)
        {
<<<<<<< HEAD
            if (heapSet.at(i) == value)
=======
            if (this->heapSet.at(i)==value)
>>>>>>> bc6f7e342b6b15209577e22c92c47b15677852a2
            {
                return true;
            }
        }
        return false;
    }
<<<<<<< HEAD


=======
 
>>>>>>> bc6f7e342b6b15209577e22c92c47b15677852a2
    void makeHeap() {

        if (minMax == true)
        {
<<<<<<< HEAD
            make_heap(heapSet.begin(), heapSet.end(), cmp);
=======
            make_heap(this->heapSet.begin(), this->heapSet.end(),cmp);
>>>>>>> bc6f7e342b6b15209577e22c92c47b15677852a2
        }
        else {
            make_heap(this->heapSet.begin(), this->heapSet.end());
        }
    }
};


/// Precondition: N/A
/// Postcondition: Will output the options for minHeap
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


/// Precondition: N/A
/// Postcondition: switch for all the functions of the max Heap
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
        case 2: std::cout << boolalpha << "\n\t\tisEmpty: " << minHeap.isEmpty(); break;
        case 3: minHeap.push(inputInteger("Please input a number: ")); break;
        case 4: minHeap.getFront(); break;
        case 5: minHeap.pop(); break;
        case 6: minHeap.displayAll(); break;
        case 7: std::cout << "\tVector is a heap: " << boolalpha << minHeap.isHeap(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    cout << "\n";
    pause();
    clrScrn();
}

/// Precondition: N/A
/// Postcondition: Will output the options for maxHeap
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

/// Precondition: N/A
/// Postcondition: switch for all the functions of the min Heap
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
        case 4: maxHeap.getFront(); break;
        case 5: maxHeap.pop(); break;
        case 6: maxHeap.displayAll(); break;
        case 7: std::cout << "\tVector is a heap: " << boolalpha << maxHeap.isHeap(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    cout << "\n";
    pause();
    clrScrn();
}


/// Precondition: N/A
/// Postcondition: Will output the options for the heaps using vector
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