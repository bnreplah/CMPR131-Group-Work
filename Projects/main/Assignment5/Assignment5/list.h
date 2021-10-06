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
	list<student> swapList = list<student>();
	const bool DEBUG = true;
public:
	listDriver() {
		
	}

	void clear() {
		this->listOne.clear();
	}

	/// Precondition:  (int) n must be greater than 0
	/// Postcondition: resizes the allocated amount in the list listOne
	void resize(int n) {
		this->listOne.resize(static_cast<size_t>(n));
	}

	void readNPopulate(string pFileName) {
		
		
		fstream fstrm = fstream(pFileName, ios::in);
		student temp;
		
		// fstrm.open(pFileName, ios::in);
		if (!fstrm.bad()) {
			
			while (!fstrm.eof()) {
				fstrm >> temp;
				if (temp.empty())
					continue;
				else {
					listOne.push_front(temp);
					std::cout << *listOne.cbegin() << "\n";
				}
			}
		}
		else
			std::cout << "The file doesn't exist\n";

		fstrm.close();
	}


	void pop_front() {

	}


	void pop_back() {

	}

	auto begin() {
		return this->listOne.begin();
	}

	auto end() {
		return this->listOne.end();
	}

	auto rbegin() {
		return this->listOne.rbegin();
	}
	
	auto rend() {
		return this->listOne.rend();
	}


	const student back() {
		return this->listOne.back();
	}

	ostream& displayAll(ostream& strm) {

		return strm;
	}
	
	
	ostream& displayAll_reverse(ostream& strm) {

		return strm;
	}

	
	void erase(list<student>::iterator it) {
		
		this->listOne.erase(it);
	}
	
	void erase(list<student>::iterator start, list<student>::iterator end) {
		
		this->listOne.erase(start,end);
	}

	void insert(list<student>::iterator iter, student obj) {
		listOne.insert(iter, obj);
	}


	void swap() {

	}


	void sort() {
		this->listOne.sort();
	}

	//runs all the tests on the testing module
	void testing() {


		std::cout << "begin:       " << *listOne.begin();
		std::cout << "end:         " << *listOne.end();
		std::cout << "const begin: " << *listOne.cbegin();
		std::cout << "const end:   " << *listOne.cend();
		std::cout << "";
		std::cout << "";
		std::cout << "";
		std::cout << ""; 
		std::cout << "";
		std::cout << "";
		std::cout << "";
	}//end testing 

};

char listMenuOption()
{
	string options[] = { "\n\tLists are sequence containers that allow constant time insert and erase operations anywhere within the",
						"\n\tsequence, and iteration in both directions.\n",
						"\n\t" + string(100, char(205)) +
						"\n\t\tA> clear() - Destroys all elements from the list",
						"\n\t\tB> resize(n) - Changes the list so that it contains n elements",
						"\n\t\tC> Read input.dat and push_front(e) - Adds a new element at the front of the list",
						"\n\t\tD> pop_front() - Deletes the first element",
						"\n\t\tE> front() - Accesses the first element",
						"\n\t\tF> Read input.dat and push_back(e) - Adds a new element at the end of the list",
						"\n\t\tG> pop_back() - Delete the last element",
						"\n\t\tH> back() Accesses the last element",
						"\n\t\tI> begin() - Returns an iterator refereing to the first element in the list",
						"\n\t\tJ> end() Returns an iterator referring to the past-the-end element in the list",
						"\n\t\tK> Using iterator begin() and end() returns all elements in the list",
						"\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the list",
						"\n\t\tM> rend() - Returns a reverse iterator pointing to the element preceding the first element",
						"\n\t\t            in the list",
						"\n\t\tN> Using iterator rbegin() and rend() returns all elements in the list",
						"\n\t\tO> erase(it) - Removes from the vector a single element(using an iterator)",
						"\n\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements( using iterators)",
						"\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.",
						"\n\t\tR> swap() - Exchanges the content of the container by another list's content of the same type",
						"\n\t\tS> Sort - Sorts the list.",
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
		case 'S':; break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
	} while (true);
}



void testing() {
	listDriver run = listDriver();
	run.readNPopulate("input.dat");
	
}