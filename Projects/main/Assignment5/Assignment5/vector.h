
#pragma once

#include <iostream>
#include "input.h"
#include "student.h"
#include <vector>
#include <fstream>

using namespace std;

class vectorDriver
{
private:

	vector <student> myVector;

public:
	/// Precondition: vectorDriver object must be initialized
	/// Postcondition: will clear all the values in the vector
	vectorDriver()
	{
		myVector.clear();
	}

	/// Precondition: vectorDriver object must be initialized
	/// Postcondition: clears all the elements from the vectorDriver
	void clearVector()
	{
		myVector.clear();
		cout << "The vector has been cleared" << endl;
	}

	/// Precondition: vectorDriver object must be initialized
	/// Postcondition: will reserve the space for the given value for the user
	void reserveVector()
	{
		int reserveInt = inputInteger("Enter the capacity (1-100):", 1, 100);
		myVector.reserve(reserveInt);
		cout << "Vector has been reserved " << reserveInt << " element(s)." << endl;

	}

	/// Precondition: vectorDriver object must be initialized
	/// Postcondition: will resize the vector by the value given by the user
	void resizeVector()
	{
		int size = inputInteger("Enter the new size(1-100): ", 1, 100);
		myVector.resize(size);
		cout << "Vector has been resized " << size << " element(s)." << endl;
	}

	/// Precondition: vectorDriver object must be initialized
	/// Postcondition: will return the number of students in the myVetorDriver object
	int getSizeOfVector()
	{
		return myVector.size();
	}

	/// Precondition: there must be elements in the object
	/// Postcondition: will return the last value inputted
	void popBackVector()
	{
		myVector.pop_back();
	}

	/// Precondition: there must be elements in the object
	/// Postcondition: will return the first element (positioned in the front)
	void frontOfVector()
	{
		cout << "[" << 0 << "] " << myVector.front() << endl;;
	}

	/// Precondition: none
	/// Postcondition: will output all of the elements in the 
	friend ostream& operator <<(ostream& strm, const vectorDriver& obj)
	{
		for (int i = 0; i < obj.myVector.size(); i++)
		{
			strm << "[" << i << "]: " << obj.myVector.at(i).getName() << ", " << obj.myVector.at(i).getLevel() << ", " << obj.myVector.at(i).getGpa() << endl;

		}
		return strm;
	}

	/// Precondition:there must be elements in the object 
	/// Postcondition: will return the last element added 
	void backOfVector()
	{
		cout << "[" << myVector.size() - 1 << "] " << myVector.back() << endl;
	}

	/// Precondition:the object must be initialized and the value must be a student object
	/// Postcondition: will add the student object to the end of the vector 
	void pushBackToVector(student value)
	{
		myVector.push_back(value);
	}

	/// Precondition: there must be a student object in the given index
	/// Postcondition: will return the student in the given object
	void indexOfVector(int index)
	{
		cout << "[" << index << "] " << myVector.at(index) << endl;
	}

	/// Precondition: there must be students in the vectorDriver object
	/// Postcondition: will output the memory address and the value of the first element using iterator
	void iBegin() {
		std::vector<student>::iterator iter = myVector.begin();
		cout << "\nThe iterator referring the first element: " << &iter << "(" << *iter << ")\n";
	}

	/// Precondition: there must be students in the vectorDriver object
	/// Postcondition: will output the memory address and the value of the last element using iterator
	void iEnd() {
		std::vector<student>::iterator iter = myVector.end();
		cout << "\nThe iterator referring to the past-the-end element:" << &iter << "\n";
	}

	/// Precondition: there must be students in the vectorDriver object
	/// Postcondition: will output the memory address and the value of the elements from begin() to end() using iterator
	void iReturn() {
		cout << "\nUsing begin() and end(), the vector contains:\n";
		for (std::vector<student>::iterator iter = myVector.begin(); iter != myVector.end(); iter++)
		{
			cout << "\t" << &iter << " (" << *iter << ")\n";
		}
		cout << endl;
	}

	/// Precondition: there must be students in the vectorDriver object
	/// Postcondition: will output the last element using reverse iterator
	void irBegin() {
		std::vector<student>::reverse_iterator iter = myVector.rbegin();
		cout << "\nThe reverse iterator pointing to the last element: " << &iter << "(" << *iter << ")\n";
	}

