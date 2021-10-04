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
#include <cstdlib>
#include <iomanip>
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
	///
	bool operator < (const student& obj) {
		return (this->gpa < obj.gpa) || (this->name < obj.name);
	}
	
	
	/// (>)
	///
	bool operator > (const student& obj) {
		return (this->gpa > obj.gpa) || (this->name > obj.name);
	}

	/// (<<)
	/// 
	friend ostream& operator <<(ostream& strm, const student& obj) {
		strm << "(" << obj.name << ", " << obj.level << ", " << setprecision(2) << obj.gpa << ")";
		return strm;
	}


	/// 
	///



	/// (==)
	///
	bool operator ==(const student& obj) {
		return ((this->gpa == obj.gpa) && (this->level == obj.level) && (this->name == obj.name));
	}


	/// (<=)
	///
	bool operator <=(const student& obj) {
		return ((this->gpa <= obj.gpa) && (this->level <= obj.level) && (this->name <= obj.name));
	}


	/// (>=) 
	/// 
	bool operator <=(const student& obj) {
		return ((this->gpa >= obj.gpa) && (this->level >= obj.level) && (this->name >= obj.name));
	}


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

char listMenuOption()
{
	string options[] = { "\n\tLists are sequence containers that allow constant time insert and erase operations anywhere within the",
						"\n\tsequence, and iteration in both directions.\n",
						"\n\t2> Rational Numbers",
						"\n\t" + string(100, char(205)) +
						"\n\t\tA> clear() - Destroys all elements from the list",
						"\n\t\tB> resize(n) - Changes the list so that it contains n elements",
						"\n\t\tC> Read input.dat and push_front(e) - Adds a new element at the front of the list",
						"\n\t\tD> pop_front() - Deletes the first element",
						"\n\t\tE> front() - Accesses the first element",
						"\n\t\tF> Read input.dat and push_back(e) - Adds a new element at the end of the list",
						"\n\t\tG> pop_back() - Delete the last element",
						"\n\t\tH> back() Accesses the last element",
						"\n\t\tI> begin() - Returns an iterator refereing to the first element in the list",
						"\n\t\tJ> end() Returns an iterator referring to the past-the-end element in the list",
						"\n\t\tK> Using iterator begin() and end() returns all elements in the list",
						"\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the list",
						"\n\t\tM> rend() - Returns a reverse iterator pointing to the element preceding the first element",
						"\n\t\t            in the list",
						"\n\t\tN> Using iterator rbegin() and rend() returns all elements in the list",
						"\n\t\tO> erase(it) - Removes from the vector a single element(using an iterator)",
						"\n\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements( using iterators)",
						"\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.",
						"\n\t\tR> swap() - Exchanges the content of the container by another list's content of the same type",
						"\n\t\tS> Sort - Sorts the list.",
						"\n\t" + string(100 , char(196)) +
						"\n\t\t0> return "
						"\n\t" + string(100, char(205))
	};
	for (string option : options)
		cout << option;

	char optionChar = inputChar("\n\t\toption ", static_cast<string>("abcdefghijklmnopqrs0"));
	clrScrn();

	return optionChar;
}

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver
void runLinkedList()
{
	do
	{
		switch (listMenuOption())
		{
		case '0': return; break;
		case 'A':; break;
		case 'B':; break;
		case 'C':; break;
		case 'D':; break;
		case 'E':; break;
		case 'F':; break;
		case 'G':; break;
		case 'H':; break;
		case 'I':; break;
		case 'J':; break;
		case 'K':; break;
		case 'L':; break;
		case 'M':; break;
		case 'N':; break;
		case 'O':; break;
		case 'P':; break;
		case 'Q':; break;
		case 'R':; break;
		case 'S':; break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
	} while (true);
}