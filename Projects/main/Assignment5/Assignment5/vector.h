
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
	/// Precondition:
	/// Postcondition:
	vectorDriver()
	{
		myVector.clear();

	}

	/// Precondition:
	/// Postcondition:
	void clearVector()
	{
		myVector.clear();
		cout << "The vector has been cleared" << endl;
	}

	/// Precondition:
	/// Postcondition:
	void reserveVector()
	{
		int reserveInt = inputInteger("Enter the capacity (1-100):", 1, 100);

		myVector.reserve(reserveInt);

		cout << "Vector has been reserved " << reserveInt << " element(s)." << endl;

	}

	/// Precondition:
	/// Postcondition:
	void resizeVector()
	{
		int size = inputInteger("Enter the new size(1-100): ", 1, 100);
		myVector.resize(size);
		cout << "Vector has been resized " << size << " element(s)." << endl;
	}

	/// Precondition:
	/// Postcondition:
	int getSizeOfVector()
	{
		return myVector.size();

	}

	/// Precondition:
	/// Postcondition:
	void popBackVector()
	{

		myVector.pop_back();
	}

	/// Precondition:
	/// Postcondition:
	void frontOfVector()
	{
		cout << "[" << 0 << "] " << myVector.front() << endl;;
	}


	/// Precondition:
	/// Postcondition:
	friend ostream& operator <<(ostream& strm, const vectorDriver& obj)
	{
		for (int i = 0; i < obj.myVector.size(); i++)
		{
			strm << "[" << i << "]: " << obj.myVector.at(i).getName() << ", " << obj.myVector.at(i).getLevel() << ", " << obj.myVector.at(i).getGpa() << endl;

		}
		return strm;
	}
	
	/// Precondition:
	/// Postcondition:
	void backOfVector()
	{
		cout << "[" << myVector.size() - 1 << "] " << myVector.back() << endl;
	}

	/// Precondition:
	/// Postcondition:
	void indexOfVector(int index)
	{
		cout << "[" << index << "] " << myVector.at(index) << endl;

	}
};

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
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

/// Precondition:
/// Postcondition:
void indexMethod(vectorDriver myVector)
{
	if (vectorIsEmptyMethod(myVector))
		return;

	int index = inputInteger("Enter the index:(0 -" + to_string(myVector.getSizeOfVector() - 1) + "): ", 0, myVector.getSizeOfVector() - 1);

	myVector.indexOfVector(index);
}

/// Precondition:
/// Postcondition:
void backMethod(vectorDriver myVector)
{
	if (vectorIsEmptyMethod(myVector))
		return;

	myVector.backOfVector();
}

/// Precondition:
/// Postcondition:
void frontMethod(vectorDriver& myVector)
{
	if (vectorIsEmptyMethod(myVector))
		return;

	myVector.frontOfVector();
}

/// Precondition:
/// Postcondition:
void popBackMethod(vectorDriver& myVector)
{
	if (vectorIsEmptyMethod(myVector))
		return;


	myVector.popBackVector();
	cout << myVector;
}

/// Precondition:
/// Postcondition:
void readFileMethod(vectorDriver& myVector)
{
	string input;
	string line;
	fstream inFile;

	inFile.open("input.dat", ios::in);

	//while (inFile >> input)
	//{
	//	getline(inFile, line);
	//
	//	while(getline(s,))

	//
	//}

	cout << myVector;

}

/// Precondition:
/// Postcondition:
void resizeMethod(vectorDriver& myVector)
{
	myVector.resizeVector();

}

/// Precondition:
/// Postcondition:
void clearMethod(vectorDriver& myVector)
{
	myVector.clearVector();


}

/// Precondition:
/// Postcondition:
void reserveMethod(vectorDriver& myVector)
{
	myVector.reserveVector();

}

/// Precondition:
/// Postcondition:
char vectorMenuOption()
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
		case 'I':; break;
		case 'J':; break;
		case 'K':; break;
		case 'L':; break;
		case 'M':; break;
		case 'N':; break;
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