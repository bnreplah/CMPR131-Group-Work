#pragma once
#include <iostream>


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
	}//end ~MyLinkList

	/// Precondition: 
	/// Postcondition: 
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
	}//end insert node

	/// Precondition: num should to exist in the linked list
	/// Postcondition: if num exits, deletes the first node found with value num
	void deleteNode(T num) {
		ListNode<T, LinkTList<T>>* nodePtr;
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
	}//end deleteNode

	//Challenge2()
	/// Precondition: ptr is a ptr of ListNode type
	/// Postcondition: prints out the value ptr
	void print(ListNode<T, LinkTList>* ptr) const {
		std::cout << " " << ptr->value;
	}//end print

	/// Precondition: N/A
	/// Postcondition: Prints out all the values of the list
	void print() const {
		ListNode<T, LinkTList<T>>* nodePtr;
		nodePtr = head;
		std::cout << "{";
		while (nodePtr) {
			print(nodePtr);
			nodePtr = nodePtr->next;
			if (nodePtr) std::cout << ",";
		}//end while
		std::cout << " }\n";
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

	}//end insertPos 


	//Challenge7()
	///
	void deletePos(int pos) { //Assignment 7
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

	///
	///
	T getPos(int pos) const {
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
};//end class






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
ostream& operator <<<>(ostream& out, const DynamicTQueue<T>& obj) {//recall template friend needs <>
	if (obj.empty())
		return out;
	for (int i = 0; i < obj.numItems; i++) {
		out << "\n" << obj.qArray.getPos(i);
	}

	return out;
}



