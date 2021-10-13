#pragma once
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include "input.h"

/**
*
*
*
*/
class myBag_int
{
private:

	list<int>* container = nullptr;													//initiates the list pointer to nullptr
	size_t capacity = size_t(100);													//holds the maximum size of the bag 
	size_t size = size_t(0);														//holds the current number of nodes in the list
	list<int>::iterator cursor;														//the itterator pointing to the current position in the bag

public:

	/// [Default Constructor]
	/// Precondition: container is uninitialized
	/// Postcondition: 
	myBag_int() {
		if (container == nullptr) {
			container = new list<int>();
			cursor = container->begin();//set pointer to first value in the array
		}//end if
	}//end myBag_int
	

	/// [Argument Constructor]
	/// Precondition:  
	/// Postcondition: 
	myBag_int(size_t cap) {
		if (container == nullptr) {
			capacity = cap;
			container = new list<int>(cap);
			cursor = container->begin();
		}//end if
	}//end myBag_int

	/// Precondition:  
	/// Postcondition: 
	myBag_int(myBag_int& copy) {
		this->container = copy.container;
		this->capacity = copy.capacity;
		this->size = copy.size;
		this->cursor = this->container->begin();
	}//end myBag_int

	/// Precondition:  
	/// Postcondition: 
	myBag_int(const myBag_int& copy) {
		this->container = copy.container;
		this->capacity = copy.capacity;
		this->size = copy.size;
		this->cursor = this->container->begin();
	}//end myBag_int


	~myBag_int() {
		delete container;
	}

	/// [const]
	/// Precondition: cannot be an empty list  
	/// Postcondition: If nullptr, returns, if found returns pointer, if 
	list<int>::iterator search(int searchValue) const {
															//returns if nullptr, might give error

		if (!container->empty()) {															//if the container is not empty
			for (list<int>::iterator itt = this->container->begin(); itt != this->container->end() ; ++itt) {
				if (*itt == searchValue) {
					printf("\nFound %i", *itt);
					
					return itt;
				}//end if

			}//end for
			printf("\n Value %i not found in my bag", searchValue);
			return this->container->begin();
		}//end if
		//else
		return this->container->end();																				//might error out since not return type iterator
	}//end search

	/// Precondition: (size_t) cap is a positive integer that represents the new capacity of the list
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

	
	/// Precondition: the (list<int>) container exists and is not nullptr 
	/// Postcondition: The list is cleared
	void clear() { 
		if (container != nullptr) {
			container->clear();
			cursor = container->begin();
			size = 0;
		}//end if
	}//end clear

	/// Precondition: Inserts (int) value into the bag 
	/// Postcondition:
	void insert(int value) {
		if(cursor != this->container->end())
			this->container->insert(cursor, value);														//if empty, will insert at the begining, otherwise at current position
		else {
			this->container->insert(this->container->begin(), value);
		}
		if (cursor != this->container->end() && *cursor != this->container->back())														//if the pointer is not at the last value in the list
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
			int temp = *cursor;
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

	list<int>::iterator get() {
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

	void display(list<int>::iterator disp){
		if(disp != this->container->end())
			std::cout << *disp;
	}


	void moveCursor(list<int>::iterator move) {
		this->cursor = move;
	}

	/// Precondition:
	/// Postcondition:
	friend ostream& operator << (ostream& strm, const myBag_int& out){
		int count = int();
		for (list<int>::iterator itt = out.container->begin(); itt != out.container->end(); ++itt) {
			strm << "\n\t\t["<< count++ <<"]\t---\t"<< *itt;
		}//end for

		return strm;
	
	}

};

/// Precondition: N/A
/// Postcondition: displays list main menu
char myBag_intMenuOption()
{
	std::string options[] = { "\n\t1> Non-template MyBag of integers",
						"\n\t" + std::string(100, char(205)) +
						"\n\t\tA> clear",
						"\n\t\tB> insert",
						"\n\t\tC> search",
						"\n\t\tD> remove",
						"\n\t\tE> sort",
						"\n\t\tF> display",
						"\n\t\tG> get",
						"\n\t" + std::string(100 , char(196)) +
						"\n\t\t0> return "
						"\n\t" + string(100, char(205))
	};
	for (std::string option : options)
		std::cout << option;

	char optionChar = inputChar("\n\t\toption ", static_cast<string>("abcdefg0"));
	clrScrn();

	return optionChar;
}

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runMyBag()
{
	myBag_int intBag = myBag_int();
	do
	{
		switch (myBag_intMenuOption())
		{
		case '0': return; break;
		case 'A': intBag.clear(); break;
		case 'B':intBag.insert(inputInteger("\nInput a value into the bag: ")); break;
		case 'C':intBag.search(inputInteger("\nInput a value to search for in the bag: ")); break;
		case 'D':intBag.remove(); break;
		case 'E':intBag.sort(); break;
		case 'F':intBag.display(); break;
		case 'G':intBag.display(intBag.get()); break;
		default: std::cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		std::cout << "\n";
		pause();
		clrScrn();
	} while (true);
}

