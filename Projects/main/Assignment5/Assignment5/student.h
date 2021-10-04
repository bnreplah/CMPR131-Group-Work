#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "input.h"
/**
* Class student
*	Attributes: (string) name, (string) strLevel, (double) gpa
*				name is the student's name
*				strLevel is the level in school which the student is ( 1-Freshmen, 2-Sophmore, 3-Juinor, 4-Seinor )
*				gpa is the students grade point average, ranged between (0.0, 4.0)
*	Methods:	
*			getName()
*			getLevel()
*			getGpa()
*			setName()
*			setLevel()
*			setGpa()
*			operator <
*			operator >
*			operator <=
*			operator <=
*			operator ==
*			operator !=
*			Copy constructor overloaded
* 
* 
*/
class student {
private:

	string name = string();											//

	string strLevel = string();										//
	//int level = int();

	double gpa = double();											//

public:

	/// [Default Constructor]
	/// Precondition:  
	/// Postcondition: 
	student(string pName, string pLevel, double pGpa) : name(pName), strLevel(pLevel), gpa(pGpa) {}//end student constructor

	/// [Copy Constructor]
	/// Precondition:
	/// Postcondition:
	student(const student& copy) {
		this->gpa = copy.gpa;
		this->strLevel = copy.strLevel;
		this->name = copy.name;

	}//end copy constructor



	/// Precondition:  
	/// Postcondition: 
	string getName() const {
		return this->name;
	}//end getName

	/// Precondition:  
	/// Postcondition: 
	string getLevel() const {
		return this->strLevel;
	}//end getLevel

	/// Precondition:  
	/// Postcondition: 
	double getGpa() const {
		return this->gpa;
	}//end getGpa

	/// Precondition:  
	/// Postcondition:  
	void setName() {
		string tName = inputString("\nEnter a new student name: ", true);
		this->name = tName;
	}// end setName

	/// Precondition:  
	/// Postcondition: 
	void setLevel() {
		string tLevel = inputString("\nEnter the his/her Level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", true);
		this->strLevel = tLevel;
	}// end setLevel

	/// Precondition:  
	/// Postcondition: 
	void setGpa() {
		double tGpa = inputDouble("\nEnter his/her GPA (0.0..4.0): ", 0.0, 4.0);
		this->gpa = tGpa;
	}// end setGpa

	/// (<)
	/// ! check for issue with the or statement
	/// Precondition:
	/// Postcondition:
	bool operator < (const student& obj) {
		return (this->gpa < obj.gpa) || (this->name < obj.name);
	}


	/// (>)
	/// ! check for issue with the or statement
	/// Precondition:
	/// Postcondition:
	bool operator > (const student& obj) {
		return (this->gpa > obj.gpa) || (this->name > obj.name);
	}

	/// (<<)
	/// Precondition:
	/// Postcondition:
	friend ostream& operator <<(ostream& strm, const student& obj) {
		strm << "(" << obj.name << ", " << obj.strLevel << ", " << setprecision(2) << obj.gpa << ")";
		return strm;
	}



	/// (==)
	/// Precondition:
	/// Postcondition:
	bool operator ==(const student& obj) {
		return ((this->gpa == obj.gpa) && (this->strLevel == obj.strLevel) && (this->name == obj.name));
	}


	/// (<=)
	/// Precondition:
	/// Postcondition:
	bool operator <=(const student& obj) {
		return ((this->gpa <= obj.gpa) && (this->strLevel <= obj.strLevel) && (this->name <= obj.name));
	}


	/// (>=) 
	/// Precondition: N/A 
	/// Postcondition: comparing objects of two students by the less than or equal sign
	bool operator <=(const student& obj) {
		return ((this->gpa >= obj.gpa) && (this->strLevel >= obj.strLevel) && (this->name >= obj.name));
	}


	
};

