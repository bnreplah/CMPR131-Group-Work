#pragma once
//
// Team members:
//
// Assigned: Tony and Ben
//
//
//

#include "input.h"
#include <string>
#include <iomanip>
#include <cstdio>
#include <iostream>

//prototypes
void runComplex();
char runComplex_menuOption();
void runComplex_A_Menu();
void runComplex_B_Menu();
//class Complex;





///****************************************************************************************************************************************
/// Complex class
///****************************************************************************************************************************************

/**
* Class Complex
*	i^0 = 1							if (imagPower %2 == 0)? -1 : ( (imagPower %3 == 0)? -i; i );
*	i^1 = \sqrt(-1)					if
*	i^2*n = (-1)					imagPower %2 == 0
*	i^3*n = -i						imagPower %3 == 0
*	i^4 = 1
*	i^5 = i
* ...
*
*/
class Complex {
private:
	//bool negative = bool();
	double realNum = double();
	double imagNum = double();
	int imagPower = int();
	const bool DEBUG = true;
public:


	/// [Default constructor]
	Complex() : realNum(0), imagNum(0), imagPower(1) {
		if (DEBUG) std::cout << "\nRN: " << realNum << ": IN: " << imagNum << "i^" << imagPower << "\n";
	}

	/// [Argument Constructor]
	/// 
	Complex(double pRealNum, double pImagNum, int pPower) : realNum(pRealNum), imagNum(pImagNum), imagPower(pPower) {}


	/// [Copy Constructor]
	///
	Complex(const Complex& obj) {

		realNum = obj.realNum;
		imagNum = obj.imagNum;
		imagPower = obj.imagPower;

	}


	//******************************************************************************************************
	// Operators
	//******************************************************************************************************



	/// [Assignment Operator]
	///
	Complex& operator =(const Complex& obj) {
		this->realNum = obj.realNum;
		this->imagNum = obj.imagNum;
		this->imagPower = obj.imagPower;
		return *this;
	}//end (=)

	/// [Additive Operator]
	/// STUB
	Complex operator +(const Complex& obj) {

		return *this;
	}//end (+)

	Complex operator +(double value) const {
		return Complex((this->realNum + value), this->imagNum, this->imagPower);

	}//end (+)

	/// [Subtraction Operator]
	///
	Complex operator -(const Complex& obj) {

		return *this;
	}//end (-)

	/// Precondition:
	/// Postcondition:
	Complex operator -(double value) {
		return Complex((this->realNum - value), this->imagNum, this->imagPower);
	}//end (-)



	/// [Multiplicative Operator]
	///
	Complex operator *(const Complex& obj) {

		return *this;
	}//end (*)

	/// Precondition: 
	/// Postcondition:
	Complex operator *(double value) {
		return Complex((this->realNum * value), (this->imagNum * value), this->imagPower);
	}//end (*)


	/// [Division Operator]
	///
	Complex operator /(const Complex& obj) {

		return *this;
	}//end (/)

	/// Preconditition: (double) value must not equal 0, since you cannot divide by 0
	/// Postcondition: returns *this Complex object following the compilation
	Complex operator /(double value) {
		if (value == 0)//produce error cannot divide by 0 
			return *this;
		return Complex((this->realNum / value), (this->imagNum / value), this->imagPower);
	}//end (/)

	/// Precondition:
	/// Postcondition:
	void operator +=(const Complex& obj) {
		*this = *this + obj;
	}//end (+=)

	/// Precondition:
	/// Postcondition:
	void operator -=(const Complex& obj) {
		*this = *this - obj;
	}//end (-=)

	/// Precondition:
	/// Postcondition:
	void operator *=(const Complex& obj) {
		*this = *this * obj;
	}//end (*=)

	/// Precondition:
	/// Postcondition:
	void operator /=(const Complex& obj) {
		*this = *this / obj;
	}//end (/=)


	/// Precondition:
	/// Postcondition:
	void operator +=(double value) {
		*this = *this + value;
	}//end (+=)

	/// Precondition:
	/// Postcondition:
	void operator -=(double value) {
		*this = *this - value;
	}//end (-=)

	/// Precondition:
	/// Postcondition:
	void operator *=(double value) {
		*this = *this * value;
	}//end (*=)

	/// Precondition:
	/// Postcondition:
	void operator /=(double value) {
		*this = *this / value;
	}//end (/=)



	//******************************************************************************************************************
	// Mutators ( set ) Methods
	//******************************************************************************************************************

	void setReal(double value) {
		this->realNum = value;
	}//end setReal


	void setImaginary(double value) {
		this->imagNum = value;
	}//end setimaginary


	void setPower(double value) {
		this->imagPower = value;
	}//end setPower




	//********************************************************************************************************************
	// Accessors ( get ) Methods
	//********************************************************************************************************************


	double getReal() const {
		return this->realNum;
	}

	double getImaginary() const {
		return this->imagNum;
	}

	double getPower() const {
		return this->imagPower;
	}


	string print() {
		if (imagPower == 1)
			return to_string(realNum) + " + " + to_string(imagNum) + "i";
		return to_string(realNum) + " + " + to_string(imagNum) + "i^" + to_string(imagPower) + " ";
	}

