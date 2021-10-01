// File: Rational.h
// Assigned to: 
//			Thien
//	Team Members: [Reviewed]
//			Ben Halpern [Reviewed: 9/30/21]
//			Itz Rodriquez
//			Tony Cheng
//			Jose Chavez
//			Thien Nguyen
//	Professor Quach
//	CMPR 131
//	Assignment 4
//	9/23/21
//[REVIEWED] 9/30/21

#pragma once

#include <iostream>
#include "input.h"

using namespace std;

class Rational
{
private:
	int* numerator = nullptr;
	int* denominator = nullptr;
	bool _error_bit = bool(false);
public:
	// [Default constructor]
	Rational()
	{
		numerator = new int(0);
		denominator = new int(1);
	}//end Default Constructor

	// [Argument constructor]
	Rational(int newNum, int newDenom)
	{
		if (newDenom == 0)
			return;
		numerator = new int(newNum);
		denominator = new int(newDenom);
	}//end argument Constructor

	// [Copy constructor]
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

	// [Destructor]
	~Rational()
	{
		delete numerator;
		delete denominator;
	}

	int  GCD(int tempNumerator, int tempDenominator)
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

	int LCD(int tempNumerator, int tempDenominator)
	{
		return (tempNumerator * tempDenominator) / GCD(tempNumerator, tempDenominator);
	}

	// NORMALIZE IS WRONG NEEDS TO REDUCE
	// precondition: numerator and denominator set
	// postcondition: reduces fraction, checks if denominator == 0, and finds GCD 
	void normalize()
	{
		// testing reducing for loop
		if (*numerator % *denominator == 0)
		{
			for (int i = *denominator * *numerator; i > 1; i--)
			{
				if ((*denominator % i == 0) && (*numerator % i == 0))
				{
					*denominator /= i;
					*numerator /= i;
				}
			}
		}

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

		if (*denominator % *numerator == 0) {
			*denominator /= *numerator;
			*numerator /= *numerator;
		}

		int gcd = GCD(*numerator, *denominator);
		*numerator /= gcd;
		*denominator /= gcd;
	}


	// precondition: numerator and denominator set
	// postcondition: copys fraction, checks if denominator == 0, and finds GCD 
	void displayNormalization()
	{
		cout << "\n\tNormalized rational number R2 (a copy of R1)";

		Rational copyR1 = Rational(*numerator, *denominator);


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

		int gcd = GCD(*copyR1.numerator, *copyR1.denominator);
		*copyR1.numerator /= gcd;
		*copyR1.denominator /= gcd;

		cout << "\n\n\t" << copyR1;
	}

	// precondition: numerator and denominator set
	// postcondition: copys fraction and multiplys by -1
	void singleNegate()
	{
		Rational copyR1 = Rational(*numerator, *denominator);
		cout << "\n\tNegated rational number R2 (a copy of R1)";
		cout << "\n\n\t-(" << copyR1 << ") = " << copyR1 * (-1);
	}

	// precondition: numerator and denominator set
	// postcondition: adds int to a fraction both front and back
	void addSingleRational()
	{
		int addNumber = inputInteger("\n\tEnter an integer value:");
		Rational copyR1 = Rational(*numerator, *denominator);
		cout << "\n\tR2 + value";
		cout << "\n\t(" << copyR1 << ") + " << addNumber << " = " << copyR1 + addNumber;
		cout << "\n\n\tvalue + R2";
		cout << "\n\t" << addNumber << " + (" << copyR1 << ") = " << addNumber + copyR1;
	}

	// precondition: numerator and denominator set
	// postcondition: subtracts int to a fraction both front and back
	void subSingleRational()
	{
		int subNumber = inputInteger("\n\tEnter an integer value:");
		Rational copyR1 = Rational(*numerator, *denominator);
		cout << "\n\tR2 - value";
		cout << "\n\t(" << copyR1 << ") - " << subNumber << " = " << copyR1 - subNumber;
		cout << "\n\n\tvalue - R2";
		cout << "\n\t" << subNumber << " - (" << copyR1 << ") = " << subNumber - copyR1;
	}

