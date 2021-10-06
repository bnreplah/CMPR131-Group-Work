/*
* Class student
*	Attributes: (string) name, (string) strLevel, (double) gpa
*				name is the student's name
*				strLevel is the level in school which the student is ( 1-Freshmen, 2-Sophmore, 3-Junior, 4-Senior )
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




// decimal point formula
//cout.setf(ios::fixed);
//cout.setf(ios::showpoint);
//cout.precision(2);

class student 
{

	string mName = string();
	const int LEVELS_ARRSIZE = 4;
	const string LEVELS[4] = {"Freshmen", "Sophmore", "Juinor", "Senior"};
	int mLevel = int();												//could be enum type
	double mGpa = double();											//
	bool mEmpty = bool(true);
public:

	// [CONSTRUCTORS]
	//////////////////////


	/// [Default Constructor]
	/// Precondition:  N/A
	/// Postcondition: Default values are set to 0 or - for unintialized
	student(string pName = string("-"), int pNLevel = int(0), double pGpa = double(0.0)) : mName(pName), mLevel(pNLevel), mGpa(pGpa) {
		if ((pName != "-") && pNLevel == 0)
			mEmpty = false;
	}//end student constructor




	/// [Copy Constructor]
	/// Precondition: copy is a copy of the student object to be copied into this object
	/// Postcondition: copies one object to another
	student(const student& copy) {
		this->mGpa = copy.mGpa;
		this->mLevel = copy.mLevel;
		this->mName = copy.mName;
		this->mEmpty = copy.mEmpty;
	}//end copy constructor


	

	// [ACCESSORS FUNCTIONS]
	//////////////////////
	/// Precondition:  N/A
	/// Postcondition: returns the name of the student ( uninitialized is blank )
	string getName() const {
		return this->mName;
	}



	/// Precondition:  N/A
	/// Postcondition: returns the level of the student ( uninitialized is blank )
<<<<<<< HEAD
	string getLevel() const {
		
		switch (this->mLevel) {
		case (1): return LEVELS[0];
			break;
		case (2): return LEVELS[1];
			break;
		case (3): return LEVELS[2];
			break;
		case (4): return LEVELS[3];
			break;
		default:
			return LEVELS[0];
			break;
		}

=======
	string getLevel() const
	{
		return this->strLevel;
>>>>>>> 9e6ffe501f68637e2d16a0ece37e9a1c9de93f0a
	}//end getLevel

	/// Precondition:
	/// Postcondition:
	int getNLevel() const {
		return this->mLevel;
	}//end getNLevel

	/// Precondition:  N/A
	/// Postcondition: returns the gpa of the student
<<<<<<< HEAD
	double getGpa() const {
		return this->mGpa;
=======
	double getGpa() const
	{
		return this->gpa;
>>>>>>> 9e6ffe501f68637e2d16a0ece37e9a1c9de93f0a
	}//end getGpa


	// [MUTATORS FUNCTIONS]
	//////////////////////

	/// Precondition:  N/A
	/// Postcondition: prompts the user through a sanitized input and then sets that to the gpa
<<<<<<< HEAD
	void setName() {
		
		this->mName = inputString("\nEnter a new student name: ", true);
	
		//method footer
		if (this->mEmpty)
			this->mEmpty = false;
=======
	void setName()
	{
		this->name = inputString("\n\tEnter a new student name: ", true);
>>>>>>> 9e6ffe501f68637e2d16a0ece37e9a1c9de93f0a
	}// end setName

	/// Precondition:  N/A
	/// Postcondition: prompts the user through a sanitized input and then sets that to the gpa
	void setName(string pName) {

		this->mName = pName;
	
		//method footer
		if (this->mEmpty)
			this->mEmpty = false;
	}// end setName


	/// Precondition:  N/A
	/// Postcondition: prompts the user through a sanitized input and then sets that to the level
<<<<<<< HEAD
	void setLevel() {

		this->mLevel = inputInteger("\nEnter the his/her Level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", 1, 4);
	
		//method footer	
		if (this->mEmpty)
			this->mEmpty = false;
	}// end setLevel
	
	/// Precondition:  (int) pLevel is an value 0-3 representing the index of the level
	/// Postcondition: prompts the user through a sanitized input and then sets that to the level
	void setLevel(int pLevel) {
		if (pLevel >= 4)
			this->mLevel = 4;
		else if (pLevel <= 0)
			this->mLevel = 0;
		else
			this->mLevel = pLevel;

		//method footer
		if (this->mEmpty)
			this->mEmpty = false;
	}// end setLevel


	/// Precondition: (string) pLevel is the level as a string value, case sensitive
	/// Postcondition: prompts the user through a sanitized input and then sets that to the level
	void setLevel(string pLevel) {

		for (int i = 0; i < LEVELS_ARRSIZE; i++) {
			if (LEVELS[i].compare(pLevel) == 0)
				this->mLevel = i;
		}

		//method footer
		if (this->mEmpty)
			this->mEmpty = false;

=======
	void setLevel()
	{
		this->strLevel = inputString("\n\tEnter the his/her Level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", true);
>>>>>>> 9e6ffe501f68637e2d16a0ece37e9a1c9de93f0a
	}// end setLevel

	/// Precondition: N/A  
	/// Postcondition: prompts the user through a sanitized input and then sets that to the gpa
<<<<<<< HEAD
	void setGpa() {
		
		this->mGpa = inputDouble("\nEnter his/her GPA (0.0..4.0): ", 0.0, 4.0);

		//method footer
		if (this->mEmpty)
			this->mEmpty = false;
	}// end setGpa
	
	/// Precondition: N/A  
	/// Postcondition: prompts the user through a sanitized input and then sets that to the gpa
	void setGpa(double pGpa) {
		if (pGpa <= 0.0)
			this->mGpa = 0.0;
		if (pGpa >= 5.0)//easter egg allowing for weighted gpa values
			this->mGpa = 5.0;
		else
			this->mGpa = pGpa;

		//method footer
		if (this->mEmpty)
			this->mEmpty = false;
	}// end setGpa

	/// Precondition: N/A
	/// Postcondition: returns true if the student object is empty
	bool empty() {
		return this->mEmpty;
	}

	/// (==)
	/// Precondition: (student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa, strLevel and name are all equal to that of the object
	bool operator ==(const student& obj) const{
		return ((this->mGpa == obj.mGpa) && (this->mLevel == obj.mLevel) && (this->mName == obj.mName));
	}//end
=======
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
>>>>>>> 9e6ffe501f68637e2d16a0ece37e9a1c9de93f0a

	/// (==)
	/// Precondition: (student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa, strLevel and name are all equal to that of the object
<<<<<<< HEAD
	bool operator ==(const student& obj) {
		return ((this->mGpa == obj.mGpa) && (this->mLevel == obj.mLevel) && (this->mName == obj.mName));
	}//end

	/// [const]
	/// (<=)
	/// Precondition: (student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa, strLevel and name are all less than or equal to the object
	bool operator <=(const student& obj) const{
		return ((this->mGpa <= obj.mGpa) && (this->mLevel <= obj.mLevel) && (this->mName <= obj.mName));
	}//end

	
	/// (<=)
	/// Precondition: (student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa, strLevel and name are all less than or equal to the object
	bool operator <=(const student& obj) {
		return ((this->mGpa <= obj.mGpa) && (this->mLevel <= obj.mLevel) && (this->mName <= obj.mName));
	}//end

	/// [const]
	/// (>=) 
	/// Precondition: (student&) obj is the student object to the right 
	/// Postcondition: comparing objects of two students by the less than or equal sign
	bool operator >=(const student& obj) const {
		return ((this->mGpa >= obj.mGpa) && (this->mLevel >= obj.mLevel) && (this->mName >= obj.mName));
	}//end
=======
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
>>>>>>> 9e6ffe501f68637e2d16a0ece37e9a1c9de93f0a

	
	/// (>=) 
	/// Precondition: (student&) obj is the student object to the right 
	/// Postcondition: comparing objects of two students by the less than or equal sign
	bool operator >=(const student& obj) {
		return ((this->mGpa >= obj.mGpa) && (this->mLevel >= obj.mLevel) && (this->mName >= obj.mName));
	}//end

	/// [const]
	/// [ASSIGNMENT OPERATOR]
	//////////////////////
	/// Precondition: (student&) obj is an object of the student class to the right of the assignment, being assigned to the object
	/// Postcondition:
<<<<<<< HEAD
	void operator = (const student& obj) {
		this->mGpa = obj.mGpa;
		this->mName = obj.mName;
		this->mLevel = obj.mLevel;
		this->mEmpty = obj.mEmpty;
	}//end (=)

	/// [ASSIGNMENT OPERATOR]
	/// Precondition: (student&) obj is an object of the student class to the right of the assignment, being assigned to the object
	/// Postcondition:
	void operator = (student& obj) {
		this->mGpa = obj.mGpa;
		this->mName = obj.mName;
		this->mLevel = obj.mLevel;
		this->mEmpty = obj.mEmpty;
	}//end (=)


	/// [const]
	/// (<)
	/// ! check for issue with the or statement
	/// Precondition: (student&) obj is the student object to the right of the comparison
	/// Postcondition: returns true if the gpa or the name are less than the object 
	bool operator < (const student& obj) const {
		if (this->mEmpty)
			return mEmpty;
		else if (obj.mEmpty)
			return !obj.mEmpty;
		//end precondition checks

		return (this->mGpa < obj.mGpa) || (this->mName < obj.mName);
	}//end


	/// (<)
	/// ! check for issue with the or statement
	/// Precondition: (student&) obj is the student object to the right of the comparison
	/// Postcondition: returns true if the gpa or the name are less than the object 
	bool operator < (const student& obj) {
		if (this->mEmpty)
			return mEmpty;
		else if (obj.mEmpty)
			return !obj.mEmpty;
		//end precondition checks

		return (this->mGpa < obj.mGpa) || (this->mName < obj.mName);
	}//end

	/// [const]
	/// (>)
	/// ! check for issue with the or statement
	/// Precondition: (student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa or the name are greater than the object 
	bool operator > (const student& obj) const {
		if (this->mEmpty)
			return !mEmpty;
		else if (obj.mEmpty)
			return obj.mEmpty;
		//end precondition checks
		//else
		return (this->mGpa > obj.mGpa) || (this->mName > obj.mName);
	}//end

	/// (>)
	/// ! check for issue with the or statement
	/// Precondition: (student&) obj is the student object to the right
	/// Postcondition: returns true if the gpa or the name are greater than the object 
	bool operator > (const student& obj) {
		if (this->mEmpty)
			return !mEmpty;
		else if (obj.mEmpty)
			return obj.mEmpty;
		//end precondition checks
		//else
		return (this->mGpa > obj.mGpa) || (this->mName > obj.mName);
	}//end

	/// [const]
	/// (<<)
	/// Precondition: output stream used with an output stream object and the output stream operator << 
	/// Postcondition: displays to the stream the student in the format ( name, level, gpa ) 
	friend ostream& operator <<(ostream& strm, const student& obj) {
		if (obj.mEmpty) {
			return strm << "\n\bThe Student is empty\n";
		}
		strm << obj.mName << ", " << obj.getLevel() << ", " << setprecision(2) << obj.mGpa;
		return strm;
	}//end


	/// (<<)
	/// Precondition: output stream used with an output stream object and the output stream operator << 
	/// Postcondition: displays to the stream the student in the format ( name, level, gpa ) 
	friend ostream& operator <<(ostream& strm, student& obj) {
		if (obj.mEmpty) {
			return strm << "\n\bThe Student is empty\n";
		}
		strm << obj.mName << ", " << obj.getLevel() << ", " << setprecision(2) << obj.mGpa;
		return strm;
	}//end

	/// (>>)
	/// Precondition: output stream used with an output stream object and the output stream operator << 
	/// Postcondition: displays to the stream the student in the format ( name, level, gpa ) 
	friend istream& operator >>(istream& strm, student& obj) {
		string current;
		getline(strm, current, ',');
		std::cout << current;
		obj.mName = current;
		getline(strm, current, ',');
		std::cout << current;
		obj.setLevel(current);
		getline(strm, current, '\n');
		std::cout << current;
		obj.mGpa = stod(current);
		return strm;
	}//end

};//end class

=======
	void operator = (const student& obj)
	{
		this->gpa = obj.gpa;
		this->name = obj.name;
		this->strLevel = obj.strLevel;
	}//end (=)
};
>>>>>>> 9e6ffe501f68637e2d16a0ece37e9a1c9de93f0a
