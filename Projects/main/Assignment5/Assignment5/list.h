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
//	
//	10/11/21
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
//#include <cassert>
using namespace std;//remove this before integration and replace with the std:: prefix instead ( bad habit to use using statements inside header files )

//[int CLASS MOVED TO HEADER FILE TO BE USED BOTH BY THE VECTOR AND LIST PARTS]

/*
*	Class : listDriver
*/
class listDriver
{
private:
	list<int> listOne = list<int>();

	const bool DEBUG = true;
public:
	// [CONSTRUCTORS]
	//////////////////////
	
	listDriver() {}

	// member functions
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//////////////////////

	//######################################################################################
	// Mutators
	//######################################################################################

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
		int temp;
		fstrm.open(pFileName, ios::in);

		if (!fstrm.fail() || !fstrm.is_open())
		{
			while (!fstrm.eof())
			{
				fstrm >> temp;            //reading the int form the file
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
	int& front()
	{
		//cout << "\n\tFirst element from the list is (" << listOne.front() << ").";

		return listOne.front();
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
		int temp;
		fstrm.open(pFileName, ios::in);

		if (!fstrm.fail() || !fstrm.is_open())
		{
			while (!fstrm.eof())
			{
				fstrm >> temp;            //reading the int form the file
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
	int& back()
	{
	
		cout << "\n\tLast element from the list is (" << listOne.back() << ").";

		return listOne.back();
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
	list<int>::iterator begin()
	{
		std::list<int>::iterator listIt = listOne.begin();
		cout << "\n\tThe iterator referring the first element: " << &listIt << " (" << *listIt << ")";

		return this->listOne.begin();
	}

	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the begin in a text format
	void showBegin()
	{
		if (emptyCheck())
			return;
		list<int>::iterator itt = listOne.begin();
		std::cout << &itt;
	}
	
	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the end in a text format
	void showEnd()
	{
		if (emptyCheck())
			return;
		list<int>::iterator itt = listOne.end();
		std::cout << &itt;
	}

	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the rbegin in a text format
	void showRbegin()
	{
		if (emptyCheck())
			return;
		list<int>::reverse_iterator itt = listOne.rbegin();
		std::cout << &itt;
	}
	
	
	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the rend in a text format
	void showRend() 
	{
		if (listOne.empty())
			return;
		list<int>::reverse_iterator itt = listOne.rend();
		std::cout << &itt;
	}

	/// Precondition: list initiated
	/// Postcondition: creates an iterator and outputs last elements iterator
	list<int>::iterator end()
	{
		std::list<int>::iterator listIt = listOne.end();
		cout << "\n\tThe iterator referring to the past-the-end element: " << &listIt;

		return this->listOne.end();
	}

	/// Precondition: list initiated
	/// Postcondition: creates a reverse iterator and outputs reverse beginning element and iterator
	list<int>::reverse_iterator rbegin()
	{
		std::list<int>::reverse_iterator iter = listOne.rbegin();
		cout << "\n\tThe iterator referring the reverse first element: " << &iter << "(" << *iter << ").\n";

		return this->listOne.rbegin();
	}

	/// Precondition: list initiated
	/// Postcondition: creates a reverse iterator and outputs reverse last elements iterator
	list<int>::reverse_iterator rend()
	{
		std::list<int>::reverse_iterator iter = listOne.rend();
		cout << "\n\tThe iterator referring to the reverse past-the-end element: " << &iter;

		return this->listOne.rend();
	}

	/// Precondition: it is an itterator to the value to be remove
	/// Postcondition: removes value at position
	void erase(list<int>::iterator it)
	{
		this->listOne.erase(it);
	}

	/// Precondition: pStart itterator is the start of the value to be deleted, end is the end itterator to be deleted exclusive
	/// Postcondition: removes the range
	list<int>::iterator erase(list<int>::const_iterator pStart, list<int>::const_iterator end)
	{
		return listOne.erase(pStart, end);
	}

	/// Precondition: int object to be inserterd after the begin 
	/// Postcondition: inserts the int object into the list
	list<int>::iterator insert(int& obj)
	{
		return listOne.insert(listOne.begin(), obj);
	}

	/// Precondition: N/A
	/// Postcondition: insterts a int object in the list
	list<int>::iterator insert()
	{
		int obj = int();
		std::cin >> obj;
		return listOne.insert(listOne.begin(), obj);
		std::cout << "\n\tThe new element has been inserted after the begin itterator\n";
	}

	/// Precondition: n/a
	/// Postcondition: swaps the list with an empty list ( clears the list indirectly )
	void swap()
	{
		list<int> swapList = list<int>();
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

		for (list<int>::iterator itt = listOne.begin(); itt != listOne.end(); ++itt)
		{
			std::cout << &itt << " "<< *itt << "\n";
		}//end for
	}

	
	
	//runs all the tests on the testing module


	//######################################################################################
	// Accessors
	//######################################################################################

	/// Precondition: list initiated
	/// Postcondition: checks if list is empty
	bool emptyCheck()
	{
		if (listOne.empty())
			cout << "\n\t\tThe list is empty.";
		return listOne.empty();
	}

	/// Precondition: list initiated
	/// Postcondition: displays all elements in reverse
	void displayAll_reverse() const
	{
		if (listOne.empty())
		{
			std::cout << "\n\tThe list is empty\n";
			return;
		}//end if

		for (auto itt = ++(listOne.rbegin()); itt != listOne.rend(); itt++)
		{
			std::cout << &itt << " " << *itt << "\n";
		}
		//std::cout << *listOne.rbegin() << "\n";
	}

	/// [const]
	/// Precondition: list initiated
	/// Postcondition: returns first element
	const int& front() const
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


	/// [const]
	/// Precondition: list cannot be empty
	/// Postcondition: outputs back element
	const int& back() const
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


	/// [const]
	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the rbegin in a text format
	void showRbegin() const
	{
		if (listOne.empty())
			return;
		list<int>::const_reverse_iterator itt = listOne.crbegin();
		std::cout << &itt;
	}


	/// [const]
	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the rend in a text format
	void showRend() const
	{
		if (listOne.empty())
			return;
		list<int>::const_reverse_iterator itt = listOne.crend();
		std::cout << &itt;
	}


	/// [const]
	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the begin in a text format
	void showBegin() const
	{
		if (listOne.empty())
			return;
		list<int>::const_iterator itt = listOne.cbegin();
		std::cout << &itt;
	}
	
	/// [const]
	/// Precondition: N/A
	/// Postcondition: returns the address of the end()
	void showEnd() const
	{
		if (listOne.empty())
			return;
		list<int>::const_iterator itt = listOne.cend();
		std::cout << &itt;
	}


};