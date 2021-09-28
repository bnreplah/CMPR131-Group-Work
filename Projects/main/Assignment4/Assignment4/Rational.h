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
	int* numerator = nullptr;
	int* denominator = nullptr;

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
	}//end argument Constructor

	// copy constructor
	Rational(const Rational& object)
	{
		if (numerator != nullptr && denominator != nullptr)
		{
			if (*denominator == 0)
				return;
			*numerator = *object.numerator;
			*denominator = *object.denominator;
		}
		else
		{
			if (!numerator) numerator = new int(*object.numerator);
			if (!denominator) denominator = new int(*object.denominator);
		}
	}

	/*Rational(const Rational& object)
	{
		if (denominator == 0)
			return;
		if (numerator != NULL && denominator != NULL)
		{
			*this->numerator = *object.numerator;
			*this->denominator = *object.denominator;
		}
		else
		{
			if (!numerator) numerator = new int(*object.numerator);
			if (!denominator) denominator = new int(*object.denominator);
		}
	}*/

	~Rational()
	{
		delete numerator;
		delete denominator;
	}

	int  greatCommonDivisor(int tempNumerator, int tempDenominator)
	{
		while (true)
		{
			tempNumerator = tempNumerator % tempDenominator;
			if (tempNumerator == 0)
				return tempDenominator;
			tempDenominator = tempDenominator % tempNumerator;
			if (tempDenominator == 0)
				return tempNumerator;
		}
	}

	void normalize()
	{
		if (*numerator < 0 && *denominator < 0)
		{
			abs(*numerator);
			abs(*denominator);
		}
		else if (*denominator < 0)
		{
			*numerator *= -1;
			abs(*denominator);
		}

		int gcd = greatCommonDivisor(*numerator, *denominator);
		*numerator /= gcd;
		*denominator /= gcd;
	}

	Rational displayNormalization()
	{
		cout << "\n\tNormalized rational number R2 (a copy of R1)";

		Rational copyR1 = Rational(*numerator, *denominator);

		cout << "copy r1 " << copyR1;

		if (*copyR1.numerator < 0 && *copyR1.denominator < 0)
		{
			*copyR1.numerator = abs(*copyR1.numerator);
			*copyR1.denominator = abs(*copyR1.denominator);
		}
		else if (*copyR1.denominator < 0)
		{
			*copyR1.numerator *= -1;
			*copyR1.denominator = abs(*copyR1.denominator);
		}

		int gcd = greatCommonDivisor(*copyR1.numerator, *copyR1.denominator);
		*copyR1.numerator /= gcd;
		*copyR1.denominator /= gcd;

		cout << "\n\n\t" << copyR1;

		return copyR1;
	}

	void negate()
	{


	}


	//#######################################################################################################################################
	// Mutators methods
	//#######################################################################################################################################

	void setNumerator(int newNum)
	{
		*this->numerator = newNum;
	}//end setNumerator


	void setDenominator(int newDenom)
	{
		if (newDenom == 0)
			newDenom = 1;
		if (newDenom < 0)
		{
			newDenom *= -1;
			newDenom *= -1;
		}
		*this->denominator = newDenom;
	}//end setNumerator

	void operator=(const Rational& object)
	{
		if (denominator == 0)
			return;
		if (numerator != NULL && denominator != NULL)
		{
			*this->numerator = *object.numerator;
			*this->denominator = *object.denominator;
		}
		else
		{
			if (!numerator) numerator = new int(*object.numerator);
			if (!denominator) denominator = new int(*object.denominator);
		}
		//return *this;
	}

	Rational operator * (const int& number)
	{
		return Rational((number * *numerator), *denominator);


	}

	//Rational& operator=(Rational& object) // const
	//{
	//	if (denominator == 0)
	//		return;
	//	if (numerator != NULL && denominator != NULL)
	//	{
	//		*this->numerator = *object.numerator;
	//		*this->denominator = *object.denominator;
	//	}
	//	else
	//	{
	//		if (!numerator) numerator = new int(*object.numerator);
	//		if (!denominator) denominator = new int(*object.denominator);
	//	}
	//	return *this;
	//}

	//#######################################################################################################################################
	// Accessor methods
	//#######################################################################################################################################


	int getNumerator() const
	{
		return *this->numerator;
	}//end setNumerator


	int getDenominator() const
	{
		return *this->denominator;
	}//end setNumerator


	//#######################################################################################################################################
	// Friend methods
	//#######################################################################################################################################


	friend ostream& operator <<(ostream& output, const Rational& theObject)
	{
		output << *theObject.numerator << "/" << *theObject.denominator;
		return output;
	}

	/*friend istream& operator >>(istream& input, Rational& theObject)
	{
		cout << "\n\tEnter the numerator: ";
		input >> *theObject.numerator;
		cout << "\tEnter the denominator: ";
		input >> *theObject.denominator;
		if (*theObject.denominator == 0)
			*theObject.denominator = 1;
		if (*theObject.denominator < 0)
		{
			*theObject.denominator *= -1;
			*theObject.numerator *= -1;
		}
		return input;
	}*/

	friend Rational operator +(const Rational& theObject1, const Rational& theObject2)
	{
		// a/b + c/d = (a * d + b * c) / ( b * d)
		int tempNumerator = (*theObject1.numerator * *theObject2.denominator + *theObject1.denominator * *theObject2.numerator);
		int tempDenominator = (*theObject1.denominator * *theObject2.denominator);
		Rational temp(tempNumerator, tempDenominator);

		temp.normalize();

		if (tempDenominator < 0)
		{
			tempDenominator *= -1;
			tempNumerator *= -1;
		}

		return temp;
	}

	friend Rational operator -(const Rational& theObject1, const Rational& theObject2)
	{
		// a/b-c/d=(a*d-b*c)/(b*d)
		int tempNumerator = (*theObject1.numerator * *theObject2.denominator - *theObject1.denominator * *theObject2.numerator);
		int tempDenominator = (*theObject1.denominator * *theObject2.denominator);

		Rational temp(tempNumerator, tempDenominator);

		if (tempDenominator < 0)
		{
			tempDenominator *= -1;
			tempNumerator *= -1;
		}

		temp.normalize();

		return temp;
	}


	friend Rational operator *(const Rational& theObject1, const Rational& theObject2)
	{
		// (a/b)*(c/d)=(a*c)/(b*d)
		int tempNumerator = (*theObject1.numerator * *theObject2.numerator);
		int tempDenominator = (*theObject1.denominator * *theObject2.denominator);

		Rational temp(tempNumerator, tempDenominator);

		temp.normalize();

		return temp;
	}

	friend Rational operator /(const Rational& theObject1, const Rational& theObject2)
	{
		// (a/b)*(c/d)=(a*d)/(b*c)
		int tempNumerator = (*theObject1.numerator * *theObject2.denominator);
		int tempDenominator = (*theObject1.denominator * *theObject2.numerator);

		if (tempDenominator < 0)
		{
			tempNumerator *= -1;
			tempDenominator *= -1;
		}

		Rational temp(tempNumerator, tempDenominator);
		temp.normalize();

		return temp;
	}


	friend bool operator !=(const Rational& theObject1, const Rational& theObject2)
	{
		//(a/b)!=(c/d) means (a*d)!=(c*b)
		int temp1 = (*theObject1.numerator * *theObject2.denominator);
		int temp2 = (*theObject1.denominator * *theObject2.numerator);
		if (temp1 != temp2)
			return true;
		else
			return false;
	}

	friend bool operator >=(const Rational& theObject1, const Rational& theObject2)
	{
		//(a/b)>=(c/d) means (a*d)>=(c*b)
		int temp1 = (*theObject1.numerator * *theObject2.denominator);
		int temp2 = (*theObject1.denominator * *theObject2.numerator);
		if (temp1 > temp2 || temp1 == temp2)
			return true;
		else
			return false;
	}

	friend bool operator >(const Rational& theObject1, const Rational& theObject2)
	{
		//(a/b)>(c/d) means (a*d)>(c*b)
		int temp1 = (*theObject1.numerator * *theObject2.denominator);
		int temp2 = (*theObject1.denominator * *theObject2.numerator);
		if (temp1 > temp2)
			return true;
		else
			return false;
	}

	friend bool operator <=(const Rational& theObject1, const Rational& theObject2)
	{
		int temp1 = (*theObject1.numerator * *theObject2.denominator);
		int temp2 = (*theObject1.denominator * *theObject2.numerator);
		if (temp1 < temp2 || temp1 == temp2)
			return true;
		else
			return false;
	}

	friend bool operator <(const Rational& theObject1, const Rational& theObject2)
	{
		//(a/b)<(c/d) means (a*d)<(c*b)
		int temp1 = (*theObject1.numerator * *theObject2.denominator);
		int temp2 = (*theObject1.denominator * *theObject2.numerator);
		if (temp1 < temp2)
			return true;
		else
			return false;
	}

	friend bool operator ==(const Rational& theObject1, const Rational& theObject2)
	{
		//(a/b)=(c/d) means (a*d)=(c*b)
		int temp1 = (*theObject1.numerator * *theObject2.denominator);
		int temp2 = (*theObject1.denominator * *theObject2.numerator);
		if (temp1 == temp2)
			return true;
		else
			return false;
	}
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
						 "\n\t\t2. Enter the denominator",
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
	Rational rationalOne;

	do
	{
		switch (singleRationalMenuOption())
		{
		case 0: return; break;
		case 1: rationalOne.setNumerator(inputInteger("\n\tEnter the numerator: ")); break;
		case 2: rationalOne.setDenominator(inputInteger("\n\tEnter the denominator: ")); break;
		case 3: cout << "\n\t\tRational number R1 = " << rationalOne; break;
		case 4: rationalOne.displayNormalization(); break;
		case 5: cout << "\n\tThe negative of R1 is: " << rationalOne * (-1); break;
		case 6:; break;
		case 7:; break;
		case 8:; break;
		case 9:; break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
		clrScrn();

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