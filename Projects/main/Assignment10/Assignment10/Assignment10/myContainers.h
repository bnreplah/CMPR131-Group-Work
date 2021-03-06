#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
//################################################################################################################################################
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//					StaticStack Template Class
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//################################################################################################################################################



template<class T>
class StaticTStack {
private:
	T* sArray = nullptr;//to hold the array/container
	int stackSize = int();//the size/limited size of the container
	int top = int(); //the index/top of the container, only keeping track of the position
public:
	//constructor
	//default constructor
	StaticTStack(int size);
	//copy constructor

	//destructor
	~StaticTStack() {
		delete[]sArray;
	}

	bool empty() const {
		return top == -1;
	}//end isEmpty()

	bool full() const {
		return top == stackSize - 1;
	}//end isFull()

	//algorithm:
	//  if full Error/return
	//  else{
	//      top++;then stackArray[top] = item;
	//      assigning next element to stackArray
	void push(T element) {
		if (full()) return;
		else sArray[++top] = element;
	}

	T atTop() const {//returns the next element 
		if (empty()) return T(top);
		return sArray[top];
	}

	T pop() {//removes and returns
		if (empty()) return T();

		return sArray[top--];
	}

	friend ostream& operator <<<>(ostream& out, const StaticTStack<T>& obj);


};

template <class T>
ostream& operator <<<>(ostream& out, const StaticTStack<T>& obj) {//recall template friend needs <>
	if (!obj.empty()) {
		for (int i = obj.top; i >= 0; i--) {
			out << *(obj.sArray + i) << '\n';
		}
	}
	return out;
}



template <class T>
StaticTStack<T>::StaticTStack(int size) {
	sArray = new T[size];//defining array style
	stackSize = size;//keep track of size
	top = -1;//cause nothing in yet.
}


template<class T>
class StaticTQueue {
private:
	T* qArray = nullptr;
	int queueSize = int();
	int front = int();
	int rear = int();
	int numItems = int();
public:

	// 
	// Initializes the values to default
	StaticTQueue() {
		qArray = nullptr;
		queueSize = int();
		front = int(-1);
		rear = int(-1);
		numItems = int(0);
	}

	//
	//allocates an array of size int size
	StaticTQueue(int size) {
		qArray = new T[size];
		queueSize = size;
		front = int(-1);
		rear = int(-1);
		numItems = int(0);
	}

	StaticTQueue(const StaticTQueue& obj) {
		qArray = new T[obj.queueSize];

		//copy the attributes
		queueSize = obj.queueSize;
		front = obj.front;
		rear = obj.rear;
		numItems = obj.numItems;

		//copy the values
		for (int i = 0; i < obj.queueSize; i++) {
			qArray[i] = obj.qArray[i];
		}//end for
	}//end copy constructor

	~StaticTQueue() {
		delete[] qArray;
	}//end destructor


	void enqueue(T item) {//inserts item at front
		if (full())
			return;
		//calc new rear
		rear = (rear + 1) % queueSize;

		//cout << "\nRear: " << rear;//debugging

		qArray[rear] = item;
		numItems++;//increment numItems
	}//end enqueue

	T dequeue() {//pulls from the rear value
		if (empty())
			return T();
		front = (front + 1) % queueSize;

		//cout << "\nFront: " << front;//debugging

		numItems--;
		return *(qArray + front);
	}//end dequeue

	void clear() {//clears the array
		front = queueSize - 1;
		rear = queueSize - 1;
		numItems = 0;
	}//end clear


	bool full() const {
		return !(numItems < queueSize);
	}//end full

	bool empty() const {
		return numItems == 0;
	}//end empty

	friend ostream& operator <<<> (ostream& out, const StaticTQueue<T>& obj);



};

template<class T>
ostream& operator <<<>(ostream& out, const StaticTQueue<T>& obj) {//recall template friend needs <>
	if (obj.empty())
		return out;
	for (int i = obj.front, j = obj.numItems; j != 0; j--) {
		i = (i + 1) % obj.queueSize;
		out << "\n" << *(obj.qArray + i);
	}
	return out;
}


//###############################################################################################################################################
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//			ListNode Template Class
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//###############################################################################################################################################



template<class T, class T1>
class ListNode {
public:
	T value = T();
	ListNode<T, T1>* next = nullptr;
	ListNode() {
		value = T();
		next = nullptr;
	}
	ListNode(T nodeValue) {
		value = nodeValue;
		next = nullptr;
	}//end ListNode Constructor

	void operator = (T nValue) {
		value = nValue;
	}

	friend T1;
};



//###############################################################################################################################################
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//				LinkList Template Class
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//###############################################################################################################################################

/// <summary>
/// A template link list class which allows for the storing, sorting, insertion, appending, and display of the objects within the list
/// How to use:
///		<Type T> objects must have:
///			A valid assignment operator
///			A valid copy constructor
///			A valid default no parameter constructor
///			  Valid logical comparison operators
/// Methods:
///		- clear
///		- appendNode
///		- insertNode
///		- deleteNode
///		- print
///		- insertPos
///		- deletePos
///		- reverse
///		
/// </summary>
/// <typeparam name="T"></typeparam>
template <class T>
class LinkTList {
private:
	// Declare a structure for  the list

	ListNode<T, LinkTList<T>>* head = nullptr;
	int size = int();
public:

	/// [Default Constructor]
	LinkTList() {
		head = nullptr;//new ListNode<T, LinkTList<T>>();
		size = 0;
	}//end default constructor

	//Challenge3()
	/// copy constructor
	LinkTList(const LinkTList<T>& obj) {// copy constructor
		head = nullptr; //initialize head to nullptr
		ListNode<T, LinkTList<T>>* nodePtr = nullptr;//nodePtr to tranverse the list
		nodePtr = obj.head;//set the node pointer to beginining of other list

		//while poiting to node traverses list
		while (nodePtr) {
			insertNode(nodePtr->value);//insert into current list
			nodePtr = nodePtr->next;//set the current pointer to the next pointer in the list
		}//end while
		size = obj.size;
	}//end copy constructor

