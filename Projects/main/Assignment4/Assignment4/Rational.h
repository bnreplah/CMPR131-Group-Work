#pragma once
//
// Assigned: Thien
//

class Rational {
private:
	int *numerator;
	int *denominator;


public:
	/// [Default constructor]
	Rational() {
		numerator = new int(0);
		denominator = new int(1);
	}//end Default Constructor


	Rational(int newNum, int newDenom)  {
		if (newDenom == 0)
			return;
		numerator = new int(newNum);
		denominator = new int(newDenom);
	}//end Default Constructor

	~Rational() {
		delete numerator;
		delete denominator;
	}
	

	//#######################################################################################################################################
	// Mutators methods
	//#######################################################################################################################################



	void setNumerator(int newNum) {
		*this->numerator = newNum;
	}//end setNumerator
	
	
	void setDenomenator(int newDenom) {
		*this->denominator = newDenom;
	}//end setNumerator
	


	//#######################################################################################################################################
	// Accessor methods
	//#######################################################################################################################################


	int getNumerator() const {
		return *this->numerator;
	}//end setNumerator
	
	
	int getDenomenator() const {
		return *this->denominator;
	}//end setNumerator

	


	//#######################################################################################################################################
	// Friend methods
	//#######################################################################################################################################


};//end class


