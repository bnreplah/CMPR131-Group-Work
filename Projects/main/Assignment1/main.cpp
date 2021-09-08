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
using namespace std;


//Prototypes:
int menuOption();
void Option1();
void Option2();
void Option3();
int inputNumber();
void convertPrint(int number);
int decToBase(int number, int base);
void convertPrintAll(int number);
int number;

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
        case 1: Option1(); break;
        case 2: Option2(); break;
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
    } while (true);
}

// precondition : choose case A to enter an integer
// postcondition : inputs users integer to be converted
int inputNumber()
{
    number = inputInteger("\n\tEnter an integer number to convert from base 10: ");
    return number;
}

// precondition : choose case B takes user input to convert
// postcondition : outputs integer, converted integer and chosen base
void convertPrint(int number)
{
    int newBase = inputInteger("\n\tEnter the base (2... 36) to convert to: ", 2, 36);
    cout << "\n\t" << number << " (base of 10) = ";
    //if (number <0)
    //{
    //    cout << "-";
    //}
    int convertedNumber = decToBase(number, newBase);
    cout << " (base of " << newBase << ")\n\n";
}


// precondition : number and desired base have been declared
// postcondition : will convert number to a chosen base

int decToBase(int number, int base)
{
    // this boolean to facilitate the handling negative input 
    bool negative = false;

    if (number < 0)
    {
        //the number would be multiplied by -1 so it can assign the correct char from base vector
        //otherwise it will cause a runtime errror
        number = (number * -1);
        negative = true;
    }

    int quotient = number;
    int remainder = 0;

    vector<char> baseVector = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F',
        'G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };


    vector<char> remainVector;



    while (quotient != 0)
    {
        remainder = quotient % base;
        quotient = quotient / base;
        remainVector.push_back(baseVector.at(remainder));
    }

    for (int i = remainVector.size() - 1; i >= 0; i--)
    {

        //This condition is to handle negative numbers, adds a "-"
        if (negative == true)
        {
            cout << "-" << remainVector[i];
            negative = false;
        }
        else if (negative == false)
        {

            cout << remainVector[i];
        }
    }
    return 0;
}

// precondition : number has been declared 
// postcondition : outputs number and all possible conversions and bases
void convertPrintAll(int number)
{
    cout << "\n\t" << number << " (base of 10) = \n";

    int baseTwo = 2;
    int baseThritySix = 36;

    for (int i = baseTwo; i <= baseThritySix; i++) {

        cout << "\t\t";
        int convertedNumber = decToBase(number, i);

        if (i == 2) cout << " (base of " << i << " - binary)\n";
        else if (i == 8) cout << " (base of " << i << " - octal)\n";
        else if (i == 10) cout << " (base of " << i << " - decimal)\n";
        else if (i == 16) cout << " (base of " << i << " - hex)\n";
        else cout << " (base of " << i << ")\n";
    }
}

void Option2()
{
    do
    {
        cout << "\n\t    2> Base Converter ";
        cout << "\n\t======================================";
        cout << "\n\t    A> Enter an integer number (base 10)";
        cout << "\n\t    B> Specify and converting base";
        cout << "\n\t    C> Display all converted bases (2... 36)";
        cout << "\n\t======================================";
        cout << "\n\t    0> return";


        char option = inputChar(string("\n\n\tOption: "), string("abc"));

        switch (option)
        {
        case '0': exit(0);
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



