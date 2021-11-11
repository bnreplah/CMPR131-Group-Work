#pragma once
#include <iostream>
#include <string>
#include "myContainers.h"

class bTreeContainer {
private:
	Tree<int> bTree = Tree<int>();
public:
	bTreeContainer(){
	}
	void insertNode() {
		int entry = inputInteger("\n\t\tEnter an integer: ");
		bTree.insertNode(entry);
	}

	void countNode() {
		std::cout << "\n\t\tCount of Nodes = " + std::to_string(bTree.getSize(bTree.returnRoot()));
	}

	void searchNode() {
		int entry = inputInteger("\n\t\tEnter an integer key to search: ");
		bool result = bTree.Search(bTree.returnRoot(), entry);
		if (result == false) {
			std::cout << "\n\t\t" + to_string(entry) + " cannot be found.";
		}
		else {
			std::cout << "\n\t\t" + to_string(entry) + " is found.";
		}
	}

	void pre_orderTravesal() {
		std::cout << "\n\t\tPre-order traveral of bTree with " + std::to_string(bTree.getSize(bTree.returnRoot())) + " nodes:";
		bTree.preOrder(bTree.returnRoot());
		bTree.resetNodePtr();
	}

	void in_orderTravesal() {
		std::cout << "\n\t\tIn-order traveral of bTree with " + std::to_string(bTree.getSize(bTree.returnRoot())) + " nodes:";
		bTree.inOrder(bTree.returnRoot());
		bTree.resetNodePtr();
	}

	void post_orderTravesal() {
		std::cout << "\n\t\tPost-order traveral of bTree with " + std::to_string(bTree.getSize(bTree.returnRoot())) + " nodes:";
		bTree.postOrder(bTree.returnRoot());
		bTree.resetNodePtr();
	}

	void deleteTree() {
		std::cout << "\n\t\tAll " + std::to_string(bTree.getSize(bTree.returnRoot())) + " nodes/leaves have been destroyed.";
		bTree.deleteTree(bTree.returnRoot());
	}
};

char bTreeMenu() {
	std::cout << "\n\t1> bTree container";
	std::cout << "\n\t" + string(100, char(205));
	std::cout << "\n\t\tA> Insert a node/leaf";
	std::cout << "\n\t\tB> Count of Nodes/leaves";
	std::cout << "\n\t\tC> Search a node/leaf";
	std::cout << "\n\t\tD> Pre-order traversal";
	std::cout << "\n\t\tE> In-order traversal";
	std::cout << "\n\t\tF> Post-order traveral";
	std::cout << "\n\t\tG> Delete the entire tree";
	std::cout << "\n\t" + string(100, char(196));
	std::cout << "\n\t\t0> return ";
	std::cout << "\n\t" + string(100, char(205));
	char charOption = inputChar("\n\t\tOption: ", "abcdefg0");
	return charOption;
}

void mainBTree() {
	bTreeContainer ThisTree = bTreeContainer();
	do
	{
		switch (bTreeMenu())
		{
		case 0: exit(0); break;
		case 'A': ThisTree.insertNode(); break;
		case 'B': ThisTree.countNode(); break;
		case 'C': ThisTree.searchNode(); break;
		case 'D': ThisTree.pre_orderTravesal(); break;
		case 'E': ThisTree.in_orderTravesal(); break;
		case 'F': ThisTree.post_orderTravesal(); break;
		case 'G': ThisTree.deleteTree(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		pause();
		clrScrn();
	} while (true);
}