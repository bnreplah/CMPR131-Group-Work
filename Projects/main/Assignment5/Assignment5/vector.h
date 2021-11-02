// File: Vector.h
//	Team Members:
//      Ben Halpern
//      Itz Rodriquez
//      Tony Cheng
//      Jose Chavez
//      Thien Nguyen
//      Jesus Sierra
//	Professor Q
//	CMPR 131
//	Assignment 5
//	10/1/21
// 

/***[Description]
*	Vector.h Formal Description and Use:
* 
* 
* 
* 
*	Naming Conventions:
*       [tags] are used to define design element comments such as this one and those of [const] for constant members and accesors, and [mutator] for mutator methods
*           When the tag is lower case the design element is a local comment, when the first letter is capitalized the design element is a gloabl tag relating to a comment with a scope pertaining to
*           the document as a whole.
*       The names of classses are capitalized following the CamelHump naming convention
*       'm' is used as a prefix to defined private members of a class following the CamelHump naming convention
*       'p' is used as a prefix to define formal paramters of methods following the CamelHump naming convention
*
*   Condition Documentation:
*       prior to functions, the documentation of the precondition and postcondition are described with three brackets so that the descriptions would work with Microsoft Visual Studio InteliSense,
*           which produces would then display the precondition and postcondition when as a tip when the function is being implemented in the various parts of the program.
*
*   Class Invarients:
*       Class invarients provide a list of the various methods in each classes and provide a short description outlining the use and implimentation notes for that class. The methods in the class invariant don't provide formal parameters
*           but instead they show the datatype of each formal parameter in a similiar format and style that might be seen in a protoype declaration.
*
*   Flow, Structural, and Document comments are seen throughout the code and are noted by the use of only two forward slashes '//' when defining the comments
*       A series of '###' may be used to denote flow indicator to help the programmer navigate the various classes
*/



#pragma once

#include <iostream>
#include "input.h"
#include "Student.h"
#include <vector>
#include <fstream>
#include <iterator>
using namespace std;

/**[Class Invarient]
*	Class: VectorDriver
*	Private Member Variables:
* 
* 
*	Private Member Methods:
*
*/
class VectorDriver
{
private:

	vector <Student> mMyVector;

public:

	//######################################################################################
	// Constructors
	//######################################################################################

	/// [Default Constructor]
	/// Precondition: N/A
	/// Postcondition: initializes default vector
	VectorDriver() {}

	//######################################################################################
	// Accessors
	//######################################################################################

	/// Precondition: vectorDriver object must be initialized
	/// Postcondition: will return the number of students in the myVetorDriver object
	int getSizeOfVector()
	{
		return mMyVector.size();
	}

	//######################################################################################
	// Mutators
	//######################################################################################

	/// Precondition: vectorDriver object must be initialized
	/// Postcondition: clears all the elements from the vectorDriver
	void clearVector()
	{
		mMyVector.clear();
		cout << "The vector has been cleared" << endl;
	}

	/// Precondition: vectorDriver object must be initialized
	/// Postcondition: will reserve the space for the given value for the user
	void reserveVector()
	{
		int reserveInt = inputInteger("Enter the capacity (1-100):", 1, 100);
		mMyVector.reserve(reserveInt);
		cout << "Vector has been reserved " << reserveInt << " element(s)." << endl;
	}

	/// Precondition: vectorDriver object must be initialized
	/// Postcondition: will resize the vector by the value given by the user
	void resizeVector()
	{
		int size = inputInteger("Enter the new size(1-100): ", 1, 100);
		mMyVector.resize(size);
		cout << "Vector has been resized " << size << " element(s)." << endl;
	}

	/// Precondition: there must be elements in the object
	/// Postcondition: will return the last value inputted
	void popBackVector()
	{
		mMyVector.pop_back();
	}

	/// Precondition: there must be elements in the object
	/// Postcondition: will return the first element (positioned in the front)
	void frontOfVector()
	{
		cout << "[" << 0 << "] " << mMyVector.front() << endl;;
	}

	/// Precondition: none
	/// Postcondition: will output all of the elements in the 
	friend ostream& operator <<(ostream& pStrm, const VectorDriver& pObj)
	{
		for (int i = 0; i < pObj.mMyVector.size(); i++)
		{
			pStrm << "[" << i << "]: " << pObj.mMyVector.at(i).getName() << ", " << pObj.mMyVector.at(i).getLevel() << ", " << pObj.mMyVector.at(i).getGpa() << "\n";

		}
		return pStrm;
	}

