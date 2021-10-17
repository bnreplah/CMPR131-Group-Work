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
	const int mLEVELS_ARRSIZE = 4;
	const string mLEVELS[4] = { "Freshman", "Sophmore", "Junior", "Senior" };

	int mLevel = int();												//could be enum type
	double mGpa = double();	
	bool mEmpty = bool(true);
	bool mError = bool(false);
	const bool mDEBUG = bool(false);

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
	Student(const Student& pCopy)
	{
		this->mGpa = pCopy.mGpa;
		this->mLevel = pCopy.mLevel;
		this->mName = pCopy.mName;
		this->mEmpty = pCopy.mEmpty;
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
		case (1): return mLEVELS[0];
			break;
		case (2): return mLEVELS[1];
			break;
		case (3): return mLEVELS[2];
			break;
		case (4): return mLEVELS[3];
			break;
		default:
			return "unknown";
			break;
		}
	}//end getLevel

	/// [const]
	/// Precondition: N/A
	/// Postcondition: returns the integer level of the student
	int getNLevel() const
	{
		return this->mLevel;
	}//end getNLevel

	/// [const]
	/// Precondition: N/A
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
	bool operator ==(const Student& pObj) const
	{
		return ((this->mGpa == pObj.mGpa) && (this->mLevel == pObj.mLevel) && (this->mName == pObj.mName));
	}//end

	/// [const]
	/// (<=)
	/// Precondition: (student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa, strLevel and name are all less than or equal to the object
	bool operator <=(const Student& pObj) const
	{
		return ((this->mGpa <= pObj.mGpa) && (this->mLevel <= pObj.mLevel) && (this->mName <= pObj.mName));
	}//end

	/// [const]
	/// (>=) 
	/// Precondition: (student&) obj is the student object to the right 
	/// Postcondition: comparing objects of two students by the less than or equal sign
	bool operator >=(const Student& pObj) const
	{
		return ((this->mGpa >= pObj.mGpa) && (this->mLevel >= pObj.mLevel) && (this->mName >= pObj.mName));
	}//end

	/// [const]
	/// (<)
	/// ! check for issue with the or statement
	/// Precondition: (student&) obj is the student object to the right of the comparison
	/// Postcondition: returns true if the gpa or the name are less than the object 
	bool operator < (const Student& pObj) const
	{
		if (this->mEmpty && pObj.mEmpty || *this == pObj)
			return false;
		if (this->mEmpty)
			return !mEmpty;
		else if (pObj.mEmpty)
			return pObj.mEmpty;
		//end precondition checks

		return  (this->mName < pObj.mName);// (this->mGpa < obj.mGpa);
	}//end

	/// [const]
	/// (>)
	/// ! check for issue with the or statement
	/// Precondition: (student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa or the name are greater than the object 
	bool operator > (const Student& pObj) const
	{
		if (this->mEmpty && pObj.mEmpty || *this == pObj)
			return false;
		if (this->mEmpty)
			return mEmpty;
		else if (pObj.mEmpty)
			return !pObj.mEmpty;
		//end precondition checks
		//else
		return (this->mGpa > pObj.mGpa) || (this->mName > pObj.mName);
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
		for (int i = 0; i < mLEVELS_ARRSIZE; i++)
		{
			//std::cout << LEVELS[i].compare(pLevel);
			if (mLEVELS[i] == pLevel)
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
	bool operator ==(Student& pObj)
	{
		if (this->mEmpty && pObj.mEmpty)
			return true;
		return ((this->mGpa == pObj.mGpa) && (this->mLevel == pObj.mLevel) && (this->mName == pObj.mName));
	}//end

	/// (<=)
	/// Precondition: (Student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa, strLevel and name are all less than or equal to the object
	bool operator <=(Student& pObj)
	{
		return ((this->mGpa <= pObj.mGpa) && (this->mLevel <= pObj.mLevel) && (this->mName <= pObj.mName));
	}//end


	/// (>=) 
	/// Precondition: (Student&) obj is the student object to the right 
	/// Postcondition: comparing objects of two students by the less than or equal sign
	bool operator >=(Student& pObj)
	{
		return ((this->mGpa >= pObj.mGpa) && (this->mLevel >= pObj.mLevel) && (this->mName >= pObj.mName));
	}//end

	/// [const]
	/// [ASSIGNMENT OPERATOR]
	/// Precondition: (Student&) obj is an object of the Student class to the right of the assignment, being assigned to the object
	/// Postcondition: Copies the private members of the (const student&) obj to the Student object called from.
	void operator = (const Student& pObj)
	{
		this->mGpa = pObj.mGpa;
		this->mName = pObj.mName;
		this->mLevel = pObj.mLevel;
		this->mEmpty = pObj.mEmpty;
	}//end (=)

	/// [ASSIGNMENT OPERATOR]
	/// Precondition: (Student&) obj is an object of the Student class to the right of the assignment, being assigned to the object
	/// Postcondition: Assigns the private members of the (const student&) obj to the Student object called from.
	void operator = (Student& pObj)
	{
		this->mGpa = pObj.mGpa;
		this->mName = pObj.mName;
		this->mLevel = pObj.mLevel;
		this->mEmpty = pObj.mEmpty;
	}//end (=)

	/// (<)
	/// ! check for issue with the or statement
	/// Precondition: (Student&) obj is the student object to the right of the comparison
	/// Postcondition: returns true if the gpa or the name are less than the object 
	bool operator < (Student& pObj)
	{
		if (this->mEmpty && pObj.mEmpty || *this == pObj)
			return false;
		if (this->mEmpty)
			return !mEmpty;
		else if (pObj.mEmpty)
			return pObj.mEmpty;

		//end precondition checks

		return  (this->mName < pObj.mName);//&&  (this->mGpa< obj.mGpa) ;
	}//end

	/// (>)
	/// ! check for issue with the or statement
	/// Precondition: (Student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa or the name are greater than the object 
	bool operator > (Student& pObj)
	{
		if (this->mEmpty && pObj.mEmpty || *this == pObj)
			return false;
		if (this->mEmpty)
			return mEmpty;
		else if (pObj.mEmpty)
			return !pObj.mEmpty;
		//end precondition checks
		//else
		return  (this->mName > pObj.mName); //&& (this->mGpa > obj.mGpa);
	}//end

	//######################################################################################
	// Friend functions
	//######################################################################################

	/// [const]
	/// (<<)
	/// Precondition: output stream used with an output stream object and the output stream operator << 
	/// Postcondition: displays to the stream the student in the format ( name, level, gpa ) 
	friend ostream& operator <<(ostream& pStrm, const Student& pObj)
	{
		/*if (obj.mEmpty)
		{
			return strm << "\n\bThe Student is empty\n";
		}*/
		pStrm << pObj.mName << ", " << pObj.getLevel() << ", " << setprecision(2) << pObj.mGpa;
		return pStrm;
	}//end

	/// (<<)
	/// Precondition: output stream used with an output stream object and the output stream operator << 
	/// Postcondition: displays to the stream the student in the format ( name, level, gpa ) 
	friend ostream& operator <<(ostream& pStrm, Student& pObj)
	{
		/*if (obj.mEmpty) {
			return strm << "\n\bThe Student is empty\n";
		}*/
		pStrm << pObj.mName << ", " << pObj.getLevel() << ", " << setprecision(2) << pObj.mGpa;
		return pStrm;
	}//end

	/// (>>)
	/// Precondition: output stream used with an output stream object and the output stream operator << 
	/// Postcondition: populates the student from the standard input stream( name, level, gpa )
	friend istream& operator >>(istream& pStrm, Student& pObj)
	{
		pObj.setName();
		pObj.setLevel();
		pObj.setGpa();
		return pStrm;
	}//end
	
	/// (>>)
	/// Precondition: output stream used with an output stream object and the output stream operator << 
	/// Postcondition: populates the student form the standard file stream ( name, level, gpa )
	friend fstream& operator >>(fstream& pStrm, Student& pObj)
	{
		string current;
		//if(obj.DEBUG)std::cout << "\n======= reading file... ======= \n";
		if (pStrm.is_open() && pStrm.good() && !pStrm.eof())
		{
			//cout << "\n\t";
			getline(pStrm, current, ',');

			pObj.setName(current);
			if (pObj.mDEBUG)std::cout << pObj.getName() << ", ";

			getline(pStrm, current, ',');
			pObj.setLevel(current);
			if (pObj.mDEBUG)std::cout << pObj.getLevel() << ", ";
			//std::cout << obj.getNLevel() << "\n";

			if (pStrm >> current)
				pObj.setGpa(stof(current));
			if (pObj.mDEBUG)std::cout << pObj.getGpa() << "\n";
			getline(pStrm, current, '\n');//blank get line to eat the "\n"
		}
		return pStrm;
	}//end
};//end class