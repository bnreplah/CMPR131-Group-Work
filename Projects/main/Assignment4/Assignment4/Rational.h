//
//
//
//

#pragma once

#include <iostream>
#include "input.h"
using namespace std;

class Rational
{
private:
	int* numerator;
	int* denominator;

public:
	/// [Default constructor]
	Rational()
	{
		numerator = new int(0);
		denominator = new int(1);
	}//end Default Constructor

	Rational(int newNum, int newDenom)
	{
		if (newDenom == 0)
			return;
		numerator = new int(newNum);
		denominator = new int(newDenom);
	}//end Default Constructor

	~Rational()
	{
		delete numerator;
		delete denominator;
	}


	//#######################################################################################################################################
	// Mutators methods
	//#######################################################################################################################################

	void setNumerator(int newNum)
	{
		*this->numerator = newNum;
	}//end setNumerator


	void setDenomenator(int newDenom)
	{
		*this->denominator = newDenom;
	}//end setNumerator


	//#######################################################################################################################################
	// Accessor methods
	//#######################################################################################################################################


	int getNumerator() const
	{
		return *this->numerator;
	}//end setNumerator


	int getDenomenator() const
	{
		return *this->denominator;
	}//end setNumerator


	//#######################################################################################################################################
	// Friend methods
	//#######################################################################################################################################


	/*friend ostream& operator <<(ostream& outs, const Rational& theObject)
	{
		outs << theObject.numerator << "/" << theObject.denominator;
		return outs;
	}


	friend istream& operator >>(istream& ins, Rational& theObject)
	{
		cout << "\n\tEnter the numerator: ";
		ins >> theObject.numerator;
		cout << "\tEnter the denominator: ";
		ins >> theObject.denominator;
		if (theObject.denominator == 0)
			theObject.denominator = 1;
		if (theObject.denominator < 0)
		{
			theObject.denominator *= -1;
			theObject.numerator *= -1;
		}
		return ins;
	}*/




};//end class

int multiRationalMenuOption()
{
	int optionInteger;
	header("B> Multiple Rational Numbers");
	string options[] = { "\n\t\t1. Enter rational number R1",
						 "\n\t\t2. Enter rational number R2",
						 "\n\t\t3. Verify condition operators (==, !=, >=, >, <= and <) of R1 and R2",
						 "\n\t\t4. Evaluate arithmatic operators (+, - , * and /) of R1 and R2",
						 "\n\t\t5. Evaluate (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889",
						 "\n\t" + string(100 , char(196)) +
						 "\n\t\t0. return "
	};
	for (string option : options)
		cout << option;

	cout << "\n\t" << string(100, char(205));
	optionInteger = inputInteger("\n\t\tOption: ", 0, 9);
	clrScrn();

	return optionInteger;
}

void runMulitRational()
{
	int optionInteger;

	do
	{
		switch (multiRationalMenuOption())
		{
		case 0: return; break;
		case 1:; break;
		case 2:; break;
		case 3:; break;
		case 4:; break;
		case 5:; break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
	} while (true);
}

int singleRationalMenuOption()
{
	int optionInteger;
	header("A> A Rational Number");
	string options[] = { "\n\t\t1. Enter the numerator",
						 "\n\t\t2. Enter the deminator",
						 "\n\t\t3. Display the rational number",
						 "\n\t\t4. Normalize the rational number",
						 "\n\t\t5. Negate the rational number",
						 "\n\t\t6. Add (+) the rational number with a constant",
						 "\n\t\t7. Subtract (-) the rational number with a constant",
						 "\n\t\t8. Multiply (*) the rational number with a constant",
						 "\n\t\t9. Divide (/) the rational number with a constant",
						 "\n\t" + string(100 , char(196)) +
						 "\n\t\t0. return "
	};
	for (string option : options)
		cout << option;

	cout << "\n\t" << string(100, char(205));
	optionInteger = inputInteger("\n\t\tOption: ", 0, 9);
	clrScrn();

	return optionInteger;
}

void runSingleRational()
{
	int optionInteger;

	do
	{

		switch (singleRationalMenuOption())
		{
		case 0: return; break;
		case 1:; break;
		case 2:; break;
		case 3:; break;
		case 4:; break;
		case 5:; break;
		case 6:; break;
		case 7:; break;
		case 8:; break;
		case 9:; break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
	} while (true);
}

char rationalMenuOption()
{
	string options[] = { "\n\tA rational number is a number that can be written as a fraction, a/b, where a is numerator and",
						"\n\tb is denominator. Rational numbers are all real numbers, and can be positive or negative. A",
						"\n\tnumber that is not rational is called irrational. Most of the numbers that people use in everyday",
						"\n\tlife are rational.These include fractions, integers and numbers with finite decimal digits."
						"\n\tIn general, a number that can be written as a fraction while it is in its own form is rational."
						"\n\n\t2> Rational Numbers",
						"\n\t" + string(100, char(205)) +
						"\n\t\tA> A Rational Number",
						"\n\t\tB> Multiple Rational Numbers",
						"\n\t" + string(100 , char(196)) +
						"\n\t\t0> return "
						"\n\t" + string(100, char(205))
	};
	for (string option : options)
		cout << option;

	char optionChar = inputChar("\n\t\toption ", static_cast<string>("ab0"));
	clrScrn();

	return optionChar;
}//end menuOptions

// main driver function
void runRational()
{
	Rational rationalOne;

	rationalOne.setNumerator(inputInteger("Enter number"));
	rationalOne.getNumerator();

	do
	{
		switch (rationalMenuOption())
		{
		case '0': return; break;
		case 'A': runSingleRational();; break;
		case 'B': runMulitRational(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
	} while (true);
}