	//*********************************************************************************************************************
	// Friend functions
	//*********************************************************************************************************************


	friend ostream& operator <<(ostream& strm, Complex& obj) {
		strm << setprecision(3) << obj.realNum << " + " << obj.imagNum << "i";
		if (obj.imagPower > 1 || obj.imagPower < 1) strm << "^" << obj.imagPower << " ";
		return strm;
	}//end output stream operator


	friend ostream& operator <<(ostream& strm, const Complex& obj) {
		strm << setprecision(3) << obj.getReal() << " + " << obj.getImaginary() << "i";
		if (obj.imagPower > 1 || obj.imagPower < 1) strm << "^" << obj.getPower() << " ";
		return strm;
	}//end output stream operator


};





///
/// Menu Driver
/// 
/// Precondition: N/A
/// Postcondition: prompt the complex number menu
void runComplex() {
	
	string menuHeader = "\n\t\tA complex number is a number that can be expressed in the form a + b i, where a and b are real numbers,\n\t\tand i isn an imaginary number representing the square root of -1. The imagainary number i must satisfy the \n\t\tequation represented by the \"imaginary uni\", i^2 = -1. \n\t\tIn the form a + b i, a is the real part and b is the imaginary part.\n\t\t";
	do {
		clrScrn();
		std::cout << menuHeader;
		switch (runComplex_menuOption()) {
		case 'A':// A Complex Number
			runComplex_A_Menu();
			break;

		case 'B':// Multiple Complex Numbers
			runComplex_B_Menu();
			break;

		case '0': return;



		}//end switch
	} while (true);



}//end runComplex





char runComplex_menuOption() {
	




		char chChoice = char();


		std::cout << "\n\t"; header("\t1> Complex Numbers");
		std::cout << "\n\t\tA> A Complex Number" 
				  << "\n\t\tB> Multiple Complex Numbers";
		std:cout << "\n\t"; header("");

		chChoice = inputChar(string("\n\t\tOption: "), string("AB0"));
		return chChoice;
	

}//end runComplex_menuOption


void runComplex_A_Menu() {
	Complex cNumber = Complex();
	bool calcMode = bool(false);
	double consVal = double();
	do {
		clrScrn();
		std::cout << "\n\t\t\t"; header("\t\t\tA> A Complex Number");
		std::cout << "\n\t\t\t1. Enter the Real Number";					//mSetReal()
		std::cout << "\n\t\t\t2. Enter the Imaginary Number";				//mSetImag()
		std::cout << "\n\t\t\t3. Display the Complex Number";				// overload << 
		std::cout << "\n\t\t\t4. Negate the Complex Number";				// mNegate()
		std::cout << "\n\t\t\t5. Add (+) Complex Number with a Constant";
		std::cout << "\n\t\t\t6. Subtract (-) the Complex Number with a Constant";
		std::cout << "\n\t\t\t7. Multiply (*) the Complex Number with a Constant";
		std::cout << "\n\t\t\t8. Divide (/) the Complex Number with a Constant";
		std::cout << "\n\t\t\t"; header("");
		header("\n\t\t\t0. Return");

		switch (inputInteger("\n\t\t\t\tOption: ", 0, 9)) {//option 9 for calculator mode +=. etc
		case 1:// Enter the Real Number
			cNumber.setReal(inputDouble("Please enter the Real Number Part: "));
			
			break;

		case 2:// Enter the Imaginary Number
			cNumber.setImaginary(inputDouble("Please enter the Imaginary Part (without i): "));
			
			break;

		case 3:// Display the Complex Number
			
			std::cout << "Complex Number C1: " << cNumber;
			
			break;

		case 4:// Negate the Complex Number
			std::cout << (cNumber * (-1));
			if (calcMode) cNumber *= -1;
			
			break;

		case 5:// Add (+) the Complex Number with a Constant
			consVal = inputDouble("Enter a constant number: ");
			std::cout << "\n" << (cNumber + consVal);
			if (calcMode) cNumber += consVal;

			break;

		case 6:// Subtract (-) the Complex Number with a Constant
			consVal = inputDouble("Enter a constant number: ");
			std::cout << "\n" << (cNumber - consVal);
			if (calcMode) cNumber -= consVal;
			
			break;

		case 7:// Multiply (*) the Complex Number with a Constant
			consVal = inputDouble("Enter a constant number: ");
			std::cout << "\n" << (cNumber * consVal);
			if (calcMode) cNumber *= consVal;
			
			
			break;

		case 8:// Divide (/) the Complex Number with a Constant
			consVal = inputDouble("Enter a constant number: ");
			std::cout << "\n" << (cNumber / consVal);
			if (calcMode) cNumber /= consVal;
			
			
			break;

		case 9:// Calculator Mode
			if (calcMode) calcMode = false;
			else calcMode = true;

			std::cout << boolalpha << "[calcMode set to]: " << calcMode;

			break;


		case 0: return;


		default:
			std::cout << "\nERROR: An error occured within the menu A.\n";
			break;
		}//end switch
		pause();
		

	} while (true);



}



void runComplex_B_Menu() {




}



