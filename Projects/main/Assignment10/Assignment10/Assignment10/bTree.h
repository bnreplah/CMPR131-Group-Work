#pragma once
#include <iostream>
#include <string>
#include "myContainers.h"

class bTreeContainer {
private:
	Tree<int> bTree;
public:
	bTreeContainer(){
		bTree = Tree<int>();
	}
	void insertNode() {

	}

	void countNode() {

	}

	void searchNode() {

	}

	void pre_orderTravesal() {
		std::cout << "\n\t\tPre-order traveral of bTree with" + std::to_string(bTree.getSize()) + "nodes:";
		bTree.preOrder();
	}

	void in_orderTravesal() {
		std::cout << "\n\t\tIn-order traveral of bTree with" + std::to_string(bTree.getSize()) + "nodes:";
		bTree.inOrder();
	}

	void post_orderTravesal() {
		std::cout << "\n\t\tPost-order traveral of bTree with" + std::to_string(bTree.getSize()) + "nodes:";
		bTree.postOrder();
	}

	void deleteTree() {

	}
};