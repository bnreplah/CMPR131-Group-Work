//	File: templateMyBag.h
//	Team Members:
//      Ben Halpern
//      Itz Rodriquez
//      Tony Cheng
//      Jose Chavez
//      Thien Nguyen
//      Jesus Sierra
//	Professor Q
//	CMPR 131
//	Assignment 6
//	10/7/21
//
#pragma once

#include <iostream>

#include "input.h"
#include <list>
using namespace std;

/**[templateMyBag class invariant]
* *   2) Create a template class called MyBag (same name) for dynamic array of double. The class is based from step #1.
*/
template <typename T>
class myBag
{
private:
	
	list<T>* container = nullptr;													//initiates the list poTer to nullptr
	size_t capacity = size_t(100);													//holds the maximum size of the bag 
	size_t size = size_t(0);														//holds the current number of nodes in the list
	typename list<T>::iterator cursor;														//the itterator poTing to the current position in the bag

public:

	/// [Default Constructor]
	/// Precondition: container is uninitialized
	/// Postcondition: 
	myBag() {
		if (container == nullptr) {
			container = new list<T>();
			cursor = container->begin();//set poTer to first value in the array
		}//end if
	}//end myBag


	/// [Argument Constructor]
	/// Precondition:  
	/// Postcondition: 
	myBag(size_t cap) {
		if (container == nullptr) {
			capacity = cap;
			container = new list<T>(cap);
			cursor = container->begin();
		}//end if
	}//end myBag

	/// Precondition:  
	/// Postcondition: 
	myBag(myBag& copy) {
		this->container = copy.container;
		this->capacity = copy.capacity;
		this->size = copy.size;
		this->cursor = this->container->begin();
	}//end myBag

	/// Precondition:  
	/// Postcondition: 
	myBag(const myBag& copy) {
		this->container = copy.container;
		this->capacity = copy.capacity;
		this->size = copy.size;
		this->cursor = this->container->begin();
	}//end myBag


	~myBag() {
		delete container;
	}

	/// [const]
	/// Precondition: cannot be an empty list  
	/// Postcondition: If nullptr, returns, if found returns poTer, if 
	typename list<T>::iterator search(T searchValue) const {
		//returns if nullptr, might give error

		if (!container->empty()) {															//if the container is not empty
			for (typename list<T>::iterator itt = this->container->begin(); itt != this->container->end(); ++itt) {
				if (*itt == searchValue) {
					std::cout << "\nFound" << *itt;

					return itt;
				}//end if

			}//end for
			std::cout << "\n Value " << searchValue << " not found in my bag";
			return this->container->begin();
		}//end if
		//else
		return this->container->end();																				//might error out since not return type iterator
	}//end search

	/// Precondition: (size_t) cap is a positive Teger that represents the new capacity of the list
	/// Postcondition: sets the capacity of the list
	void setCapacity(size_t cap) {
		this->capacity = cap;
	}//end setCapacity

	/// [const]
	/// Precondition: N/A
	/// Postcondition: Returns the capacity of the list
	size_t getCapacity() const {
		return capacity;
	}//end getCapacity

	/// Precondition:
	/// Postcondition:
	size_t getSize() const {
		return size;
	}//end getSize


	/// Precondition: the (list<T>) container exists and is not nullptr 
	/// Postcondition: The list is cleared
	void clear() {
		if (container != nullptr) {
			container->clear();
			cursor = container->begin();
			size = 0;
		}//end if
	}//end clear

	/// Precondition: Inserts (T) value To the bag 
	/// Postcondition:
	void insert(T value) {
		if (cursor != this->container->end())
			this->container->insert(cursor, value);														//if empty, will insert at the begining, otherwise at current position
		else {
			this->container->insert(this->container->begin(), value);
		}
		if (cursor != this->container->end() && *cursor != this->container->back())														//if the poTer is not at the last value in the list
			++cursor;
		else
			this->next();

		++size;

	}//end insert

	/// Precondition:
	/// Postcondition:
	void remove() {
		if (this->size == 1) {																		//if only one value
			clear();
		}
		else if (this->size == 0) {
			return;
		}
		else {//else size > 1
			if (cursor == this->container->end())
				this->next();
			T temp = *cursor;
			this->next();
			this->container->remove(temp);
			--size;
		}
	}

	/// Precondition:
	/// Postcondition:
	void next() {
		if (cursor != this->container->end()) {
			++cursor;
			if (cursor == this->container->end())
				cursor = this->container->begin();
		}//end if
		else if (cursor == this->container->end() && this->size != 0)
			cursor = this->container->begin();
		else return;
	}

	typename list<T>::iterator get() {
		if (size != 0) {
			next();
			return cursor;
		}
		return this->container->end();
	}

	/// Precondition:
	/// Postcondition:
	void sort() {
		this->container->sort();
	}

	void display() {
		std::cout << *this;
	}

	void display(typename list<T>::iterator disp) {
		if (disp != this->container->end())
			std::cout << *disp;
	}


	void moveCursor(typename list<T>::iterator move) {
		this->cursor = move;
	}

	/// Precondition:
	/// Postcondition:
	friend ostream& operator << (ostream& strm, const myBag& out) {
		T count = T();
		for (typename list<T>::iterator itt = out.container->begin(); itt != out.container->end(); ++itt) {
			strm << "\n\t\t[" << count++ << "]\t---\t" << *itt;
		}//end for

		return strm;

	}

};


/// Precondition: N/A
/// Postcondition: displays list main menu
char templateMyBagMenuOption()
{
	string options[] = { "\n\t2> Template MyBag<double> container",
						"\n\t" + string(100, char(205)) +
						"\n\t\tA> clear",
						"\n\t\tB> insert",
						"\n\t\tC> search",
						"\n\t\tD> remove",
						"\n\t\tE> sort",
						"\n\t\tF> display",
						"\n\t\tG> get",
						"\n\t" + string(100 , char(196)) +
						"\n\t\t0> return "
						"\n\t" + string(100, char(205))
	};
	for (string option : options)
		cout << option;

	char optionChar = inputChar("\n\t\toption ", static_cast<string>("abcdefg0"));
	clrScrn();

	return optionChar;
}

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runtemplateMyBag()
{
	myBag<double> tBag = myBag<double>();
	do
	{
		switch (templateMyBagMenuOption())
		{
		case '0': return; break;
		case 'A': tBag.clear(); break;
		case 'B': tBag.insert(inputDouble("\nInput a double value into the bag: ")); break;
		case 'C': tBag.search(inputDouble("\nInput a double value to search for in the bag: ")); break;
		case 'D': tBag.remove(); break;
		case 'E': tBag.sort(); break;
		case 'F': tBag.display(); break;
		case 'G': tBag.display(tBag.get()); break;
		default: std::cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
		clrScrn();
	} while (true);
}