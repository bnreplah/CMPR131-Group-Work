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

    //default constructor
    StudentSort() {
        operationCount = int();
    }

    void removeAStudent(int index) {
        studSort.erase(studSort.begin()+index);
    }

    //precondition: studSort must be initialized
    //postcondition: will return the size
    int getSize() {
        return studSort.size();
    }

    //precondition: studSort must be initialized
    //postcondition: will display all the elements in the array
    void displayAll() {

        if (studSort.size() == 0)
        {
            cout << "\n\t\tRecords are empty\n\n";
        }
        else
        {
            cout << "\n\tStudent records:";
            cout << "\n\n\tID:" << setw(24) << "NAME:" << setw(25) << "MAJOR:" << setw(15) << "GPA:";

            for (int i = 0; i < studSort.size(); i++)
            {
                cout << "\n\t" << studSort[i].getID() << setw(25) << studSort[i].getFullName()
                    << setw(25) << studSort[i].getMajor() << setw(15) << studSort[i].getGPA();
            }//end for

            cout << "\n\n";
        }

        //for (int i = 0; i < studSort.size(); i++) {
        //    cout << "\n\t" << studSort[i];
        //}//end for
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

    //precondition: StundentSort object must be initialized and parameter must be an integer value
    //postcondition: will return the element at the given index value 
    Student elementAt(int index) {
        return studSort.at(index);
    }

    //precondition: StundentSort object must be initialized and parameter must be aStudent object value
    //postcondition: will return true if found and false if not found  
    bool searchForStudent(Student stud) {
        
        typename vector<Student>::iterator itBegin = studSort.begin();
        typename vector<Student>::iterator itEnd = studSort.end();
        return search.linearSearch(studSort, stud, itBegin,itEnd);
    }

    void writeOutToFile() {

        outFile("Students.dat", studSort);
    }

};

//precondition: StudentSort object must be initialized and file must exists
//postcondition:  will read the data file and will store the elements on to the StudentSort object
void readDataFile(StudentSort &arr) {
    
    ifstream file = ifstream();
    if (file.good()) {
        file.open("Students.dat");
        if (file.is_open() && file.good()){

            while (!file.eof()){
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
                else{
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

void insertRecord(StudentSort &arr) {
    Student temp= Student();
    
    temp.setID(inputInteger("Enter a new student ID: ",true));
    temp.setFullName(inputString("Enter the student's name:",true));
    temp.setMajor(inputString("Enter the student's major: ", true));
    temp.setGPA(inputDouble("Enter the student's GPA: ", 0.0,4.0));

    arr.addElement(temp);
    cout << "\n\t\tThe student has been added to the array\n";
}

//precondition: SortedArray must be initialized
//postcondition: Recursive serial search
int linearSearchIndex(StudentSort arr, string searchValue, int count) {
    //linear search

    if (count == (arr.getSize()- 1) && arr.elementAt(count).getFullName() != searchValue) { //if at the last index and not found return false

        return -1;
    }

    if (arr.elementAt(count).getFullName() == searchValue) { // once found returns true
        return count;
    }

    else
        ++count;
    return linearSearchIndex(arr, searchValue, count); //calls recursively
}



void removeRecord(StudentSort &arr) {

    string nameToRemove = inputString("Enter a student's name to remove: ", true);

    int indexToRemove = linearSearchIndex(arr, nameToRemove, 0);

    if (indexToRemove == -1)
    {
        cout << "The student record cannot be found to be removed.";
    }
    else
    {
        arr.removeAStudent(indexToRemove);
        cout << "Student " << nameToRemove << " has been removed";
    }

}

void sortStudentAscID(StudentSort& arr) {




}


void sortRecords(StudentSort& arr) {
    char ascDesc = inputChar("Choose sort in (A)-ascending or (D)-descending order:", string("ad"));

    char sortType = inputChar("Choose by (I)-ID, (N)-name, (M)-major or (G)-GPA:", string("inmg"));


    switch (ascDesc)
    {
    case('A'): {
     
        switch (sortType)
        {
        case('I'): {



            break;

        }
        
        case('N'): {

            break;

        }
        
        case('M'): {

            break;

        }
        
        case('G'): {

            break;

        }
        
        
        }

        break;
    }

    case('D'): {


        break;
    }
    }




}

void writeDataFile(StudentSort arr) {

    arr.writeOutToFile();

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
        case ('C'):insertRecord(myArray); break;
        case ('D'):removeRecord(myArray); break;
        case ('E'):sortRecords(); break;
        case ('F'):writeDataFile(myArray); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        pause();
        clrScrn();
    } while (true);
    std::cout << "\n";
    pause();
    clrScrn();
}