	~LinkTList() {
		ListNode<T, LinkTList<T>>* nodePtr;//to traverse the list
		ListNode<T, LinkTList<T>>* nextNode;//to point to the next node

		nodePtr = head;//position nodePtr at the head of the list

		while (nodePtr != nullptr) {
			nextNode = nodePtr->next;//set next node to nextNode before deleting the nodePtr

			delete nodePtr;//delete the current node

			nodePtr = nextNode;//position the current node to the nextNode
		}//end while
	}//end ~LinkTList

	/// Precondition: N/A
	/// Postcondition: clears the whole list
	void clear() {
		ListNode<T, LinkTList<T>>* nodePtr;//to traverse the list
		ListNode<T, LinkTList<T>>* nextNode;//to point to the next node

		nodePtr = head;//position nodePtr at the head of the list
		head = nullptr;
		while (nodePtr != nullptr) {
			nextNode = nodePtr->next;//set next node to nextNode before deleting the nodePtr

			delete nodePtr;//delete the current node

			nodePtr = nextNode;//position the current node to the nextNode
		}//end while
		this->size = 0;
	}//end clear

	/// Precondition: 
	/// Postcondition: returns the index of the value matching the item to find, otherwise -1 if not found
	int find(T num) const {
		int i = int();
		for (i = 0; i < this->size; i++) {
			if (this->getPos(i) == num)
				return i;
		}//end for
		return -1;

	}//end find


	/// Precondition: T num is an object to be set as the value of the node, must have a valid copy constructor and assignment constructor
	/// Postcondition: the node is added to the end of the list
	void appendNode(T num) {//to end of the list
		ListNode<T, LinkTList<T>>* newNode = nullptr;//to point to the new node to be attached
		ListNode<T, LinkTList<T>>* nodePtr = nullptr;//to move through the list


		newNode = new ListNode<T, LinkTList<T>>();//Allocate a new node 
		newNode->value = num;//store num in the newNode
		newNode->next = nullptr;

		if (!head)//if head points to nullptr/ no other nodes in the list
			head = newNode;

		else {//insert the node at the end of the list

			nodePtr = head;//Initialize nodePtr to head of list

			while (nodePtr->next)//traverse the list
				nodePtr = nodePtr->next;
			nodePtr->next = newNode;//set it at end of the list

		}//end else
		size++;
		newNode = nullptr;
		nodePtr = nullptr;

	}//end appendNode

	/// Precondition: N/A
	/// Postcondition: num is inserted in numerical/lexigraphical ascending order
	void insertNode(T num) {
		ListNode<T, LinkTList<T>>* newNode = nullptr;
		ListNode<T, LinkTList<T>>* nodePtr = nullptr;
		ListNode<T, LinkTList<T>>* previousNode = nullptr;//holds the value of the previous node

		newNode = new ListNode<T, LinkTList<T>>();
		newNode->value = num;
		newNode->next = nullptr;

		if (!head)
			head = newNode;
		else {
			nodePtr = head;//start at begining of list

			while (nodePtr && nodePtr->value < num) {//traverse while value is < num
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}//end while
			//breaks from the loop once the node is empty or the value is >= num

			//insert node
			if (!previousNode) {//loop exited on first itteration
				head = newNode;
				newNode->next = nodePtr;
			}//end if
			else {
				previousNode->next = newNode;//insert new node after previous node
				newNode->next = nodePtr;//set the pointer to the next node in the series.
			}//end else

		}//end else
		size++;
		previousNode = nullptr;
		newNode = nullptr;
		nodePtr = nullptr;
	}//end insert node

	/// Precondition: num should to exist in the linked list
	/// Postcondition: if num exits, deletes the first node found with value num
	void deleteNode(T num) {
		ListNode<T, LinkTList<T>>* nodePtr = nullptr;
		ListNode<T, LinkTList<T>>* previousNode = nullptr;

		if (!head)//if nothing in list return
			return;
		if (head->value == num) {//if the value is the first value
			nodePtr = head->next;//set nodePtr to the next pointer
			delete head;//delete the first node
			head = nodePtr;//set the new head to the next node
		}//end if
		else {
			nodePtr = head;//start from the begining of the list

			while (nodePtr && nodePtr->value != num) {//while nodePtr is not null and nodePtr does not = num traverse the list
				previousNode = nodePtr;//set the previous node to the current node
				nodePtr = nodePtr->next;//set the current node to the next node
			}//end while
			if (nodePtr) {//if nodePtr is not at the end of the list
				previousNode->next = nodePtr->next;//bridge the gap over the to be deleted node
				delete nodePtr;//then delete the node
			}//end if

		}//end else
		size--;
		nodePtr = nullptr;
		previousNode = nullptr;
	}//end deleteNode

	//Challenge2()
	/// Don't use if object cannot be converted to a string through the string() constructor
	/// Precondition: ptr is a ptr of ListNode type and the value in the list must be able to be converted to a string()
	/// Postcondition: prints out the value ptr
	string print(ListNode<T, LinkTList>* ptr) const {

		return string(ptr->value);
	}//end print

	/// Don't use if object cannot be converted to a string through the string() constructor
	/// Precondition: N/A
	/// Postcondition: Prints out all the values of the list
	string print() const {
		string printOut = string();
		ListNode<T, LinkTList<T>>* nodePtr = nullptr;
		nodePtr = head;
		printOut = "{";
		while (nodePtr) {
			printOut += print(nodePtr);
			nodePtr = nodePtr->next;
			if (nodePtr) printOut += ",";
		}//end while
		printOut += " }";
		nodePtr = nullptr;
		return printOut;
	}//end print


