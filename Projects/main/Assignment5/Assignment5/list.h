// File: List.h
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
// Assigned to:
//		Thien, Itz, Ben
//	Reviewed by: [name]					Date: [mm/dd/yy]
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
//#include <cassert>
using namespace std;//remove this before integration and replace with the std:: prefix instead ( bad habit to use using statements inside header files )

//[STUDENT CLASS MOVED TO HEADER FILE TO BE USED BOTH BY THE VECTOR AND LIST PARTS]

/*
*	Class : listDriver
*/
class listDriver
{
private:
	list<student> listOne = list<student>();

	const bool DEBUG = true;
public:
	// [CONSTRUCTORS]
	//////////////////////
	
	listDriver() 
	{
		
	}

	// member functions
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//////////////////////

	/// Precondition: list initiated
	/// Postcondition: list is cleared
	void clear()
	{
		this->listOne.clear();
		cout << "\n\tThe list has been cleared.";
	}

	/// Precondition:  (int) n must be greater than 0 and less that 100
	/// Postcondition: resizes the allocated amount in the list listOne
	void resize()
	{
		int nSize = inputInteger("\n\tEnter the new size(1...100): ", 1, 100);
		this->listOne.resize(static_cast<size_t>(nSize));
		cout << "\n\tThe list has been resized to " << listOne.size() << " elements.";
	}

	/// Precondition: input.dat in project folder
	/// Postcondition: read file using push_front
	void readFrontNPopulate()
	{
		string pFileName = "input.dat";
		fstream fstrm = fstream();
		student temp;
		fstrm.open(pFileName, ios::in);

		if (!fstrm.fail() || !fstrm.is_open())
		{
			while (!fstrm.eof())
			{
				fstrm >> temp;            //reading the student form the file
				if (!temp.empty())
				{
					listOne.push_front(temp);
				}
				if (fstrm.eof())
				{
					break;
				}
			}
			std::cout << "\n\tThe list now has " << listOne.size() << " elements\n";
		}//end if
		else
		{
			std::cout << "\n\n\tFailed to read input.dat\n";
		}
		fstrm.close();
	}
	
	/// Precondition: list initiated
	/// Postcondition: front element removed
	void pop_front()
	{
		if (emptyCheck())
			return;

		cout << "\n\tFirst element, (" << listOne.front() << "), has been removed from the list.";
		cout << "\n\n\t";
		listOne.pop_front();
		displayAll();
	}

	/// Precondition: list initiated
	/// Postcondition: outputs first element
	student& front()
	{
		cout << "\n\tFirst element from the list is (" << listOne.front() << ").";

		return listOne.front();
	}

	/// [const]
	/// Precondition: list initiated
	/// Postcondition: returns first element
	const student& front() const
	{
		return listOne.front();
	}

	/// [const]
	/// Precondition:
	/// Postcondition:returns the first element of the list in a text format
	void showFront() const
	{
		if (listOne.empty())
			return;
		std::cout << "\n\tFirst element of the list is (" << listOne.front() << ")\n";
	}
	
	/// Precondition: list cannot be empty
	/// Postcondition: returns the first element of the list in a text format
	void showFront()
	{
		if (emptyCheck())
			return;
		std::cout << "\n\tFirst element of the list is (" << listOne.front() << ")\n";
	}

	/// Precondition: input.dat in project folder
	/// Postcondition: read file using push_back
	void readBackNPopulate()
	{
		string pFileName = "input.dat";
		fstream fstrm = fstream();
		student temp;
		fstrm.open(pFileName, ios::in);

		if (!fstrm.fail() || !fstrm.is_open())
		{
			while (!fstrm.eof())
			{
				fstrm >> temp;            //reading the student form the file
				if (!temp.empty())
				{
					listOne.push_back(temp);
				}
				if (fstrm.eof())
				{
					break;
				}
			}
			std::cout << "\n\tThe list now has " << listOne.size() << " elements\n";
		}//end if
		else
		{
			std::cout << "\n\tFailed to read input.dat\n";
		}
		fstrm.close();
	}

	/// Precondition: list cannot be empty
	/// Postcondition: back element removed
	void pop_back()
	{
		if (emptyCheck())
			return;

		std::cout << "\n\tLast element, ( " << listOne.back() << ")\n";
		listOne.pop_back();
		std::cout << "\n\tThe list now has " << listOne.size() << " elements\n";
		displayAll();
	}