	// precondition: numerator and denominator set
	// postcondition: multiplys a fraction by an int front and back
	void multiplySingleRational()
	{
		int multiplyNumber = inputInteger("\n\tEnter an integer value:");
		Rational copyR1 = Rational(*numerator, *denominator);
		cout << "\n\tR2 * value";
		cout << "\n\t(" << copyR1 << ") * " << multiplyNumber << " = " << copyR1 * multiplyNumber;
		cout << "\n\n\tvalue * R2";
		cout << "\n\t" << multiplyNumber << " * (" << copyR1 << ") = " << multiplyNumber * copyR1;
	}

	// precondition: numerator and denominator set
	// postcondition: divides a fraction by an int front and back
	void divSingleRational()
	{
		int divideNumber = inputInteger("\n\tEnter an integer value:");
		Rational copyR1 = Rational(*numerator, *denominator);
		cout << "\n\tR2 / value";
		cout << "\n\t(" << copyR1 << ") / " << divideNumber << " = " << copyR1 / divideNumber;
		cout << "\n\n\tvalue / R2";
		cout << "\n\t" << divideNumber << " / (" << copyR1 << ") = " << divideNumber / copyR1;
	}

	// precondition: 1st rational object initiated
	// postcondition: sets rational object a numerator and denominator
	void inputMultiRationalOne()
	{
		setNumerator(inputInteger("\n\tEnter the numerator for R1: "));
		setDenominator(inputInteger("\tEnter the denominator for R1: "));
	}