	//Challenge6()
	/// Precondition: int pos has to be >= 0
	/// Postcondition: inserts T num at the position pos
	void insertPos(int pos, T num) { //Assignment 7

		ListNode<T, LinkTList<T>>* newNode;
		ListNode<T, LinkTList<T>>* nodePtr;//In order to tranverse the list
		ListNode<T, LinkTList<T>>* previousNode;//for tranversing the list

		newNode = new ListNode<T, LinkTList<T>>();
		newNode->value = num;
		newNode->next = nullptr;

		if (!head) {//if empty return
			head = newNode;
			size++;
			return;
		}

		if (pos == 0) {//position 0 is head
			newNode->next = head;
			head = newNode;//set head to the current node
			size++;
			return;
		}//end if


		//traverse the list
		nodePtr = head;//set at begining of list
		previousNode = nullptr;//initialize
		for (int i = 0; (i < pos); i++) {//loops as long as current position is less than pos and as long as null pointer is in the list
			//cout << "\ncurrent itterator index: " << i;
			//if(nodePtr) cout << "\ncurrent node :" << nodePtr->value;
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			if (!(previousNode->next))
				break;
		}//end for
		//if(nodePtr) cout << "\nExited Node : " << nodePtr->value;
		//unlinkage procedure:
		if (nodePtr) {//if not past end of the list
			newNode->next = nodePtr;
			previousNode->next = newNode;
			size++;
		}//end if 
		else {//if at the end of the list
			previousNode->next = newNode;
			size++;
		}

		previousNode = nullptr;
		newNode = nullptr;
		nodePtr = nullptr;
	}//end insertPos 


	//Challenge7()
	/// Precondition: (size_t) pos is a value holding the position (index) to be removed from the list, the index must be valid, and the list can't be empty 
	/// Postcondition: removes the node at that position from the list
	void deletePos(size_t pos) { //Assignment 7
		if (!head)//if empty return
			return;

		ListNode<T, LinkTList<T>>* nodePtr;//In order to tranverse the list
		ListNode<T, LinkTList<T>>* previousNode;//for tranversing the list

		if (pos == 0) {//position 0 is head
			nodePtr = head->next;//set current node to next node
			delete head;
			head = nodePtr;//set head to the current node
			size--;
			return;
		}//end if


		//traverse the list
		nodePtr = head;//set at begining of list
		previousNode = nullptr;//initialize
		for (int i = 0; (i < pos) && nodePtr->next; i++) {//loops as long as current position is less than pos and as long as null pointer is in the list
			//cout << "\ncurrent itterator index: " << i;
			//cout << "\ncurrent node :" << nodePtr->value;
			previousNode = nodePtr;
			nodePtr = nodePtr->next;

		}//end for
		//cout << "\nExited Node : " << nodePtr->value;
		//unlinkage procedure:
		if (nodePtr) {//making sure nodePtr exists
			previousNode->next = nodePtr->next;
			delete nodePtr;
			size--;
		}//end if 
		//if doesn't exist returns

		nodePtr = nullptr;
		previousNode = nullptr;
	}//end delete pos 

	//Challenge4()
	/// Precondition: Needs atleast 2 nodes
	/// Postcondition: reverses the order 
	void reverse() {
		if (!head || !(head->next))//can't reverse if empty
			return;

		ListNode<T, LinkTList<T>>* tHead = nullptr;
		ListNode<T, LinkTList<T>>* previousNode = nullptr;
		ListNode<T, LinkTList<T>>* nextNode = nullptr;
		ListNode<T, LinkTList<T>>* nodePtr = nullptr;
		nodePtr = head;
		nextNode = head;
		//end initialization

		//first itter
		previousNode = nodePtr;//set the nodePtr to the previous node
		nodePtr = nextNode;//set the nodePtr to the nextNode
		nextNode = nextNode->next;//set the nextNode to the next node in the sequence
		//cout << "\nPN: " << previousNode->value;
		//cout << "\nCN: " << nodePtr->value;
		//if (nextNode) cout << "\nNN: " << nextNode->value;
		tHead = previousNode;//have tHead point to the previousNode
		previousNode->next = nullptr;//dislink the first item from the rest of the link after the proper pointers have been assigned
		//cout << "\ntHead "<<tHead->value;

		while (nextNode) {//while nextNode exists
			previousNode = nodePtr;//set the nodePtr to the previous node
			nodePtr = nextNode;//set the nodePtr to the nextNode
			nextNode = nextNode->next;//set the nextNode to the next node in the sequence
			//cout << "\nPN: " << previousNode->value;
			//cout << "\nCN: " << nodePtr->value;
			//if (nextNode) cout << "\nNN: " << nextNode->value;
			tHead = previousNode;//have tHead point to the previousNode
			nodePtr->next = tHead;//set the current node next pointer to point to the tHead

		}//loops until hits nullptr and no more in the original list
		tHead = nodePtr;//last push back of tHead
		head = tHead;
	}//end reverse


	//Challenge12()
	/// Precondition: size is the size of the array
	///			     T* is a type T pointer to an array
	/// Postcondition: inserts the value of the array into the linked list
	void mergeArray(T* arr, int size) {
		for (int i = 0; i < size; i++) {
			insertNode(*(arr + i));//will insert it in lexigraphical order. relies on insertNode, therefore data type must have logical operands overloaded
		}
	}

	/// Precondition: (size_t) pos must be a valid index of a node in th elist, the list can't be empty, otherwise a blank value is returned 
	/// Postcondition: returns the value at that position
	T getPos(size_t pos) const {
		if (!head)//if empty return
			return T();

		ListNode<T, LinkTList<T>>* nodePtr;//In order to tranverse the list
		ListNode<T, LinkTList<T>>* previousNode;//for tranversing the list

		if (pos == 0) {//position 0 is head
			nodePtr = head->next;//set current node to next node
			return head->value;

		}//end if


		//traverse the list
		nodePtr = head;//set at begining of list
		previousNode = nullptr;//initialize
		for (int i = 0; (i < pos) && nodePtr->next; i++) {//loops as long as current position is less than pos and as long as null pointer is in the list
			//cout << "\ncurrent itterator index: " << i;
			//cout << "\ncurrent node :" << nodePtr->value;
			previousNode = nodePtr;
			nodePtr = nodePtr->next;

		}//end for
		//cout << "\nExited Node : " << nodePtr->value;
		//unlinkage procedure:
		if (nodePtr) {//making sure nodePtr exists
			return nodePtr->value;
		}//end if 
		else if (previousNode)
			return previousNode->value;
		else
			return head->value;
		//if doesn't exist returns

	}//end getPos

