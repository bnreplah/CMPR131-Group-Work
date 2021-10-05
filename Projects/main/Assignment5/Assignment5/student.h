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
	const string LEVELS[4] = {"Freshmen", "Sophmore", "Juinor", "Senior"};
	string *strLevel = nullptr;										//
	int level = int();												//could be enum type

	double gpa = double();											//

public:

	/// [Default Constructor]
	/// Precondition:  N/A
	/// Postcondition: Default values are set to 0 or - for unintialized
	student(string pName = string("-"), int pNLevel = int(0), double pGpa = double(0.0)) : name(pName), level(pNLevel), gpa(pGpa) {
		switch (pNLevel) {
		case (1): *this->strLevel = LEVELS[0];
			break;
		case (2): *this->strLevel = LEVELS[1];
			break;
		case (3): *this->strLevel = LEVELS[2];
			break;
		case (4): *this->strLevel = LEVELS[3];
			break;
		default: 
			*this->strLevel = LEVELS[0];
			break;
		}
	
	}//end student constructor


	/// [Copy Constructor]
	/// Precondition: copy is a copy of the student object to be copied into this object
	/// Postcondition: copies one object to another
	student(const student& copy) {
		this->gpa = copy.gpa;
		this->level = copy.level;
		this->name = copy.name;

	}//end copy constructor



	/// Precondition:  N/A
	/// Postcondition: returns the name of the student ( uninitialized is blank )
	string getName() const {
		return this->name;
	}//end getName

	/// Precondition:  N/A
	/// Postcondition: returns the level of the student ( uninitialized is blank )
	string getLevel() const {
		return *this->strLevel;
	}//end getLevel

	/// Precondition:
	/// Postcondition:
	int getNLevel() const {
		return this->level;
	}//end getNLevel

	/// Precondition:  N/A
	/// Postcondition: returns the gpa of the student
	double getGpa() const {
		return this->gpa;
	}//end getGpa

	/// Precondition:  N/A
	/// Postcondition: prompts the user through a sanitized input and then sets that to the gpa
	void setName() {
		
		this->name = inputString("\nEnter a new student name: ", true);
		
	}// end setName

	/// Precondition:  N/A
	/// Postcondition: prompts the user through a sanitized input and then sets that to the level
	void setLevel() {

		this->level = inputInteger("\nEnter the his/her Level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", 1, 4);
		switch (this->level) {
		case (1): *this->strLevel = LEVELS[0];
			break;
		case (2): *this->strLevel = LEVELS[1];
			break;
		case (3): *this->strLevel = LEVELS[2];
			break;
		case (4): *this->strLevel = LEVELS[3];
			break;
		default:
			*this->strLevel = LEVELS[0];
			break;
		}//end switch

	}// end setLevel

	/// Precondition: this (int) level must not be empty
	/// Postcondition: updates the strLevel from the level
	void updateLevel() {
		switch (this->level) {
		case (1): *this->strLevel = LEVELS[0];
			break;
		case (2): *this->strLevel = LEVELS[1];
			break;
		case (3): *this->strLevel = LEVELS[2];
			break;
		case (4): *this->strLevel = LEVELS[3];
			break;
		default:
			*this->strLevel = LEVELS[0];
			break;
		}

	}//end updateLabel

	/// Precondition: N/A  
	/// Postcondition: prompts the user through a sanitized input and then sets that to the gpa
	void setGpa() {
		
		this->gpa = inputDouble("\nEnter his/her GPA (0.0..4.0): ", 0.0, 4.0);

	}// end setGpa

	/// (<)
	/// ! check for issue with the or statement
	/// Precondition: (student&) obj is the student object to the right of the comparison
	/// Postcondition: returns true if the gpa or the name are less than the object 
	bool operator < (const student& obj) {
		return (this->gpa < obj.gpa) || (this->name < obj.name);
	}//end

	/// (>)
	/// ! check for issue with the or statement
	/// Precondition: (student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa or the name are greater than the object 
	bool operator > (const student& obj) {
		return (this->gpa > obj.gpa) || (this->name > obj.name);
	}//end

	/// (<<)
	/// Precondition: output stream used with an output stream object and the output stream operator << 
	/// Postcondition: displays to the stream the student in the format ( name, level, gpa ) 
	friend ostream& operator <<(ostream& strm, const student& obj) {
		strm << "( " << obj.name << ", " << obj.strLevel << ", " << setprecision(2) << obj.gpa << " )";
		return strm;
	}//end

	/// (==)
	/// Precondition: (student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa, strLevel and name are all equal to that of the object
	bool operator ==(const student& obj) {
		return ((this->gpa == obj.gpa) && (this->strLevel == obj.strLevel) && (this->name == obj.name));
	}//end


	/// (<=)
	/// Precondition: (student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa, strLevel and name are all less than or equal to the object
	bool operator <=(const student& obj) {
		return ((this->gpa <= obj.gpa) && (this->strLevel <= obj.strLevel) && (this->name <= obj.name));
	}//end


	/// (>=) 
	/// Precondition: (student&) obj is the student object to the right 
	/// Postcondition: comparing objects of two students by the less than or equal sign
	bool operator <=(const student& obj) {
		return ((this->gpa >= obj.gpa) && (this->strLevel >= obj.strLevel) && (this->name >= obj.name));
	}//end


	/// [ASSIGNMENT OPERATOR]
	/// Precondition: (student&) obj is an object of the student class to the right of the assignment, being assigned to the object
	/// Postcondition:
	void operator = (const student& obj) {
		this->gpa = obj.gpa;
		this->name = obj.name;
		this->level = obj.level;
	}//end (=)

	
};//end class