	/// Precondition: list cannot be empty
	/// Postcondition: outputs back element
	student& back()
	{
	
		cout << "\n\tLast element from the list is (" << listOne.back() << ").";

		return listOne.back();
	}
	
	/// [const]
	/// Precondition: list cannot be empty
	/// Postcondition: outputs back element
	const student& back() const
	{
		return this->listOne.back();
	}

	/// [const]
	/// Precondition: list cannot be empty
	/// Postcondition: returns the last element of the list in a text format
	void showBack() const
	{
		if (listOne.empty())
			return;
		std::cout << "\n\tLast element of the list is ( " << listOne.back() << ")\n";
	}

	/// Precondition: list cannot be empty
	/// Postcondition: returns the last element of the list in a text format
	void showBack()
	{
		if (emptyCheck())
			return;
		std::cout << "\n\tLast element of the list is ( " << listOne.back() << ")\n";
	}

	/// Precondition: list initiated
	/// Postcondition: creates an iterator and outputs beginning element and iterator
	list<student>::iterator begin()
	{
		std::list<student>::iterator listIt = listOne.begin();
		cout << "\n\tThe iterator referring the first element: " << &listIt << " (" << *listIt << ")";

		return this->listOne.begin();
	}

	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the begin in a text format
	void showBegin()
	{
		if (emptyCheck())
			return;
		list<student>::iterator itt = listOne.begin();
		std::cout << &itt;
	}
	
	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the end in a text format
	void showEnd()
	{
		if (emptyCheck())
			return;
		list<student>::iterator itt = listOne.end();
		std::cout << &itt;
	}

	/// [const]
	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the begin in a text format
	void showBegin() const
	{
		if (listOne.empty())
			return;
		list<student>::const_iterator itt = listOne.cbegin();
		std::cout << &itt;
	}
	
	/// Precondition: N/A
	/// Postcondition: returns the address of the end()
	void showEnd() const
	{
		if (listOne.empty())
			return;
		list<student>::const_iterator itt = listOne.cend();
		std::cout << &itt;
	}

	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the rbegin in a text format
	void showRbegin()
	{
		if (emptyCheck())
			return;
		list<student>::reverse_iterator itt = listOne.rbegin();
		std::cout << &itt;
	}
	
	
	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the rend in a text format
	void showRend() 
	{
		if (listOne.empty())
			return;
		list<student>::reverse_iterator itt = listOne.rend();
		std::cout << &itt;
	}

	/// [const]
	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the rbegin in a text format
	void showRbegin() const
	{
		if (listOne.empty())
			return;
		list<student>::const_reverse_iterator itt = listOne.crbegin();
		std::cout << &itt;
	}
	

	/// [const]
	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the rend in a text format
	void showRend() const
	{
		if (listOne.empty())
			return;
		list<student>::const_reverse_iterator itt = listOne.crend();
		std::cout << &itt;
	}
	
	/// Precondition: list initiated
	/// Postcondition: creates an iterator and outputs last elements iterator
	list<student>::iterator end()
	{
		std::list<student>::iterator listIt = listOne.end();
		cout << "\n\tThe iterator referring to the past-the-end element: " << &listIt;

		return this->listOne.end();
	}

	/// Precondition: list initiated
	/// Postcondition: creates a reverse iterator and outputs reverse beginning element and iterator
	list<student>::reverse_iterator rbegin()
	{
		std::list<student>::reverse_iterator iter = listOne.rbegin();
		cout << "\n\tThe iterator referring the reverse first element: " << &iter << "(" << *iter << ").\n";

		return this->listOne.rbegin();
	}

	/// Precondition: list initiated
	/// Postcondition: creates a reverse iterator and outputs reverse last elements iterator
	list<student>::reverse_iterator rend()
	{
		std::list<student>::reverse_iterator iter = listOne.rend();
		cout << "\n\tThe iterator referring to the reverse past-the-end element: " << &iter;

		return this->listOne.rend();
	}

	/// Precondition: it is an itterator to the value to be remove
	/// Postcondition: removes value at position
	void erase(list<student>::iterator it)
	{
		this->listOne.erase(it);
	}

	/// Precondition: pStart itterator is the start of the value to be deleted, end is the end itterator to be deleted exclusive
	/// Postcondition: removes the range
	list<student>::iterator erase(list<student>::const_iterator pStart, list<student>::const_iterator end)
	{
		return listOne.erase(pStart, end);
	}

