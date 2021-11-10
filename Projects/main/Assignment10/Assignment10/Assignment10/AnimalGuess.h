// File: AnimalGuess.h
// Team Members:
//          Itz Rodrigez 
//          Thien Nguyen
//

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "binary_tree_node.h"
#include "myContainers.h"
using namespace std;

/// Precondition: 
/// Postcondition: 
void playAnimal()
{
   
    Tree<string> animalTree = Tree<string>();

    cout << "\n\t\tThink of an animal and press the RETURN/ENTER key to begin...\n";
    pause();

    //reading file animal.txt
    ifstream inputFile = ifstream();
    


    string file = "animal.txt";
    inputFile.open(file);
    string nodeValue;
    if (inputFile && inputFile.good() && inputFile.is_open())
    {
        // input to nodes

        while (getline(inputFile,nodeValue))
        {
            
            cout << nodeValue << '\n';
            animalTree.insertNode(nodeValue);

        }


    }
    else
    {
        cout << "\n\t\tERROR: opening the animal.txt file\n";
    }

    inputFile.close();
}

/// Precondition: 
/// Postcondition: 
void saveAnimal()
{




}

/// Precondition: 
/// Postcondition: 
int animalMenuOption()
{
    header("3> Animal Guessing Game");
    string options[] = { "\n\tA game tree for a simple game of \"animal\" twenty questions would look like:",
                         "\n\t                                 [ Is it a mammal? ]",
                         "\n\t                                     /        \\",
                         "\n\t                                    /          \\",
                         "\n\t                [ Does it have stripes? ]     [ Is it a bird? ]",
                         "\n\t                      /      \\                  /      \\",
                         "\n\t                     /        \\                /        \\",
                         "\n\t                ( Zebra )    ( Lion )   [ Does it fly? ]  ( Gila monster )",
                         "\n\t                                           /      \\",
                         "\n\t                                          /        \\",
                         "\n\t                                    ( Eagle )     ( Penguin )",
                         "\n",
                         "\n\tA learning version of twenty questions: one that not only plays the game, but learns new",
                         "\n\tobjects when it loses.",
                         "\n\tWelcome to Animal Guessing Game",
                         "\n\t" + string(100, char(205)),
                         "\n\t\tA> Play the game",
                         "\n\t\tB> Save the game file",
                         "\n\t" + string(100 , char(196)) +
                         "\n\t\t0 > exit "
    };
    for (string option : options)
        cout << option;
    header("");

    int optionInteger = inputChar("\n\t\tOption: ",static_cast<string>("AB0"));
    clrScrn();

    return optionInteger;

}//end menuOptions

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runAnimalGuess()
{
    // make tree



    do
    {
        switch (animalMenuOption())
        {
        case '0': return; break;
        case 'A': playAnimal(); break;
        case 'B': saveAnimal(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
        clrScrn();
    } while (true);
}














//###################################################################################################
// FOR REFERENCE/CHEATING PURPOSES ONLY                                         ERASE ONCE COMPLETION
//###################################################################################################

//// FILE: animal.cxx
//// An animal-guessing program to illustrate the use of the binary tree toolkit.
//
//#include <cstdlib>     // Provides EXIT_SUCCESS
//
//// PROTOTYPES for functions used by this game program:
//void ask_and_move(binary_tree_node<string>*& current_ptr);
//// Precondition: current_ptr points to a non-leaf node in a binary taxonomy tree.
//// Postcondition: The question at the current node has been asked. The current
//// pointer has been shifted left (if the user answered yes) or right
//// (for a no answer).
//
//binary_tree_node<string>* beginningTree();
//// Postcondition: The function has created a small taxonomy tree. The return
//// value is the root pointer of the new tree.
//
//void instruct();
//// Postcondition: Instructions for playing the game have been printed to the
//// screen.
//
//void learn(binary_tree_node<string>*& leaf_ptr);
//// Precondition: leaf_ptr is a pointer to a leaf in a taxonomy tree. The leaf
//// contains a wrong guess that was just made.
//// Postcondition: Information has been elicited from the user, and the tree has
//// been improved.
//
//void play(binary_tree_node<string>* current_ptr);
//// Precondition: current_ptr points to the root of a binary taxonomy tree with
//// at least two leaves.
//// Postcondition: One round of the animal game has been played, and maybe the
//// tree has been improved.
//
//int main()
//{
//    binary_tree_node<string>* taxonomy_root_ptr;
//
//    instruct();
//    taxonomy_root_ptr = beginningTree();
//    do
//        play(taxonomy_root_ptr);
//    while (inquire("Shall we play again?"));
//
//    cout << "Thank you for teaching me a thing or two." << endl;
//    return EXIT_SUCCESS;
//}
//
//void ask_and_move(binary_tree_node<string>*& current_ptr)
//// Library facilities used: bintree.h, string, useful.h
//{
//    cout << current_ptr->data();
//    if (inquire(" Please answer:"))
//        current_ptr = current_ptr->left();
//    else
//        current_ptr = current_ptr->right();
//}
//
//binary_tree_node<string>* beginningTree()
//// Library facilities used: bintree.h, string
//{
//    binary_tree_node<string>* root_ptr;
//    binary_tree_node<string>* child_ptr;
//
//    const string root_question("Are you a mammal?");
//    const string left_question("Are you bigger than a cat?");
//    const string right_question("Do you live underwater?");
//    const string animal1("Kangaroo");
//    const string animal2("Mouse");
//    const string animal3("Trout");
//    const string animal4("Robin");
//
//    // Create the root node with the question �Are you a mammal?�
//    root_ptr = new binary_tree_node<string>(root_question);
//
//    // Create and attach the left subtree.
//    child_ptr = new binary_tree_node<string>(left_question);
//    child_ptr->set_left(new binary_tree_node<string>(animal1));
//    child_ptr->set_right(new binary_tree_node<string>(animal2));
//    root_ptr->set_left(child_ptr);
//
//    // Create and attach the right subtree.
//    child_ptr = new binary_tree_node<string>(right_question);
//    child_ptr->set_left(new binary_tree_node<string>(animal3));
//    child_ptr->set_right(new binary_tree_node<string>(animal4));
//    root_ptr->set_right(child_ptr);
//
//    return root_ptr;
//}
//
//void instruct()
//// Library facilities used: iostream
//{
//    cout << "Let's play!" << endl;
//    cout << "You pretend to be an animal, and I try to guess what you are.\n";
//}
//
//void learn(binary_tree_node<string>*& leaf_ptr)
//// Library facilities used: bintree.h, iostream, string, useful.h
//{
//    string guess_animal;    // The animal that was just guessed
//    string correct_animal;  // The animal that the user was thinking of
//    string new_question;    // A question to distinguish the two animals
//
//    // Set strings for the guessed animal, correct animal and a new question.
//    guess_animal = leaf_ptr->data();
//    cout << "I give up. What are you? " << endl;
//    getline(cin, correct_animal);
//    cout << "Please type a yes/no question that will distinguish a" << endl;
//    cout << correct_animal << " from a " << guess_animal << "." << endl;
//    cout << "Your question: " << endl;
//    getline(cin, new_question);
//
//    // Put the new question in the current node, and add two new children.
//    leaf_ptr->set_data(new_question);
//    cout << "As a " << correct_animal << ", " << new_question << endl;
//    if (inquire("Please answer"))
//    {
//        leaf_ptr->set_left(new binary_tree_node<string>(correct_animal));
//        leaf_ptr->set_right(new binary_tree_node<string>(guess_animal));
//    }
//    else
//    {
//        leaf_ptr->set_left(new binary_tree_node<string>(guess_animal));
//        leaf_ptr->set_right(new binary_tree_node<string>(correct_animal));
//    }
//}
//
//void play(binary_tree_node<string>* current_ptr)
//// Library facilities used: bintree.h, iostream, string, useful.h
//{
//    cout << "Think of an animal, then press the return key.";
//    eat_line();
//
//    while (!current_ptr->is_leaf())
//        ask_and_move(current_ptr);
//
//    cout << ("My guess is " + current_ptr->data() + ". ");
//    if (!inquire("Am I right?"))
//        learn(current_ptr);
//    else
//        cout << "I knew it all along!" << endl;
//}
//
//
//// FILE: useful.cxx
//// IMPLEMENTS: A toolkit of functions (See useful.h for documentation.)
//
//#include <cassert>   // Provides assert
//#include <cctype>    // Provides toupper
//#include <cstdlib>   // Provides rand, RAND_MAX
//
//using namespace std;
//
//void display(double x)
//// Library facilities used: iostream.h, stdlib.h
//{
//    const char STAR = '*';
//    const char BLANK = ' ';
//    const char VERTICAL_BAR = '|';
//    const int  LIMIT = 39;
//    int i;
//
//    if (x < -LIMIT)
//        x = -LIMIT;
//    else if (x > LIMIT)
//        x = LIMIT;
//
//    for (i = -LIMIT; i < 0; i++)
//    {
//        if (i >= x)
//            cout << STAR;
//        else
//            cout << BLANK;
//    }
//    cout << VERTICAL_BAR;
//    for (i = 1; i <= LIMIT; i++)
//    {
//        if (i <= x)
//            cout << STAR;
//        else
//            cout << BLANK;
//    }
//    cout << endl;
//}
//
//double random_fraction()
//// Library facilities used: stdlib.h
//{
//    return rand() / double(RAND_MAX);
//}
//
//double random_real(double low, double high)
//// Library facilities used: assert.h
//{
//    assert(low <= high);
//    return low + random_fraction() * (high - low);
//}
//
//void eat_line()
//// Library facilities used: iostream.h
//// 
//{
//    char next;
//
//    do
//        cin.get(next);
//    while (next != '\n');
//}
//
//bool inquire(const char query[])
//// Library facilities used: ctype.h, iostream.h
//{
//    char answer;
//    do
//    {
//        cout << query << " [Yes or No]" << endl;
//        cin >> answer;
//        answer = toupper(answer);
//        eat_line();
//    } while ((answer != 'Y') && (answer != 'N'));
//    return (answer == 'Y');
//}