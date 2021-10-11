#pragma once
#include <iostream>
#include <string>
#include <iterator>



/**
*
*
*
*/
class myBag_Int
{
private:
	int* container = nullptr;
	size_t capacity = size_t(100);
	size_t size = size_t();
	int* next = nullptr;
public:

	myBag_Int() {
		container = new int[capacity];
		next = container;//set pointer to first value in the array
	}
	
	myBag_Int(size_t cap) {
		capacity = cap;
		container = new int[capacity];
	}
	//~myBag() {}

	/// [stub]
	/// Precondition:
	/// Postcondition:
	int search() const { return; }

	void setCapacity(size_t cap) {
		this->capacity = cap;
	}

	size_t getCapacity() const {
		return capacity;
	}

	size_t getSize() const {
		return size;
	}

	/// [stub]
	/// Precondition:
	/// Postcondition:
	void clear() { 
		next = nullptr;
		delete []container;
		container = nullptr;
		container = new int[capacity];
		next = container;
	}

	/// [stub]
	/// Precondition:
	/// Postcondition:
	void insert() {
		/*
		insert code here
		*/

		++next;

	}

	void remove() {

		/*
		insert code here
		*/
		if(next != &(container[0]))
			--next;
	}


	/// [stub]
	/// Precondition:
	/// Postcondition:
	void sort() {}

	/// [stub]
	/// Precondition:
	/// Postcondition:
	void display() {}

};

/// Precondition: N/A
/// Postcondition: displays list main menu
char myBagMenuOption()
{
	string options[] = { "\n\t1> Non-template MyBag of integers",
						"\n\t" + string(100, char(205)) +
						"\n\t\tA> clear",
						"\n\t\tB> insert",
						"\n\t\tC> search",
						"\n\t\tD> remove",
						"\n\t\tE> sort",
						"\n\t\tF> display",
						"\n\t" + string(100 , char(196)) +
						"\n\t\t0> return "
						"\n\t" + string(100, char(205))
	};
	for (string option : options)
		cout << option;

	char optionChar = inputChar("\n\t\toption ", static_cast<string>("abcdef0"));
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
	do
	{
		switch (myBagMenuOption())
		{
		case '0': return; break;
		case 'A':; break;
		case 'B':; break;
		case 'C':; break;
		case 'D':; break;
		case 'E':; break;
		case 'F':; break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
		clrScrn();
	} while (true);
}