	/// Precondition: None
	/// Postcondition: returns the value stored in size
	int getSize() const {
		return this->size;
	}//end getSize

	////possibly try-catch scenario?
	//// still needs to be debugged and tested
	///// Precondition: N/A
	///// Postcondition: returns a summated version of the list
	//T summate() const{
	//	T sum = T();
	//	ListNode<T, LinkTList<T>>* nodePtr = nullptr;//In order to tranverse the list
	//	nodePtr = head;
	//	for(int i = 0; i < size; i++) {
	//		sum += this[]
	//		nodePtr = nodePtr->next;
	//	}//end whle
	//	
	//	nodePtr = nullptr;
	//	return sum;
	//}//end summate

	/// Postcondition: (size_t) pos must be a valid index within the list, and can't be greater than or equal to the size of the list
	/// Precondition: returns a reference to the value at the index pos
	T& operator [](size_t pos) const {


		ListNode<T, LinkTList<T>>* nodePtr = nullptr;//In order to tranverse the list
		ListNode<T, LinkTList<T>>* previousNode = nullptr;//for tranversing the list

		if (pos == 0) {//position 0 is head
			nodePtr = head->next;//set current node to next node
			return head->value;

		}//end if
		else {

			//traverse the list
			nodePtr = head;//set at begining of list
			previousNode = nullptr;//initialize
			for (int i = 0; (i < pos) && nodePtr->next; i++) {//loops as long as current position is less than pos and as long as null pointer is in the list
				//cout << "\ncurrent itterator index: " << i;
				//cout << "\ncurrent node :" << nodePtr->value;
				previousNode = nodePtr;
				nodePtr = nodePtr->next;

			}//end for
			//cout << "\nExited Node : " << nodePtr->value;

			if (nodePtr) {//making sure nodePtr exists
				return nodePtr->value;
			}//end if 
			else if (previousNode)
				return previousNode->value;
			else
				return  head->value;
			//if doesn't exist returns
		}
		nodePtr = nullptr;//sets the values back to nullptr, if the statement reaches since a reference is returned
		previousNode = nullptr;//sets the values back to nullptr, if the statement reaches since a reference is returned


	}


	T& operator [](int pos) {


		ListNode<T, LinkTList<T>>* nodePtr = nullptr;//In order to tranverse the list
		ListNode<T, LinkTList<T>>* previousNode = nullptr;//for tranversing the list

		if (pos == 0) {//position 0 is head
			nodePtr = head->next;//set current node to next node
			return head->value;

		}//end if
		else {

			//traverse the list
			nodePtr = head;//set at begining of list
			previousNode = nullptr;//initialize
			for (int i = 0; (i < pos) && nodePtr->next; i++) {//loops as long as current position is less than pos and as long as null pointer is in the list
				//cout << "\ncurrent itterator index: " << i;
				//cout << "\ncurrent node :" << nodePtr->value;
				previousNode = nodePtr;
				nodePtr = nodePtr->next;

			}//end for
			//cout << "\nExited Node : " << nodePtr->value;

			if (nodePtr) {//making sure nodePtr exists
				return nodePtr->value;
			}//end if 
			else if (previousNode)
				return previousNode->value;
			else
				return head->value;
			//if doesn't exist returns
		}






	}

	/// Precondition: N/A
	/// Postcondition: Returns true if the list is empty, returns false if the list is not empty
	bool empty() {
		if (this->size <= 0)
			return true;
		else if (this->head && this->size > 0)
			return false;
		return true;//returns true if there neither of the conditions are met
	}//end empty

	///// [DEVELOPMENTAL]
	///// Precondition: N/A
	///// Postcondition: returns an itterator pointing to head
	//iterator<ListNode> begin() {
	//	return head;
	//}//end begin()

	///// [DEVELOPMENTAL]
	///// Precondition: the list must not be empty
	///// Postcondition: returns an iterator pointing to the last node in the list
	//iterator<ListNode> end() {
	//	if (this->empty())
	//		return (this->[0]);
	//	else
	//		return (this->[size]);
	//}//end end()

	/// exclusive split
	/// [DEVELOPMENTAL]
	/// Precondition: (T) splitValue must have a valid logical comparison operators and must be a value to split the list
	/// Postcondition: returns a pair of the two resulting lists
	pair<LinkTList<T>, LinkTList<T>> split(T splitValue) const {
		LinkTList<T> lowerHalf = LinkTList<T>();
		LinkTList<T> upperHalf = LinkTList<T>();
		for (int i = 0; i < this->getSize(); i++) {
			if (this->getPos(i) < splitValue)
				lowerHalf.insertNode(this->getPos(i));
			else if (this->getPos(i) > splitValue)
				upperHalf.insertNode(this->getPos(i));
			else//if i == index
				continue;
		}//end for
		return pair<LinkTList<T>, LinkTList<T>>(lowerHalf, upperHalf);

	}//end split




	friend ostream& operator << (ostream& strm, const LinkTList<T>& obj) {
		for (int i = 0; i < obj.getSize(); i++) {
			strm << obj.getPos(i) << "\n";
		}//end for
		return strm;
	}//end <<



};//end class






//###############################################################################################################################################
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//				Dynamic Template Stack
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//###############################################################################################################################################





template<class T>
class DynamicTStack {
private:
	LinkTList<T> dArray;
	int stackSize = int();//the size/limited size of the container
	int top = int(); //the index/top of the container, only keeping track of the position
public:
	//constructor
	//default constructor
	DynamicTStack();

	DynamicTStack(int size);
	//copy constructor