	/// Precondition:there must be elements in the object 
	/// Postcondition: will return the last element added 
	void backOfVector()
	{
		cout << "[" << mMyVector.size() - 1 << "] " << mMyVector.back() << endl;
	}

	/// Precondition:the object must be initialized and the value must be a student object
	/// Postcondition: will add the student object to the end of the vector 
	void pushBackToVector(Student pValue)
	{
		mMyVector.push_back(pValue);
	}

	/// Precondition: there must be a student object in the given index
	/// Postcondition: will return the student in the given object
	void indexOfVector(int pIndex)
	{
		cout << "[" << pIndex << "] " << mMyVector.at(pIndex) << endl;
	}

	/// Precondition: there must be students in the vectorDriver object
	/// Postcondition: will output the memory address and the value of the first element using iterator
	void iBegin()
	{
		std::vector<Student>::iterator iter = mMyVector.begin();
		cout << "\nThe iterator referring the first element: " << &iter << "(" << *iter << ")\n";
	}
	
	/// Precondition: there must be students in the vectorDriver object
	/// Postcondition: will output the memory address and the value of the last element using iterator
	void iEnd()
	{
		std::vector<Student>::iterator iter = mMyVector.end();
		cout << "\nThe iterator referring to the past-the-end element:" << &iter << "\n";
	}

	/// Precondition: there must be students in the vectorDriver object
	/// Postcondition: will output the memory address and the value of the elements from begin() to end() using iterator
	void iReturn()
	{
		cout << "\nUsing begin() and end(), the vector contains:\n";
		for (std::vector<Student>::iterator iter = mMyVector.begin(); iter != mMyVector.end(); iter++)
		{
			cout << "\t" << &iter << " (" << *iter << ")\n";
		}
		cout << endl;
	}

	/// Precondition: there must be students in the vectorDriver object
	/// Postcondition: will output the last element using reverse iterator
	void irBegin()
	{
		std::vector<Student>::reverse_iterator iter = mMyVector.rbegin();
		cout << "\nThe reverse iterator pointing to the last element: " << &iter << "(" << *iter << ")\n";
	}

	/// Precondition: there must be students in the vectorDriver object
	/// Postcondition: will output the last element using reverse iterator
	void irEnd()
	{
		std::vector<Student>::reverse_iterator iter = mMyVector.rend();
		cout << "\nThe reverse iterator pointing to the theoretical element preceding the first element in the vector: " << &iter << "\n\n";
	}

	/// Precondition: there must be students in the vectorDriver object
	/// Postcondition: will output the elements in reverse order using reverse iterator
	void irReturn()
	{
		cout << "\nUsing rbegin() and rend(), the vector contains reversed elements:\n";
		for (std::vector<Student>::reverse_iterator iter = mMyVector.rbegin(); iter != mMyVector.rend(); iter++)
		{
			cout << "\t" << &iter << " (" << *iter << ")\n";
		}
		cout << endl;
	}

	/// Precondition: File must exist and the vectorDrvier object must be initialized
	/// Postcondition: will push each student object onto the vectorDriver object using a CSV file
	void readFile()
	{
		Student input;
		fstream inFile = fstream("input.dat", ios::in);
		int count = 0;

		inFile.open("input.dat", ios::in);
		if (!inFile.bad())
		{
			while (!inFile.eof())
			{
				inFile >> input;
				if (input.empty())
				{
					continue;
				}
				else
				{
					mMyVector.push_back(input);
					count++;
				}
			}
			cout << "The vector now has " << count << " elements.\n\n";
			for (int num = 0; num < count; num++) {
				//cout << "[" << num << "] " << pMyVector[num] << endl;
			}
		}
		else
		{
			cout << "The file doesn't exist.\n";
		}
		inFile.close();
	}

	/// Precondition: The vectorDriver object must be initialized
	/// Postcondition: Will insert a student into the vectorDriver object
	void insertEntry()
	{
		vector<Student>::iterator it = mMyVector.begin();
		Student newStudent;

		newStudent.setName();
		newStudent.setLevel();
		newStudent.setGpa();
		mMyVector.insert(it, newStudent);
		cout << "\nThe new element has been inserted after the begin iterator.\n";
	}

