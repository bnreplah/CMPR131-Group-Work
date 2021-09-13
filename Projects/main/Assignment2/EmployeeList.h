// Team Members:
// Itz Rodriguez
// Ben Halpern
//
//


/**
* Semantic prefixes notations possibly implemented
*   _ prefix for private class variable
*   ptr for pointers
*   m for member variables
*   c for constants
*   ch for chars
*   str for strings
*   i, j, k for iterator loop variable and indexes
*   itr for iterator types
* 
*/


#pragma once
#include "input.h"
#include <iostream>
#include "myContainers.h"
#include <fstream>
#include <string>


bool debug = true;
//prototypes
char subMenuOptions_el();
class Employee;
void OptionA(LinkTList<Employee>& employeeList);
void OptionB(LinkTList<Employee>& employeeList);
void OptionC(LinkTList<Employee>& employeeList);
void OptionD(LinkTList<Employee>& employeeList);
void OptionE(LinkTList<Employee>& employeeList);
Employee& search_id(int id, const LinkTList<Employee> &employeeList);

class Employee {
private:
    static int nextId;
    int employee_id = int();                                                                        //set to a string in case wants a non int id
    char status = char('U');                                                                        //initialized to unknown
    string lastName = string();
    string firstName = string();
    string startingDate = string();
    string endingDate = string();


public:

    Employee() {
        employee_id = nextId;
        //std::cout << nextId;
        nextId++;
    }//end default constructor

    

    //sets the employee_id value only and default status, used for populating an employee value without changing the nextId
    Employee(int code, char inStat = char('U')) {
        this->employee_id = code;
    }//end employee code constructor


    Employee(string inLast, string inFirst, string inStartDat, string inEndDat, int inEmpID = nextId, char inStat = char('U') ) {
        input( inLast, inFirst, inStartDat, inEndDat, inEmpID, inStat );
    }//end Employee

    Employee(const Employee &right) {
        this->employee_id = right.employee_id;
        this->lastName = right.lastName;
        this->firstName = right.firstName;
        this->status = right.status;
        this->startingDate = right.startingDate;
        this->endingDate = right.endingDate;
        
    }//end copy constructor

    Employee& operator = (const Employee& right)  {
        this->employee_id = right.employee_id;
        this->lastName = right.lastName;
        this->firstName = right.firstName;
        this->status = right.status;
        this->startingDate = right.startingDate;
        this->endingDate = right.endingDate;
        return *this;
    }//end = assingment operator

    bool operator < (const Employee& right) {
        return this->employee_id < right.employee_id;
    }//end operator <

    bool operator > (const Employee& right) {
        return this->employee_id > right.employee_id;
    }//end operator >

    /// Precondition:
    /// Postcondition: compares the employee id, the last name and the first name to determine if the objects are == , doesn't mean that the starting date or ending date are the same
    bool operator ==(const Employee& right) {
        if ((this->employee_id == right.employee_id) && (this->lastName == right.lastName) && (this->firstName == right.firstName)) {
            return true;
        }//end if
        return false;
    }

