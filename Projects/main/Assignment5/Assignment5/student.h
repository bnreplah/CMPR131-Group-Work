// File: Student.h
//	Team Members:
//      Ben Halpern
//      Itz Rodriquez
//      Tony Cheng
//      Jose Chavez
//      Thien Nguyen
//      Jesus Sierra
//	Professor Q
//	CMPR 131
//	Assignment 5
//	10/1/21

/*
* Class Student
*	Attributes: (string) name, (string) strLevel, (double) gpa
*				name is the student's name
*				strLevel is the level in school which the student is ( 1-Freshmen, 2-Sophmore, 3-Juinor, 4-Seinor )
*				gpa is the students grade point average, ranged between (0.0, 4.0)
*	Methods:
*			getName()	const
*			getLevel()	const
*			getNLevel()	const
*			getGpa()	const
*			setName()
*			setLevel()		3 overloads
*			setGpa()		2 overloads
*			operator <		2 overloads
*			operator >		2 overloads
*			operator <=		2 overloads
*			operator <=		2 overloads
*			operator ==		2 overloads
*			operator !=		2 overloads
*			operator =		2 overloads
*		friends:
*			operator <<		2 overloads
*			operator >>
*			Copy constructor overloaded
*/

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include "input.h"
#include <fstream>

class Student
{
private:
	string mName = string();
	const int LEVELS_ARRSIZE = 4;
	const string LEVELS[4] = { "Freshman", "Sophmore", "Junior", "Senior" };

	int mLevel = int();												//could be enum type
	double mGpa = double();	
	bool mEmpty = bool(true);
	bool mError = bool(false);
	const bool DEBUG = bool(false);

	/// Precondition: N/A
	/// Postcondition: checks if the student is empty
	void checkEmpty()
	{
		mEmpty = (mName.empty());
	}

public:

	//######################################################################################
	// Constructors
	//######################################################################################

	/// [Default Constructor]
	/// Precondition:  N/A
	/// Postcondition: Default values are set to 0 or unknown for unintialized
	Student(string pName = string("unknown"), int pNLevel = int(0), double pGpa = double(0.0)) : mName(pName), mLevel(pNLevel), mGpa(pGpa)
	{
		if ((pName != "unknown") && pNLevel != 0)
			mEmpty = false;
	}//end student constructor

	/// [Copy Constructor]
	/// Precondition: copy is a copy of the student object to be copied into this object
	/// Postcondition: copies one object to another
	Student(const Student& copy)
	{
		this->mGpa = copy.mGpa;
		this->mLevel = copy.mLevel;
		this->mName = copy.mName;
		this->mEmpty = copy.mEmpty;
	}//end copy constructor

	//######################################################################################
	// Accessors
	//######################################################################################

	/// [const]
	/// Precondition: N/A
	/// Postcondition: returns the name of the student ( uninitialized is blank )
	string getName() const
	{
		return this->mName;
	}//end getName

	/// [const]
	/// Precondition: N/A
	/// Postcondition: returns the level of the student ( uninitialized is blank )
	string getLevel() const
	{
		switch (this->mLevel)
		{
		case (1): return LEVELS[0];
			break;
		case (2): return LEVELS[1];
			break;
		case (3): return LEVELS[2];
			break;
		case (4): return LEVELS[3];
			break;
		default:
			return "unknown";
			break;
		}
	}//end getLevel

	/// [const]
	/// Precondition:
	/// Postcondition:
	int getNLevel() const
	{
		return this->mLevel;
	}//end getNLevel

	/// [const]
	/// Precondition:  N/A
	/// Postcondition: returns the gpa of the student
	double getGpa() const
	{
		return this->mGpa;
	}//end getGpa

	/// [const]
	/// Precondition: N/A
	/// Postcondition: returns true if the student object is empty
	bool empty() const
	{
		return this->mEmpty;
	}

	/// [const]
	/// Precondition: N/A
	/// Postcondition: returns true if the student object is empty
	bool error() const
	{
		return this->mError;
	}//end error

	/// [const]
	/// (==)
	/// Precondition: (student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa, strLevel and name are all equal to that of the object
	bool operator ==(const Student& obj) const
	{
		return ((this->mGpa == obj.mGpa) && (this->mLevel == obj.mLevel) && (this->mName == obj.mName));
	}//end

	/// [const]
	/// (<=)
	/// Precondition: (student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa, strLevel and name are all less than or equal to the object
	bool operator <=(const Student& obj) const
	{
		return ((this->mGpa <= obj.mGpa) && (this->mLevel <= obj.mLevel) && (this->mName <= obj.mName));
	}//end

	/// [const]
	/// (>=) 
	/// Precondition: (student&) obj is the student object to the right 
	/// Postcondition: comparing objects of two students by the less than or equal sign
	bool operator >=(const Student& obj) const
	{
		return ((this->mGpa >= obj.mGpa) && (this->mLevel >= obj.mLevel) && (this->mName >= obj.mName));
	}//end

