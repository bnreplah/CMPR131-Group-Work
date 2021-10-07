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
#include <iterator>
#include <string>
#include <fstream>
#include "input.h"
#include "student.h"
#include <cassert>
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
	student& front()
	{
		return listOne.front();

	}

	/// Precondition:
	/// Postcondition:
	const student& front() const
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
	student& back()
	{
		return this->listOne.back();
	}
	
	/// Precondition:
	/// Postcondition:
	const student& back() const
	{
		return this->listOne.back();
	}

	/// Precondition:
	/// Postcondition:
	list<student>::iterator begin()
	{
		return this->listOne.begin();
	}

	void showBegin() {
		list<student>::iterator itt = listOne.begin();
		std::cout << &itt;
	}
	
	void showEnd() {
		list<student>::iterator itt = listOne.end();
		std::cout << &itt;
	}

	void showBegin() const{
		list<student>::const_iterator itt = listOne.cbegin();
		std::cout << &itt;
	}
	
	void showEnd() const{
		list<student>::const_iterator itt = listOne.cend();
		std::cout << &itt;
	}
	void showRbegin() {
		list<student>::reverse_iterator itt = listOne.rbegin();
		std::cout << &itt;
	}
	
	void showRend() {
		list<student>::reverse_iterator itt = listOne.rend();
		std::cout << &itt;
	}

	void showRbegin() const{
		list<student>::const_reverse_iterator itt = listOne.crbegin();
		std::cout << &itt;
	}
	
	void showRend() const{
		list<student>::const_reverse_iterator itt = listOne.crend();
		std::cout << &itt;
	}
	

	/// Precondition:
	/// Postcondition:
	list<student>::iterator end()
	{
		return this->listOne.end();
	}

	// iterator option K here

	/// Precondition:
	/// Postcondition:
	list<student>::reverse_iterator rbegin()
	{
		return this->listOne.rbegin();
	}

	/// Precondition:
	/// Postcondition:
	list<student>::reverse_iterator rend()
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
	list<student>::iterator insert( student& obj)
	{
		return listOne.insert(listOne.begin(), obj);
		
	}


	/// Precondition:
	/// Postcondition:
	void swap()
	{
		list<student> swapList = list<student>();
		listOne.swap(swapList);
		std::cout<< "\nList has been swapped wiht an empty list, swap list new size: " << swapList.size()<< "\n";
	}


	/// Precondition:
	/// Postcondition:
	void sort()
	{
		this->listOne.sort();
	}

	/// Precondition:
	/// Postcondition:
	void displayAll() 
	{
		if (listOne.empty()) {
			std::cout << "\nThe list is empty\n";
			return;
		}//end if

		for (list<student>::iterator itt = listOne.begin(); itt != listOne.end(); ++itt) {
			std::cout << &itt << " "<< *itt << "\n";
		}//end for
		
	}


	/// Precondition:
	/// Postcondition:
	void displayAll_reverse() const
	{
		for (auto itt = ++(listOne.rbegin()); itt != listOne.rend();itt++ ) {
			std::cout << &itt << " " << *itt << "\n";
		}
		//std::cout << *listOne.rbegin() << "\n";
		
	}

	/// Precondition:
	/// Postcondition:
	bool emptyCheck()
	{
		if (listOne.empty())
			cout << "\n\t\tThe list is empty.";
		return listOne.empty();
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
	
	clrScrn();
	listDriver run = listDriver();
	std::cout << "\nChecking that the file is empty and displaying it's contents:\n ";
	run.displayAll();
	std::cout << "\n============================               reading file - front                    =======================\n ";
	run.readFrontNPopulate("input.dat");
	std::cout << "\n============================            Display in reverse                 =======================\n ";
	run.displayAll_reverse();
	std::cout << "\n============================                resize to 5                    =======================\n ";
	run.resize(5);
	std::cout << "\n============================                    sort                       =======================\n ";
	run.sort();
	std::cout << "\n============================				   Display                     =======================\n ";
	run.displayAll();
	std::cout << "\n============================                   pop_back                 =======================\n ";
	run.pop_back();
	std::cout << "\n============================				   Display                     =======================\n ";
	run.displayAll();
	std::cout << "\n============================                   pop_front                 =======================\n ";
	run.pop_front();
	std::cout << "\n";
	std::cout << "\n============================				   Display                     =======================\n ";
	run.displayAll();
	std::cout << "\n============================               reading file - back                   =======================\n ";
	run.readBackNPopulate("input.dat");
	std::cout << "\n============================				   Display                     =======================\n ";
	run.displayAll();
	std::cout << "\nfront:" << run.front() << "\n";
	std::cout << "\n============================				   Display                     =======================\n ";
	run.displayAll();
	std::cout << "\nback:" << run.back() << "\n";
	std::cout << "\nbegin: "; run.showBegin(); std::cout << "\n";
	std::cout << "\nend: "; run.showEnd(); std::cout << "\n";
	std::cout << "\nrbegin: "; run.showRbegin(); std::cout << "\n";
	std::cout << "\nrend: "; run.showRend(); std::cout << "\n";
	std::cout << "\n============================				   erase                     =======================\n ";
	run.erase(++(run.begin()));
	std::cout << "\n============================				   Display                     =======================\n ";
	run.displayAll();
	std::cout << "\n============================				   erase(start,finsih)                     =======================\n ";
	run.erase(run.begin(), run.end());
	std::cout << "\n============================				   Display                     =======================\n ";
	run.displayAll();
	std::cout << "\n============================               reading file - back                   =======================\n ";
	run.readBackNPopulate("input.dat");
	std::cout << "\n============================				   Display                     =======================\n ";
	run.displayAll();
	std::cout << "\n============================				   clear                     =======================\n ";
	run.clear();
	std::cout << "\n============================				   Display                     =======================\n ";
	run.displayAll();
	std::cout << "\n============================				   insert                     =======================\n ";
	student temp = student("john", 1, 2.0);
	run.insert(temp);
	run.insert(temp);
	run.displayAll();

}