	////destructor
	//~DynamicTStack() {
	//    delete[] dArray;
	//}

	int getSize() const {
		return stackSize;
	}

	bool empty() const {
		return top == -1;

	}//end isEmpty()

	//bool full() const {
	//    return top == stackSize - 1;
	//}//end isFull()

	//algorithm:
	//  if full Error/return
	//  else{
	//      top++;then stackArray[top] = item;
	//      assigning next element to stackArray
	void push(T element) {
		dArray.insertPos(++top, element);
		stackSize++;
	}

	T atTop() const {//returns the next element 
		if (empty()) return T(top);
		return dArray.getPos(top);
	}

	T atPos(int i) const {
		if (!empty())
			return dArray.getPos(i);
		else
			return T(-1);
	}

	T pop() {//removes and returns
		if (empty()) return T(-1);
		T oldValue = dArray.getPos(top);
		dArray.deletePos(top--);
		return oldValue;
	}

	friend ostream& operator <<<>(ostream& out, const DynamicTStack<T>& obj);


};

template <class T>
ostream& operator <<<>(ostream& out, const DynamicTStack<T>& obj) {//recall template friend needs <>
	if (!obj.empty()) {
		for (int i = obj.top; i >= 0; i--) {
			out << obj.dArray.getPos(i) << '\n';
		}
	}
	return out;
}


template <class T>
DynamicTStack<T>::DynamicTStack() {
	stackSize = 0;//keep track of size
	top = -1;//cause nothing in yet.
}

template <class T>
DynamicTStack<T>::DynamicTStack(int size) {
	stackSize = size;//keep track of size
	top = -1;//cause nothing in yet.
}





//###############################################################################################################################################
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//				Dynamic Que Template Class
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//###############################################################################################################################################




template<class T>
class DynamicTQueue {
private:
	LinkTList<T> qArray;
	int queueSize = int();
	//int front = int();
	//int rear = int();
	int numItems = int();
public:

	// 
	// Initializes the values to default
	DynamicTQueue() {
		//queueSize = int();
		//front = int(-1);
		//rear = int(-1);
		numItems = int(0);
	}

	DynamicTQueue(const DynamicTQueue& obj) {


		//copy the attributes       
		numItems = obj.numItems;

		//copy the values
		for (int i = 0; i < obj.numItems; i++) {
			qArray[i] = obj.qArray[i];
		}//end for
	}//end copy constructor


	void enqueue(T item) {//inserts item at front
		qArray.insertPos(numItems, item);//introduce in the rear
		numItems++;//increment numItems
	}//end enqueue

	T dequeue() {//pulls from the rear value
		T value = T();
		if (!empty()) {

			numItems--;
			value = qArray[0];//take value from front
			//cout << "\n" << value;
			qArray.deletePos(0);//delete last position
		}
		return value;
	}//end dequeue

	void clear() {//clears the array

		for (int i = numItems - 1; i >= 0; i--) {//delete the nodes
			qArray.deletePos(i);
		}

		numItems = 0;
	}//end clear


	bool empty() const {
		return numItems == 0;
	}//end empty

	friend ostream& operator <<<> (ostream& out, const DynamicTQueue<T>& obj);

};


template<class T>
ostream& operator <<<> (ostream& out, const DynamicTQueue<T>& obj) {//recall template friend needs <>
	if (obj.empty())
		return out;
	for (int i = 0; i < obj.numItems; i++) {
		out << "\n" << obj.qArray.getPos(i);
	}

	return out;
}

//###############################################################################################################################################
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//				Binary Tree Template Node Class
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//###############################################################################################################################################


/// <summary>
/// TreeNode template structure to be used in the Tree template class
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
class BinaryTreeNode {
private:
	BinaryTreeNode<T>* right_node = nullptr;
	BinaryTreeNode<T>* left_node = nullptr;
	T value = T();
	bool empty = bool(true);
public:
	/// <summary>
	/// Default constructor
	/// </summary>
	BinaryTreeNode() {

	}//end default constructor	


	BinaryTreeNode(T data, bool pEmpty) {
		value = data;
		this->left_node = nullptr;
		this->right_node = nullptr;
		this->empty = pEmpty;
	}//end default constructor


	BinaryTreeNode(T& data) {
		value = data;
		this->left_node = nullptr;
		this->right_node = nullptr;
	}//end default constructor
	BinaryTreeNode(T& data, BinaryTreeNode<T>* left_ptr, BinaryTreeNode<T>* right_ptr) {
		value = data;
		this->left_node = left_ptr;
		this->right_node = right_ptr;
	}//end default const	

	BinaryTreeNode(T data, BinaryTreeNode<T>* left_ptr, BinaryTreeNode<T>* right_ptr) {
		value = data;
		this->left_node = left_ptr;
		this->right_node = right_ptr;
	}//end default const	



	BinaryTreeNode(const BinaryTreeNode<T>* obj) {
		if (obj && obj->empty() != true) {//if object exists and is not null
			this->left_node = obj->left_node;
			this->right_node = obj->right_node;
			this->value = obj->value;
		}

	}

	void setRight(BinaryTreeNode<T>* nodeRight) {
		this->right_node = nodeRight;
		this->empty = false;
	}

	void setLeft(BinaryTreeNode<T>* nodeLeft) {
		this->left_node = nodeLeft;
		this->empty = false;
	}

	BinaryTreeNode<T>* getRight() {
		return right_node;
	}


	BinaryTreeNode<T>* getLeft() {
		return left_node;
	}

	BinaryTreeNode<T>* getRight() const {
		return right_node;
	}


	BinaryTreeNode<T>* getLeft() const {
		return left_node;
	}


	T& getValue() {
		return value;
	}
	T getValue() const {
		return value;
	}

	void setValue(T pValue) {
		this->value = pValue;
		this->empty = false;
	}

	void set_Value(const T& pValue) {
		this->value = pValue;
		this->empty = false;

	}

