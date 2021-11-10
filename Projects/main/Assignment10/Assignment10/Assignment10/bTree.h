#pragma once
#include <iostream>
#include <string>
#include "myContainers.h"

class bTreeContainer {
private:
	Tree<int> bTree;
public:
	bTreeContainer(){
		
	}
	void insertNode() {

	}

	void countNode() {

	}

	void searchNode() {

	}

	void pre_orderTravesal() {
		std::cout << "\n\t\tPre-order traveral of bTree with" + std::to_string(bTree.getSize(bTree.nodePtr)) + "nodes:";
		bTree.preOrder(bTree.nodePtr);
		bTree.resetNodePtr();
	}

	void in_orderTravesal() {
		std::cout << "\n\t\tIn-order traveral of bTree with" + std::to_string(bTree.getSize(bTree.nodePtr)) + "nodes:";
		bTree.inOrder(bTree.nodePtr);
		bTree.resetNodePtr();
	}

	void post_orderTravesal() {
		std::cout << "\n\t\tPost-order traveral of bTree with" + std::to_string(bTree.getSize(bTree.nodePtr)) + "nodes:";
		bTree.postOrder(bTree.nodePtr);
		bTree.resetNodePtr();
	}

	void deleteTree() {

	}
};