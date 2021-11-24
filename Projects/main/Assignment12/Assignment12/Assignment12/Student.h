#include <iostream>
#include <fstream>

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



	Student(const Student& obj)
	{
		this->id = obj.id;
		this->fullName = obj.fullName;
		this->major = obj.major;
		this->gPA = obj.gPA;
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

	double getGPA()  {
		return gPA;
	}

	int getID() const {
		return id;
	}

	string getFullName() const{
		return fullName;
	}

	string getMajor() const{
		return major;
	}

	double getGPA() const {
		return gPA;
	}

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

	bool operator ==(const Student& obj ) {
		return (this->id == obj.id) && (this->gPA == obj.gPA) && (this->major == obj.major) && (this->fullName == obj.fullName);
	}
	
	bool operator !=(const Student& obj) {
		return (this->id != obj.id) || (this->gPA != obj.gPA) || (this->major != obj.major) || (this->fullName != obj.fullName);
	}

	friend ostream& operator << (ostream& strm, const Student& obj) {
		strm << obj.getID()<< "," << obj.getFullName() << "," << obj.getMajor() << "," << obj.getGPA();
		return strm;
	}

	bool operator < (const Student& obj) {
		return this->id < obj.id;
	}
};