	bool isLeaf() {
		return ((this->left_node == nullptr) && (this->right_node == nullptr));
	}


	bool isEmpty() {
		if (this->value == T() && this->left_node == nullptr && this->right_node == nullptr)
			this->empty = true;
		else
			this->empty = false;
		return empty;
	}
	//operator overlaods



	BinaryTreeNode<T>& operator=(const BinaryTreeNode<T>* obj) {
		this->right_node = obj->right_node;
		this->left_node = obj->left_node;
		this->value = obj->value;
		this->empty = obj->empty;
		return this;
	}

	bool operator< (const T rhs) {
		return value < rhs;
	}
	bool operator< (const T rhs) const {
		return value < rhs;
	}


	bool operator> (T rhs) {
		return value > rhs;
	}

	bool operator> (const T rhs) const {
		return value > rhs;
	}
	bool operator<= (T rhs) {
		return value <= rhs;
	}

	bool operator>= (T rhs) {
		return value >= rhs;
	}

	bool operator<= (const T rhs) const {
		return value <= rhs;
	}

	bool operator>= (const T rhs) const {
		return value >= rhs;
	}


	T operator + (T rhs) {
		return (value + rhs);
	}

	T operator - (T rhs) {
		return (value - rhs);
	}



	friend ostream& operator<<<> (ostream& strm, const BinaryTreeNode<T>& obj);

};





template<class T>
ostream& operator<<<> (ostream& strm, const BinaryTreeNode<T>& obj) {
	strm << obj.value;
	return strm;
}

template<class T>
fstream& operator>><> (fstream& strm, BinaryTreeNode<T>& obj) {
	strm >> obj.value;
	return strm;
}




//###############################################################################################################################################
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//				Tree Template Class
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//###############################################################################################################################################


///prototypes





/**
*
*
*/
template<class T, class Node = BinaryTreeNode<T> >//, class Node = BinaryTreeNode<T> >
class Tree {
private:
	Node* root = nullptr;
	size_t size = size_t();//the amount of nodes
	//size_t depth = size_t();//the level of the depth 

	////untested
	///// Precondition:
	///// Postcondition:
	//Node*& minNode(Node* node ) {
	//	Node*& cursor = node;
	//	if (cursor && cursor->getLeft() != nullptr)
	//		return minNode(cursor->left);
	//	return cursor;
	//}




	/// Precondition:
	/// Postcondition:
	Node* insert(Node* node, T& data) {
		if (node == nullptr)
		{
			return new Node(data);
		}
		if (data < node->getValue()) {//if value is greater than data
			node->setLeft(insert(node->getLeft(), data));

		}
		else if (node->getValue() < data)
		{//if value is less that data
			node->setRight(insert(node->getRight(), data));
		}
		return node;
	}

	/// Precondition:
	/// Postcondition:
	bool insert(Node*& node, Node*& posNode) {
		if (posNode == nullptr) {
			posNode = node;
			return true;
		}//end if

		else if (posNode->getLeft() == nullptr) {//if value is greater than data
			posNode->setLeft(node);
			return true;
		}
		else if (posNode->getRight() == nullptr)
		{//if value is less that data
			posNode->setRight(node);
			return true;
		}
		return false;
	}

	/// Precondition:
	/// Postcondition:
	//untested
	//Node* insertTree(const Node*& rNode) {
	//	if (!rNode || rNode == nullptr) {//if the passed value is nullptr return nullptr
	//		return nullptr;
	//	}
	//	Node* l_node = nullptr;
	//	Node* r_node = nullptr;
	//	//if has no children
	//	
	//	if (rNode->getLeft() == nullptr && rNode->getRight() == nullptr)
	//		insert(root, rNode->value);

	//	else if (rNode->getLeft() == nullptr) {//add the right subtree
	//		r_node = rNode->getRight();
	//		insertTree(r_node);//adds values from bottom up
	//	}
	//	else if (rNode->getRight() == nullptr) {
	//		l_node = rNode->getRight();
	//		insertTree(l_node);//adds values from bottom up
	//	}
	//	else {
	//		l_node = rNode->getRight();
	//		r_node = rNode->getRight();
	//		insertTree(l_node); 
	//		insertTree(r_node);
	//		insert(root, rNode->value);
	//	}
	//	return rNode;
	//}


public:
	Node* nodePtr = nullptr;

	/// Precondition:
	/// Postcondition:
	Tree() {
		size = 0;
		nodePtr = root;
	}

	/// NEEEDS TO BE FIXED...
	/// copy constructor
	/// copies tree
	Tree(const Tree<T>& cTree) {
		deleteTree(root);

		//root = copyTree(cTree.nodePtr);//getting error cannot convert from BinaryTree<T> to BinaryTree<T>*
		nodePtr = root;
	}//end copy constructor

	/// Precondition:
	/// Postcondition:
	~Tree() {
		deleteTree(nodePtr);
	}


	//############################################################################################################
	// getSize	[tested]
	//############################################################################################################


	/// Precondition:
	/// Postcondition:
	/// [TESTED]
	size_t getSize(Node* node) {
		if (node == nullptr) {
			return 0;
		}
		else {
			return (1 + getSize(node->getLeft()) + getSize(node->getRight()));
		}

	}//end getSize

	//############################################################################################################
	// insertNode	[tested]
	//############################################################################################################

	/// Precondition:
	/// Postcondition:
	///	depends on private member function insert(Node* node, T data)
	/// [TESTED]
	void insertNode(T data) {

		if (root == nullptr) {//if root is null put at root 
			root = insert(root, data);
			root->isEmpty();
		}
		else {//if root is not null
			insert(root, data);
		}
	}

	//############################################################################################################
	// removeNode	[untested]!! searches for the value 
	//############################################################################################################


