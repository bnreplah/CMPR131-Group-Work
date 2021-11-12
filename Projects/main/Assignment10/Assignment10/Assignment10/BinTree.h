#pragma once
#include <iostream>
#include <string>
#include "myContainers.h"
#include "input.h"
class BinTreeContainerInt {
private:
	Tree<int> binTree;
	size_t size = size_t();
public:
	BinTreeContainerInt(){
		binTree = Tree<int>();
	}
	void insertNode() {
		binTree.resetNodePtr();
		int newVal = inputInteger("\n\t\tEnter an integer: ");
		this->binTree.insertNode(newVal);
	}

	void countNode() {
		binTree.resetNodePtr();
		std::cout << "\n\tCount of nodes = " << binTree.getSize(binTree.nodePtr);
	}

	/*void searchNode() {
		BinaryTreeNode<int>* foundNode = nullptr;
		
		binTree.resetNodePtr();
		if (binTree.nodePtr->isEmpty()) {
			std::cout << "\n\t\tERROR: The binary tree is empty";
			return;
		}
		int searchValue = inputInteger("\n\t\tEnter a value to search for: ");
		binTree.resetNodePtr();
	
		if (!foundNode) {
			std::cout << "\n\t\t" << searchValue << " was not found in the tree";
			return;
		}
		else {
			std::cout << "\n\t\t" << searchValue << " is found";
		}
	}*/

	void searchNode() {
		int entry = inputInteger("\n\t\tEnter an integer key to search: ");
		bool result = binTree.Search(binTree.nodePtr, entry);
		if (result == false) {
			std::cout << "\n\t\t" + to_string(entry) + " cannot be found.";
		}
		else {
			std::cout << "\n\t\t" + to_string(entry) + " is found.";
		}
		binTree.resetNodePtr();
	}

	void pre_orderTravesal() {
		binTree.resetNodePtr();
		if (binTree.nodePtr->isEmpty()) {
			std::cout << "\n\t\tERROR: The binary tree is empty";
			return;
		}
		std::cout << "\n\t\tPre-order traveral of bTree with " + std::to_string(binTree.getSize(binTree.nodePtr)) + " nodes:";
		binTree.preOrder(binTree.nodePtr);
		binTree.resetNodePtr();
	}

	void in_orderTravesal() {
		binTree.resetNodePtr();
		if (binTree.nodePtr->isEmpty()) {
			std::cout << "\n\t\tERROR: The binary tree is empty";
			return;
		}
		std::cout << "\n\t\tIn-order traveral of bTree with " + std::to_string(binTree.getSize(binTree.nodePtr)) + " nodes:";
		binTree.inOrder(binTree.nodePtr);
		binTree.resetNodePtr();
	}

	void post_orderTravesal() {
		binTree.resetNodePtr();
		if (binTree.nodePtr->isEmpty()) {
			std::cout << "\n\t\tERROR: The binary tree is empty";
			return;
		}
		std::cout << "\n\t\tPost-order traveral of bTree with " + std::to_string(binTree.getSize(binTree.nodePtr)) + " nodes:";
		binTree.postOrder(binTree.nodePtr);
		binTree.resetNodePtr();
	}

	void deleteTree() {
		binTree.resetNodePtr();
		if (binTree.nodePtr->isEmpty()) {
			std::cout << "\n\t\tERROR: The binary tree is empty";
			return;
		}
		
		size = binTree.getSize(binTree.nodePtr);
		binTree.resetNodePtr();
		binTree.deleteTree(binTree.nodePtr);
		std::cout << "\n\t\tAll " << std::to_string(size) << " nodes/leaves have been destroyed.";
		binTree.resetNodePtr();
	}

	/*void deleteTree() {
		std::cout << "\n\t\tAll " + std::to_string(size) + " nodes/leaves have been destroyed.";
		bTree.deleteTree(bTree.nodePtr);
		bTree.resetNodePtr();
		size = 0;
	}*/

};




void runBinTree() {
	BinTreeContainerInt intTree = BinTreeContainerInt();
	

	do
	{
		header("\tBinTree container");
		string options[] = { "\n\t\tA> Insert a node/leaf",
							 "\n\t\tB> Count of Nodes/leaves",
							 "\n\t\tC> Search a node/leaf",
							 "\n\t\tD> Pre-order traversal",
							 "\n\t\tE> In-order traversal",
							 "\n\t\tF> Post-order traversal",
							 "\n\t\tG> Delete the entire tree",
							 "\n\t" + string(100 , char(196)) +
							 "\n\t\t0 > exit "
		};
		for (string option : options)
			cout << option;
		header("");

		char optionChar = inputChar("\n\t\tOption: ", string("abcdefg"));
		clrScrn();

		switch (optionChar)
		{
		case ('0'): return;
		case ('A'): intTree.insertNode(); break;
		case ('B'): intTree.countNode(); break;
		case ('C'): intTree.searchNode(); break;
		case ('D'): intTree.pre_orderTravesal(); break;
		case ('E'): intTree.in_orderTravesal(); break;
		case ('F'): intTree.post_orderTravesal(); break;
		case ('G'): intTree.deleteTree(); break;
		
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
		clrScrn();
	} while (true);
}