// Patient.h
// 
// Created by Professor Q
// 
// Assigned to and modified by:
//			Itzcoatl, Thien
// Team Members:
//      Ben Halpern
//      Itz Rodrigez 
//      Tony Cheng
//      Jose Chavez
//      Thien Nguyen
//      Jesus Sierra
// Professor Q
// CMPR 131
// Assignment 8
// 10/22/21
//
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
	static string ER_description[5];
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

	/// Precondition: Patient object initialized and checInTime must hold a value
	/// Postcondition: will return set check in time(time will always be time > 0)
	unsigned int getCheckedInTime() const
	{
		return checkedInTime;
	}

	/// Precondition: Patient object initialized and priority must hold a value	
	/// Postcondition: will return set priority
	int getPriority() const
	{
		return priority;
	}

	/// Precondition: Patient object initialized and name must hold a value	
	/// Postcondition: will return set name
	string getName() const
	{
		return name;
	}
		
	//precondition: Patient Object must be initialized
	//postcondition: will return the checkedInTime value
	int getCheckedIn() const
	{
		return checkedInTime;
	}

	/// Precondition: Patient object initialized and age must hold a value	
	/// Postcondition: will return the value of age
	int getAge() const
	{
		return age;
	}

	/// Precondition: Patient object initialized and gender must hold a value	
	/// Postcondition: will return tha value of gender
	char getGender() const
	{
		return gender;
	}

	/// Precondition: Patient object initialized and priority must hold a value of 1 or greater	
	/// Postcondition: will return set priority in string form
	static string getStatus(Patient pat)
	{
		return ER_description[pat.priority - 1];
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

	/// Precondition: Patient object must be initialized and must hold values in the member fields
	/// Postcondition: will output the demographic information of the patient
	friend ostream& operator << (ostream& outs, const Patient& obj);
};

/// Precondition: Both patient objects must be initialized
/// Postcondition: Both objects will compare the priority values
bool operator < (const Patient& P1, const Patient& P2)
{
	return P1.priority < P2.priority;
}

/// Precondition: Patient object priority set
/// Postcondition: will designate description to set priority from 1 to 5
string Patient::ER_description[5] = { "Stable, with no resources anticipated or prescriptions",
									  "Stable, with only one type of resource anticipated ",
									  "Stable, with multiple types of resources needed to investigate or treat",
									  "High risk of deterioration, or signs of a time-critical problem",
									  "Immediate, life-saving intervention required without delay" };

/// Precondition: Patient object must be initialized and must hold values in the member fields
/// Postcondition: will output the demographic information of the patient
ostream& operator << (ostream& outs, const Patient& obj)
{
	outs << "\n\tER level: " << obj.getPriority() << " - " << obj.ER_description[obj.getPriority()-1];
	outs << "\n\n\t\t\tChecked-In time: " << obj.getCheckedIn();
	outs << "\n\t\t\tPatient's name: " << obj.getName();
	outs << "\n\t\t\tPatient's age: " << obj.getAge();
	outs << "\n\t\t\tPatient's gender: " << obj.getGender() << "\n";
	return outs;
}