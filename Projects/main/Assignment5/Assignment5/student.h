/*
* Class student
*	Attributes: (string) name, (string) strLevel, (double) gpa
*				name is the student's name
*				strLevel is the level in school which the student is ( 1-Freshmen, 2-Sophmore, 3-Junior, 4-Senior )
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
*			operator >=
*			operator ==
*			operator !=
*			Copy constructor overloaded
*/

// decimal point formula
//cout.setf(ios::fixed);
//cout.setf(ios::showpoint);
//cout.precision(2);

#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "input.h"

class student 
{
private:
	string name = string();
	string strLevel = string();
	//int level = int();

	double gpa = double();

public:
	// [CONSTRUCTORS]
	//////////////////////

	/// [Default Constructor]
	/// Precondition:  N/A
	/// Postcondition: Default values are set to 0 or - for unintialized
	student(string pName = string("-"), string pLevel = string("-"), double pGpa = double(0.0)) : name(pName), strLevel(pLevel), gpa(pGpa)
	{}//end student constructor

	/// [Copy Constructor]
	/// Precondition: copy is a copy of the student object to be copied into this object
	/// Postcondition: copies one object to another
	student(const student& copy)
	{
		this->gpa = copy.gpa;
		this->strLevel = copy.strLevel;
		this->name = copy.name;
	}//end copy constructor


	// [ACCESSORS FUNCTIONS]
	//////////////////////

	/// Precondition:  N/A
	/// Postcondition: returns the name of the student ( uninitialized is blank )
	string getName() const
	{
		return this->name;
	}//end getName

	/// Precondition:  N/A
	/// Postcondition: returns the level of the student ( uninitialized is blank )
	string getLevel() const
	{
		return this->strLevel;
	}//end getLevel

	/// Precondition:  N/A
	/// Postcondition: returns the gpa of the student
	double getGpa() const
	{
		return this->gpa;
	}//end getGpa


	// [MUTATORS FUNCTIONS]
	//////////////////////

	/// Precondition:  N/A
	/// Postcondition: prompts the user through a sanitized input and then sets that to the gpa
	void setName()
	{
		this->name = inputString("\n\tEnter a new student name: ", true);
	}// end setName

	/// Precondition:  N/A
	/// Postcondition: prompts the user through a sanitized input and then sets that to the level
	void setLevel()
	{
		this->strLevel = inputString("\n\tEnter the his/her Level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", true);
	}// end setLevel

	/// Precondition: N/A  
	/// Postcondition: prompts the user through a sanitized input and then sets that to the gpa
	void setGpa()
	{
		this->gpa = inputDouble("\n\tEnter his/her GPA (0.0..4.0): ", 0.0, 4.0);
	}// end setGpa

	// [FRIEND FUNCTIONS]
	//////////////////////

	/// (<)
	/// ! check for issue with the or statement
	/// Precondition: (student&) obj is the student object to the right of the comparison
	/// Postcondition: returns true if the gpa or the name are less than the object 
	bool operator < (const student& obj)
	{
		return (this->gpa < obj.gpa) || (this->name < obj.name);
	}

	/// (>)
	/// ! check for issue with the or statement
	/// Precondition: (student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa or the name are greater than the object 
	bool operator > (const student& obj)
	{
		return (this->gpa > obj.gpa) || (this->name > obj.name);
	}

	/// (<<)
	/// Precondition: output stream used with an output stream object and the output stream operator << 
	/// Postcondition: displays to the stream the student in the format ( name, level, gpa ) 
	friend ostream& operator << (ostream& strm, const student& obj)
	{
		strm << "( " << obj.name << ", " << obj.strLevel << ", " << setprecision(2) << obj.gpa << " )";
		return strm;
	}

	/// (==)
	/// Precondition: (student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa, strLevel and name are all equal to that of the object
	bool operator == (const student& obj)
	{
		return ((this->gpa == obj.gpa) && (this->strLevel == obj.strLevel) && (this->name == obj.name));
	}

	/// (<=)
	/// Precondition: (student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa, strLevel and name are all less than or equal to the object
	bool operator <= (const student& obj)
	{
		return ((this->gpa <= obj.gpa) && (this->strLevel <= obj.strLevel) && (this->name <= obj.name));
	}

	/// (>=) 
	/// Precondition: (student&) obj is the student object to the right 
	/// Postcondition: comparing objects of two students by the less than or equal sign
	bool operator >= (const student& obj)
	{
		return ((this->gpa >= obj.gpa) && (this->strLevel >= obj.strLevel) && (this->name >= obj.name));
	}


	/// [ASSIGNMENT OPERATOR]
	//////////////////////
	/// Precondition: (student&) obj is an object of the student class to the right of the assignment, being assigned to the object
	/// Postcondition:
	void operator = (const student& obj)
	{
		this->gpa = obj.gpa;
		this->name = obj.name;
		this->strLevel = obj.strLevel;
	}//end (=)
};