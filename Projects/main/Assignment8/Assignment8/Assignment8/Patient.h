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
	Patient()
	{
		checkedInTime;
		priority = 0;
		name = "unknown";
		age = 0;
		gender = 'u';
	}

	void setCheckedInTime(unsigned int t)
	{
		this->checkedInTime= t;
	}

	unsigned int getCheckedInTime() const
	{
		return checkedInTime;
	}

	void setPriority(int priority)
	{
		this->priority = priority;
	}

	int getPriority() const
	{
		return priority;
	}

	void setName(string name)
	{
		this->name = name;
	}

	string getName() const
	{
		return name;
	}

	void setAge(int age)
	{
		this->age = age;
	}

	int getAge() const
	{
		return age;
	}

	void setGender(char gender)
	{
		this->gender = gender;
	}

	char getGender() const
	{
		return gender;
	}

	friend bool operator <(const Patient& P1, const Patient& P2); //key in priority queue

	friend ostream& operator<<(ostream& outs, const Patient& obj);
};

bool operator <(const Patient& P1, const Patient& P2)
{
	return P1.priority < P2.priority;
}

string Patient::ER_description[5] = { "Stable, with no resources anticipated or prescriptions", "Stable, with only one type of resource anticipated " ,"Stable, with multiple types of resources needed to investigate or treat", "High risk of deterioration, or signs of a time-critical problem", "Immediate, life-saving intervention required without delay" };

ostream& operator <<(ostream& outs, const Patient& obj)
{
	outs << "ER level: " << obj.getPriority() << " - " << obj.ER_description[obj.getPriority()-1] << '\n';
	outs << "\t\t\tChecked-In time: " << obj.getCheckedInTime() << '\n';
	outs << "\t\t\tPatient's name: " << obj.getName() << '\n';
	outs << "\t\t\tPatient's age: " << obj.getAge() << '\n';
	outs << "\t\t\tPatient's gender: " << obj.getGender() << '\n';
	return outs;
}
