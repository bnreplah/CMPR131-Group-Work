// Team Members:
//Itz Rodriguez
//
//
//


#pragma once
#include "input.h"
#include <iostream>
#include "myContainers.h"
#include <fstream>
#include <string>

//prototypes
char subMenuOptions_el();
void OptionA();
void OptionB();
void OptionC();
void OptionD();
void OptionE();






//###################################################################
// Driver function
//###################################################################


//driver for the EMployeeList header file
void runEmployeeList() {


    do
    {
        switch (subMenuOptions_el())
        {
        case '0': return; break;
        case 'A':OptionA(); break;
        case 'B':OptionB(); break;
        case 'C':OptionC(); break;
        case 'D':OptionD(); break;
        case 'E':OptionE(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
        clrScrn();
    } while (true);
}//end runEmployeeList





//###################################################################
// Menu function
//###################################################################

char subMenuOptions_el() {


    header("\n\t\t1> List of Employees ");
    string options[] = { "\n\t\t\tA> Read data from file and store into a list ",
                        "\n\t\t\tB> Insert a new employee record into the list ",
                        "\n\t\t\tC> Update an employee record from the list ",
                        "\n\t\t\tD> Display all, active or inactive employee records from the list",
                        "\n\t\t\tE> Write data from the list to a file",
                        "\n" + string(100 , char(196)) +
                        "\n\t\t\t0> return "

    };
    for (string option : options)
        cout << option;
    header("");

    char optionCh = inputChar("\n\t\t\tOption: ", string("ABCDE0"));
    clrScrn();
    return optionCh;

}//end menu

//###################################################################
// A> Read data from file and store into a list
//###################################################################

void OptionA() {
    
    string filename;
    string inputFromFile;
   

    //Asking for the file name
    cout << "Enter the file name: ";
    //cin >> filename;
    cout << endl;
    filename = "EmployeeRecords.dat";


    //Opening the data file
    fstream dataFile(filename, ios::in);

    //if opened the file successfully then continue
    if (dataFile)
    {
        //Get the line from the file
        getline(dataFile,inputFromFile ,'\n');

        while (dataFile)
        {
            cout << inputFromFile << endl;

            getline(dataFile, inputFromFile, '\n');

        }

        dataFile.close();

    }
    else
    {
        cout << "ERROR: Cannot opent the file" << endl;
    }



}
//end of OptionA()

void OptionB() {

}
void OptionC() {

}

void OptionD() {

}
void OptionE() {

}

class Employee {
private:
    int employee_id;
    char status;
    string lastName;
    string firstName;
    string startingDate;
    string endingDate;


public:

    Employee() {

    }
    
    Employee(Employee&) {

    }

    ~Employee() {

    }

    void input(char inStat,int inEmpID,string inLast,string inFirst, string inStartDat, string inEndDat){
        status = inStat;
        employee_id = inEmpID;
        lastName = inLast;
        firstName = inFirst;
        startingDate = inStartDat;
        endingDate = inEndDat;
    }

    int getId() const{
        return employee_id;
    }

    char getStatus() const {
        return status;
    }

    string getLastName() const {
        return lastName;
    }
        
    string getFirstName() const {
        return firstName;
    }

    string getStartingDate() const {
        return startingDate;
    }

    string getEndingDate() const {
        return endingDate;
    }

    void setStatus(char newStat) {
        status = newStat;
    }
    
    void setLastName(string newLastNm) {
        lastName = newLastNm;
    }
        
    void setFirstName(string newFirstNm) {
        firstName = newFirstNm;
    }

    void setStartingDate(string newStartDate) {
        startingDate = newStartDate;
    }
        
    void setStartingDate(string newEndDate) {
        endingDate = newEndDate;
    }



};//end employee class