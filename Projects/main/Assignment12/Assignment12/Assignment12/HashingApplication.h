/// File:    HashingApplication.h
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
#include "myContainers.h"
#include "Student.h"
#include "input.h"
#include "UnsortedArray.h"
#include "SortedArray.h"
class HashingList {
private:
    
    int operationCount = int();
    int hashSize = int(5);
    unsortedArray <LinkTList <Student>> hList;
public:
    //default constrctor
    HashingList() {
        
    }

    //precondition: 
    //postcondition: returns the index from the hash function
    size_t getHash(Student obj) {
        return obj.getID() % hashSize;
    }

    //precondition:
    //postcondition:
    void addElement( Student &obj) {
        size_t index = getHash(obj);

        //seems like it doesn't like the recursion push_back maybe apply append_node
        hList[index].push_back(obj);
    }
    
    //precondition:
    //postcondition:
    void addElement(Student obj) {
        size_t index = getHash(obj);

        //seems like it doesn't like the recursion push_back maybe apply append_node
        hList[index].push_back(obj);
    }

    //precondition:
    //postcondition:
    void removeElement(Student &obj) {
        size_t index = getHash(obj);
        hList[index].deleteNode(obj);
    }

    //precondition:
    //postcondition:
    void search(Student& obj) {

    }

    //precondition:
    //postcondition:
    void display(){
        hList.displayAllElements(hList.begin());
    }

};


//precondition:
//postcondition:
void optionA(HashingList &arr, int size) {

    ifstream file = ifstream();

    if (file.good()) {
        file.open("Students.dat");
        if (file.is_open() && file.good())
        {
            while (!file.eof())
            {
                Student tempStudent;
                file >> tempStudent;
                cout << "\nTemp Student #: " << tempStudent.getID() % size;
                cout << " Temp Student ID: " << tempStudent.getID();
            }
        }
        else {
            cout << "\n\t\tERROR: File does not exists.\n";
        }
        file.close();
    }
}

void optionB(HashingList& arr ) {//search an element 

}

void optionC(HashingList& arr) {//insert an element
    arr.addElement(Student(inputInteger("\n\tPlease enter the student's ID: ", true), inputString("\n\tPlease enter the Student's name: ", true), inputString("\nPlease enter the Student's Major: ", true), inputDouble("\nPlease enter the GPA", 0.0, 5.0) ));
}

void optionD(HashingList& arr) {//remove an element
    
    //arr.removeElement();
}

void optionE(HashingList& arr) {//display element
    arr.display();
}

//precondition:
//postcondition:
char hashingOption()
{
    header("\n\t3> Application using hashing");
    std::cout << "\n\t\tA> Read data file, hash and insert into the dynamic array";
    std::cout << "\n\t\tB> Search an element from the dynamic array";
    std::cout << "\n\t\tC> Insert an element from the dynamic array";
    std::cout << "\n\t\tD> Remove an element from the dynamic array";
    std::cout << "\n\t\tE> Display all records from the array";
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
void runHashingApplication()
{
    clrScrn();
    HashingList hashArray = HashingList();
    do
    {
        switch (hashingOption())
        {
        case ('0'): return; break;
        case ('A'):optionA(hashArray, 10); break;
        case ('B'):optionB(hashArray); break;
        case ('C'):optionC(hashArray); break;
        case ('D'):optionD(hashArray); break;
        case ('E'):optionE(hashArray); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    std::cout << "\n";
    pause();
    clrScrn();
}