	/// Precondition:
	/// Postcondition: removes the node with the removeValue
	/// [untested]
	/// 
	void removeNode(T removeValue, Node* prev, Node* node) {
		Node* l_next = nullptr;
		Node* r_next = nullptr;
		if (!root || root == nullptr) {
			empty = true;
			return;
		}
		else if (!node && node == nullptr) {
			return;
		}
		else {//if the 
			if (node->value == removeValue) {
				if (node->isLeaf()) {//if the node is a leaf dont need to do complicated linking
					if (prev->getLeft() == node) {
						prev->getLeft() = nullptr;
						delete node;
						size--;
					}
					else if (prev->getRight() == node) {
						prev->getRight() = nullptr;
						delete node;
						size--;
					}
				}//end if
				else {//if not a leaf
					if (prev->getLeft() == node) {//if is on the left branch
						l_next = node->getLeft();//link left before disconnecting
						r_next = node->getRight();//link right before disconnecting
						prev->getLeft() = nullptr;//unlink
						delete node;//delete the node
						size--;
						insertTree(l_next);//add the left subtree
						insertTree(r_next);//add the right subtree
					}
					else if (prev->getRight() == node) {
						l_next = node->getLeft();//link left before disconnecting
						r_next = node->getRight();//link right before disconnecting
						prev->getRight() = nullptr;//unlink
						delete node;//delete node
						size--;
						insertTree(l_next);
						insertTree(r_next);
					}
				}//end else
			}//end if
			else {//if the value is not found yet
				if (node->value < removeValue)//if the value is less than the value of the node 
					removeNode(removeValue, node, node->getLeft());//recurse down the left subtree
				else if (node->value > removeValue)//if the vlaue is greater than the value of the node
					removeNode(removeValue, node, node->right);//recurse down the right subtree
			}//end else
		}

	}


	//############################################################################################################
	// removeNode	[untested]!! searches for the removeNode 
	//############################################################################################################


	/// Precondition:
	/// Postcondition: removes the node if it exists in the tree
	/// [untested]
	void removeNode(Node* prev, Node* removeNode) {
		Node* l_next = nullptr;
		Node* r_next = nullptr;
		if (!prev || !removeNode)
			return;
		if (removeNode->isLeaf()) {//if the node is a leaf dont need to do complicated linking
			if (prev->getLeft() == removeNode) {
				prev->getLeft() = nullptr;
				delete removeNode;
				size--;
			}
			else if (prev->getRight() == removeNode) {
				prev->getRight() = nullptr;
				delete removeNode;
				size--;
			}
		}//end if
		else {//if not a leaf
			if (prev->getLeft() == removeNode) {//if is on the left branch
				l_next = removeNode->getLeft();//link left before disconnecting
				r_next = removeNode->getRight();//link right before disconnecting
				prev->getLeft() = nullptr;//unlink
				delete removeNode;//delete the node
				size--;
				insertTree(l_next);//add the left subtree
				insertTree(r_next);//add the right subtree
			}
			else if (prev->getRight() == removeNode) {
				l_next = removeNode->getLeft();//link left before disconnecting
				r_next = removeNode->getRight();//link right before disconnecting
				prev->getRight() = nullptr;//unlink
				delete removeNode;//delete node
				size--;
				insertTree(l_next);
				insertTree(r_next);
			}
		}//end else
	}

	//############################################################################################################
	// orderTraversals	[tested]
	//############################################################################################################


	//##########################################################################
	// inOrder	[tested] 
	//##########################################################################


	/// Precondition:
	/// Postcondition:
	void inOrder(Node* currentNode) {
		if (currentNode == nullptr) {
			return;
		}
		inOrder(currentNode->getLeft());
		std::cout << "\n\t" + std::to_string(currentNode->getValue());
		inOrder(currentNode->getRight());
	}

	//##########################################################################
	// postOrder	[tested] 
	//##########################################################################


	/// Precondition:
	/// Postcondition:
	void postOrder(Node* currentNode) {
		if (currentNode == nullptr) {
			return;
		}
		postOrder(currentNode->getLeft());
		postOrder(currentNode->getRight());
		std::cout << "\n\t" + std::to_string(currentNode->getValue());
	}

	//##########################################################################
	// preOrder	[tested] 
	//##########################################################################

	/// Precondition:
	/// Postcondition:
	void preOrder(Node* currentNode) {
		if (currentNode == nullptr) {
			return;
		}
		std::cout << "\n\t" + std::to_string(currentNode->getValue());
		preOrder(currentNode->getLeft());
		preOrder(currentNode->getRight());
	}


	//[untested]
	 /// Precondition: relies on read function, read is a function that takes in an filestream object and a binaryTree node to populate and returns the newly populated address
	 /// Postcondition:
	void preOrder(Node*& currentNode, Node& read(fstream&, Node*&), fstream& inputFile) {
		Node* newNode = nullptr;
		if (currentNode == nullptr) {//if the current node in the preOrder is nullptr then read and populate
			newNode = new Node();
			std::cout << boolalpha << insert(read(inputFile, newNode), currentNode);
		}//end if

		preOrder(currentNode->getLeft(), read, inputFile);
		preOrder(currentNode->getRight(), read, inputFile);
	}



	//############################################################################################################
	// binarySearch	[tested]
	//############################################################################################################


	/// Precondition:
	/// Postcondition:
	Node* binarySearch(T searchValue, Node* node) const {
		if ((!node || node == nullptr))//stop case
			return node;
		else if (node->getValue() == searchValue)//can be combined in one if statment, broken up for visibility
			return node;

		if (searchValue < node->getValue())
			return binarySearch(searchValue, node->getLeft());//return the stop case of the left subtree
		else if (node->getValue() < searchValue)
			return binarySearch(searchValue, node->getRight());//implicit else | returns the stop case of the right subtree
	}//end bianrySearch

	bool Search(Node* node, T searchValue)const {
		if ((!node || node == nullptr)) {
			return false;
		}
		//stop case
		else if (node->getValue() == searchValue) {
			return true;
		}
		else if (node->getValue() < searchValue) {
			return Search(node->getLeft(), searchValue);
		}
		else if (node->getValue() > searchValue) {
			return Search(node->getRight(), searchValue);
		}
		else {
			return false;
		}
	}