	/// Precondition: student object to be inserterd after the begin 
	/// Postcondition: inserts the student object into the list
	list<student>::iterator insert(student& obj)
	{
		return listOne.insert(listOne.begin(), obj);
	}

	/// Precondition: N/A
	/// Postcondition: insterts a student object in the list
	list<student>::iterator insert()
	{
		student obj = student();
		std::cin >> obj;
		return listOne.insert(listOne.begin(), obj);
		std::cout << "\n\tThe new element has been inserted after the begin itterator\n";
	}

	/// Precondition: n/a
	/// Postcondition: swaps the list with an empty list ( clears the list indirectly )
	void swap()
	{
		list<student> swapList = list<student>();
		listOne.swap(swapList);
		std::cout<< "\n\tList has been swapped wiht an empty list, swap list new size: " << swapList.size()<< "\n";
	}

	/// Precondition: list cannot be empty
	/// Postcondition: list is sorted alphabetically
	void sort()
	{
		if (emptyCheck())
			return;

		this->listOne.sort();
		cout << "\n\tSorted list: \n\t";
		displayAll();
	}

	/// Precondition: list cannot be empty
	/// Postcondition: displays all elements
	void displayAll() 
	{
		if (listOne.empty())
		{
			std::cout << "\n\tThe list is empty\n";
			return;
		}//end if

		for (list<student>::iterator itt = listOne.begin(); itt != listOne.end(); ++itt)
		{
			std::cout << &itt << " "<< *itt << "\n";
		}//end for
	}

	/// Precondition: list initiated
	/// Postcondition: displays all elements in reverse
	void displayAll_reverse() const
	{
		for (auto itt = ++(listOne.rbegin()); itt != listOne.rend(); itt++)
		{
			std::cout <<  &itt << " " << *itt << "\n";
		}
		//std::cout << *listOne.rbegin() << "\n";
	}

	/// Precondition: list initiated
	/// Postcondition: checks if list is empty
	bool emptyCheck()
	{
		if (listOne.empty())
			cout << "\n\t\tThe list is empty.";
		return listOne.empty();
	}

	//runs all the tests on the testing module

};

