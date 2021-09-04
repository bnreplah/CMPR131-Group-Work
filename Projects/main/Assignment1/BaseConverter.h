// option 2: the base converter has three options, A: intakes a integer - B: will convert 
// the given integer to a desired base - C: will convert the given integer to all bases (2 to 36)
//
//
// 
//

#pragma once
#include "input.h"
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int inputNumber();
void convertPrint(int number);
int decToBase(int number, int base);
void convertPrintAll(int number);
int number;

// precondition : choose B the base converter in the main menu
// postcondition : will output 4 options
void menuOption2()
{
    clrScrn();
    do
    {
        header("\n\t    2> Base Converter ");
        
        cout << "\n\t    A> Enter an integer number (base 10)";
        cout << "\n\t    B> Specify and converting base";
        cout << "\n\t    C> Display all converted bases (2... 36)";
        cout << "\n" + string(100, char(196));
        cout << "\n\t    0> return";
        header("");
        char option = inputChar("\n\n\tOption: ", "abc0");

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
            cout << "\nError: ";
            break;
        }
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
    int convertedNumber = decToBase(number, newBase);
    cout << " (base of " << newBase << ")\n\n";
}

// precondition : number and desired base have been declared
// postcondition : will convert number to a chosen base
int decToBase(int number, int base)
{
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
        cout << remainVector[i];
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