	//############################################################################################################
	// deleteTree	[tested]
	//############################################################################################################


	/// Precondition:
	/// Postcondition:
	void deleteTree(Node* node, bool display = false) {

		if (node == nullptr)
			return;

		if (node->getLeft() != nullptr) {
			deleteTree(node->getLeft());//delete left subtree
		}
		if (node->getRight() != nullptr) {
			deleteTree(node->getRight());//delete right subtree
		}
		if (display == true)
			//std::cout << "\nDeleting node: " << node->getValue();
			delete node;
		node = nullptr;
		nodePtr = nullptr;
		root = nullptr;
		size = 0;

	}

	/// Precondition:
	/// Postcondition:
	// Node& copyTree(const Node* node){
	//	
	//	if (node == nullptr)
	//		return nullptr;
	//	node->getLeft() = copyTree(node->getLeft);
	//	node->getRight() = copyTree(node->getRight);
	//	return new Node(node->getValue(), node->getLeft(), node->getRight() );

	//}//end copyTree


	//############################################################################################################
	// copyTree	[untested]
	//############################################################################################################



	// Node& copyTree(const Node* node){
	//	 Node *l_next = nullptr;
	//	 Node *r_next = nullptr;

	//	if (node == nullptr)
	//		return nullptr;


	//	l_next = copyTree(node->getLeft);
	//	r_next = copyTree(node->getRight);
	//	return new Node(node->getValue(),l_next, r_next);
	//	
	//}//end copyTree


	//############################################################################################################
	// resetNodePtr	[tested]
	//############################################################################################################


	void resetNodePtr() {
		this->nodePtr = root;
	}



	//############################################################################################################
	// operators	[?] possibly untested
	//############################################################################################################


	void operator = (const Tree<T>* cTree) {
		deleteTree(this->root);

		this->root = this->copyTree(cTree->root);
		this->resetNodePtr();
		return;
	}

	///// Precondition:
	///// Postcondition:
	//Node* operator[](size_t index) {
	//	switch (index) {
	//	case(0):return root;
	//	case(1):return root->getLeft();
	//	case(2):return root->getRight();
	//	default: {
	//		//dynamic algorithm to recurse the tree returning the values displayed from left to right from each depth

	//		break;
	//	}
	//	}
	//}

	//############################################################################################################
	// min and max traversals	[tested] [not fully excercised]
	//############################################################################################################



	//##########################################################################
	// leftLast	[tested] 
	//##########################################################################


	/// call resetNodePtr prior to use
	Node*& leftLast() {



		if (nodePtr && (nodePtr->getLeft() == nullptr))//if the left is null and nodePtr is not return nodePtr
			return nodePtr;
		else if (nodePtr && (nodePtr->getLeft() != nullptr)) {
			nodePtr = nodePtr->getLeft();//if neither the left is null and nodePtr is not null then set nodePtr to the right node
			return leftLast();//recursive call
		}
		else//if nodePtr is null, meaning that it starts off null and root is null then return root
			return root;

	}


	//##########################################################################
	// rightLast	[tested] 
	//##########################################################################


	Node*& rightLast() {


		if (nodePtr && (nodePtr->getRight() == nullptr))//if the right is null and nodePtr is not return nodePtr
			return nodePtr;
		else if (nodePtr && (nodePtr->getRight() != nullptr)) {
			nodePtr = nodePtr->getRight();//if neither the right is null and nodePtr is not null then set nodePtr to the right node
			return rightLast();//recursive call
		}
		else//if nodePtr is null, meaning that it starts off null and root is null then return root
			return root;

	}


	//##########################################################################
	// leftLastParent	[tested] 
	//##########################################################################


	Node*& leftLastParent() {
		Node* next = nullptr;
		if (nodePtr && !nodePtr->isLeaf() && nodePtr->getLeft())
			next = nodePtr->getLeft();
		if (next && next->isLeaf())
			return nodePtr;
		else if (next && !next->isLeaf()) {
			nodePtr = next;
			return leftLastParent();
		}
		else
			return root;

	}


	//##########################################################################
	// rightLastParent	[tested] 
	//##########################################################################


	Node*& rightLastParent() {
		Node* next = nullptr;
		if (nodePtr && !nodePtr->isLeaf() && nodePtr->getRight())
			next = nodePtr->getRight();
		if (next && next->isLeaf())
			return nodePtr;
		else if (next && !next->isLeaf()) {
			nodePtr = next;
			return rightLastParent();
		}
		else
			return root;

	}



};

//requires overloaded input stram operator for file to BinaryTreeNode<T>
// populates currentNode and returns the address to be pointed to
template<class T, class Node = BinaryTreeNode<T> >
Node& read(fstream& fStrm, Node*& currentNode) {
	bool debug = true;
	if (fStrm >> currentNode) {
		if (debug) std::cout << currentNode->getValue();
	}
	return currentNode;

}


//improve upon this function greatly
/// Precondition:
/// Postcondition:
template<class T>
void printTree(const string& prefix, BinaryTreeNode<T>* node, bool isLeft, bool root, bool last) {
	if (node != nullptr) {
		cout << prefix;
		if (!root) {
			if (isLeft) {
				if (node->getLeft() == nullptr && node->getRight() == nullptr) {//if has no children
					cout << char(192) << string(3, char(196));
				}
				else
					cout << char(195) << string(3, char(196));
			}
			else {//is right
				if (last) {//if last value
					cout << char(192) << string(3, char(196));
				}
				else//if not the last value
					cout << char(195) << string(3, char(196));
			}
			cout << " " << node->getValue() << "\n";
		}
		else
			cout << " " << node->getValue() << "\n";


		string s = "    ";
		s[0] = char(179);
		printTree(prefix + (isLeft ? s : "    "), node->getLeft(), true, false, false);
		printTree(prefix + (isLeft ? s : "    "), node->getRight(), false, false, true);

	}



}

//template<class T>