	/// Precondition: The vectorDriver object must be initialized
	/// Postcondition: will swap the values with another vector <student> that is initialized
	void swapVector()
	{
		vector <Student> v2;

		cout << "\nvector (v2) is initially empty.\n";
		v2.swap(mMyVector);
		cout << "\nvector (v1) is empty after swapped with vector (v2).\n";
		cout << "\nvector (v2) after swapped with vector (v1).\n";

		for (int i = 0; i < v2.size(); i++)
		{
			cout << "[" << i << "]: " << v2[i] << "\n";
		}
	}

	/// Precondition: there must be students in the vectorDriver object
	/// Postcondition: will sort the vector in alphabetical order by iterator
	void sortVector()
	{
		std::vector<Student>::iterator start_it = mMyVector.begin();
		std::vector<Student>::iterator end_it = mMyVector.end();

		sort(start_it, end_it);
		cout << "\nThe vector has been sorted.\n";
	}

	/// Precondition: there must be students in the vectorDriver object
	/// Postcondition: will erase the first element using iterator
	void eraseFromVector()
	{
		vector<Student>::iterator itt = mMyVector.begin();
		mMyVector.erase(itt);
		cout << "An element after the begin iterator " << &itt << " has been removed.";
	}

	/// Precondition: there must be students in the vectorDriver object
	/// Postcondition: will erase elements by a range of iterators	
	vector<Student>::iterator eraseRangeVector()
	{
		vector<Student>::iterator beg = mMyVector.begin();
		//std::cout << &beg;
		vector<Student>::iterator end = mMyVector.end();
		//std::cout << &end;// << endl;
		
		cout << "All elements starting at begin iterator " << &beg << " and going up to end iterator " << &end << " have been removed." << endl;
		return mMyVector.erase(mMyVector.begin(), mMyVector.end());
	}
};

/// Precondition: vectorDriver must be initialized
/// Postcondition: will return true if there are no elements in the vectorDriver object or false if there is at least one student
bool vectorIsEmptyMethod(VectorDriver pMyVector)
{
	bool empty = false;
	if (pMyVector.getSizeOfVector() == 0)
	{
		cout << "\n\tThere are no student records" << endl;
		return true;
	}
	return false;
}

/// Precondition: there must be students in the vectorDriver object
/// Postcondition: will erase elements by a range of iterators
void eraseVectorRangeMethod(VectorDriver& pMyVector)
{
	if (vectorIsEmptyMethod(pMyVector))
		return;
	pMyVector.eraseRangeVector();
}

/// Precondition: vectorDriver must be initialized and it must have students in the object
/// Postcondition: will erase the first element using iterator
void iterErase(VectorDriver& pMyVector)
{
	if (vectorIsEmptyMethod(pMyVector))
		return;
	pMyVector.eraseFromVector();
}

/// Precondition: vectorDriver must be initialized and have students in the object
/// Postcondition: will output the element in the vectorDriver given relative to the index given by the user
void indexMethod(VectorDriver pMyVector)
{
	if (vectorIsEmptyMethod(pMyVector))
		return;

	int index = inputInteger("Enter the index:(0 -" + to_string(pMyVector.getSizeOfVector() - 1) + "): ", 0, pMyVector.getSizeOfVector() - 1);

	pMyVector.indexOfVector(index);
}

/// Precondition: vectorDriver must be initialized and have students in the object
/// Postcondition: will output the last element of the vectorDriver object
void backMethod(VectorDriver pMyVector)
{
	if (vectorIsEmptyMethod(pMyVector))
		return;
	pMyVector.backOfVector();
}

/// Precondition: vectorDriver must be initialized and have students in the object
/// Postcondition: will output the first element of the vectorDriver object
void frontMethod(VectorDriver& pMyVector)
{
	if (vectorIsEmptyMethod(pMyVector))
		return;

	pMyVector.frontOfVector();
}

/// Precondition: vectorDriver must be initialized and have students in the object
/// Postcondition: will remove the last element of the vectorDriver object and output the elements of the object
void popBackMethod(VectorDriver& pMyVector)
{
	if (vectorIsEmptyMethod(pMyVector))
		return;

	pMyVector.popBackVector();
	cout << pMyVector;
}

/// Precondition: file must exists and must be a CSV format
/// Postcondition: will input the student object fields and place the students in the vectorDriver object
void readFileMethod(VectorDriver& pMyVector)
{
	fstream fstrm = fstream();
	Student temp;
	fstrm.open("input.dat", ios::in);
	while (!fstrm.eof())
	{
		fstrm >> temp;
		if (!temp.empty())
		{
			pMyVector.pushBackToVector(temp);
		}
		if (fstrm.eof())
		{
			break;
		}
	}
	fstrm.close();
	cout << pMyVector;
}

