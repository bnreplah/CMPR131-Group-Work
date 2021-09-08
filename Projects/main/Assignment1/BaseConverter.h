//
// Option 1 
//		Thien Nguyen
//		Itz Rodriquez
//		Tony Cheng
//		Jose Chavez
//		Ben Halpern
#pragma once
#include "input.h"
#include <iostream>;
#include <string>
#include <vector>
#include <cmath>

int inputNumber();
void convertPrint(int number);
int decToBase(int number, int base);
void convertPrintAll(int number);
int number;


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
