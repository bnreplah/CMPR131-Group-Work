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
#include "input.h"
using namespace std;

class Animal {
private:
	//AnimalNode* yes_node = nullptr;
    //AnimalNode* no_node = nullptr;
    bool question = bool(true);
    string value;
    bool yes = bool(true); // left or right subtree
    bool firstQuestion = bool(true);// root
    string guess; // used when guess is wrong

public:
	/// <summary>
	/// Default constructor
	/// </summary>
    /// 
    Animal()
    {

    }
	Animal(string &data, bool quest, bool pYes, bool pFirstQuestion = false) {
		value = data;
        this->question = quest;
        this->yes = pYes;
        this->firstQuestion = pFirstQuestion;
	}//end default constructor

    //copy constructor
	//Animal(const Animal* obj) {
 //       if (obj) {//if object exists and is not null
 //           this->question = obj->question;
 //           this->value = obj->value;
 //           this->yes = obj->yes;
 //           this->firstQuestion = obj->firstQuestion;
 //           this->guess = obj->guess;
 //       }
	//}
        //copy constructor
	Animal(const Animal& obj) {

            this->question = obj.question;
            this->value = obj.value;
            this->yes = obj.yes;
            this->firstQuestion = obj.firstQuestion;
            this->guess = obj.guess;
	}

    //Precondition: Animal must be initialized
    //Postcondition: will return the value of the firstQuestion
    bool isFirstQuest()const {
        return firstQuestion;
    }

    //Precondition: 
    //Postcondition:
    void setFirstQuest(bool fQuest) {

        firstQuestion = fQuest;
    }

    //Precondition:
    //Postcondition:
    bool isQuest()const {
        return question;
    }

    //Precondition:
    //Postcondition:
    void setQuest(bool quest) {

        question = quest;
    }

    //Precondition:
    //Postcondition:
	string &getData() {
		return value;
	}

    //Precondition:
    //Postcondition:
	void setValue(string pValue) {
		this->value = pValue;
	}

    //Precondition:
    //Postcondition:
	void set_Value(const string& pValue) {
        this->value = pValue;
	}

    //Precondition:
    //Postcondition:
    bool isYes() {
        return yes;
    }

    //Precondition:
    //Postcondition:
    void setYes(bool answer){
        yes = answer;
    }

	//operator overlaods
    //Node* insert(Node* parent, Animal& child) {
    //    
    //      left = yes, right = no
    //    if (parent == nullptr)
    //    {                        left/yes    right/no                
    //        return new Node(child, nullptr, nullptr);
    //    }

    //    if (child < parent->getValue()) {//if value is greater than data
    //        parent->setLeft(insert(parent->getLeft(), child));
    //              }
    // 
    //   else if (parent->getValue() < child)
    //    {//if value is less that data
    //        parent->setRight(insert(parent->getRight(), child));
    //    }
    //    return parent;
    //}

    //precondition:
    //postcondition:
	void operator=(const Animal* obj) {

        this->question = obj->question;
        this->value = obj->value;
        this->yes = obj->yes;
        this->firstQuestion = obj->firstQuestion;
        this->guess = obj->guess;
	}


    //precondition:
    //postcondition:
	bool operator< (Animal rhs) {
		return *this < rhs;
    }

    //precondition:
    //postcondition:
	bool operator> (Animal rhs) {
		return *this > rhs;
	}

    //precondition:
    //postcondition:
	bool operator< (const Animal rhs) const {
		return  *this < rhs;
	}

    //precondition:
    //postcondition:
	bool operator> (const Animal rhs) const {
		return *this > rhs;
	}
};



//Prototypes:
void saveAnimal();
int animalMenuOption();
void readFile(Tree<string> myTree);
void playAnimal();
bool read(fstream& fileInput, BinaryTreeNode<Animal>*& myNode, bool yesNo);

