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

/*  [Description]
*	List.h Formal Description and Use
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
#include <list>
#include <cstdlib>
#include <iomanip>
#include <iterator>
#include <string>
#include <fstream>
#include "input.h"
#include "Student.h"
//#include <cassert>
using namespace std;//remove this before integration and replace with the std:: prefix instead ( bad habit to use using statements inside header files )

//[STUDENT CLASS MOVED TO HEADER FILE TO BE USED BOTH BY THE VECTOR AND LIST PARTS]

/* [Class Invarient]
*	Class : ListDriver
*	Private Member Variables:
* 
* 
*	Public Member Variables:
* 
* 
*/
class ListDriver
{
private:

	list<Student> mListOne = list<Student>();

	const bool mDEBUG = true;

public:

	//######################################################################################
	// Constructors
	//######################################################################################

	/// [Default Constructor]
	/// Precondition: N/A
	/// Postcondition: initializes default list
	ListDriver() {}

	//######################################################################################
	// Accessors
	//######################################################################################

	//[const]
	/// Precondition: list initiated
	/// Postcondition: checks if list is empty
	bool emptyCheck() const
	{
		if (mListOne.empty())
			cout << "\n\t\tThe list is empty.";
		return mListOne.empty();
	}

	/// [const]
	/// Precondition:
	/// Postcondition:returns the first element of the list in a text format
	void showFront() const
	{
		if (emptyCheck())
			return;
		std::cout << "\n\tFirst element of the list is (" << mListOne.front() << ")\n";
	}

	/// [const]
	/// Precondition: list cannot be empty
	/// Postcondition: returns the last element of the list in a text format to the standard output
	void showBack() const
	{
		if (emptyCheck())
			return;
		std::cout << "\n\tLast element of the list is ( " << mListOne.back() << ")\n";
	}

	/// [const]
	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the crbegin in a text format to the standard output
	void showRbegin() const
	{
		if (emptyCheck())
			return;
		list<Student>::const_reverse_iterator itt = mListOne.crbegin();
		cout << "\n\tThe reverse iterator referring to last element of the list: " << &itt << " ( " << *itt << ")\n";
	}

	/// [const]
	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the crend in a text format to the standard output
	void showRend() const
	{
		if (emptyCheck())
			return;
		list<Student>::const_reverse_iterator listIt = mListOne.crend();
		cout << "\n\tThe reverse iterator referring to the reverse past-the-front element: " << &listIt;
	}

	/// [const]
	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the cbegin in a text format
	void showBegin() const
	{
		if (emptyCheck())
			return;
		list<Student>::const_iterator itt = mListOne.cbegin();
		cout << "\n\tThe iterator referring to first element of the list: " << &itt << " ( " << *itt << ")\n";
	}

	/// [const]
	/// Precondition: N/A
	/// Postcondition: returns the address of the cend()
	void showEnd() const
	{
		if (emptyCheck())
			return;
		list<Student>::const_iterator itt = mListOne.cend();
		cout << "\n\tThe iterator referring to the  past-the-end element: " << &itt;
	}

	//######################################################################################
	// Mutators
	//######################################################################################

	//[mutator]
	/// Precondition: list initiated
	/// Postcondition: list is cleared
	void clear()
	{
		this->mListOne.clear();
		cout << "\n\tThe list has been cleared.";
	}

	//[mutator]
	/// Precondition: (int) n must be greater than 0 and less that 100
	/// Postcondition: resizes the allocated amount in the list listOne
	void resize()
	{
		int nSize = inputInteger("\n\tEnter the new size(1...100): ", 1, 100);
		this->mListOne.resize(static_cast<size_t>(nSize));
		cout << "\n\tThe list has been resized to " << mListOne.size() << " elements.";
	}

	//[mutator]
	/// Precondition: input.dat in project folder
	/// Postcondition: read file using push_front
	void readFrontNPopulate()
	{
		string pFileName = "input.dat";
		fstream fstrm = fstream();
		Student temp;
		fstrm.open(pFileName, ios::in);

		if (!fstrm.fail() || !fstrm.is_open())
		{
			while (!fstrm.eof())
			{
				fstrm >> temp;            //reading the student form the file
				if (!temp.empty())
				{
					mListOne.push_front(temp);
				}
				if (fstrm.eof())
				{
					break;
				}
			}
			std::cout << "\n\tThe list now has " << mListOne.size() << " elements\n";
		}//end if
		else
		{
			std::cout << "\n\n\tFailed to read input.dat\n";
		}
		fstrm.close();
	}

