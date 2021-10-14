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
#include <list>
#include <iterator>
#include "input.h"

using namespace std;

/**[templateMyBag class invariant]
* *   2) Create a template class called MyBag (same name) for dynamic array of double. The class is based from step #1.
*/

template<class T>
class myBag
{
private:

	list<T>* container = nullptr;													//initiates the list pointer to nullptr
	size_t capacity = size_t(100);													//holds the maximum size of the bag 
	size_t size = size_t(0);														//holds the current number of nodes in the list
	list<typename>::iterator cursor;														//the itterator pointing to the current position in the bag

public:

	/// [Default Constructor]
	/// Precondition: container is uninitialized
	/// Postcondition: 
	myBag()
	{
		if (container == nullptr)
		{
			container = new list<T>();
			cursor = container->begin();//set pointer to first value in the array
		}//end if
	}//end myBag


	/// [Argument Constructor]
	/// Precondition:  
	/// Postcondition: 
	myBag(size_t cap)
	{
		if (container == nullptr)
		{
			capacity = cap;
			container = new list<T>(cap);
			cursor = container->begin();
		}//end if
	}//end myBag

	/// Precondition:  
	/// Postcondition: 
	//template<class T>
	myBag(myBag<T>& copy)
	{
		this->container = copy.container;
		this->capacity = copy.capacity;
		this->size = copy.size;
		this->cursor = this->container->begin();
	}//end myBag

	/// Precondition:  
	/// Postcondition: 
	//template<class T>
	myBag(const myBag<T>& copy)
	{
		this->container = copy.container;
		this->capacity = copy.capacity;
		this->size = copy.size;
		this->cursor = this->container->begin();
	}//end myBag

	~myBag()
	{
		delete container;
	}

