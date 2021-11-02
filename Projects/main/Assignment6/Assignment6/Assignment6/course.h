// File: course.h
//	Team Members:
//      Ben Halpern
//      Itz Rodriquez
//      Tony Cheng
//      Jose Chavez
//      Thien Nguyen
//      Jesus Sierra
//	Professor Q
//	CMPR 131
//	Assignment 6
//	10/7/21
//
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "input.h"
#include "templateMyBag.h"
//#include "student.h"
/** [Course class invariant]
*  3) Create a class called Course that have the following requirements:
*   
*   variables (attributes):
*       A string stores the name of course
*       myBag of integers stores a collection of registered student IDs
*       myBag of strings stores a collection of registered student names
*       myBag of doubles stores a collection of registered student scores
*       myBag of chars stores a collection of registered student grades
*       constructor(s) and destructor
*       accessors and mutators
*       friend function(s) 
* 
*	Option3 utilizes the Course class and performs:
*       create a dynamic array of courses
*       read data from text files and insert into the courses structures
*       search for student's ID or name from a course
*       remove a student record from a course
*       display courses' information
* 
* 
*/
class course{
	string ticket = string();
	string name = string();									//course name
	myBag<int> regStudentIds;								//a bag of integers of the holding the register student's ids
	myBag<pair<string, int>> regStudentNames;							//a bag of strings holding the registered student's names
	myBag<pair<double, int>> regStudentScores;							//a bag of doubles holding the registered student's scores
	myBag<pair<char, int>> regStudentGrades;							//a bag of chars holding the registered student's grades (A,B,C,D,F)
	size_t size;
public:
	course() { this->size = 0; }

	course(string pName, string pTicket = string("#00000")) :ticket(pTicket), name(pName) { this->size = 0; }

	~course() {

	}

	//accesssors
	string getTicket() const{
		return this->ticket;
	}

	string getName() const{
		return this->name;
	}

	/// [stub]
	/// Precondition: must be put in the bag in a parallel fashion
	/// Postcondition:
	typename list<int>::iterator getStId() {
		return regStudentIds.get();
	}

	/// [stub]
	/// Precondition:must be put in the bag in a parallel fashion
	/// Postcondition:
	typename list<pair<string, int>>::iterator getStName(){
		return regStudentNames.get();
	}
	/// [stub]
	/// Precondition:
	/// Postcondition:
	typename list<pair<double,int>>::iterator getStScore() {
		return regStudentScores.get();
	}

	/// [stub]
	/// Precondition:
	/// Postcondition:
	typename list<pair<char,int>>::iterator getStGrade() {
		return regStudentGrades.get();
	}
	
	
	/// [stub]
	/// Precondition:must be put in the bag in a parallel fashion
	/// Postcondition:
	typename list<pair<string, int>>::iterator getStName(int studentId){
		int count = 0;
		for (typename list<pair<string, int>>::iterator itt = this->regStudentNames.get(); itt->second != studentId && count < this->regStudentNames.getSize(); ++itt, count++) {
			std::cout << "\n[" << count << "] out of " << this->regStudentNames.getSize() ;
			if (itt->second == studentId)
				return itt;
		}
	}
	/// [stub]
	/// Precondition:
	/// Postcondition:
	typename list<pair<double,int>>::iterator getStScore(int studentId) {
		int count = 0;
		for (typename list<pair<double, int>>::iterator itt = this->regStudentScores.get(); itt->second != studentId && count < this->regStudentScores.getSize(); ++itt, count++) {
			std::cout << "\n[" << count << "] out of " << this->regStudentScores.getSize();
			if (itt->second == studentId)
				return itt;
		}
	}

	/// [stub]
	/// Precondition:
	/// Postcondition:
	typename list<pair<char,int>>::iterator getStGrade(int studentId) {
		int count = 0;
		for (typename list<pair<char, int>>::iterator itt = this->regStudentGrades.get(); itt->second != studentId && count < this->regStudentGrades.getSize(); ++itt, count++) {
			std::cout << "\n[" << count << "] out of " << this->regStudentGrades.getSize();
			if (itt->second == studentId)
				return itt;
		}
	}



	//mutators
	void setName(string pName) {
		this->name = pName;
	}

	void setTicket(string pTicket) {
		this->ticket = pTicket;
	}

	void addStudent(int st_id, string st_name, double st_score, char st_grade) {
		regStudentIds.insert(st_id);
		regStudentNames.insert(pair<string,int>(st_name, st_id));
		regStudentScores.insert(pair<double,int>(st_score, st_id));
		regStudentGrades.insert(pair<char,int>(st_grade, st_id));
		size++;
	}

	//void addStudent(student newStudent) {
	//	regStudentIds.insert(newStudent.getId());
	//	regStudentNames.insert(pair<string, int>(newStudent.getName(),newStudent.getId()));
	//	regStudentScores.insert(pair<double, int>(inputDouble("Enter a score for the student: ", double(0), double(100)),newStudent.getId()));
	//	regStudentGrades.insert(pair<char, int>(inputChar("\nEnter a grade for the student: "),newStudent.getId()));
	//	size++;
	//}
	
	void display() {
		std::cout << "\n" << setprecision(2) << setw(15) << "Student ID" << setw(15) << " | " << setw(15) << "Student Name" << setw(15) << " | " << setw(15) << "Grade" << setw(15) << " | " << setw(15) << "Score" ;
		for (int i = 0; i < size; i++) {
			std::cout << "\n" << setprecision(2) << setw(15) << *this->getStId() << setw(15) << " | " << setw(15) << this->getStName()->first << setw(15) << " | " << setw(15) << this->getStGrade()->first << setw(15) << " | " << setw(15) << this->getStScore()->first ;
		}//end for
	}
};