	/// [const]
	/// (<)
	/// ! check for issue with the or statement
	/// Precondition: (student&) obj is the student object to the right of the comparison
	/// Postcondition: returns true if the gpa or the name are less than the object 
	bool operator < (const Student& obj) const
	{
		if (this->mEmpty && obj.mEmpty || *this == obj)
			return false;
		if (this->mEmpty)
			return !mEmpty;
		else if (obj.mEmpty)
			return obj.mEmpty;
		//end precondition checks

		return  (this->mName < obj.mName);// (this->mGpa < obj.mGpa);
	}//end

	/// [const]
	/// (>)
	/// ! check for issue with the or statement
	/// Precondition: (student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa or the name are greater than the object 
	bool operator > (const Student& obj) const
	{
		if (this->mEmpty && obj.mEmpty || *this == obj)
			return false;
		if (this->mEmpty)
			return mEmpty;
		else if (obj.mEmpty)
			return !obj.mEmpty;
		//end precondition checks
		//else
		return (this->mGpa > obj.mGpa) || (this->mName > obj.mName);
	}//end

	//######################################################################################
	// Mutators
	//######################################################################################

	/// Precondition: N/A
	/// Postcondition: prompts the user through a sanitized input and then sets that to the gpa
	void setName()
	{
		this->mName = inputString("\nEnter a new student name: ", true);

		//method footer
		if (this->mEmpty)
			checkEmpty();
	}// end setName

	/// Precondition:  N/A
	/// Postcondition: prompts the user through a sanitized input and then sets that to the gpa
	void setName(string pName)
	{
		this->mName = pName;

		//method footer
		if (this->mEmpty)
			checkEmpty();
	}// end setName

	/// Precondition:  N/A
	/// Postcondition: prompts the user through a sanitized input and then sets that to the level
	void setLevel()
	{
		this->mLevel = inputInteger("\nEnter the his/her Level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", 1, 4);

		//method footer	
		if (this->mEmpty)
			checkEmpty();
	}// end setLevel

	/// Precondition: (int) pLevel is an value 0-3 representing the index of the level
	/// Postcondition: prompts the user through a sanitized input and then sets that to the level
	void setLevel(int pLevel)
	{
		if (pLevel >= 4)
			this->mLevel = 4;
		else if (pLevel <= 0)
			this->mLevel = 0;
		else
			this->mLevel = pLevel;

		//method footer
		if (this->mEmpty)
			checkEmpty();
	}// end setLevel

	/// Precondition: (string) pLevel is the level as a string value, case sensitive
	/// Postcondition: prompts the user through a sanitized input and then sets that to the level
	void setLevel(string pLevel)
	{
		for (int i = 0; i < LEVELS_ARRSIZE; i++)
		{
			//std::cout << LEVELS[i].compare(pLevel);
			if (LEVELS[i] == pLevel)
			{
				this->mLevel = i + 1;
				return;
			}
		}
		if (this->mLevel == 0)
		{
			std::cout << "\b\nERROR: invalid data type";
		}
		//method footer
		if (this->mEmpty)
			checkEmpty();
	}// end setLevel

	/// Precondition: N/A  
	/// Postcondition: prompts the user through a sanitized input and then sets that to the gpa
	void setGpa()
	{
		this->mGpa = inputDouble("\nEnter his/her GPA (0.0..4.0): ", 0.0, 4.0);

		//method footer
		if (this->mEmpty)
			checkEmpty();
	}// end setGpa

	/// Precondition: N/A  
	/// Postcondition: prompts the user through a sanitized input and then sets that to the gpa
	void setGpa(double pGpa)
	{
		if (pGpa <= 0.0)
			this->mGpa = 0.0;
		if (pGpa >= 5.0)//easter egg allowing for weighted gpa values
			this->mGpa = 5.0;
		else
			this->mGpa = pGpa;

		//method footer
		if (this->mEmpty)
			checkEmpty();
	}// end setGpa

	/// Precondition: N/A
	/// Postcondition: returns true if the student object is empty
	bool empty()
	{
		return this->mEmpty;
	}
	
	/// Precondition: N/A
	/// Postcondition: returns true if the student object is empty
	bool error()
	{
		return this->mError;
	}

	/// (==)
	/// Precondition: (Student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa, strLevel and name are all equal to that of the object
	bool operator ==(Student& obj)
	{
		if (this->mEmpty && obj.mEmpty)
			return true;
		return ((this->mGpa == obj.mGpa) && (this->mLevel == obj.mLevel) && (this->mName == obj.mName));
	}//end

