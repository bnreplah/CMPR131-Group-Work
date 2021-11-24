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
        hList.setSize(hashSize);
       /* for (int i = 0; i < hashSize; i++) {
            hList.addElement(LinkTList<Student>());
        }*/
    }
    
    //default constrctor
    HashingList(size_t size) {
        hList.setSize(size);
        hashSize = size;
    }

    //precondition: 
    //postcondition: returns the index from the hash function
    size_t getHash(Student obj) {
        return obj.getID() % hashSize;
    }

    size_t getHash(int I_D) {
        return I_D % hashSize;
    }

    void setSize(size_t nSize) {
        hList.setSize(nSize);
        hashSize = nSize;
    }


    ////precondition:
    ////postcondition:
    //void addElement( Student &obj) {
    //    size_t index = getHash(obj);

    //    //seems like it doesn't like the recursion push_back maybe apply append_node
    //    hList[index].push_back(obj);
    //}
    //
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
    bool search(int searchID ,bool Tswitch, bool deleteSwitch) {
        if (Tswitch == false) {
            size_t hashID = getHash(searchID);
            ListNode< Student,LinkTList <Student>>* searchPtr = hList[hashID].getHead();
            while (searchPtr != nullptr) {
                if (searchPtr->getvalue().getID() == searchID) {
                    return true;
                }
                if (searchPtr == nullptr) {
                    return false;
                }
                searchPtr = searchPtr->next;
            }
            return false;
        }
        else if (Tswitch == true, deleteSwitch == false) {
            size_t hashID = getHash(searchID);
            ListNode< Student, LinkTList <Student>>* searchPtr = hList[hashID].getHead();
            while (searchPtr != nullptr) {
                if (searchPtr->getvalue().getID() == searchID) {
                    cout << "\n\t\tStudent record found at index #" << to_string(hashID);
                    cout << "\n\t\t" << searchPtr->getvalue();
                    return true;
                }
                if (searchPtr == nullptr) {
                    cout << "\n\t\tERROR: ID not found.";
                    return false;
                }
                searchPtr = searchPtr->next;
            }
            return false;
        }
        else {
            size_t hashID = getHash(searchID);
            ListNode< Student, LinkTList <Student>>* searchPtr = hList[hashID].getHead();
            while (searchPtr != nullptr) {
                if (searchPtr->getvalue().getID() == searchID) {
                    Student tarStudent = searchPtr->getvalue();
                    hList[hashID].deleteNode(tarStudent);
                    cout << "\n\t\tStudent record index #" << to_string(hashID) << " with ID : " << to_string(searchID) << " has been removed.";
                    return true;
                }
                if (searchPtr == nullptr) {
                    cout << "\n\t\tERROR: ID not found.";
                    return false;
                }
                searchPtr = searchPtr->next;
            }
            return false;
        }
    }

    void clear() {
        hList.clear();
    }

    //precondition:
    //postcondition:
    void display(){
        hList.displayAllElements(hList.begin(), 0);
    }

};


//precondition:
//postcondition:
void optionA(HashingList &arr) {
   
    ifstream file = ifstream();

    if (file.good()) {
        file.open("Students.dat");
        if (file.is_open() && file.good())
        {
            
            while (!file.eof())
            {
                Student tempStudent;
                file >> tempStudent;
                cout << "\nTemp Student #: " << arr.getHash(tempStudent);
                cout << " Temp Student ID: " << tempStudent.getID();
                arr.addElement(tempStudent);
            }
        }
        else {
            cout << "\n\t\tERROR: File does not exists.\n";
        }
        file.close();
    }
}

void optionB(HashingList& arr ) {//search an element 
    arr.search(inputInteger("\n\t\tEnter a student ID to search: ", true), true, false);
}

void optionC(HashingList& arr) {//insert an element
    int IDcheck = inputInteger("\n\t\tPlease enter the student's ID: ", true);
    bool check = arr.search(IDcheck, false, false);
    if (check == true) {
        cout << "\n\t\tERROR: ID has already inserted.";
        return;
    }
    arr.addElement(Student(IDcheck, inputString("\n\t\tPlease enter the Student's name: ", true), inputString("\n\t\tPlease enter the Student's Major: ", true), inputDouble("\n\t\tPlease enter the GPA", 0.0, 5.0) ));
    cout << "\n\t\tInserted the new record.";
}

void optionD(HashingList& arr) {//remove an element
    arr.search(inputInteger("\n\t\tEnter a student ID to remove: ", true), true, true);
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
        case ('A'):optionA(hashArray); break;
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