	/// Precondition: there must be students in the vectorDriver object
	/// Postcondition: will output the last element using reverse iterator
	void irEnd() {
		std::vector<student>::reverse_iterator iter = myVector.rend();
		cout << "\nThe reverse iterator pointing to the theoretical element preceding the first element in the vector: " << &iter << "\n\n";
	}

	/// Precondition: there must be students in the vectorDriver object
	/// Postcondition: will output the elements in reverse order using reverse iterator
	void irReturn() {
		cout << "\nUsing rbegin() and rend(), the vector contains reversed elements:\n";
		for (std::vector<student>::reverse_iterator iter = myVector.rbegin(); iter != myVector.rend(); iter++)
		{
			cout << "\t" << &iter << " (" << *iter << ")\n";
		}
		cout << endl;
	}

	/// Precondition: File must exist and the vectorDrvier object must be initialized
	/// Postcondition: will push each student object onto the vectorDriver object using a CSV file
	void readFile() {
		student input;
		fstream inFile = fstream("input.dat", ios::in);
		int count = 0;

		inFile.open("input.dat", ios::in);
		if (!inFile.bad()) {
			while (!inFile.eof()) {
				inFile >> input;
				if (input.empty()) {
					continue;
				}
				else {
					myVector.push_back(input);
					count++;
				}
			}
			cout << "The vector now has " << count << " elements.\n\n";
			for (int num = 0; num < count; num++) {
				cout << "[" << num << "] " << myVector[num] << endl;
			}
		}
		else {
			cout << "The file doesn't exist.\n";
		}
		inFile.close();
	}
};

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////

/// Precondition: vectorDriver must be initialized
/// Postcondition: will return true if there are no elements in the vectorDriver object or false if there is at least one student
bool vectorIsEmptyMethod(vectorDriver myVector)
{
	bool empty = false;
	if (myVector.getSizeOfVector() == 0)
	{
		cout << "There are no student records" << endl;
		return true;
	}
	return false;
}

/// Precondition: vectorDriver must be initialized and have students in the object
/// Postcondition: will output the element in the vectorDriver given relative to the index given by the user
void indexMethod(vectorDriver myVector)
{
	if (vectorIsEmptyMethod(myVector))
		return;

	int index = inputInteger("Enter the index:(0 -" + to_string(myVector.getSizeOfVector() - 1) + "): ", 0, myVector.getSizeOfVector() - 1);

	myVector.indexOfVector(index);
}

/// Precondition: vectorDriver must be initialized and have students in the object
/// Postcondition: will output the last element of the vectorDriver object
void backMethod(vectorDriver myVector)
{
	if (vectorIsEmptyMethod(myVector))
		return;
	myVector.backOfVector();
}

/// Precondition: vectorDriver must be initialized and have students in the object
/// Postcondition: will output the first element of the vectorDriver object
void frontMethod(vectorDriver& myVector)
{
	if (vectorIsEmptyMethod(myVector))
		return;

	myVector.frontOfVector();
}

/// Precondition: vectorDriver must be initialized and have students in the object
/// Postcondition: will remove the last element of the vectorDriver object and output the elements of the object
void popBackMethod(vectorDriver& myVector)
{
	if (vectorIsEmptyMethod(myVector))
		return;

	myVector.popBackVector();
	cout << myVector;
}

/// Precondition: file must exists and must be a CSV format
/// Postcondition: will input the student object fields and place the students in the vectorDriver object
void readFileMethod(vectorDriver& myVector)
{
	fstream fstrm = fstream();
	student temp;
	fstrm.open("input.dat", ios::in);
	while (!fstrm.eof())
	{
		fstrm >> temp;
		if (!temp.empty())
		{
			myVector.pushBackToVector(temp);
		}
		if (fstrm.eof())
		{
			break;
		}
	}
	fstrm.close();
	cout << myVector;
}

/// Precondition: vectorDriver must be initialized
/// Postcondition: will resize the vectorDriver object by the given size from the user
void resizeMethod(vectorDriver& myVector)
{
	myVector.resizeVector();
}

/// Precondition: vectorDriver must be initialized
/// Postcondition: will remove all the elements in the vectorDriver object
void clearMethod(vectorDriver& myVector)
{
	myVector.clearVector();
}

