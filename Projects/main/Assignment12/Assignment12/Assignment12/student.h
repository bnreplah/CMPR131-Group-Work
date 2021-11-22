#include <iostream>

using namespace std;

#pragma once
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

	void setID(int pID) {
		this->id = pID;
	}

	void setFullName(string pFullName) {
		this->fullName = pFullName;
	}

	void setMajor(string pMajor) {
		this->major = pMajor;
	}

	void setGPA(double pGPA) {
		this->gPA = pGPA;
	}

	//*******************************
	//Accessor
	//*******************************

	int getID() {
		return id;
	}

	string getFullName() {
		return fullName;
	}

	string getMajor() {
		return major;
	}

	double getGPA() {


	}

};