#pragma once
#include <iostream>
#include <string>
#include "myContainers.h"
#include "input.h"
class BinTreeContainer {
private:
	Tree<int> binTree;
public:
	BinTreeContainer(){
		binTree = Tree<int>();
	}
	void insertNode() {
		int newVal = inputInteger("\n\t\tEnter an integer: ");
		this->binTree.insertNode(newVal);
	}

	void countNode() {
		binTree.resetNodePtr();
		std::cout << "\n\tCount of nodes = " << binTree.getSize(binTree.nodePtr);
	}

	void searchNode() {
		int searchValue = inputInteger("\n\t\tEnter a value to search for: ");
		binTree.resetNodePtr();
		binTree.binarySearch(searchValue, binTree.nodePtr);
	}

	void pre_orderTravesal() {
		std::cout << "\n\t\tPre-order traveral of bTree with" + std::to_string(binTree.getSize(binTree.nodePtr)) + "nodes:";
		binTree.preOrder(binTree.nodePtr);
		binTree.resetNodePtr();
	}

	void in_orderTravesal() {
		std::cout << "\n\t\tIn-order traveral of bTree with" + std::to_string(binTree.getSize(binTree.nodePtr)) + "nodes:";
		binTree.inOrder(binTree.nodePtr);
		binTree.resetNodePtr();
	}

	void post_orderTravesal() {
		std::cout << "\n\t\tPost-order traveral of bTree with" + std::to_string(binTree.getSize(binTree.nodePtr)) + "nodes:";
		binTree.postOrder(binTree.nodePtr);
		binTree.resetNodePtr();
	}

	void deleteTree() {

	}
};




void runBinTree() {
	BinTreeContainer intTree = BinTreeContainer();
	

	do
	{
		header("\tBinTree container");
		string options[] = { "\n\t\tA> Insert a node/lef",
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

		char optionChar = inputChar("\n\t\tOption: ", "abcdefg");
		clrScrn();

		switch (optionChar)
		{
		case 0: return;
		case ('A'): intTree.insertNode(); break;
		case ('B'): intTree.countNode(); break;
		case ('C'):; break;
		case ('D'): ; break;
		case ('E'): ; break;
		case ('F'): ; break;
		case ('G'): ; break;
		
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
		clrScrn();
	} while (true);
}