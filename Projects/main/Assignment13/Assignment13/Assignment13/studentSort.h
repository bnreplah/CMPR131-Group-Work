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
#include "Student.h"
#include <vector>

using namespace std;
class StudentSort {
private:

    vector<Student> studSort = vector<Student>();
    int operationCount;
    Searches<Student> search = Searches<Student>();
public:

    StudentSort() {
        operationCount = int();
    }

    //precondition: studSort must be initialized
    //postcondition: will return the size
    int getSize() {
        return studSort.size();
    }

    //precondition: studSort must be initialized
    //postcondition: will display all the elements in the array
    void displayAll() {
        for (int i = 0; i < studSort.size(); i++) {
            cout << "\n\t" << studSort[i];
        }//end for
    }

    //precondition: SortedArray must be initialized
    //postcondition: will clear the array
    void clearArray() {
        studSort.clear();
    }

    //precondition: SortedArray must be initialized
    //postcondition: will add an element to the array
    void addElement(Student value) {
        studSort.push_back(value);
    }

    Student elementAt(int index) {
        return studSort.at(index);
    }

    bool searchForStudent(Student stud) {
        
        typename vector<Student>::iterator itBegin = studSort.begin();
        typename vector<Student>::iterator itEnd = studSort.end();
        
        return search.linearSearch(studSort, stud, itBegin,itEnd);
    
    }
  

};


void readDataFile(StudentSort &arr) {

    ifstream file = ifstream();

    if (file.good()) {
        file.open("Students.dat");
        if (file.is_open() && file.good())
        {

            while (!file.eof())
            {
                Student tempStudent;
                file >> tempStudent;

                //if (debug)std::cout << "\nHash index: " << arr.getHash(tempStudent);
                //if (debug)std::cout << " Student ID: " << tempStudent.getID();

                //int IDcheck = tempStudent.getID();
                bool check = arr.searchForStudent(tempStudent);
                if (check == true) {
                    std::cout << "\n\t\tStudent already exists:" << tempStudent;
                    continue;
                }
                else
                {
                    arr.addElement(tempStudent);
                    //if (debug)std::cout << "\n\t\tStudent added to records";
                }
            }
        }
        else {
            std::cout << "\n\t\tERROR: File does not exists.\n";
        }
        file.close();
    }



}

void displayRecords(StudentSort arr) {

    arr.displayAll();
}

void insertRecord() {

}

void removeRecord() {

}

void sortRecords() {


}

void writeDataFile() {


}

//precondition: N/A
//postcondition: will output the menu options
char sortStudentOption()
{
    header("\n\t2> Application of sorting student records");
    std::cout << "\n\t\tA> Read in data file";
    std::cout << "\n\t\tB> Display records";
    std::cout << "\n\t\tC> Insert a record";
    std::cout << "\n\t\tD> Remove a record";
    std::cout << "\n\t\tE> Sort records by ID, name, major or GPA";
    std::cout << "\n\t\tF> Write out data file";
    std::cout << "\n\t" + string(100, char(196));
    std::cout << "\n\t\t0> return\n";
    header("");

    int optionChar = inputChar("\n\t\tOption: ", string("abcdef0"));
    clrScrn();

    return optionChar;
}


//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runStudentSimulation()
{
    StudentSort myArray = StudentSort();
    clrScrn();

    do
    {
        switch (sortStudentOption())
        {
        case ('0'): return; break;
        case ('A'):readDataFile(myArray); break;
        case ('B'):displayRecords(myArray); break;
        case ('C'):insertRecord(); break;
        case ('D'):removeRecord(); break;
        case ('E'):sortRecords(); break;
        case ('F'):writeDataFile(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    std::cout << "\n";
    pause();
    clrScrn();
}