	//[mutator]
	/// Precondition: list initiated
	/// Postcondition: front element removed
	void pop_front()
	{
		if (emptyCheck())
			return;

		cout << "\n\tFirst element, (" << mListOne.front() << "), has been removed from the list.";
		mListOne.pop_front();
		std::cout << "\n\tThe list now has " << mListOne.size() << " elements\n";
		displayAll();
	}

	//[mutator]
	/// Precondition: list cannot be empty
	/// Postcondition: returns the first element of the list in a text format
	void showFront()
	{
		if (emptyCheck())
			return;
		std::cout << "\n\tFirst element of the list is (" << mListOne.front() << ")\n";
	}

	//[mutator]
	/// Precondition: input.dat in project folder
	/// Postcondition: read file using push_back
	void readBackNPopulate()
	{
		string pFileName = "input.dat";
		fstream fstrm = fstream();
		Student temp;
		fstrm.open(pFileName, ios::in);

		if (!fstrm.fail() || !fstrm.is_open())
		{
			while (!fstrm.eof())
			{
				fstrm >> temp;            //reading the student form the file
				if (!temp.empty())
				{
					mListOne.push_back(temp);
				}
				if (fstrm.eof())
				{
					break;
				}
			}
			std::cout << "\n\tThe list now has " << mListOne.size() << " elements\n";
		}//end if
		else
		{
			std::cout << "\n\tFailed to read input.dat\n";
		}
		fstrm.close();
	}

	//[mutator]
	/// Precondition: list cannot be empty
	/// Postcondition: back element removed
	void pop_back()
	{
		if (emptyCheck())
			return;

		std::cout << "\n\tLast element, ( " << mListOne.back() << ")\n";
		mListOne.pop_back();
		std::cout << "\n\tThe list now has " << mListOne.size() << " elements\n";
		displayAll();
	}

	//[mutator]
	/// Precondition: list cannot be empty
	/// Postcondition: returns the last element of the list in a text format
	void showBack()
	{
		if (emptyCheck())
			return;
		std::cout << "\n\tLast element of the list is ( " << mListOne.back() << ")\n";
	}

	//[mutator]
	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the begin in a text format
	void showBegin()
	{
		if (emptyCheck())
			return;
		list<Student>::iterator listIt = mListOne.begin();
		cout << "\n\tThe iterator referring the first element: " << &listIt << " (" << *listIt << ")";
	}

	//[mutator]
	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the end in a text format
	void showEnd()
	{
		if (emptyCheck())
			return;
		list<Student>::iterator listIt = mListOne.end();
		cout << "\n\tThe iterator referring to the past-the-end element: " << &listIt;
	}

	//[mutator]
	/// Precondition: list cannot be empty
	/// Postcondition: displays all elements
	void displayAll()
	{
		if (emptyCheck())
			return;

		for (list<Student>::iterator itt = mListOne.begin(); itt != mListOne.end(); ++itt)
		{
			std::cout << &itt << " " << *itt << "\n";
		}//end for
	}

	//[mutator]
	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the rbegin in a text format
	void showRbegin()
	{
		if (emptyCheck())
			return;
		list<Student>::reverse_iterator listIt = mListOne.rbegin();
		cout << "\n\tThe iterator to the last element: " << &listIt << "(" << *listIt << ").\n";
	}

	//[mutator]
	/// Precondition: list cannot be empty
	/// Postcondition: returns the memory location of the rend in a text format
	void showRend()
	{
		if (emptyCheck())
			return;
		list<Student>::reverse_iterator listIt = mListOne.rend();
		cout << "\n\tThe iterator referring to the reverse past-the-end element: " << &listIt;
	}

	//[const]
	/// Precondition: list initiated
	/// Postcondition: displays all elements in reverse
	void displayAll_reverse() const
	{
		if (emptyCheck())
			return;

		for (auto itt = mListOne.rbegin(); itt != mListOne.rend(); itt++)
		{
			std::cout << &itt << " " << *itt << "\n";
		}
		//std::cout << *listOne.rbegin() << "\n";
	}

	//[mutator]
	/// Precondition: list initiated
	/// Postcondition: returns the iterator for the begining position of the list
	list<Student>::iterator begin()
	{
		return this->mListOne.begin();
	}

	//[mutator]
	/// Precondition: list initiated
	/// Postcondition: returns an iterator pointing to the past-the-end element end
	list<Student>::iterator end()
	{
		return this->mListOne.end();
	}

	//[mutator]
	/// Precondition: it is an itterator to the value to be remove
	/// Postcondition: removes value at position
	void erase(list<Student>::iterator pIt)
	{
		this->mListOne.erase(pIt);
	}

