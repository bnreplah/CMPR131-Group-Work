/// File:    Heap_In_STL.h
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
/// 
/// Reviewed:
///             Ben Halpern     11-16-21
///  

#pragma once

#include <iostream>
#include "input.h"
#include <string>
#include <vector>
#include <cmath>
int randomNum() {
    return static_cast<int>(rand() % 100 + 1);
}


class STL_heap {
private:
    vector<int> vectorHeap;
    bool initVector;
    bool heapTrue;
    
    ///Precondition: N/A
    ///Postcondition: check if the vector is a max heap
    bool maxHeapCheck() {
        if (vectorHeap.empty() == true) {
            return true;
        }
        for (int curCheck = 1; curCheck < int(ceil(double(vectorHeap.size())/2)); curCheck++) {
            if (vectorHeap[curCheck-1] < vectorHeap[(2 * curCheck)-1] || vectorHeap[curCheck] < vectorHeap[(2 * curCheck)]) {
                return false;
            }
        }
        return true;
    }

    bool isHeap() {
        return is_heap(vectorHeap.begin(), --vectorHeap.end());
    }


public:
    /// basic constructor
    STL_heap() {
        initVector = false;
        heapTrue = false;
    }
    
    ///Precondition: N/A
    ///Postcondition: initalize the vector
    void creatVector() {
        int sizeChosen = inputInteger("\n\t\tEnter the size of the dynamic array: ", true);
        vectorHeap = vector<int>();
        vectorHeap.resize(sizeChosen);
        for (int i = 0; i < sizeChosen; i++) {//populates heap with random numbers
            vectorHeap.push_back(randomNum());
        }
        initVector = true;
    }

    ///Precondition: iniVector must be true, vectorHeap must not reach it's max size.
    ///Postcondition: push_back an element
    void vectorPushBack() {
        if (initVector == false) {
            std::cout << "\n\t\tVector has not been initalized.";
            return;
        }
        int postiveInput = inputInteger("\n\t\tEnter an positive integer: ", true);
        vectorHeap.push_back(postiveInput);
    }

    ///Precondition: initVector must be true
    ///Postcondition: make vectorHeap a heap
    void makeHeap() {
        if (initVector == false) {
            std::cout << "\n\t\tVector has not been initalized.";
            return;
        }
        std::make_heap(vectorHeap.begin(), --vectorHeap.end());
        heapTrue = true;
    }

    ///Precondition: initVector must be true
    ///Postcondition: return max element
    void displayFront() {
        if (initVector == false) {
            std::cout << "\n\t\tVector has not been initalized.";
            return;
        }
        if (vectorHeap.empty() == true) {
            std::cout << "\n\t\tVector is empty.";
            return;
        }
        if(isHeap())
            std::cout << "\n\t\tThe maximum element of heap: " + std::to_string(vectorHeap.front());
    }
    
    ///Precondition: heapTrue must be true
    ///Postcondition: add a new element to the vector and push it into the heap in order.
    void pushHeap() {
        if (heapTrue == false) {
            std::cout << "\n\t\tVector is not a heap.";
            return;
        }
        int postiveInput = inputInteger("\n\t\tEnter an positive integer: ", true);
        vectorHeap.push_back(postiveInput);
        std::push_heap(vectorHeap.begin(), --vectorHeap.end());
    }

    ///Precondition: heapTrue must be true
    ///Postcondition: romove a element to the vector and keep the heap in order.
    void popHeap() {
        if (heapTrue == false) {
            std::cout << "\n\t\tVector is not a heap.";
            return;
        }
        if (vectorHeap.empty() == true) {
            std::cout << "\n\t\tVector is empty.";
            return;
        }
        std::pop_heap(vectorHeap.begin(), --vectorHeap.end());
        vectorHeap.pop_back();
        vectorHeap.push_back(randomNum());//replaces with random number like in the professors code
        std::push_heap(vectorHeap.begin(), --vectorHeap.end());
    }

    ///Precondition: heapTrue must be true
    ///Postcondition: sort the heap.
    void sortHeap() {
        if (!isHeap()) {
            std::cout << "\n\t\tVector is not a heap.";
            return;
        }
        std::sort_heap(vectorHeap.begin(), --vectorHeap.end());
        std::cout << "\n\t\theap has been sorted\n";//added BH
    } 

    
    ///Precondition: heapTrue must be true
    ///Postcondition: return if the vector is a max heap.
    void checkIsHeap() {
        if (initVector == false) {
            std::cout << "\n\t\tVector has not been initalized.";
            return;
        }
        bool checkResult = is_heap(vectorHeap.begin(), --vectorHeap.end());//maxHeapCheck();
        if (checkResult) {
            std::cout << "\n\t\tvector is a heap.";
        }
        else {
            std::cout << "\n\t\tvector is not a heap.";
        }
    }
    
