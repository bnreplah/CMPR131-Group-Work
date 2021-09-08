//	Names:
//		Thien Nguyen
//		Itz Rodriquez
//		Tony Cheng
//		Jose Chavez
//		Ben Halpern
//	Professor Quach
//	CMPR 131
//	Assignment 1
//	8/26/21
/*
*	Description:
*		Assignment 1, A menu driven program which provides the user to select 3 options, each option takes the user to another menu,
*			on further specifications.
*
*
*/

#include <iostream>
#include "input.h"
#include "DescriptiveStats.h"
#include<cmath>
#include<vector>
#include "textToASCII.h"
#include "BaseConverter.h"
using namespace std;


//Prototypes:
int menuOption();
void Option1();
void Option2();
void Option3();


int main() {

    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;

        case 1: Option1(); break;
        case 2: Option2(); break;
        case 3: Option3(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
    } while (true);

    return EXIT_SUCCESS;
}//end main()


/// Precondition: N/A
/// Postcondition: Diplays a menue for the user and prompt for the user's option choice selection. Returns a valid option.
int menuOption() {



    int optionInt;

    header("CMPR 131 -  Chapter 1 Software Development by Thien , Itz, Tony, Jose, and Ben");
    string options[] = { "\n\t\t1> ASCII Text To ASCII Numbers ",
                        "\n\t\t2> Base Converter ",
                        "\n\t\t3> Descriptive Statistics ",
                        "\n" + string(100 , char(196)) +
                        "\n\t\t0> exit "

    };
    for (string option : options)
        cout << option;
    header("");

	int optionInteger = inputInteger("\nOption: ", 0, 3);
	clrScrn();
	return optionInteger;

}//end menuOption


/// Precondition: Option 1 is selected on main menu
/// Postcondition: exit textToAscii menu by choosing case 0

void Option1() {
    string inputText = string();
    string ascii = string();
    int ascii_size = 0;
    do
    {
        switch (Option1Menu())
        {
        case '0': return; break;
        case 'A': inputText = stringInput(); break;
        case 'B': ascii = textToAscii(inputText); break;
        case 'C': ascii_size = asciiToBin(ascii); break;
        case 'D': readTest(ascii_size); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
        clrScrn();
    } while (true);
}

void Option2()
{
    do
    {
        header("\n\t\t2>Base Converter");
        string options[] = { 
                       "\n\t    A> Enter an integer number (base 10)",
                       "\n\t    B> Specify and converting base",
                       "\n\t    C> Display all converted bases (2... 36)",
                       "\n" + string(100 , char(196)) +
                       "\n\t\t0> exit "

        };
        for (string option : options)
            cout << option;
        header("");


        char option = inputChar(string("\n\n\tOption: "), string("abc"));

        switch (option)
        {
        case '0': return;
            break;
        case 'A': inputNumber();
            break;
        case 'B': convertPrint(number);
            break;
        case 'C': convertPrintAll(number);
            break;
        default:
            break;
        }
    } while (true);
}
//end option2()



/// Precondition:
/// Postcondition:
void Option3() {
	
	//driver for Descriptive Statistics
	runDescriptiveStatistics();


}//end Option3()
//EOF