    /// Precondition:
    /// Postcondition:
    bool read(ifstream& file) {
        
        if(file.bad()) {                                                    //precondition check: if the file is invalid or the badbit is set,
            std:cout << "\nError: Bad File, please input a valid file\n"; //output an error to the screen 
            return false;                                                   //return false
        }//end if

        string line = string();                                             //
        getline(file, line);                                                //reads the next line from the file
        
        if (debug) std::cout << "\n" << line << "\n";                       //debugging check
        
        if (line.empty())                                                   //if line read is empty return false
            return false;
        
        LinkTList<string> record = LinkTList<string>(); 
        size_t delimIndex = size_t(1);                                      //sets the initial delimeter size to be greater than the start
        size_t start = size_t(0);                                           //sets the start to the beigining index
        //end initialization
    

        do{
            delimIndex = line.find(',', start);                             //sets the delimIndex from the offest of the start to find the next delimeter
            if (delimIndex < line.length()) {                               //if th delimeter exists within the line
                record.appendNode(line.substr(start, delimIndex - start));  //add a substring from the last delimeter to the current
                start = ++delimIndex;                                       //increment the delimeter and set it to start starting from the next delimeted index
            }//end if
        } while ((line.find(',', start) < line.length()));//end while 
        
        //adds last value
        if(delimIndex < line.length())                                      //if the last delimeter index used is before the end of the line
            record.appendNode(line.substr(delimIndex));                     //since the last value is skipped by the loop, add the last value is added 
        
        
        //example data:  |    D   | 2  | Quach | Nick  | 10/02/1998 | 12/02/2020 | 
        //               | status | id | Last  | First | StartDate  | EndDate    |
        if (debug) { std::cout << "\n[DEBUG]: " << record.print(); }        //debug check to display the values in the LinkList
        
        input( record[2], record[3], record[4], record[5], atoi(record[1].c_str()), record[0].at(0) );
        return true;
    }//end read

    /// Precondition: 
    /// Postcondition:
    void input(string inLast, string inFirst, string inStartDat, string inEndDat = "Current", int inEmpID = nextId, char inStat = char('U')) {
        this->status = inStat;
        this->employee_id = inEmpID;
        this->lastName = inLast;
        this->firstName = inFirst;
        this->startingDate = inStartDat;
        this->endingDate = inEndDat;

        if (debug) {
            std::cout << "\nInput: " << inStat << "," << inEmpID << "," << inLast << "," << inFirst << "," << inStartDat << ","<< inEndDat << "\n";
            std::cout << "\nThis:  " << this->status << "," << this->employee_id << "," << this->lastName << "," << this->firstName << "," << this->startingDate << ","<< this->endingDate << "\n";
        }




    }//end input

    /// Precondition:
    /// Postcondition:
    int getId() const {
        return this->employee_id;
    }

    /// Precondition:
    /// Postcondition:
    char getStatus() const {
        return this->status;
    }

    string getStatusPretty() const {
        string currentStatus = string();
        currentStatus += this->status;
        switch (this->status) {
        case('A'):
            currentStatus += "(ctive)";
            break;
        case('U'):
            currentStatus += "(known)";
            break;
        case('I'):
            currentStatus += "(nactive)";
            break;

        }
        return currentStatus;
    }//end getStatusPretty

    /// Preconditiion: 
    /// Postcondition:
    string getLastName() const {
        return this->lastName;
    }

    /// Preconditiion: 
    /// Postcondition:
    string getFirstName() const {
        return this->firstName;
    }

    /// Preconditiion: 
    /// Postcondition:
    string getStartingDate() const {
        return this->startingDate;
    }

    /// Preconditiion: 
    /// Postcondition:
    string getEndingDate() const {
        return this->endingDate;
    }

    /// Preconditiion: 
    /// Postcondition:
    void setStatus(char newStat) {
        this->status = newStat;
    }

    

    /// Preconditiion: 
    /// Postcondition:
    void setLastName(string newLastNm) {
        this->lastName = newLastNm;
    }

    /// Preconditiion: 
    /// Postcondition:
    void setFirstName(string newFirstNm) {
        this->firstName = newFirstNm;
    }

    /// Preconditiion: 
    /// Postcondition:
    void setStartingDate(string newStartDate) {
        this->startingDate = newStartDate;
    }

    /// Preconditiion: 
    /// Postcondition:
    void setEndingDate(string newEndDate) {
        this->endingDate = newEndDate;
    }

    friend ostream& operator << (ostream& strm, const Employee& obj) {
        strm << obj.getStatus() << "," << obj.getId() << "," << obj.getLastName() << "," << obj.getFirstName() << "," << obj.getStartingDate() << "," << obj.getEndingDate();
        return strm;
    }//overloading << operator

};//end employee class

int Employee::nextId = 1;

