// Team Members:
//
//
//
//


#pragma once
#include "input.h"
#include <iostream>
#include "myContainers.h"

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
                        "\n\t\t\t0> exit "

    };
    for (string option : options)
        cout << option;
    header("");

    char optionCh = inputChar("\n\t\t\tOption: ", string("ABCDE"));
    clrScrn();
    return optionCh;

}//end menu



void OptionA() {

}

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
    int id;
    char status;
    string firstName;
    string lastName;
    string hireDate;
    string termDate;


public:



}//end employee class