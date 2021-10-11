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
#include "input.h"
#include "templateMyBag.h"
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
	myBag<string> regStudentNames;							//a bag of strings holding the registered student's names
	myBag<double> regStudentScores;							//a bag of doubles holding the registered student's scores
	myBag<char> regStudentGrades;							//a bag of chars holding the registered student's grades (A,B,C,D,F)

public:
	course(string pName, string pTicket = string("#00000")):ticket(pTicket), name(pName) {}
	//accesssors
	string getTicket() const{
		return this->ticket;
	}

	string getName() const{
		return this->name;
	}

	/// [stub]
	/// Precondition:
	/// Postcondition:
	int getStId() {
		return regStudentIds.get();
	}

	/// [stub]
	/// Precondition:
	/// Postcondition:
	string getStName(){
		return regStudentNames.get();
	}
	/// [stub]
	/// Precondition:
	/// Postcondition:
	double getStScore() {
		return regStudentScores.get();
	}

	/// [stub]
	/// Precondition:
	/// Postcondition:
	char getStGrade() {
		return regStudentGrades.get();
	}



	//mutators
	void setName(string pName) {
		this->name = pName;
	}

	void setTicket(string pTicket) {
		this->ticket = pTicket;
	}

	void addStudent(int st_id, string st_name, double st_score, char st_grade) {
		regStudentIds.add(st_id);
		regStudentNames.add(st_name);
		regStudentScores.add(st_score);
		regStudentGrades.add(st_grade);
	}

	
	

};