    ///Precondition: heapTrue must be true, vectorHeap must not be empty
    ///Postcondition: return elements that are part of the heap
    void isHeapUntil() {
        if (initVector == false) {
            std::cout << "\n\t\tVector has not been initalized.";
            return;
        }
        if (vectorHeap.empty() == true) {
            std::cout << "\n\t\tVector is empty.";
            return;
        }
        //vector<int> tempHeapVector;
        //int curCheck = 1;
        //bool heap = isHeap();
        //tempHeapVector = vectorHeap;//added BH
        //std::sort_heap(tempHeapVector.begin(), --tempHeapVector.end());
        //sort(tempHeapVector.begin(), --tempHeapVector.end());
        
        //loop triggered a never ending loop

        //tempHeapVector.push_back(vectorHeap[curCheck]);
        //while (isHeap == true && curCheck <= int(ceil(double(vectorHeap.size()) / 2))) {//forever loops
        //    if (vectorHeap[curCheck - 1] < vectorHeap[(2 * curCheck) - 1]) {
        //        isHeap = false;
        //    }
        //    if (isHeap == true && ((2 * curCheck) - 1) <=int(vectorHeap.size())) {
        //        tempHeapVector.push_back(vectorHeap[(2 * curCheck) - 1]);
        //    }
        //    if (vectorHeap[curCheck - 1] < vectorHeap[(2 * curCheck)]) {
        //        isHeap = false;
        //    }
        //    if (isHeap == true && ((2 * curCheck)) <= int(vectorHeap.size())) {
        //        tempHeapVector.push_back(vectorHeap[(2 * curCheck)]);
        //    }
        //}
        
        //std::make_heap(tempHeapVector.begin(), --tempHeapVector.end());
        
        
        std::cout << "\n\t\tThe heap elements in container are :";
        vector<int>::iterator ittEnd = is_heap_until(vectorHeap.begin(), --vectorHeap.end());//gets end itterator of heap
        for (vector<int>::iterator itt = vectorHeap.begin();  (itt != ittEnd); ++itt) {//prints all elements except last element
            if (*itt != 0)
                std::cout << " " << *itt;
        }
    }

    ///Precondition: iniVector must be true
    ///Postcondition: display the vector
    void displayVector() {
        if (initVector == false) {
            std::cout << "\n\t\tVector has not been initalized.";
            return;
        }
        if (vectorHeap.empty() == true) {
            std::cout << "\n\t\tVector is empty.";
            return;
        }

        //if (isHeap()) {
            std::cout << "\n\t\tThe vector elements are :";
            for (int cur = 0; cur < int(vectorHeap.size()); cur++) {
                if (vectorHeap[cur] != 0)
                    std::cout << " " << vectorHeap[cur];
            }
        //}
    }
};

char HeapSTLOption()
{
    header("\n\t3> Heap in C++ STL");
    std::cout << "\n\t\tA> create a dynamic array";//checked
    std::cout << "\n\t\tB> push_back() an element";//checked
    std::cout << "\n\t\tC> make_heap()";//checked
    std::cout << "\n\t\tD> front";//checked
    std::cout << "\n\t\tE> push_heap()";//checked
    std::cout << "\n\t\tF> pop_heap()";//checked
    std::cout << "\n\t\tG> sort_heap()";//checked
    std::cout << "\n\t\tH> is_heap()";//checked
    std::cout << "\n\t\tI> is_heap_until()";//fixed
    std::cout << "\n\t\tJ> display";//checked
    std::cout << "\n\t" + string(100, char(196));
    std::cout << "\n\t\t0> return\n";
    header("");

    int optionChar = inputChar("\n\t\tOption: ", string("abcdefghij0"));
    clrScrn();

    return optionChar;
}

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runHeapInSTL()
{
    STL_heap stlMaxHeap = STL_heap();
    clrScrn();

    do
    {
        switch (HeapSTLOption())
        {
        case ('0'): return; break;
        case ('A'): stlMaxHeap.creatVector(); break;//checked
        case ('B'): stlMaxHeap.vectorPushBack(); break;//checked
        case ('C'): stlMaxHeap.makeHeap(); break;//checked
        case ('D'): stlMaxHeap.displayFront(); break;//checked
        case ('E'): stlMaxHeap.pushHeap(); break;//checked
        case ('F'): stlMaxHeap.popHeap(); break;//checked
        case ('G'): stlMaxHeap.sortHeap(); break;//checked
        case ('H'): stlMaxHeap.checkIsHeap(); break;//checked
        case ('I'): stlMaxHeap.isHeapUntil(); break;//checked
        case ('J'): stlMaxHeap.displayVector(); break;//checked
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    std::cout << "\n";
    pause();
    clrScrn();
}