//precondition: Class object must be initialized, the parent question and the leaf node of the tree's guess of the animal
//postcondition: will add nodes to the animal tree so that it may be more elements
void learn(BinaryTreeNode<Animal>*question, BinaryTreeNode<Animal>* leaf) {

    string newQuestion;
    string correctAnimal;
    string preposition = "Does a ";

    if (leaf != nullptr) {
        Animal guessAnimal = leaf->getValue();
    
        correctAnimal = inputString("I give up, what are you?\n",false);
    
        newQuestion = inputString("Please specify in a yes and no question the difference between a " + correctAnimal + " and a " + guessAnimal.getData()+" \n",false);
        BinaryTreeNode<Animal>* yesAnimal = nullptr;
        BinaryTreeNode<Animal>* noAnimal = nullptr;

        if (inputChar(preposition + " " + correctAnimal + " " + newQuestion, string("yn")) == 'Y')
        {
            yesAnimal = new BinaryTreeNode<Animal>(Animal(correctAnimal,false,true),false);
            leaf->getValue().setYes(false);
            noAnimal = leaf;
        }
        else
        {
            noAnimal = new BinaryTreeNode<Animal>(Animal(correctAnimal,false,false),false);
            leaf->getValue().setYes(true);
            yesAnimal = leaf;
        }

        BinaryTreeNode<Animal> *distQuestion = new BinaryTreeNode<Animal>(Animal(newQuestion,true,question->getValue().isYes()),yesAnimal,noAnimal);

        if (guessAnimal.isYes())
        {
            question->setLeft(distQuestion);
        }
        else
        {
            question->setRight(distQuestion);
        }
    }
}

/// Precondition: Tree must be initialized
/// Postcondition: Will recursively run the game
void askAndMove(BinaryTreeNode<Animal>* previousNode,BinaryTreeNode<Animal> *currentNode,bool start = false) {
    
    if (!currentNode)
        return;

    if (currentNode->isLeaf()&& !currentNode->getValue().isQuest())
    {

        if (inputChar("Is your animal a " + currentNode->getValue().getData() + "? (Y/N)", "yn")=='Y'){
            //win statement
            cout << "\n\t\tHa yes I knew it all along!\n";
            return;
        }
        else  {
            return;
        learn(previousNode,currentNode);
        }
    }
    else if (!currentNode->isLeaf() && currentNode->getValue().isQuest())
    {
        if (inputChar(currentNode->getValue().getData()+" (Y/N)", "yn") == 'Y'){
            if (start == true) currentNode = currentNode->getLeft();
            askAndMove(currentNode, currentNode->getLeft());
        }
        else//implicit no
        {
            if (start == true) currentNode = currentNode->getRight();
            askAndMove(currentNode, currentNode->getRight());
        }
    }
}

/// Precondition: Tree must be initialized
/// Postcondition: Will call the recursive function to start the animal guessing game
void playAnimal(){
    Tree<Animal> animalTree = Tree<Animal>();
    fstream fileInput = fstream();
 
 
    string fileName = "animal.txt";
 
    fileInput.open(fileName);
 
    cout << "\n\t\tThink of an animal and press the RETURN/ENTER key to begin...\n\t\t";
    pause();
   
    //reads the file and stores it into the animalTree
    if (fileInput && fileInput.good() && fileInput.is_open())
    {
    
        //animalTree.preOrder(animalTree.nodePtr,read,fileInput,true);

    }
    else
    {
        cout << "EROR: opening the file\n";
    }
    animalTree.resetNodePtr();
    askAndMove(animalTree.nodePtr,animalTree.nodePtr);
    
}
//
///// Precondition: Tree must be initialized and the file "animal.txt" must exists
///// Postcondition: Will read the contents of the text file and store it in a Tree using the animal class in a preorder traversal
//bool read(fstream &fileInput ,BinaryTreeNode<Animal> *&myNode, bool yesNo) {
//
// 
//    string inputValue;
//
//
//    if (fileInput && fileInput.good() && fileInput.is_open())
//    {
//
//
//        while (!fileInput.eof())
//        {
//            getline(fileInput, inputValue);
//       
//            if (inputValue.at(0) == '[')
//            {
//                myNode = new BinaryTreeNode<Animal> (Animal (inputValue,true,yesNo,true),false);
//                return true;
//            }
//        
//     /*      if (!fileInput.eof())
//            {
//                getline(fileInput, inputValue);*/
//
//            if (inputValue.at(0) == '(')
//            {
//                myNode = new BinaryTreeNode<Animal>(Animal(inputValue, false, yesNo, false),false);
//                return false;
//            }
//        //}
//    }
//    
//        //fileInput.close();
//    }
//    
//    //else{
//    //    cout << "\n\t\tERROR: cannot open the animal.txt file\n";
//    //}
//
//}
//
/// Precondition: Tree must be initialized
/// Postcondition: Will output the tree nodes into a text file in a preorder traversal
void saveAnimal(){




}

/// Precondition: None
/// Postcondition: Will output the diagram of a example tree and will process the choice of the user
int animalMenuOption(){
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

    char optionChar = inputChar("\n\t\tOption: ",static_cast<string>("AB0"));
    clrScrn();

    return optionChar;

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