	/// [const]
	/// Precondition: cannot be an empty list  
	/// Postcondition: If nullptr, returns, if found returns pointer, if 
	//template<class T>
	list<typename>::iterator search(int searchValue) const
	{
		//returns if nullptr, might give error

		if (!container->empty())
		{															//if the container is not empty
			for (list<T>iterator itt = this->container->begin(); itt != this->container->end(); ++itt)
			{
				if (*itt == searchValue)
				{
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
	//template<class T>
	void setCapacity(size_t cap)
	{
		this->capacity = cap;
	}//end setCapacity

	/// [const]
	/// Precondition: N/A
	/// Postcondition: Returns the capacity of the list
	//template<class T>
	size_t getCapacity() const
	{
		return capacity;
	}//end getCapacity

	/// Precondition:
	/// Postcondition:
	//template<class T>
	size_t getSize() const
	{
		return size;
	}//end getSize


	/// Precondition: the (list<int>) container exists and is not nullptr 
	/// Postcondition: The list is cleared
	//template<class T>
	void clear()
	{
		if (container != nullptr)
		{
			container->clear();
			cursor = container->begin();
			size = 0;
		}//end if
	}//end clear

	/// Precondition: Inserts (int) value into the bag 
	/// Postcondition:
	//template<class T>
	void insert(T value)
	{
		if (cursor != this->container->end())
			this->container->insert(cursor, value);														//if empty, will insert at the begining, otherwise at current position
		else
		{
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
	//template<class T>
	void remove()
	{
		if (this->size == 1)
		{																		//if only one value
			clear();
		}
		else if (this->size == 0)
		{
			return;
		}
		else
		{//else size > 1
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
	//template<class T>
	void next()
	{
		if (cursor != this->container->end())
		{
			++cursor;
			if (cursor == this->container->end())
				cursor = this->container->begin();
		}//end if
		else if (cursor == this->container->end() && this->size != 0)
			cursor = this->container->begin();
		else return;
	}

	//template<class T>
	list<typename>::iterator get()
	{
		if (size != 0)
		{
			next();
			return cursor;
		}
		return this->container->end();
	}

	/// Precondition:
	/// Postcondition:
	//template<class T>
	void sort()
	{
		this->container->sort();
	}

	//template<class T>
	void display()
	{
		std::cout << *this;
	}

	//template<class T>
	void display(list<typename>::iterator disp)
	{
		if (disp != this->container->end())
			std::cout << *disp;
	}

	//template<class T>
	void moveCursor(list<typename>::iterator move)
	{
		this->cursor = move;
	}

	/// Precondition:
	/// Postcondition:
	//template<class T>
	friend ostream& operator << (ostream& strm, const myBag<T>& out)
	{
		int count = int();
		for (iterator itt = out.container->begin(); itt != out.container->end(); ++itt)
		{
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
void runtemplateMyBag()
{
	myBag<int> mainBag = myBag<int>();

	do
	{
		switch (templateMyBagMenuOption())
		{
		case '0': return; break;
		case 'A': mainBag.clear(); break;
		case 'B': mainBag.insert(inputInteger("\nInput a value into the bag: ")); break;
		case 'C': mainBag.search(inputInteger("\nInput a value to search for in the bag: ")); break;
		case 'D': mainBag.remove(); break;
		case 'E': mainBag.sort(); break;
		case 'F': mainBag.display(); break;
		case 'G': mainBag.display(mainBag.get()); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
		clrScrn();
	} while (true);
}


/////////////////////////////////////////
//// FOR CHEATING PURPOSES ONLY
/////////////////////////////////////////
//
//
//
//
//// FILE: bag5.template
//// CLASS implemented: bag (see bag5.h for documentation)
//// NOTE:
////   Since bag is a template class, this file is included in node2.h.
//// INVARIANT for the bag class:
////   1. The items in the bag are stored on a linked list;
////   2. The head pointer of the list is stored in the member variable head_ptr;
////   3. The total number of items in the list is stored in the member variable
////       many_nodes.
//
//#include <cassert>  // Provides assert
//#include <cstdlib>  // Provides NULL, rand
//#include "node2.h"  // Provides node 
//
//namespace main_savitch_6B
//{
//	template <class Item>
//	bag<Item>::bag()
//		// Library facilities used: cstdlib
//	{
//		head_ptr = NULL;
//		many_nodes = 0;
//	}
//
//	template <class Item>
//	bag<Item>::bag(const bag<Item>& source)
//		// Library facilities used: node2.h
//	{
//		node<Item>* tail_ptr;  // Needed for argument of list_copy
//
//		list_copy(source.head_ptr, head_ptr, tail_ptr);
//		many_nodes = source.many_nodes;
//	}
//
//	template <class Item>
//	bag<Item>::~bag()
//		// Library facilities used: node2.h
//	{
//		list_clear(head_ptr);
//		many_nodes = 0;
//	}
//
//	template <class Item>
//	typename bag<Item>::size_type bag<Item>::count(const Item& target) const
//		// Library facilities used: cstdlib, node2.h
//	{
//		size_type answer;
//		const node<Item>* cursor;
//
//		answer = 0;
//		cursor = list_search(head_ptr, target);
//		while (cursor != NULL)
//		{
//			// Each time that cursor is not NULL, we have another occurrence of
//			// target, so we add one to answer, and move cursor to the next
//			// occurrence of the target.
//			++answer;
//			cursor = cursor->link();
//			cursor = list_search(cursor, target);
//		}
//		return answer;
//	}
//
//	template <class Item>
//	typename bag<Item>::size_type bag<Item>::erase(const Item& target)
//		// Library facilities used: cstdlib, node2.h
//	{
//		size_type answer = 0;
//		node<Item>* target_ptr;
//
//		target_ptr = list_search(head_ptr, target);
//		while (target_ptr != NULL)
//		{
//			// Each time that target_ptr is not NULL, we have another occurrence
//		// of target. We remove this target using the same technique that
//		// was used in erase_one.
//			++answer;
//			--many_nodes;
//			target_ptr->set_data(head_ptr->data());
//			target_ptr = target_ptr->link();
//			target_ptr = list_search(target_ptr, target);
//			list_head_remove(head_ptr);
//		}
//		return answer;
//	}
//
//	template <class Item>
//	bool bag<Item>::erase_one(const Item& target)
//		// Library facilities used: cstdlib, node2.h
//	{
//		node<Item>* target_ptr;
//
//		target_ptr = list_search(head_ptr, target);
//		if (target_ptr == NULL)
//			return false; // target isn't in the bag, so no work to do
//		target_ptr->set_data(head_ptr->data());
//		list_head_remove(head_ptr);
//		--many_nodes;
//		return true;
//	}
//
//	template <class Item>
//	Item bag<Item>::grab() const
//		// Library facilities used: cassert, cstdlib, node2.h
//	{
//		size_type i;
//		const node<Item>* cursor;
//
//		assert(size() > 0);
//		i = (std::rand() % size()) + 1;
//		cursor = list_locate(head_ptr, i);
//		return cursor->data();
//	}
//
//	template <class Item>
//	void bag<Item>::insert(const Item& entry)
//		// Library facilities used: node2.h
//	{
//		list_head_insert(head_ptr, entry);
//		++many_nodes;
//	}
//
//	template <class Item>
//	void bag<Item>::operator +=(const bag<Item>& addend)
//		// Library facilities used: node2.h
//	{
//		node<Item>* copy_head_ptr;
//		node<Item>* copy_tail_ptr;
//
//		if (addend.many_nodes > 0)
//		{
//			list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);
//			copy_tail_ptr->set_link(head_ptr);
//			head_ptr = copy_head_ptr;
//			many_nodes += addend.many_nodes;
//		}
//	}
//
//	template <class Item>
//	void bag<Item>::operator =(const bag<Item>& source)
//		// Library facilities used: node2.h
//	{
//		node<Item>* tail_ptr; // Needed for argument to list_copy
//
//		if (this == &source)
//			return;
//
//		list_clear(head_ptr);
//		many_nodes = 0;
//
//		list_copy(source.head_ptr, head_ptr, tail_ptr);
//		many_nodes = source.many_nodes;
//	}
//
//	template <class Item>
//	bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2)
//	{
//		bag<Item> answer;
//
//		answer += b1;
//		answer += b2;
//		return answer;
//	}
//
//}