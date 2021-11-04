#include <iostream>
#include "myContainers.h"
#include "input.h"
using namespace std;

int main() {
	TreeNode<string>* root = new TreeNode<string>();
	root->set_Value("root");

	cout << "a root has sprouted with no branches.\n";
	printTree("\t\t", root, false, true, false);
	cout << "\n";
	
	
	TreeNode<string>* branch1 = new TreeNode<string>();
	branch1->set_Value("branch 1");
	root->setRight(branch1);
	
	cout << "\n";
	printTree("\t\t", root, true, false, false);
	cout << "\n";
	cout << "\n";

	TreeNode<string>* branch2 = new TreeNode<string>();
	branch2->set_Value("branch 2");
	root->setRight(branch2);
	
	cout << "\n";
	printTree("\t\t", root, false, true, false);
	cout << "\n";
	cout << "\n";
	pause();
	return 0;
}