	/// (<=)
	/// Precondition: (Student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa, strLevel and name are all less than or equal to the object
	bool operator <=(Student& obj)
	{
		return ((this->mGpa <= obj.mGpa) && (this->mLevel <= obj.mLevel) && (this->mName <= obj.mName));
	}//end


	/// (>=) 
	/// Precondition: (Student&) obj is the student object to the right 
	/// Postcondition: comparing objects of two students by the less than or equal sign
	bool operator >=(Student& obj)
	{
		return ((this->mGpa >= obj.mGpa) && (this->mLevel >= obj.mLevel) && (this->mName >= obj.mName));
	}//end

	/// [const]
	/// [ASSIGNMENT OPERATOR]
	/// Precondition: (Student&) obj is an object of the Student class to the right of the assignment, being assigned to the object
	/// Postcondition:
	void operator = (const Student& obj)
	{
		this->mGpa = obj.mGpa;
		this->mName = obj.mName;
		this->mLevel = obj.mLevel;
		this->mEmpty = obj.mEmpty;
	}//end (=)

	/// [ASSIGNMENT OPERATOR]
	/// Precondition: (Student&) obj is an object of the Student class to the right of the assignment, being assigned to the object
	/// Postcondition:
	void operator = (Student& obj)
	{
		this->mGpa = obj.mGpa;
		this->mName = obj.mName;
		this->mLevel = obj.mLevel;
		this->mEmpty = obj.mEmpty;
	}//end (=)

	/// (<)
	/// ! check for issue with the or statement
	/// Precondition: (Student&) obj is the student object to the right of the comparison
	/// Postcondition: returns true if the gpa or the name are less than the object 
	bool operator < (Student& obj)
	{
		if (this->mEmpty && obj.mEmpty || *this == obj)
			return false;
		if (this->mEmpty)
			return !mEmpty;
		else if (obj.mEmpty)
			return obj.mEmpty;

		//end precondition checks

		return  (this->mName < obj.mName);//&&  (this->mGpa< obj.mGpa) ;
	}//end

	/// (>)
	/// ! check for issue with the or statement
	/// Precondition: (Student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa or the name are greater than the object 
	bool operator > (Student& obj)
	{
		if (this->mEmpty && obj.mEmpty || *this == obj)
			return false;
		if (this->mEmpty)
			return mEmpty;
		else if (obj.mEmpty)
			return !obj.mEmpty;
		//end precondition checks
		//else
		return  (this->mName > obj.mName); //&& (this->mGpa > obj.mGpa);
	}//end

	//######################################################################################
	// Friend functions
	//######################################################################################

	/// [const]
	/// (<<)
	/// Precondition: output stream used with an output stream object and the output stream operator << 
	/// Postcondition: displays to the stream the student in the format ( name, level, gpa ) 
	friend ostream& operator <<(ostream& strm, const Student& obj)
	{
		/*if (obj.mEmpty)
		{
			return strm << "\n\bThe Student is empty\n";
		}*/
		strm << obj.mName << ", " << obj.getLevel() << ", " << setprecision(2) << obj.mGpa;
		return strm;
	}//end

	/// (<<)
	/// Precondition: output stream used with an output stream object and the output stream operator << 
	/// Postcondition: displays to the stream the student in the format ( name, level, gpa ) 
	friend ostream& operator <<(ostream& strm, Student& obj)
	{
		/*if (obj.mEmpty) {
			return strm << "\n\bThe Student is empty\n";
		}*/
		strm << obj.mName << ", " << obj.getLevel() << ", " << setprecision(2) << obj.mGpa;
		return strm;
	}//end

	/// (>>)
	/// Precondition: output stream used with an output stream object and the output stream operator << 
	/// Postcondition: displays to the stream the student in the format ( name, level, gpa ) 
	friend istream& operator >>(istream& strm, Student& obj)
	{
		obj.setName();
		obj.setLevel();
		obj.setGpa();
		return strm;
	}//end
	
	/// (>>)
	/// Precondition: output stream used with an output stream object and the output stream operator << 
	/// Postcondition: displays to the stream the student in the format ( name, level, gpa ) 
	friend fstream& operator >>(fstream& strm, Student& obj)
	{
		string current;
		//if(obj.DEBUG)std::cout << "\n======= reading file... ======= \n";
		if (strm.is_open() && strm.good() && !strm.eof())
		{
			//cout << "\n\t";
			getline(strm, current, ',');

			obj.setName(current);
			if (obj.DEBUG)std::cout << obj.getName() << ", ";

			getline(strm, current, ',');
			obj.setLevel(current);
			if (obj.DEBUG)std::cout << obj.getLevel() << ", ";
			//std::cout << obj.getNLevel() << "\n";

			if (strm >> current)
				obj.setGpa(stof(current));
			if (obj.DEBUG)std::cout << obj.getGpa() << "\n";
			getline(strm, current, '\n');//blank get line to eat the "\n"
		}
		return strm;
	}//end
};//end class