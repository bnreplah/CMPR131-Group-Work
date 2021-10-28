//  Patient.h
//	Team Members:
//      Ben Halpern
//      Itz Rodriquez
//      Tony Cheng
//      Jose Chavez
//      Thien Nguyen
//      Jesus Sierra
//	Professor Q
//	CMPR 131
//	Assignment 8
//	10/22/21
// 
// Created by Professor Q
// 
// Assigned to and modified by:
//			Itzcoatl, Thien

#pragma once
#include <string>
using namespace std;

class Patient
{
private:
	int priority;
	unsigned int checkedInTime;
	string name;
	int age;
	char gender;
	unsigned int admittedTime;
	string careUnit;
	static string ErDescription[5];
public:

	//######################################################################################
	// Constructors
	//######################################################################################

	/// [Default Constructor]
	/// Precondition: Patient object initialized
	/// Postcondition: will initialize object with default values
	Patient()
	{
		checkedInTime;
		priority = 0;
		name = "unknown";
		age = 0;
		gender = 'u';
	}

	//######################################################################################
	// Accessors
	//######################################################################################

	/// Precondition: check in time set
	/// Postcondition: will return set check in time(time will always be time > 0)
	unsigned int getCheckedInTime() const
	{
		return checkedInTime;
	}

	/// Precondition: priority set
	/// Postcondition: will return set priority
	int getPriority() const
	{
		return priority;
	}

	/// Precondition: name set
	/// Postcondition: will return set name
	string getName() const
	{
		return name;
	}

	/// Precondition: age set
	/// Postcondition: will return set age
	int getAge() const
	{
		return age;
	}

	/// Precondition: gender set
	/// Postcondition: will return set gender
	char getGender() const
	{
		return gender;
	}

	/// Precondition: priority set
	/// Postcondition: will return set priority in string form
	static string getStatus(Patient pat)
	{
		return ErDescription[pat.priority - 1];
	}

	//######################################################################################
	// Mutators
	//######################################################################################

	/// Precondition: Patient object initialized
	/// Postcondition: will set current time when method is called(time will always be time > 0)
	void setCheckedInTime(unsigned int time)
	{
		this->checkedInTime = time;
	}

	/// Precondition: Patient object initialized
	/// Postcondition: will set priority of Patient object
	void setPriority(int priority)
	{
		this->priority = priority;
	}

	/// Precondition: Patient object initialized
	/// Postcondition: will set name Patient object
	void setName(string name)
	{
		this->name = name;
	}

	/// Precondition: Patient object initialized
	/// Postcondition: will set age Patient object
	void setAge(int age)
	{
		this->age = age;
	}

	/// Precondition: Patient object initialized
	/// Postcondition: will set gender Patient object
	void setGender(char gender)
	{
		this->gender = gender;
	}

	//######################################################################################
	// Friend
	//######################################################################################

	/// Precondition: two Patient object initialized and compared
	/// Postcondition: will compare if the first Patient object is less that second Patient object
	friend bool operator < (const Patient& P1, const Patient& P2); // key in priority queue

	/// Precondition: 
	/// Postcondition: 
	//friend ostream& operator << (ostream& outs, const Patient& obj);
};

/// Precondition: 
/// Postcondition: 
bool operator < (const Patient& P1, const Patient& P2)
{
	return P1.priority < P2.priority;
}

/// Precondition: Patient object priority set
/// Postcondition: will designate description to setted priority from 1 to 5
string Patient::ErDescription[5] = { "Stable, with no resources anticipated or prescriptions",
									  "Stable, with only one type of resource anticipated ",
									  "Stable, with multiple types of resources needed to investigate or treat",
									  "High risk of deterioration, or signs of a time-critical problem",
									  "Immediate, life-saving intervention required without delay" };

/// Precondition: 
/// Postcondition: 
//ostream& operator << (ostream& outs, const Patient& obj)
//{
//	//outs << "ER level: " << obj.getPriority() << " - " << obj.ER_description[obj.getPriority()-1] << '\n';
//	//outs << "\t\t\tChecked-In time: " << obj.getCheckedIn() << '\n';
//	//outs << "\t\t\tPatient's name: " << obj.getName() << '\n';
//	//outs << "\t\t\tPatient's age: " << obj.getAge() << '\n';
//	//outs << "\t\t\tPatient's gender: " << obj.getGender() << '\n';
//	return outs;
//}