/// Precondition: (int) id type
/// Postcondition: returns the found employee object within the list that matches that id, otherwise returns an empty id(0) employee object
Employee& search_id(int id,const LinkTList<Employee>& employeeList) {
    for (int i = 0; i < employeeList.getSize(); i++) {
        if (employeeList[i].getId() == id)
            return employeeList[i];
    }//end for                                                                           //if none found empty employee instance is returned
    //may have an issue with the return here, testing...
    
}//end search_id

//###################################################################
// Driver function
//###################################################################


//driver for the EMployeeList header file
void runEmployeeList() {
    LinkTList<Employee> employeeList = LinkTList<Employee>();
    
    do
    {
        
        switch (subMenuOptions_el())
        {
        case '0': return; break;
        case 'A':OptionA(employeeList); break;
        case 'B':OptionB(employeeList); break;
        case 'C':OptionC(employeeList); break;
        case 'D':OptionD(employeeList); break;
        case 'E':OptionE(employeeList); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
    } while (true);
}//end runEmployeeList





//###################################################################
// Menu function
//###################################################################

char subMenuOptions_el() {

    clrScrn();
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

void OptionA(LinkTList<Employee>& employeeList) {
    
    
    string filename = string();                                             
    ifstream* exists = new ifstream();                                     

    //This will be used to read the line and be broken down to local variables
    
    
    
    
    //Asking for the file name
    
    filename = inputString("\nEnter the filename: ", false);
    if(debug) filename = "EmployeeRecords.dat";                                       //debug stub overrides the value in input string


    //Opening the data file
    
    //checks to see if the file exists
    
    exists->open(filename, ios::in);
    //if opened the file successfully then continue
    if (!exists->fail())
    {
        exists->close();
        delete exists;

        ifstream dataFile = ifstream();
        dataFile.open(filename, ios::in);
        //end file initialization

        while (!dataFile.eof()) {
            Employee newEmployee(0);                                            //sets up an empty employee
            if (debug) std::cout << "\n[DEBUG] id (should be 0):" << newEmployee.getId() << "\n";        //for debugging purposes
            if (newEmployee.read(dataFile)) {                                   //if the line was read into the employee
                employeeList.appendNode(newEmployee);                           //add the employee to the employee list
            }//end if
        }//end while

        dataFile.close();                                                       //closing dataFile

        
        //action for after inserted into the list
        if (debug) {
            std::cout << "\n[DEBUG] size of list : " << employeeList.getSize() << "\n";
            std::cout << "\n[DEBUG] first value in list : " << employeeList[0] << "\n";
            std::cout << "\n[DEBUG] last value in list : " << employeeList[employeeList.getSize() - 1] << "\n";
            std::cout << "\n[DEBUG] all values of the list :\n";
            for (int i = 0; i < employeeList.getSize(); i++) {
                std:cout << "\n[DEBUG] \t" << employeeList[i] << "\n";
            }//end for
        }//end debug
        
        
        /*
        
        code here
        
        */


    }
    else
    {
        cout << "ERROR: Cannot open the file" << endl;
    }

}
//end of OptionA()


//###################################################################
// B> Insert a new employee record into the list 
//###################################################################


/// Precondition:
/// Postcondition:
void OptionB(LinkTList<Employee> &employeeList) {
    Employee newEmployee = Employee();
    employeeList.insertNode(newEmployee);


}//end OptionB


//###################################################################
// C> Update an employee record from the list 
//###################################################################


/// Precondition: (linkList<Employee>) employeeList contains the list of employee records in sorted order by Id, no Id may repeat
/// Postcondition: prompts the user to update the value in the employee list
void OptionC(LinkTList<Employee>& employeeList) {
    if (employeeList.empty()) {                                                                     //if the employeeList is empty .: violating the precondition, output an error message and return
    std:cout << "\nERROR: the  list is empty, please add a record\n";
        return;
    }//end if
    int editId = int();
    Employee* editEmployee = nullptr;
    int firstId = int();
    int lastId = int();
    //ask for the employee id to edit

    firstId = employeeList[0].getId();//sorted by id, first value has the lowest id
    lastId = employeeList[(employeeList.getSize() - 1)].getId();//sorted by id, last value has the highest id
    editId = inputInteger("\nPlease enter an id ("+ to_string(firstId) +"..."+ to_string(lastId) +"): ",firstId, lastId );
    
    //~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X
    // check for Logic error when 0 is entered as the id, seems to create a new value, sometimes it works ?
    //~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~X~

    //search for employee id
    editEmployee = new Employee(search_id(editId, employeeList));
    if (editEmployee->getId() == 0) {
        std::cout << "\nERROR: The employee id was not found within the list\n";
    }//end if
    else {
        do {
            
            char option;
            header("\nUpdate Employee ID : " + to_string(editEmployee->getId()) + " Record Information");
            printf("\nA > Current status : %s", editEmployee->getStatusPretty());
            printf("\nB > Current last name : %s", editEmployee->getLastName());
            printf("\nC > Current first name : %s", editEmployee->getFirstName());
            printf("\nD > Current Starting date : %s", editEmployee->getStartingDate());
            printf("\nE > Current Ending date : %s", editEmployee->getEndingDate());
            header("");
            printf("\n1 > Commit the change(s) and return");
            printf("\n0 > Uncommit the change(s) and return");
            header("");
            option = inputChar("\nOption : ", string("ABCDE10"));


            switch (option) {
            case('A'): {//A > Current status
                editEmployee->setStatus(inputChar("\nChange status to (A)ctive, (I)nactive or (U)nknown : ", string("AIU")));
                break;
            }//end case A
            case('B'): {//B > Current last name
                editEmployee->setLastName(inputString("\nEnter the new last name : ",true));

                break;
            }//end case B
            case('C'): {//C > Current first name
                editEmployee->setFirstName(inputString("\nEnter the new first name : ", true));
                break;
            }//end case C
            case('D'): {//D > Current Starting date
                editEmployee->setStartingDate(inputDate("\nEnter the new starting date (mm/dd/yy): ", '/'));
                break;
            }//end case D
                
            case('E'): {//E > Current Ending date 
                editEmployee->setEndingDate(inputDate("\nEnter the new ending date (mm/dd/yy): ", '/'));
                break;
            }//end case E
            case('1'): {//1 > Commit the change(s) and return


                printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n\t\t~~~~~~~~~~~~~~    CONFIRM COMMIT   ~~~~~~~~~~~~~~~~~~~");
                printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n\t\tCurrent status : %s", editEmployee->getStatusPretty());
                printf("\n\t\tCurrent last name : %s", editEmployee->getLastName());
                printf("\n\t\tCurrent first name : %s", editEmployee->getFirstName());
                printf("\n\t\tCurrent Starting date : %s", editEmployee->getStartingDate());
                printf("\n\t\tCurrent Ending date : %s", editEmployee->getEndingDate());
                printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n\t\t~~~~~~~~~~~~~~    CONFIRM COMMIT   ~~~~~~~~~~~~~~~~~~~");
                printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                if (inputChar("\n\t\tCommit [(Y)es/(N)o]: ", 'Y', 'N') == 'Y') {
                    search_id(editId, employeeList) = *editEmployee;
                    if (debug) std::cout << "\n" << employeeList[employeeList.find(*editEmployee)] << "\n";
                    printf("\n[COMMITED CHANGES] The changes have been commited/ Returning to the previous menu...\n");
                    return;
                }//end if
                else
                    break;
            }//end case 1
            case('0'): {//0 > Uncommit the change(s) and return
                printf("\n[UNCOMMITTED CHANGED] Returning to the previous menu...\n");
                if (debug) std::cout << "\n" << employeeList[employeeList.find(*editEmployee)] << "\n";
                return;
            }//end case 0
            default:
                printf("\nERROR: Please select a valid option");
                break;

            }//end switch

        } while (true);
    }

    //display the menu





    




}//end OptionC


//###################################################################
// D> Display all, active or inactive employee records from the list 
//###################################################################


/// Precondition:
/// Postcondition:

//=============================
//Sub menu for option D
//=============================

char subMenuOptions_Display_Employees() {

    clrScrn();
    header("\n\t\t1> Display Employee Record Information ");
    string options[] = { "\n\t\t\tA> All records",
                        "\n\t\t\tB> Active records ",
                        "\n\t\t\tC> Inactive records ",
                        "\n" + string(100 , char(196)) +
                        "\n\t\t\t0> return "

    };
    for (string option : options)
        cout << option;
    header("");

    char optionCh = inputChar("\n\t\t\tOption: ", string("ABC0"));
    clrScrn();
    return optionCh;

}//end menu




void readAllRecords(LinkTList<Employee>& employeeList) {

    bool empty = true;
    Employee temp;
    for (int i = 0; i < employeeList.getSize(); i++)
    {
        temp = employeeList.getPos(i);

        cout << "\tEmployee ID: " << "\t " << temp.getId() << endl;
        cout << "\tName: " << "\t " << temp.getLastName() << ", " << temp.getFirstName() << endl;
        cout << "\tStatus: " << "\t " << temp.getStatus() << endl;
        cout << "\tStart Date: " << "\t " << temp.getStartingDate() << endl;
        cout << "\tEnd Date: " << "\t " << temp.getEndingDate() << endl;
        cout << endl;
        empty = false;
    }

}
void readActiveRecords(LinkTList<Employee>& employeeList) {
    
    bool empty = true;
    Employee temp;
    for (int i = 0; i < employeeList.getSize(); i++)
    {
        temp = employeeList.getPos(i);
        if (temp.getStatus()=='A')
        {
            cout << "\tEmployee ID: " << "\t " << temp.getId() << endl;
            cout << "\tName: " << "\t " << temp.getLastName() << ", " << temp.getFirstName() << endl;
            cout << "\tStatus: " << "\t " << temp.getStatus() << endl;
            cout << "\tStart Date: " << "\t " << temp.getStartingDate() << endl;
            cout << "\tEnd Date: " << "\t " << temp.getEndingDate() << endl;
            cout << endl;
        
            empty = false;
        }

    }

    if (empty == true)
    {
        cout << "No records found. " << endl;
    }
}
void readInactiveRecords(LinkTList<Employee>& employeeList) {

    Employee temp;
    bool empty = true;

    for (int i = 0; i < employeeList.getSize(); i++)
    {
        temp = employeeList.getPos(i);
        if (temp.getStatus() == 'D')
        {
            cout << "\tEmployee ID: " << "\t " << temp.getId() << endl;
            cout << "\tName: " << "\t " << temp.getLastName() << ", " << temp.getFirstName() << endl;
            cout << "\tStatus: " << "\t " << temp.getStatus() << endl;
            cout << "\tStart Date: " << "\t " << temp.getStartingDate() << endl;
            cout << "\tEnd Date: " << "\t " << temp.getEndingDate() << endl;
            cout << endl;
        }

            empty = false;
    }


    if (empty == true)
    {
        cout << "No records found. " << endl;
    }
}

void OptionD(LinkTList<Employee>& employeeList) {
    if (employeeList.empty()) {                                                                     //if the employeeList is empty .: violating the precondition, output an error message and return
    std:cout << "\nERROR: the  list is empty, please add a record\n";
        return;
    }//end if
    do
    {
        switch (subMenuOptions_Display_Employees())
        {
        case '0': return; break;
        case 'A':readAllRecords(employeeList); break;
        case 'B':readActiveRecords(employeeList); break;
        case 'C':readInactiveRecords(employeeList); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
    } while (true);

}//end OptionD


//###################################################################
// E> Write data from the list to a file 
//###################################################################


/// Precondition: 
/// Postcondition:
void OptionE(LinkTList<Employee>& employeeList) {

}//end OptionE