/// Precondition: vectorDriver must be initialized
/// Postcondition: will resize the vectorDriver object by the given size from the user
void resizeMethod(VectorDriver& pMyVector)
{
	pMyVector.resizeVector();
}

/// Precondition: vectorDriver must be initialized
/// Postcondition: will remove all the elements in the vectorDriver object
void clearMethod(VectorDriver& pMyVector)
{
	pMyVector.clearVector();
}

/// Precondition: vectorDriver must be initialized
/// Postcondition: wil reserve the space for the vectorDriver object
void reserveMethod(VectorDriver& pMyVector)
{
	pMyVector.reserveVector();
}

/// Precondition: vectorDriver must be initialized and must have elements
/// Postcondition: will return the first element of the vectorDriver method
void iterBegin(VectorDriver& pMyVector)
{
	if (vectorIsEmptyMethod(pMyVector))
	{
		return;
	}
	pMyVector.iBegin();
}

/// Precondition: vectorDriver must be initialized and must have elements
/// Postcondition: will return the last element of the vectorDriver method
void iterEnd(VectorDriver& pMyVector)
{
	if (vectorIsEmptyMethod(pMyVector))
	{
		return;
	}
	pMyVector.iEnd();
}

/// Precondition: there must be students in the vectorDriver object
/// Postcondition: will output the elements in reverse order using reverse iterator
void iterReturn(VectorDriver& pMyVector)
{
	if (vectorIsEmptyMethod(pMyVector))
	{
		return;
	}
	pMyVector.iReturn();
}

/// Precondition: there must be students in the vectorDriver object
/// Postcondition: will output the last element using reverse iterator
void iterRBegin(VectorDriver& pMyVector)
{
	if (vectorIsEmptyMethod(pMyVector))
	{
		return;
	}
	pMyVector.irBegin();
}

/// Precondition: there must be students in the vectorDriver object
/// Postcondition: will output the last element using reverse iterator
void iterREnd(VectorDriver& pMyVector)
{
	if (vectorIsEmptyMethod(pMyVector))
	{
		return;
	}
	pMyVector.irEnd();
}

/// Precondition: there must be students in the vectorDriver object
/// Postcondition: will output the elements in reverse order using reverse iterator
void iterRReturn(VectorDriver& pMyVector)
{
	if (vectorIsEmptyMethod(pMyVector))
	{
		return;
	}
	pMyVector.irReturn();
}

/// Precondition: The vectorDriver object must be initialized
/// Postcondition: Will insert a student into the vectorDriver object
void iterInsert(VectorDriver& pMyVector)
{
	if (vectorIsEmptyMethod(pMyVector))
	{
		Student newStudent;

		newStudent.setName();
		newStudent.setLevel();
		newStudent.setGpa();
		pMyVector.pushBackToVector(newStudent);
		return;
	}
	pMyVector.insertEntry();
}

/// Precondition: there must be students in the vectorDriver object
/// Postcondition: will swap all the elements with an empty object 
void swapMethod(VectorDriver& pMyVector)
{
	if (vectorIsEmptyMethod(pMyVector))
	{
		return;
	}
	pMyVector.swapVector();

}

/// Precondition: there must be students in the vectorDriver object
/// Postcondition: will sort and output the elements using iterator
void iterSort(VectorDriver& pMyVector)
{
	if (vectorIsEmptyMethod(pMyVector))
	{
		return;
	}
	pMyVector.sortVector();
	cout << pMyVector;
}

/// Precondition: none
/// Postcondition: will display a menu and will return a Char chosen by the user
char vectorMenuOption()
{
	clrScrn();
	std::cout << "\n\tVectors are sequence containers representing arrays that can change in size.";
	header("\n\t1> Vector's member functions");
	string options[] = {"\n\t\tA> clear() - Removes all elements from the vector (which are destroyed)",
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

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
void runVector()
{
	VectorDriver myVector;
	do
	{
		switch (vectorMenuOption())
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
		case 'O':iterErase(myVector); break;
		case 'P':eraseVectorRangeMethod(myVector); break;
		case 'Q':iterInsert(myVector); break;
		case 'R':swapMethod(myVector); break;
		case 'S':iterSort(myVector); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
	} while (true);
}