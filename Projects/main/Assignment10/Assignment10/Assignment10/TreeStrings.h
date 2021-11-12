// Name: Prof Q
// Date: 11-3-2021
// Description: testing the binary_tree_node
// binary_tree_node.h is in External Dependencies

#pragma once

#include <iostream>
#include "binary_tree_node.h"
#include "input.h"
using namespace std;

void runTreeStrings()
{
    clrScrn();
    cout << "\n\t1> Tree of strings";
    cout << "\n\t" << string(100, char(205)) << '\n';

    // Tree Object is initialized using a string data type and root is declared
    binary_tree_node<string>* root = new binary_tree_node<string>;

    // "trunk" is stored into root as the data
    root->setData("trunk");


    // Step A
    // *******************************************
    cout << "\n\tA> Created root (" << root->getData() << ") with no leaf.\n";
    cout << '\n';
    print_tree("\t\t", root, false, true, false);
    

    // Step B
    // *******************************************
    binary_tree_node<string>* branch1 = new binary_tree_node<string>;
    branch1->setData("branch #1");
    binary_tree_node<string>* branch2 = new binary_tree_node<string>;
    branch2->setData("branch #2");

    cout << "\n\tB> Root (" << root->getData() << ") grows two branches: " << branch1->getData() << " and " << branch2->getData() << ".\n";
    root->setLeft(branch1);
    cout << "\t\tA branch of (" << root->getLeft()->getData() << ") grows left of the root.\n";
    root->setRight(branch2);
    cout << "\t\tA branch of (" << root->getRight()->getData() << ") grows right of the root.\n";

    cout << '\n';
    print_tree("\t\t", root, false, true, false);
   
    // Step C
    // *******************************************
    cout << "\n\tC> Branches grows leaves.\n";
    binary_tree_node<string>* leftLeaf1 = new binary_tree_node<string>;
    leftLeaf1->setData("leaf #1");
    root->getLeft()->setLeft(leftLeaf1);
    binary_tree_node<string>* leftLeaf2 = new binary_tree_node<string>;
    leftLeaf2->setData("leaf #2");
    root->getRight()->setRight(leftLeaf2);
    cout << "\n\t\tLeft branch of (" << root->getLeft()->getData() << ") grows two leaves: " << leftLeaf1->getData() << " and " << leftLeaf2->getData() << ".\n";

    cout << '\n';
    print_tree("\t\t", root, false, true, false);
    

    // Step D
    // *******************************************
    binary_tree_node<string>* rightLeaf1 = new binary_tree_node<string>;
    rightLeaf1->setData("leaf #3");
    root->getRight()->setLeft(rightLeaf1);
    binary_tree_node<string>* rightLeaf2 = new binary_tree_node<string>;
    rightLeaf2->setData("leaf #4");
    root->getRight()->setRight(rightLeaf2);
    cout << "\n\t\tRight branch of (" << root->getRight()->getData() << ") grows two leaves: " << rightLeaf1->getData() << " and " << rightLeaf2->getData() << ".\n";

    cout << '\n';
    print_tree("\t\t", root, false, true, false);
    

    // Step E
    // *******************************************
    binary_tree_node<string>* fruit = new binary_tree_node<string>;
    fruit->setData("apple");
    leftLeaf1->setLeft(fruit);
    cout << "\n\tD>. Left leaf sprouts and yields a fruit (" << fruit->getData() << ").\n";

    cout << '\n';
    print_tree("\t\t", root, false, true, false);
    

    binary_tree_node<string>* fruit2 = new binary_tree_node<string>;
    fruit2->setData("orange");
    binary_tree_node<string>* fruit3 = new binary_tree_node<string>;
    fruit3->setData("coconut");
    rightLeaf1->setLeft(fruit2);
    rightLeaf1->setRight(fruit3);

    cout << "\n\tE> Right leaf sprouts and yields two fruits (" << fruit2->getData() << " and " << fruit3->getData() << ").\n";

    cout << '\n';
    print_tree("\t\t", root, false, true, false);
    


    // Step F
    // *******************************************
    cout << "\n\tF> Delete tree.\n";
    delete_tree<string>(root);
    cout << '\n';
    root = NULL;
    if (root != NULL)
    {
        cout << '\n';
        print_tree("\t\t", root, false, true, false);
    }
    

}