/// Precondition: vectorDriver must be initialized
/// Postcondition: wil reserve the space for the vectorDriver object
void reserveMethod(vectorDriver& myVector)
{
	myVector.reserveVector();

}

/// Precondition: vectorDriver must be initialized and must have elements
/// Postcondition: will return the 
void iterBegin(vectorDriver& myVector) {
	if (vectorIsEmptyMethod(myVector))
	{
		return;
	}
	myVector.iBegin();
}
/// Precondition:
/// Postcondition:
void iterEnd(vectorDriver& myVector) {
	if (vectorIsEmptyMethod(myVector))
	{
		return;
	}
	myVector.iEnd();
}
/// Precondition:
/// Postcondition:
void iterReturn(vectorDriver& myVector) {
	if (vectorIsEmptyMethod(myVector))
	{
		return;
	}
	myVector.iReturn();
}
/// Precondition:
/// Postcondition:
void iterRBegin(vectorDriver& myVector) {
	if (vectorIsEmptyMethod(myVector))
	{
		return;
	}
	myVector.irBegin();
}
/// Precondition:
/// Postcondition:
void iterREnd(vectorDriver& myVector) {
	if (vectorIsEmptyMethod(myVector))
	{
		return;
	}
	myVector.irEnd();
}

/// Precondition:
/// Postcondition:
void iterRReturn(vectorDriver& myVector) {
	if (vectorIsEmptyMethod(myVector))
	{
		return;
	}
	myVector.irReturn();
}


/// Precondition:
/// Postcondition:
char listMenuOptionVector()
{
	string options[] = { "\n\tLists are sequence containers that allow constant time insert and erase operations anywhere within the",
						"\n\tsequence, and iteration in both directions.\n",
						"\n\t2> Rational Numbers",
						"\n\t" + string(100, char(205)) +
						"\n\t\tA> clear() - Removes all elements from the vector (which are destroyed)",
						"\n\t\tB> reserve(n) - Requests that the vector capacity be at least enough to contain n elements",
						"\n\t\tC> resize(n) - Resizes the container so that it contains n elements",
						"\n\t\tD> Read input.dat and push_back(e) - Adds a new element at the end of the vector",
						"\n\t\tE> pop_back() - Removes the last element in the vector",
						"\n\t\tF> front() - Returns a reference to the first element in the vector",
						"\n\t\tG> back() - Returns a reference to the last element in the vector",
						"\n\t\tH> index using at() or []) - Returns a reference to the element at position n in the vector",
						"\n\t\tI> begin() - Returns an iterator pointing to the first element in the vector",
						"\n\t\tJ> end() Returns an iterator referring to the past-the-end element in the vector",
						"\n\t\tK> Using iterator begin() and end() returns all elements in the vector",
						"\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the vector",
						"\n\t\tM> rend() - Returns a reverse iterator pointing to the theoretical element preceding the first",
						"\n\t\t       element in the vector     ",
						"\n\t\tN> Using iterator rbegin() and rend() returns all elements in the vector",
						"\n\t\tO> erase(it) - Removes from the vector a single element(using an iterator)",
						"\n\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements( using iterators)",
						"\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.",
						"\n\t\tR> swap() - Exchanges the content of the container by another vector's content of the same type",
						"\n\t\tS> Sort - Sorts the vector.",
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

/// Precondition:
/// Postcondition:
void runVector()
{
	vectorDriver myVector;
	do
	{
		switch (listMenuOptionVector())
		{
		case '0': return; break;
		case 'A':clearMethod(myVector); break;
		case 'B':reserveMethod(myVector); break;
		case 'C':resizeMethod(myVector); break;
		case 'D':readFileMethod(myVector); break;
		case 'E':popBackMethod(myVector); break;
		case 'F':frontMethod(myVector); break;
		case 'G':backMethod(myVector); break;
		case 'H':indexMethod(myVector); break;
		case 'I':iterBegin(myVector); break;
		case 'J':iterEnd(myVector); break;
		case 'K':iterReturn(myVector); break;
		case 'L':iterRBegin(myVector); break;
		case 'M':iterREnd(myVector); break;
		case 'N':iterRReturn(myVector); break;
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