	// precondition: 2nd rational object initiated
	// postcondition: sets rational object a numerator and denominator
	void inputMultiRationalTwo()
	{
		setNumerator(inputInteger("\n\tEnter the numerator for R2: "));
		setDenominator(inputInteger("\tEnter the denominator for R2: "));
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

	// precondition: rational objects initiated 
	// postcondition: makes new numerator and denominator
	void operator = (const Rational& object)
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

	// precondition: rational objects numerator and denominator set 
	// postcondition: makes a product of a fraction and int
	Rational operator * (const int& number)
	{
		Rational temp = Rational((number * *numerator), *denominator);
		temp.normalize();
		return temp;
	}

	//#######################################################################################################################################
	// Accessor methods
	//#######################################################################################################################################

	bool errorBit() { return _error_bit; }

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

	// precondition: rational objects initiated 
	// postcondition: outputs a fraction format
	friend ostream& operator << (ostream& output, const Rational& theObject)
	{
		output << *theObject.numerator << "/" << *theObject.denominator;
		return output;
	}
	// precondition: rational objects initiated 
	// postcondition: outputs a fraction format
	friend ostream& operator << (ostream& output, Rational& theObject)
	{
		output << *theObject.numerator << "/" << *theObject.denominator;
		return output;
	}

	//#############################################################################
	// Friend methods                                   FOR SINGLE RATIONAL NUMBERS
	//#############################################################################

	// precondition: rational 1st then int 2nd
	// postcondition: adds rational and int
	friend Rational operator + (const Rational& rationalNumber, const int& number)
	{
		Rational convertedInt;
		convertedInt.setNumerator(number * rationalNumber.getDenominator());
		convertedInt.setDenominator(rationalNumber.getDenominator());

		Rational answer = rationalNumber + convertedInt;

		answer.normalize();

		if (*answer.denominator < 0)
		{
			*answer.denominator *= -1;
			*answer.numerator *= -1;
		}
		return answer;
	}

	// precondition: int 1st then rational 2nd
	// postcondition: adds int and rational
	friend Rational operator + (const int& number, const Rational& rationalNumber)
	{
		Rational convertedInt;
		convertedInt.setNumerator(number * rationalNumber.getDenominator());
		convertedInt.setDenominator(rationalNumber.getDenominator());

		Rational answer = convertedInt + rationalNumber;

		answer.normalize();

		if (*answer.denominator < 0)
		{
			*answer.denominator *= -1;
			*answer.numerator *= -1;
		}
		return answer;
	}

	// precondition: rational 1st then int 2nd
	// postcondition: subtracts rational and int
	friend Rational operator - (const Rational& rationalNumber, const int& number)
	{
		Rational convertedInt;
		convertedInt.setNumerator(number * rationalNumber.getDenominator());
		convertedInt.setDenominator(rationalNumber.getDenominator());

		Rational answer = rationalNumber - convertedInt;

		answer.normalize();

		if (*answer.denominator < 0)
		{
			*answer.denominator *= -1;
			*answer.numerator *= -1;
		}
		return answer;
	}

	// precondition: int 1st then rational 2nd
	// postcondition: subtracts int and rational
	friend Rational operator - (const int& number, const Rational& rationalNumber)
	{
		Rational convertedInt;
		convertedInt.setNumerator(number * rationalNumber.getDenominator());
		convertedInt.setDenominator(rationalNumber.getDenominator());

		Rational answer = convertedInt - rationalNumber;

		answer.normalize();

		if (*answer.denominator < 0)
		{
			*answer.denominator *= -1;
			*answer.numerator *= -1;
		}
		return answer;
	}

	// precondition: rational 1st then int 2nd
	// postcondition: finds product of rational and int
	friend Rational operator * (const Rational& rationalNumber, const int& number)
	{
		Rational convertedInt;
		convertedInt.setNumerator(rationalNumber.getNumerator() * number);
		convertedInt.setDenominator(rationalNumber.getNumerator() * rationalNumber.getDenominator());

		convertedInt.normalize();

		if (*convertedInt.denominator < 0)
		{
			*convertedInt.denominator *= -1;
			*convertedInt.numerator *= -1;
		}

		return convertedInt;
	}

	// precondition: int 1st then rational 2nd
	// postcondition: finds product of int and rational
	friend Rational operator * (const int& number, const Rational& rationalNumber)
	{
		Rational answer;
		answer.setNumerator(rationalNumber.getNumerator() * number);
		answer.setDenominator(rationalNumber.getDenominator());

		answer.normalize();
		
		if (*answer.denominator < 0)
		{
			*answer.denominator *= -1;
			*answer.numerator *= -1;
		}

		return answer;
	}

	// precondition: rational 1st then int 2nd, (int) number cannot be 0
	// postcondition: divides rational by int,
	friend Rational operator / (const Rational& rationalNumber_Left, const int& number_Right)
	{
		
			
		Rational answer = Rational();
		if (number_Right == 0) {
			answer._error_bit = true;
			return answer;
		}

		answer.setDenominator(rationalNumber_Left.getDenominator() * number_Right);
		answer.setNumerator(rationalNumber_Left.getNumerator());

		answer.normalize();

		if (*answer.denominator < 0)
		{
			*answer.denominator *= -1;
			*answer.numerator *= -1;
		}

		return answer;
	}

	// precondition: int 1st then rational 2nd, (Rational) cannot equate to 0
	// postcondition: divides int by rational
	friend Rational operator / (const int& number_Left, const Rational& rationalNumber_Right)
	{
		

		Rational answer = Rational();
		if (rationalNumber_Right.getNumerator() == 0) {
			answer._error_bit = true;
			return answer;
		}
		answer.setNumerator(rationalNumber_Right.getDenominator() * number_Left);
		answer.setDenominator(rationalNumber_Right.getNumerator());

		answer.normalize();

		if (*answer.denominator < 0)
		{
			*answer.denominator *= -1;
			*answer.numerator *= -1;
		}

		return answer;
	}

	//#############################################################################
	// Friend methods                                 FOR MULTIPLE RATIONAL NUMBERS
	//#############################################################################

	// precondition: two rational objects initiated
	// postcondition: adds two rational objects
	friend Rational operator + (const Rational& theObject1, const Rational& theObject2)
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

	// precondition: two rational objects initiated
	// postcondition: subtracts two rational objects
	friend Rational operator - (const Rational& theObject1, const Rational& theObject2)
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

	// precondition: two rational objects initiated
	// postcondition: finds product of two rational objects
	friend Rational operator * (const Rational& theObject1, const Rational& theObject2)
	{
		// (a/b)*(c/d)=(a*c)/(b*d)
		int tempNumerator = (*theObject1.numerator * *theObject2.numerator);
		int tempDenominator = (*theObject1.denominator * *theObject2.denominator);

		Rational temp(tempNumerator, tempDenominator);

		temp.normalize();

		return temp;
	}

	// precondition: two rational objects initiated
	// postcondition: divides two rational objects
	friend Rational operator / (const Rational& theObject1, const Rational& theObject2)
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

	// precondition: two rational objects initiated
	// postcondition: evaluates two rational objects if they do not equal each other
	friend bool operator != (const Rational& theObject1, const Rational& theObject2)
	{
		//(a/b)!=(c/d) means (a*d)!=(c*b)
		int temp1 = (*theObject1.numerator * *theObject2.denominator);
		int temp2 = (*theObject1.denominator * *theObject2.numerator);
		if (temp1 != temp2)
			return true;
		else
			return false;
	}

	// precondition: two rational objects initiated
	// postcondition: evaluates if a rational object is greater than or equal to another
	friend bool operator >= (const Rational& theObject1, const Rational& theObject2)
	{
		//(a/b)>=(c/d) means (a*d)>=(c*b)
		int temp1 = (*theObject1.numerator * *theObject2.denominator);
		int temp2 = (*theObject1.denominator * *theObject2.numerator);
		if (temp1 > temp2 || temp1 == temp2)
			return true;
		else
			return false;
	}

	// precondition: two rational objects initiated
	// postcondition: evaluates if a rational object is greater than an another
	friend bool operator > (const Rational& theObject1, const Rational& theObject2)
	{
		//(a/b)>(c/d) means (a*d)>(c*b)
		int temp1 = (*theObject1.numerator * *theObject2.denominator);
		int temp2 = (*theObject1.denominator * *theObject2.numerator);
		if (temp1 > temp2)
			return true;
		else
			return false;
	}

	// precondition: two rational objects initiated
	// postcondition: evaluates if a rational object is less than or equal to another
	friend bool operator <= (const Rational& theObject1, const Rational& theObject2)
	{
		int temp1 = (*theObject1.numerator * *theObject2.denominator);
		int temp2 = (*theObject1.denominator * *theObject2.numerator);
		if (temp1 < temp2 || temp1 == temp2)
			return true;
		else
			return false;
	}

	// precondition: two rational objects initiated
	// postcondition: evaluates if a rational object is less than an another
	friend bool operator < (const Rational& theObject1, const Rational& theObject2)
	{
		//(a/b)<(c/d) means (a*d)<(c*b)
		int temp1 = (*theObject1.numerator * *theObject2.denominator);
		int temp2 = (*theObject1.denominator * *theObject2.numerator);
		if (temp1 < temp2)
			return true;
		else
			return false;
	}

	// precondition: two rational objects initiated
	// postcondition: evaluates two rational objects are equal to each other
	friend bool operator == (const Rational& theObject1, const Rational& theObject2)
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

// precondition: two rational objects initiated
// postcondition: evaluates ==, !=, >=,  >, <=, and  < of two rational objects
void conditionRationalNumbers(Rational& object1, Rational& object2)
{
	cout << "\n\t\tR1 == R2 -> (" << object1 << ") == (" << object2 << ") is " << (object1 == object2 ? "True" : "False");
	cout << "\n\t\tR2 != R1 -> (" << object2 << ") != (" << object1 << ") is " << (object2 != object1 ? "True" : "False");
	cout << "\n\t\tR1 >= R2 -> (" << object1 << ") >= (" << object2 << ") is " << (object1 >= object2 ? "True" : "False");
	cout << "\n\t\tR2  > R1 -> (" << object2 << ")  > (" << object1 << ") is " << (object2 > object1 ? "True" : "False");
	cout << "\n\t\tR1 <= R2 -> (" << object1 << ") <= (" << object2 << ") is " << (object1 <= object2 ? "True" : "False");
	cout << "\n\t\tR2  < R1 -> (" << object2 << ")  < (" << object1 << ") is " << (object2 < object1 ? "True" : "False");
	cout << endl;
}

// precondition: two rational objects initiated
// postcondition: evaluates  +, -, * and / of two rational objects
void evaluateRationalNumbers(Rational& object1, Rational& object2)
{
	cout << "\n\t\tAddition    : R1 + R2 -> (" << object1 << ") + (" << object2 << ") = " << object1 + object2;
	cout << "\n\t\tSubtraction : R2 - R1 -> (" << object2 << ") - (" << object1 << ") = " << object2 - object1;
	cout << "\n\t\tMutiplcation: R1 * R2 -> (" << object1 << ") * (" << object2 << ") = " << object1 * object2;
	cout << "\n\t\tDivision    : R2 / R1 -> (" << object2 << ") / (" << object1 << ") = " << object2 / object1;
	cout << endl;
}

// precondition: two rational objects initiated
// postcondition: evaluates an equation using two rational numbers
void evaluatEquation(Rational& object1, Rational& object2)
{
	// (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889
	// ?? Hard code ??
	Rational three(3, 1), seven(7, 1), nine(9, 1);
	Rational multiRationalThree(621, 889);

	cout << "\n\t\tR1 = " << object1;
	cout << "\n\t\tR2 = " << object2;
	cout << "\n\t\tR3 = " << multiRationalThree;
	cout << "\n\n\t\tEvaluating expression...";
	cout << "\n\n\t\t\t (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889 ?";
	cout << "\n\t\tstep #1: (3 * (" << object1 + object2 << ") / 7) / (R2 - (" << object1 / nine << ")) >= 621/889 ?";
	cout << "\n\t\tstep #2: ((" << three * (object1 + object2) << ") / 7) / (" << object2 - (object1 / nine) << ") >= 621/889 ?";
	cout << "\n\t\tstep #3: (" << (three * (object1 + object2)) / seven << ") / (" << object2 - (object1 / nine) << ") >= 621/889 ? ";
	Rational evaluatedRationalNumber = (((three * (object1 + object2)) / seven) / (object2 - (object1 / nine)));
	cout << "\n\t\tstep #4: (" << evaluatedRationalNumber << ") >= 621/889 ?";
	cout << "\n\t\tstep #5: " << (evaluatedRationalNumber >= multiRationalThree ? "True" : "False");
}

void runMulitRational()
{
	Rational multiRationalOne, multiRationalTwo;

	do
	{
		switch (multiRationalMenuOption())
		{
		case 0: return; break;
		case 1: multiRationalOne.inputMultiRationalOne();
			cout << "\n\tR1 = " << multiRationalOne; break;
		case 2: multiRationalTwo.inputMultiRationalTwo();
			cout << "\n\tR2 = " << multiRationalTwo; break;
		case 3: conditionRationalNumbers(multiRationalOne, multiRationalTwo); break;
		case 4: evaluateRationalNumbers(multiRationalOne, multiRationalTwo); break;
		case 5: evaluatEquation(multiRationalOne, multiRationalTwo); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
		clrScrn();
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
		case 5: rationalOne.singleNegate(); break;
		case 6: rationalOne.addSingleRational(); break;
		case 7: rationalOne.subSingleRational(); break;
		case 8: rationalOne.multiplySingleRational(); break;
		case 9: rationalOne.divSingleRational(); break;
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

//////////////////////////
// MAIN DRIVER FUNCTION // 
//////////////////////////
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