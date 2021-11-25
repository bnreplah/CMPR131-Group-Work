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
    int hashSize = int(5);//initially set to 5
    UnsortedArray <LinkTList <Student>> hList = UnsortedArray <LinkTList <Student>>();
public:
    //default constrctor
    HashingList() {
        
        hList.setSize(hashSize);
        operationCount = 0;
    }

    //default constrctor
    HashingList(size_t size) {
        hList.setSize(size);
        hashSize = size;
    }
    //default constrctor
    HashingList(const HashingList& copy) {
    }

    //precondition: HashingList must be initialized 
    //postcondition: returns the index from the hash function
    size_t getHash(Student obj) {
        return obj.getID() % hashSize;
    }

    //precondition: HashingList must be initialized and parameter must be an integer value
    //postcondtion: will return the Hash value
    size_t getHash(int ID) {
        return ID % hashSize;
    }

    //precondition: HashingList must be initialized and parameter must be a size_t value
    //postcondition: set size of the hList and size value used in the size
    void setSize(size_t nSize) {
        hList.setSize(nSize);
        hashSize = nSize;
    }
    
    //precondition: HashingList must be initialized 
    //postcondition: only get size of vector
    size_t getSize() {
         return hList.getSize();
    }

    //precondition: HashingList must be initialized 
    //postcondition: returns operationCount
    int getOperations() {
        return operationCount;
    }

    //precondition: HashingList must be initialized and the parameter must be a student object
    //postcondition: will add a student object on the container
    void addElement(Student obj) {
        size_t index = getHash(obj);
        hList[index].insertNode(obj);
    }

    //precondition: HashingList must be initialized and the parameter must be a student object
    //postcondition: will remove a student object on the container
    void removeElement(Student &obj) {
        size_t index = getHash(obj);
        hList[index].deleteNode(obj);
    }

    //precondition: HashingList must be initialized with three parameters of an integer, and two booleans
    //postcondition: will search for a student and return the position if found
    bool search(int searchID ,bool Tswitch, bool deleteSwitch) {
        operationCount = 0;
        
        if (Tswitch == false) {//check for insertion
            size_t hashID = getHash(searchID);
            ListNode< Student,LinkTList <Student>>* searchPtr = hList[hashID].getHead();
            while (searchPtr != nullptr) {
                ++operationCount;
                if (searchPtr == nullptr) {
                    return false;
                }
                else if (searchPtr->getvalue().getID() == searchID) {
                    
                    return true;
                }
                
                searchPtr = searchPtr->next;
            }
            return false;
        }
        else if ((Tswitch == true) && (deleteSwitch == false)) {
            size_t hashID = getHash(searchID);
            ListNode< Student, LinkTList <Student>>* searchPtr = hList[hashID].getHead();
            while (searchPtr != nullptr) {
                ++operationCount;
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
                ++operationCount;
                if (searchPtr->getvalue().getID() == searchID) {
                    Student tarStudent = searchPtr->getvalue();
                    hList[hashID].deleteNode(tarStudent);
                    cout << "\n\t\tStudent record found at index #" << to_string(hashID) << " with ID : " << to_string(searchID) << " has been removed.";
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

    //precondition: HashingList must be initialized 
    //postconditon: will clear the container of all the elements
    void clear() {
        hList.clear();
    }

    //precondition: HashingList must be initialized 
    //postcondition: displays elements in chained hash array format
    void display(){
        hList.displayAllElements(hList.begin(), 0);
    }
    
};

//precondition: HashingList must be initialized, file must be exists
/// Postcondition: will read the file and add elements to the container object
void optionA(HashingList &arr, bool debug = false) {
   
    ifstream file = ifstream();

    if (file.good()){
        file.open("Students.dat");
        if (file.is_open() && file.good())
        {
            
            while (!file.eof())
            {
                Student tempStudent;
                file >> tempStudent;

                if(debug)std::cout << "\nHash index: " << arr.getHash(tempStudent);
                if(debug)std::cout << " Student ID: " << tempStudent.getID();
                
                int IDcheck = tempStudent.getID();
                bool check = arr.search(IDcheck, false, false);
                if (check == true) {
                    std::cout << "\n\t\tID already exists: ID#" << IDcheck;
                    continue;
                }
                else
                {
                    arr.addElement(tempStudent);
                    if(debug)std::cout << "\n\t\tStudent added to records";
                }
            }
        }
        else {
            std::cout << "\n\t\tERROR: File does not exists.\n";
        }
        file.close();
    }
}

/// Precondition: HashingList must be initialized
/// Postcondition: will search for a student with the ID given
void optionB(HashingList& arr ) {//search an element 
    arr.search(inputInteger("\n\t\tEnter a student ID to search: ", true), true, false);
    cout << "\n\t\tNumber of comparisons: " << arr.getOperations() << "\n";
}

/// Precondition: HashingList must be initialized
/// Postcondition: will insert an element in the container class
void optionC(HashingList& arr) {//insert an element
    bool check = false;
    int IDcheck = int();
    
    do {
        IDcheck = inputInteger("\n\t\tPlease enter the student's ID: ", true);
        check = arr.search(IDcheck, false, false);
        cout << "\n\t\tNumber of comparisons: " << arr.getOperations() << "\n";
        if (check == true) {
            std::cout << "\n\t\tERROR: ID has already been inserted.";
        }
        else
        {
            arr.addElement(Student(IDcheck, inputString("\n\t\tPlease enter the Student's name: ", true), inputString("\n\t\tPlease enter the Student's Major: ", true), inputDouble("\n\t\tPlease enter the GPA: ", 0.0, 5.0)));
            std::cout << "\n\t\tInserted the new record.";
        }
    } while (check);
}


/// Precondition: HashingList must be initialized
/// Postcondition: will remove an element which matches the ID given
void optionD(HashingList& arr) {//remove an element
    arr.search(inputInteger("\n\t\tEnter a student ID to remove: ", true), true, true);
    cout << "\n\t\tNumber of comparisons: " << arr.getOperations() << "\n";
    //arr.removeElement();
}


/// Precondition: HashingList must be initialized
/// Postcondition: Will display the elements in the container
void optionE(HashingList& arr) {//display element
    arr.display();
}

//precondition: N/A
//postcondition: will output the menu options
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