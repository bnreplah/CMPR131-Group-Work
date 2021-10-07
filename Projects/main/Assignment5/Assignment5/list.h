// File: List.h
// Team members:
//		 
//
//
//
// Assigned to:
// 
// 
//
//	Reviewed by: [name]					Date: [mm/dd/yy]
//				
//
//

/**
* Description
* 
*/

#pragma once

#include <iostream>
#include <list>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
#include "input.h"
#include "student.h"
using namespace std;//remove this before integration and replace with the std:: prefix instead ( bad habit to use using statements inside header files )

//[STUDENT CLASS MOVED TO HEADER FILE TO BE USED BOTH BY THE VECTOR AND LIST PARTS]

/**
*	Class : listDriver
* 
* 
*/
class listDriver
{
private:
	list<student> listOne = list<student>();
	//list<student> swapList = list<student>();
	const bool DEBUG = true;
public:
	// [CONSTRUCTORS]
	//////////////////////

	listDriver() 
	{
		
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// [MEMBER FUNCTIONS]
	//////////////////////

	/// Precondition:
	/// Postcondition:
	void clear()
	{
		this->listOne.clear();
	}

	/// Precondition:  (int) n must be greater than 0
	/// Postcondition: resizes the allocated amount in the list listOne
	void resize(int n)
	{
		this->listOne.resize(static_cast<size_t>(n));
	}


	/// Precondition:
	/// Postcondition:
	void readFrontNPopulate(string pFileName)
	{

		fstream fstrm = fstream();
		student temp;
		fstrm.open(pFileName, ios::in);

		while (!fstrm.eof()) {
			fstrm >> temp;//reading the student form the file
			if (!temp.empty()) {
				listOne.push_front(temp);
			}
			if (fstrm.eof()) {
				break;
			}


		}
		fstrm.close();
	}

	/// Precondition:
	/// Postcondition:
	void pop_front()
	{
		listOne.pop_front();
	}


	/// Precondition:
	/// Postcondition:
	student front() 
	{
		return listOne.front();

	}
	/// Precondition:
	/// Postcondition:
	student front() const
	{
		return listOne.front();

	}

	/// Precondition:
	/// Postcondition:
	void readBackNPopulate(string pFileName)
	{

		fstream fstrm = fstream();
		student temp;
		fstrm.open(pFileName, ios::in);

		while (!fstrm.eof()) {
			fstrm >> temp;//reading the student form the file
			if (!temp.empty()) {
				listOne.push_back(temp);
			}
			if (fstrm.eof()) {
				break;
			}


		}
		fstrm.close();
	}


	/// Precondition:
	/// Postcondition:
	void pop_back()
	{
		listOne.pop_back();
	}

	/// Precondition:
	/// Postcondition:
	student back()
	{
		return this->listOne.back();
	}
	
	/// Precondition:
	/// Postcondition:
	student back() const
	{
		return this->listOne.back();
	}

	/// Precondition:
	/// Postcondition:
	auto begin()
	{
		return this->listOne.begin();
	}

	/// Precondition:
	/// Postcondition:
	auto end()
	{
		return this->listOne.end();
	}

	// iterator option K here

	/// Precondition:
	/// Postcondition:
	auto rbegin()
	{
		return this->listOne.rbegin();
	}

	/// Precondition:
	/// Postcondition:
	auto rend()
	{
		return this->listOne.rend();
	}

	//  iterator option N here



	/// Precondition:
	/// Postcondition:
	void erase(list<student>::iterator it)
	{
		
		this->listOne.erase(it);
	}

	/// Precondition:
	/// Postcondition:
	void erase(list<student>::iterator start, list<student>::iterator end)
	{
		
		this->listOne.erase(start,end);
	}

	/// Precondition:
	/// Postcondition:
	void insert(list<student>::iterator iter, student obj)
	{
		listOne.insert(iter, obj);
	}


	/// Precondition:
	/// Postcondition:
	void swap(list<student>& pRight)
	{
		listOne.swap(pRight);
	}


	/// Precondition:
	/// Postcondition:
	void sort()
	{
		this->listOne.sort();
	}

	/// Precondition:
	/// Postcondition:
	void displayAll() const
	{
		
		for (auto itt = listOne.begin(); itt != listOne.end(); ++itt) {
			std::cout << *itt << "\n";
		}
		
	}


	/// Precondition:
	/// Postcondition:
	void displayAll_reverse() const
	{
		for (auto itt = ++(listOne.rbegin()); itt != listOne.rend();itt++ ) {
			std::cout << *itt << "\n";
		}
		//std::cout << *listOne.rbegin() << "\n";
		
	}

	/// Precondition:
	/// Postcondition:
	void emptyCheck()
	{
		if (listOne.empty())
			cout << "\n\t\tThe list is empty.";
		else
			return;
	}

	//runs all the tests on the testing module

	
};

/// Precondition:
/// Postcondition:
char listMenuOption()
{
	string options[] = { "\n\tLists are sequence containers that allow constant time insert and erase operations anywhere within the",
						"\n\tsequence, and iteration in both directions.\n",
						"\n\t" + string(100, char(205)) +
						"\n\t\tA> clear() - Destroys all elements from the list",									//done
						"\n\t\tB> resize(n) - Changes the list so that it contains n elements",						//done
						"\n\t\tC> Read input.dat and push_front(e) - Adds a new element at the front of the list",	//done
						"\n\t\tD> pop_front() - Deletes the first element",											//done
						"\n\t\tE> front() - Accesses the first element",											//done
						"\n\t\tF> Read input.dat and push_back(e) - Adds a new element at the end of the list",		//done
						"\n\t\tG> pop_back() - Delete the last element",											//done
						"\n\t\tH> back() Accesses the last element",												//done
						"\n\t\tI> begin() - Returns an iterator refereing to the first element in the list",		//done
						"\n\t\tJ> end() Returns an iterator referring to the past-the-end element in the list",		//done
						"\n\t\tK> Using iterator begin() and end() returns all elements in the list",				//done
						"\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the list",	//done
						"\n\t\tM> rend() - Returns a reverse iterator pointing to the element preceding the first element",
						"\n\t\t            in the list",															//done
						"\n\t\tN> Using iterator rbegin() and rend() returns all elements in the list",				//
						"\n\t\tO> erase(it) - Removes from the vector a single element(using an iterator)",			//done
						"\n\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements( using iterators)",//done
						"\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.",							//done
						"\n\t\tR> swap() - Exchanges the content of the container by another list's content of the same type", //
						"\n\t\tS> Sort - Sorts the list.",															//done
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
// Precondition: N/A 
// Postcondition: main driver
void runLinkedList()
{
	listDriver mainList;

	do
	{
		switch (listMenuOption())
		{
		case '0': return; break;
		case 'A':; break;
		case 'B':; break;
		case 'C':; break;
		case 'D':; break;
		case 'E':; break;
		case 'F':; break;
		case 'G':; break;
		case 'H':; break;
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
		case 'S': mainList.sort(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
		clrScrn();
	} while (true);
}



/// Precondition:
/// Postcondition:
void testing() {
	listDriver run = listDriver();
	run.readFrontNPopulate("input.dat");
	run.displayAll_reverse();
	run.resize(5);
	run.sort();
	run.displayAll();
	run.pop_back();
	std::cout << "\n";
	run.displayAll();
	
	run.pop_front();
	std::cout << "\n";
	run.displayAll();
}