	//[mutator]
	/// Precondition: pStart itterator is the start of the value to be deleted, end is the end itterator to be deleted exclusive
	/// Postcondition: removes the range
	list<Student>::iterator erase(list<Student>::const_iterator pStart, list<Student>::const_iterator pEnd)
	{
		return mListOne.erase(pStart, pEnd);
	}

	//[mutator]
	/// Precondition: N/A
	/// Postcondition: insterts a student object in the list
	list<Student>::iterator insert()
	{
		Student obj = Student();
		std::cin >> obj;
		std::cout << "\nThe new element has been inserted after the begin itterator\n";
		return mListOne.insert(mListOne.begin(), obj);
	}

	//[mutator]
	/// Precondition: n/a
	/// Postcondition: swaps the list with an empty list ( clears the list indirectly )
	void swap()
	{
		list<Student> swapList = list<Student>();
		mListOne.swap(swapList);
		std::cout << "\n\tList has been swapped wiht an empty list, swap list new size: " << swapList.size() << "\n";
	}

	//[mutator]
	/// Precondition: list cannot be empty
	/// Postcondition: list is sorted alphabetically
	void sort()
	{
		if (emptyCheck())
			return;

		this->mListOne.sort();
		cout << "\n\tSorted list: \n";
		displayAll();
	}

	/// Precondition: list initiated
	/// Postcondition: checks if list is empty
	bool emptyCheck()
	{
		if (mListOne.empty())
			cout << "\n\t\tThe list is empty.";
		return mListOne.empty();
	}
};

/// Precondition: N/A
/// Postcondition: displays list main menu
char listMenuOption()
{
	clrScrn();
	std::cout << "\n\tLists are sequence containers that allow constant time insert and erase operations anywhere within the" <<
		"\n\tsequence, and iteration in both directions.";
	header("\n\t2> List container");
	string options[] = {"\n\t\tA> clear() - Destroys all elements from the list",												//done:	Option_
						"\n\t\tB> resize(n) - Changes the list so that it contains n elements",									//done:	Option_
						"\n\t\tC> Read input.dat and push_front(e) - Adds a new element at the front of the list",				//done:	Option_
						"\n\t\tD> pop_front() - Deletes the first element",														//done:	Option_
						"\n\t\tE> front() - Accesses the first element",														//done:	Option_
						"\n\t\tF> Read input.dat and push_back(e) - Adds a new element at the end of the list",					//done:	Option_
						"\n\t\tG> pop_back() - Delete the last element",														//done:	Option_
						"\n\t\tH> back() Accesses the last element",															//done:	Option_
						"\n\t\tI> begin() - Returns an iterator refereing to the first element in the list",					//done:	Option_
						"\n\t\tJ> end() Returns an iterator referring to the past-the-end element in the list",					//done:	Option_
						"\n\t\tK> Using iterator begin() and end() returns all elements in the list",							//done:	Option_
						"\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the list",				//done:	Option_
						"\n\t\tM> rend() - Returns a reverse iterator pointing to the element preceding the first element",		//done:	Option_
						"\n\t\t            in the list",																		//done:	Option_
						"\n\t\tN> Using iterator rbegin() and rend() returns all elements in the list",							//done:	Option_
						"\n\t\tO> erase(it) - Removes from the vector a single element(using an iterator)",						//done:	Option_
						"\n\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements( using iterators)",		//done:	Option_
						"\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.",										//done:	Option_
						"\n\t\tR> swap() - Exchanges the content of the container by another list's content of the same type",  //done:	Option_
						"\n\t\tS> Sort - Sorts the list.",																		//done:	Option_
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
	ListDriver mainList;

	do
	{
		switch (listMenuOption())
		{
		case '0': return; break;
		case 'A': mainList.clear(); break;
		case 'B': mainList.resize(); break;
		case 'C': mainList.readFrontNPopulate(); break;
		case 'D': mainList.pop_front(); break;
		case 'E': mainList.showFront(); break;
		case 'F': mainList.readBackNPopulate(); break;
		case 'G': mainList.pop_back(); break;
		case 'H': mainList.showBack(); break;
		case 'I': mainList.showBegin(); break;
		case 'J': mainList.showEnd(); break;
		case 'K': mainList.displayAll(); break;
		case 'L': mainList.showRbegin(); break;
		case 'M': mainList.showRend(); break;
		case 'N': mainList.displayAll_reverse(); break;
		case 'O':if(!mainList.emptyCheck())mainList.erase(mainList.begin()); break;
		case 'P':if(!mainList.emptyCheck())mainList.erase(mainList.begin(), mainList.end()); break;
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