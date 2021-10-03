// File: List.h
// Team members:
//		 
//
//
//
// Assigned to:
// 
// 
//
//	Reviewed by: [name]					Date: [mm/dd/yy]
//				
//
//

/**
* Description
* 
*/


#pragma once

#include <iostream>
#include <list>
#include "input.h"

using namespace std;

class student {
private:

	string name = string();											//
	
	string level = string();										//
	
	double gpa = double();											//

public:

	/// [Default Constructor]
	/// Precondition:  
	/// Postcondition: 
	student(string pName, string pLevel, double pGpa): name(pName), level(pLevel), gpa(pGpa) {}//end student constructor
	
	/// [Copy Constructor]
	/// Precondition:
	/// Postcondition:
	student(const student& copy) {
		this->gpa = copy.gpa;
		this->level = copy.level;
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
		return this->level;
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
		string tLevel = inputString("\nEnter the his/her level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", true);
		this->level = tLevel;
	}// end setLevel
	
	/// Precondition:  
	/// Postcondition: 
	void setGpa(){
		double tGpa = inputDouble("\nEnter his/her GPA (0.0..4.0): ",0.0 , 4.0);
		this->gpa = tGpa;
	}// end setGpa
	
	/// (<)
	/// comparing student.[] 


	/// (<<)
	/// 
	friend ostream& operator <<(ostream& strm, const student& obj) {
		strm << "\nGPA: " << obj.getGpa();
		strm << "\nLevel: " << obj.getLevel();
		strm << "\nStudent Name" << obj.getName() << "\n";
	}


	/// (>)
	///



	/// (==)
	///


	/// (<=)
	///


	/// (>=) 
	/// 


	/// ()
	///
	

	/// ()
	///
};


/**
*	Class : listDriver
* 
* 
*/
class listDriver
{
	
private:
	list<student> listOne = list<student>();

public:
	listDriver() {
	
	}

	void testing() {
		cout << "begin:       " << *listOne.begin();
		cout << "end:         " << *listOne.end();
		cout << "const begin: " << *listOne.cbegin();
		cout << "const end:   " << *listOne.cend();
		cout << "";
		cout << "";
		cout << "";
		cout << ""; 
		cout << "";
		cout << "";
		cout << "";
	}//end testing 

};

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver
void runLinkedList()
{




}