/// Precondition: N/A
/// Postcondition: displays list main menu
char listMenuOption()
{
	string options[] = { "\n\tLists are sequence containers that allow constant time insert and erase operations anywhere within the",
						"\n\tsequence, and iteration in both directions.\n",
						"\n\t" + string(100, char(205)) +
						"\n\t\tA> clear() - Destroys all elements from the list",												//done
						"\n\t\tB> resize(n) - Changes the list so that it contains n elements",									//done
						"\n\t\tC> Read input.dat and push_front(e) - Adds a new element at the front of the list",				//done
						"\n\t\tD> pop_front() - Deletes the first element",														//done
						"\n\t\tE> front() - Accesses the first element",														//done
						"\n\t\tF> Read input.dat and push_back(e) - Adds a new element at the end of the list",					//done
						"\n\t\tG> pop_back() - Delete the last element",														//done
						"\n\t\tH> back() Accesses the last element",															//done
						"\n\t\tI> begin() - Returns an iterator refereing to the first element in the list",					//done
						"\n\t\tJ> end() Returns an iterator referring to the past-the-end element in the list",					//done
						"\n\t\tK> Using iterator begin() and end() returns all elements in the list",							//done
						"\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the list",				//done
						"\n\t\tM> rend() - Returns a reverse iterator pointing to the element preceding the first element",
						"\n\t\t            in the list",																		//done
						"\n\t\tN> Using iterator rbegin() and rend() returns all elements in the list",							//
						"\n\t\tO> erase(it) - Removes from the vector a single element(using an iterator)",						//done
						"\n\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements( using iterators)",		//done
						"\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.",										//done
						"\n\t\tR> swap() - Exchanges the content of the container by another list's content of the same type",  //
						"\n\t\tS> Sort - Sorts the list.",																		//done
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
// Postcondition: main driver, runs selected function
void runLinkedList()
{
	listDriver mainList;

	do
	{
		switch (listMenuOption())
		{
		case '0': return; break;
		case 'A': mainList.clear(); break;
		case 'B': mainList.resize(); break;
		case 'C': mainList.readFrontNPopulate(); break;
		case 'D': mainList.pop_front(); break;
		case 'E': if(!mainList.emptyCheck()) mainList.front(); break;
		case 'F': mainList.readBackNPopulate(); break;
		case 'G': mainList.pop_back(); break;
		case 'H': if (!mainList.emptyCheck())mainList.back(); break;
		case 'I': if (!mainList.emptyCheck())mainList.begin(); break;
		case 'J': if (!mainList.emptyCheck())mainList.end(); break;
		case 'K': mainList.displayAll(); break;
		case 'L': if (!mainList.emptyCheck())mainList.rbegin(); break;
		case 'M': if (!mainList.emptyCheck())mainList.rend(); break;
		case 'N': mainList.displayAll_reverse(); break;
		case 'O': mainList.erase(++(mainList.begin())); break;
		case 'P': mainList.erase(mainList.begin(), mainList.end()); break;
		case 'Q': mainList.insert(); break;
		case 'R': mainList.swap(); break;
		case 'S': mainList.sort(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
		clrScrn();
	} while (true);
}
//
///// Precondition:
///// Postcondition:
//void testing()
//{
//	clrScrn();
//	listDriver run = listDriver();
//	std::cout << "\nChecking that the file is empty and displaying it's contents:\n ";
//	run.displayAll();
//	std::cout << "\n============================             reading file - front              =======================\n ";
//	run.readFrontNPopulate();
//	std::cout << "\n============================              Display in reverse               =======================\n ";
//	run.displayAll_reverse();
//	std::cout << "\n============================                 resize to 5                   =======================\n ";
//	run.resize();
//	std::cout << "\n============================                    sort                       =======================\n ";
//	run.sort();
//	std::cout << "\n============================				   Display                     =======================\n ";
//	run.displayAll();
//	std::cout << "\n============================                   pop_back                    =======================\n ";
//	run.pop_back();
//	std::cout << "\n============================				   Display                     =======================\n ";
//	run.displayAll();
//	std::cout << "\n============================                  pop_front                    =======================\n ";
//	run.pop_front();
//	std::cout << "\n";
//	std::cout << "\n============================				   Display                     =======================\n ";
//	run.displayAll();
//	std::cout << "\n============================              reading file - back              =======================\n ";
//	run.readBackNPopulate();
//	std::cout << "\n============================				   Display                     =======================\n ";
//	run.displayAll();
//	std::cout << "\nfront:" << run.front() << "\n";
//	std::cout << "\n============================				   Display                     =======================\n ";
//	run.displayAll();
//	run.showFront(); std::cout << "\n";
//	run.showBack(); std::cout << "\n";
//	std::cout << "\nThe itterator referring to the firt element: "; run.showBegin(); std::cout << " (" << *run.begin() << " )\n";
//	std::cout << "\nThe iterator referring to the past-the-end element: "; run.showEnd(); std::cout << "\n";
//	std::cout << "\nThe iterator referring the reverse first element: "; run.showRbegin(); std::cout << "( " << *run.rbegin() << " )\n";
//	std::cout << "\nThe iterator referring to the reverse past-the-end element:"; run.showRend(); std::cout << "\n";
//	std::cout << "\n============================				   erase                       =======================\n ";
//	run.erase(++(run.begin()));
//	std::cout << "\n============================				   Display                     =======================\n ";
//	run.displayAll();
//	std::cout << "\n============================			  erase(start,finsih)              =======================\n ";
//	run.erase(run.begin(),run.end());
//	std::cout << "\n============================				   Display                     =======================\n ";
//	run.displayAll();
//	std::cout << "\n============================              reading file - back              =======================\n ";
//	run.readBackNPopulate();
//	std::cout << "\n============================				   Display                     =======================\n ";
//	run.displayAll();
//	std::cout << "\n============================				   clear                       =======================\n ";
//	run.clear();
//	std::cout << "\n============================				   Display                     =======================\n ";
//	run.displayAll();
//	std::cout << "\n============================				   insert                      =======================\n ";
//	student temp = student("john", 1, 2.0);
//	run.insert(temp);
//	run.insert(temp);
//	run.insert();
//	run.swap();
//	if (!run.emptyCheck())run.front();
//	run.displayAll();
//	std::cout << "\n============================               reading file - back             =======================\n ";
//	run.readBackNPopulate();
//	run.insert();
//	std::cout << "\n============================				   Display                     =======================\n ";
//	run.displayAll();
//}