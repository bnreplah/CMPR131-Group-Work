#pragma once
//
// Team members:
//				Ben Halpern
//				Tony Cheng
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

	
	/// [const]
	/// [Additive Operator]
	/// STUB
	Complex operator +(const Complex& obj) const {

		return Complex((this->getReal() + obj.getReal()), (this->getImaginary() + obj.getImaginary()), 1);
	}//end (+)

	/// [const] 
	///
	Complex operator +(double value) const {
		return Complex((this->realNum + value), this->imagNum, this->imagPower);

	}//end (+)

	/// [const]
	/// [Subtraction Operator]
	///
	Complex operator -(const Complex& obj) const {

		return Complex((this->getReal() - obj.getReal()), (this->getImaginary() - obj.getImaginary()), 1);
	}//end (-)

	/// [const]
	/// Precondition:
	/// Postcondition:
	Complex operator -(double value) const {
		return Complex((this->realNum - value), this->imagNum, this->imagPower);
	}//end (-)
	
	 /// Precondition:
	/// Postcondition:
	Complex operator -(double value) {
		return Complex((this->realNum - value), this->imagNum, this->imagPower);
	}//end (-)


	/// [const]
	/// [Multiplicative Operator]
	///
	Complex operator *(const Complex& obj) const{
		double first = double();
		double outer = double();
		double inner = double();
		double last = double();//produces i^2 = -1
		double iVal = double();
		if (DEBUG) std::cout << "\n[DEBUG]: (" << *this << ")" << "*" << "(" << obj << ")";
		//(12 + 12i) * (1 + 2i) = 12 + 24i + 12i + 24i^2 = 12 + 36i + 24(-1) = -12 + 36i
		first = this->getReal() * obj.getReal();
		outer = this->getReal() * obj.getImaginary(); //i
		inner = this->getImaginary() * obj.getReal(); //i
		last = this->getImaginary() * obj.getImaginary(); //i^2

		return Complex((first + (iVal * last)), (outer + inner), 1);


	}//end (*)

	/// Precondition: 
	/// Postcondition:
	Complex operator *(double value) const {
		return Complex((this->realNum * value), (this->imagNum * value), this->imagPower);
	}//end (*)
	
	/// Precondition: 
	/// Postcondition:
	Complex operator *(double value) {
		return Complex((this->realNum * value), (this->imagNum * value), this->imagPower);
	}//end (*)


	/// [Division Operator]
	///
	Complex operator /(const Complex& obj) const {
		//(12 - 2i) / (2 + 3i) 
		double multInverse_first = double();
		double multInverse_second = double();
		multInverse_first = 1 / obj.getReal();
		multInverse_second = 1 / obj.getImaginary();
		return (*this) * (Complex(multInverse_first, multInverse_second, 1));
	}//end (/)
	
	/// [Division Operator]
	///
	Complex operator /(const Complex& obj) {
		if (obj.getReal() == 0 && obj.getImaginary() == 0)//produce error cannot divide by 0
			return *this;
		
		double multInverse_first = double();
		double multInverse_second = double();
		multInverse_first = 1 / obj.getReal();
		multInverse_second = 1 / obj.getImaginary();
		return (*this) * (Complex(multInverse_first, multInverse_second, 1));
		//return *this;
	}//end (/)

	/// [const]
	/// Preconditition: (double) value must not equal 0, since you cannot divide by 0
	/// Postcondition: returns *this Complex object following the compilation
	Complex operator /(double value) const {
		if (value == 0)//produce error cannot divide by 0 
			return *this;
		return Complex((this->realNum / value), (this->imagNum / value), this->imagPower);
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

	/// Precondition:
	/// Postcondition:
	bool operator ==(Complex& obj) {
		return (this->realNum == obj.realNum) && (this->imagNum == obj.imagNum) && (this->imagPower == obj.imagPower);
	}//end (==)


	/// Precondition:
	/// Postcondition:
	bool operator >=(Complex& obj) {
		return (this->realNum >= obj.realNum) && (this->imagNum >= obj.imagNum) && (this->imagPower >= obj.imagPower);
	}//end (>=)

	/// Precondition:
	/// Postcondition:
	bool operator <=(Complex& obj) {
		return (this->realNum <= obj.realNum) && (this->imagNum <= obj.imagNum) && (this->imagPower <= obj.imagPower);
	}//end (<=)

	
	/// Precondition:
	/// Postcondition:
	bool operator !=(Complex& obj) {
		return (this->realNum != obj.realNum) || (this->imagNum != obj.imagNum) || (this->imagPower != obj.imagPower);
	}//end (<=)
	
	/// Precondition:
	/// Postcondition:
	bool operator !=(const Complex& obj) const{
		return (this->realNum != obj.realNum) || (this->imagNum != obj.imagNum) || (this->imagPower != obj.imagPower);
	}//end (<=)







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
		
		strm << setprecision(3) << obj.realNum;
		if (obj.getPower() != 0 && obj.getImaginary() != 0.000000 ) strm << " + " << obj.imagNum << "i";
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
	Complex cNumber1 = Complex();
	Complex cNumber2 = Complex();
	//Complex cNumber3 = Complex();
	bool calcMode = bool(false);
	double consVal = double();
	do {
		clrScrn();
		std::cout << "\n\t\t\t"; header("\t\t\tB> Multiple Complex Number");
		std::cout << "\n\t\t\t1. Enter the Complex Number C1";					
		std::cout << "\n\t\t\t2. Enter the Complex Number C2";				
		std::cout << "\n\t\t\t3. Verify Condition Operators (==, !=) of C1 and C2";				
		std::cout << "\n\t\t\t4. Evaluate Arithmetic Operators of C1 and C2";
		std::cout << "\n\t\t\t5. Evaluate steps in (3 *(C1 + C2)/7) / (C1 - C2 / 9) != (1.07109 + 0.120832i) ";		
		std::cout << "\n\t\t\t"; header("");
		header("\n\t\t\t0. Return");

		switch (inputInteger("\n\t\t\t\tOption: ", 0, 6)) {//option 9 for calculator mode +=. etc
		case 1:
			cNumber1.setReal(inputDouble("Please enter the Real Number Part for C1: "));
			cNumber1.setImaginary(inputDouble("Please enter the Imaginry part for C1: "));
			std::cout << "\n\t\t" << cNumber1 << "\n";
			break;

		case 2:
			cNumber2.setReal(inputDouble("Please enter the Real Number Part for C2(without i): "));
			cNumber2.setImaginary(inputDouble("Please enter the Imaginary Part C2: "));
			std::cout << "\n\t\t" << cNumber2 << "\n";
			break;

		case 3:

				std::cout << "\n C1 == C2: " << boolalpha << " --> " << cNumber1 << " == " << cNumber2 << "? " << (cNumber1 == cNumber2);
				std::cout << "\n C1 != C2: " << boolalpha << " --> " << cNumber1 << " != " << cNumber2 << "? " << (cNumber1 != cNumber2);
			break;


		case 4:// Evaluate arithmetic operators (+, -, *, /) of C1 and C2
				//need condititons for divide by 0
				std::cout << "\n C1 + C2: " << boolalpha << " --> " << cNumber1 << " + " << cNumber2 << "? " << (cNumber1 + cNumber2);
				std::cout << "\n C1 - C2: " << boolalpha << " --> " << cNumber1 << " - " << cNumber2 << "? " << (cNumber1 - cNumber2);
				std::cout << "\n C1 * C2: " << boolalpha << " --> " << cNumber1 << " * " << cNumber2 << "? " << (cNumber1 * cNumber2);
				std::cout << "\n C1 / C2: " << boolalpha << " --> " << cNumber1 << " / " << cNumber2 << "? " << (cNumber1 / cNumber2);


			break;

		case 5:
				
				std::cout << "\n\t\t C1: " << cNumber1;
				std::cout << "\n\t\t C2: " << cNumber2;
				std::cout << "\n\t\t Evaluating expression... ";
				std::cout << "\n\t\t (3 * (C1 + C2) / 7) / (C2 - C1 / 9) != (1.07109 + 0.120832i)";
				std::cout << "\n\t\t Step#1: (3 * (" << (cNumber1 + cNumber2) << ") / 7) / (" << (cNumber2 - cNumber1 / 9.0) << ") != (1.07109 + 0.120832i)";
				std::cout << "\n\t\t Step#2: (3 * (" << (cNumber1 + cNumber2) / 7.0  << ") / (" << (cNumber2 - cNumber1 / 9.0) << ") != (1.07109 + 0.120832i)";
				std::cout << "\n\t\t Step#3: (" << (((cNumber1 + cNumber2) * 3.0 ) / 7.0)  << ") / (" << (cNumber2 - cNumber1 / 9.0) << ") != (1.07109 + 0.120832i)";
				std::cout << "\n\t\t Step#4: " << (((cNumber1 + cNumber2) * 3.0 ) / 7.0 ) / (cNumber2 - cNumber1 / 9.0) << " != (1.07109 + 0.120832i)";
				std::cout << "\n\t\t Step#5: " << (((cNumber1 + cNumber2) * 3.0 ) / 7.0 ) / (cNumber2 - cNumber1 / 9.0) << " != (1.07109 + 0.120832i) ? ";
				std::cout << "\n\t\t Step#6: " << boolalpha << (((((cNumber1 + cNumber2) * 3.0) / 7.0) / (cNumber2 - cNumber1 / 9.0)) != Complex(1.07109, 0.120832, 1)) << "\n";

			break;

			
		case 0: return;


		default:
			std::cout << "\nERROR: An error occured within the menu A.\n";
			break;
		}//end switch
		pause();


	} while (true);




}



