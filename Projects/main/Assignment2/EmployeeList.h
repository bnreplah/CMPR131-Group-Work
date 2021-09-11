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

    void input(char inStat, int inEmpID, string inLast, string inFirst, string inStartDat, string inEndDat) {
        status = inStat;
        employee_id = inEmpID;
        lastName = inLast;
        firstName = inFirst;
        startingDate = inStartDat;
        endingDate = inEndDat;
    }

    int getId() const {
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

    void setEndingDate(string newEndDate) {
        endingDate = newEndDate;
    }



};//end employee class




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
    
    //File name will be stored here
    string filename;
    
    //This will be used to read the strings to be converted to the poper data types
    string inputFromFile;

    //This will be used to read the line and be broken down to local variables
    string inputLineFromFile;
    LinkTList <Employee> list;
    
    //These local variables will be used to initalized the Employee class
    int ID;
    char stat;
    string lastNm;
    string firstNm;
    string startDate;
    string endDate;

    //Asking for the file name
    cout << "Enter the file name: ";
    //cin >> filename;
    cout << endl;
    filename = "EmployeeRecords.dat";


    //Opening the data file
    fstream dataFile(filename, ios::in);

    //========================================================================
    //PROBLEM HERE: There's and issue with the delimiting the file line by line
    //so far it just reads the first line and does not continue to read the next line
    //========================================================================

    //if opened the file successfully then continue
    if (dataFile)
    {
        //Get the line from the file
        getline(dataFile,inputLineFromFile ,'\n');    
        //if opened the file successfully then continue
        while (dataFile)
        {
            if (dataFile)
            {
                //Get each string delimited by ',' from the file
                getline(dataFile,inputFromFile ,',');
                cout <<endl << "----------------------------" << endl;
               
                //while it's still content inside run
                while (dataFile)
                {

                    //for each line there should be 6 strings, converted if needed, that will be stored into the employee class
                    for (int i = 0; i < 6; i++)
                    {
                        switch (i)
                        {
                        case 0: 
                            //char status, will grab the char at the beginning of the string which should be either 'A', 'U','D'
                            stat = inputFromFile.at(0);
                            cout << "status: "<<stat << endl;
                            break;
                        case 1: 
                            //int employee_id, stoi will convert the string into integer so that it may be properly stored into the employee class
                            ID = stoi(inputFromFile);
                            cout << "ID : " << ID << endl;
                            break;
                        case 2:
                            //string lastName , this will directly store the string inot the lastname 
                            lastNm = inputFromFile;
                            cout <<"Last Name: "<< lastNm << endl;
                            break;
                        case 3:
                            //string firstName, this will directly store the string inot the firstname 
                            firstNm = inputFromFile;
                            cout <<"First Name: "<< firstNm << endl;
                            break;
                        case 4:
                            //string startingDate, this will directly store the string inot the startDate
                            startDate = inputFromFile;
                            cout <<"Start Date: "<< startDate << endl;
                            break;
                        case 5:
                            //string endingDate, this will directly store the string inot the endDate
                            endDate = inputFromFile;
                            cout << "End Date: "<<endDate << endl;
                            break;
                        default:
                            cout << "ERROR: setting the values in switch case." << endl;
                            break;
                        }
                        getline(dataFile, inputFromFile, ',');
                    }
                }
                dataFile.close();
            }
            else
            {
                cout << "ERROR: Cannot opent the file" << endl;
            }
           
            //The Employee Objects would be initialized here and inputted into a list

        getline(dataFile,inputLineFromFile ,'\n');    
        }
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

