/// File:    Student.h
/// Team Members:
///          Itz Rodrigez 
///          Tony Cheng
///          Ben Halpern
///          Jose Chavez
///          Thien Nguyen
///          Jesus Sierra
/// Professor Q
/// CMPR 131
/// Assignment 12
/// 11/24/21
/// Description:
///
/// 
///
/// 
/// Reviewed:
///  

#pragma once
#include <iostream>
#include <fstream>

using namespace std;


class Student {
private:
	int id = int();
	string fullName;
	string major;
	double gPA = double();


public:

	//*******************************
	//Constructors
	//*******************************

	//default constructor
	Student() {
		id = 0.0;
		fullName = "Unknown";
		major = "Unknown";
		gPA = 0.0;
	}
	// constructor
	Student(const Student& obj)
	{
		this->id = obj.id;
		this->fullName = obj.fullName;
		this->major = obj.major;
		this->gPA = obj.gPA;
	}
	
	// constructor
	Student(int pId, string pFullName, string pMajor, double pGPA)
	{
		this->id = pId;
		this->fullName = pFullName;
		this->major = pMajor;
		this->gPA = pGPA;
	}


	//*******************************
	//Mutators
	//*******************************

	//precondition: Student object must be initialized, parameter must be integer value
	//postcondition: will set the value to the ID
	void setID(int pID) {
		this->id = pID;
	}
	//precondition: Student object must be initialized, parameter must be string value
	//postcondition: Will set the value to full name 
	void setFullName(string pFullName) {
		this->fullName = pFullName;
	}

	//precondition: Student object must be initialized, parameter must be string value
	//postcondition: Will set the value to major 
	void setMajor(string pMajor) {
		this->major = pMajor;
	}

	//precondition: Student object must be initialized, parameter must be double value
	//postcondition: Will set the value to gPA 
	void setGPA(double pGPA) {
		this->gPA = pGPA;
	}

	//*******************************
	//Accessor
	//*******************************
	
	//precondition: Student object must be initialized
	//postcondition: will return the ID value
	int getID() {
		return id;
	}

	//precondition: Student object must be initialized
	//postcondition: will return the fullName value
	string getFullName() {
		return fullName;
	}

	//precondition: Student object must be initialized
	//postcondition: will return the major value
	string getMajor() {
		return major;
	}

	//precondition: Student object must be initialized
	//postcondition: will return the gPA value
	double getGPA()  {
		return gPA;
	}

	//precondition: Student object must be initialized
	//postcondition: will return the ID
	int getID() const {
		return id;
	}

	//precondition: Student object must be initialized
	//postcondition: will return the fullName value	
	string getFullName() const{
		return fullName;
	}

	//precondition: Student object must be initialized
	//postcondition: will return the major value
	string getMajor() const{
		return major;
	}

	//precondition: Student object must be initialized
	//postcondition: will return the gPA value
	double getGPA() const {
		return gPA;
	}
	//overloaded operator
	//precondition: file must exists and Student object must be initialized
	//postcondition: will store the values from the file on the student object	
	friend ifstream& operator >> (ifstream& stream, Student& stud) {
		string line;
		int index = int();
		int startingIndex = 0;

		getline(stream, line, '\n');
		index = line.find(',', index) + 1;
		stud.setID(stoi(line.substr(0, index - startingIndex)));

		startingIndex = index;
		index = line.find(',', index) +1;
		stud.setFullName(line.substr(startingIndex, index - startingIndex - 1));

		startingIndex = index;
		index = line.find(',', index) + 1;
		stud.setMajor(line.substr(startingIndex, index - startingIndex -1));

		startingIndex = index;
		stud.setGPA(stod(line.substr(startingIndex)));

		return stream;
	}
	//overloaded == operator
	bool operator ==(const Student& obj ) {
		return (this->id == obj.id) && (this->gPA == obj.gPA) && (this->major == obj.major) && (this->fullName == obj.fullName);
	}
	
	//overloaded != operator
	bool operator !=(const Student& obj) {
		return (this->id != obj.id) || (this->gPA != obj.gPA) || (this->major != obj.major) || (this->fullName != obj.fullName);
	}

	//overloaded << operator
	friend ostream& operator << (ostream& strm, const Student& obj) {
		strm << obj.getID()<< "," << obj.getFullName() << "," << obj.getMajor() << "," << obj.getGPA();
		return strm;
	}

	//overloaded < operator
	bool operator < (const Student& obj) {
		return this->id < obj.id;
	}
};