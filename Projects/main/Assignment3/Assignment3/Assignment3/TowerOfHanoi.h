// File: TowerOfHanoi.h	
// Names:
//      Ben Halpern
//		Thien Nguyen
//		Itz Rodriquez
//	Professor Quach
//	CMPR 131
//	Assignment 3: TowerOfHanoi
//	9/23/21

//Description: This program will simulate the game of Tower of Hanoi. Using the vector class it simulates the rings and the pegs 
// of the game. The program will recognize the game is won when all the rings are in the C peg and will count the moves it took to 
// finish the game.

#pragma once

#include <iostream>
#include <vector>
#include "input.h"
using namespace std;

class TowerOfHanoi
{
private:

    vector<int> vectorA;
    vector<int> vectorB;
    vector<int> vectorC;
    int rings;
    bool gameOver;
    bool winner;
    string message;

public:
    //default constructor
    TowerOfHanoi()
    {
        rings = 0;
        vectorA.empty();
        vectorB.empty();
        vectorC.empty();
        gameOver = false;
        winner = false;
        message = "";
    }

    //precondition: input must be a char value of either A, B or C
    //postcondition: this will assign the vectors from the private fields according to the char that was inputted
    vector<int> assignVector(char vectorChoice)
    {
        if (vectorChoice == 'A')
        {
            return vectorA;
        }
        if (vectorChoice == 'B')
        {
            return vectorB;
        }
        if (vectorChoice == 'C')
        {
            return vectorC;
        }
    }

    //precondition: objects must be an integer vector and a char value of either A,B or C
    //postcondition: this will assign the vector values onto the private fields of the class in accordance to the char provided
    void setVector(vector<int> vect, char X) {

        if (X == 'A')
        {
            vectorA = vect;
        }
        if (X == 'B')
        {
            vectorB = vect;
        }
        if (X == 'C')
        {
            vectorC = vect;
        }
    }

    //precondition: no condition
    //postcondition: this will assign the value of message to ""
    void resetMessage()
    {
        message = "";
    }

    //precondition: no condition
    //postcondition: this will print out the title of the game and an error message below it
    void displayErrorMessage() {

        cout << endl << "\t\t\t     Tower of Hanoi" << endl;;
        cout << endl << "     " << message << endl;
    }

    //precondition: must be positive int values greater than zero 
    //postcondition: will check if the ring being transferred to is smaller than the one in the 
    //destination peg, if not then will return false, and the message value will change

    bool ringSizeCheck(int fromInt, int toInt) {

        if (fromInt > toInt)
        {
            message = "\tERROR: Cannot place big ring on a small ring, Please try again";
            return false;
        }
        return true;
    }

    //precondition: value must be an integer vector
    //postcondition: will check if the vector is empty, if so will return true and the value of message wil change
    bool emptyPeg(vector<int> vect) {

        if (vect.size() == 0)
        {
            message = "\tERROR: There are no rings placed in that peg to move, Please try again";
            return true;
        }

        return false;
    }

    //precondition: integer must be zero or greater
    //postcondition: will check if the ring value on the top of the destination peg is zero, if so will return true
    bool toRingCheck(int ringValue) {

        if (ringValue == 0)
        {
            return true;
        }

        return false;
    }

    //precondition: values must be chars
    //postcondition: will check if the chars are the same, if so will return true and the value of message will change
    bool samePegChoseCheck(char from, char to) {

        if (from == to)
        {
            message = "\tERROR: Cannot choose the same peg, Please try again";
            return true;
        }
        return false;
    }


    //precondition: must be 2 char values and 2 int vectors
    //postcondition: this will go through all the checks, and if it is a legal move then will return true
    bool CheckCheck(char from, char to, vector<int> fromVector, vector<int> toVector) {

        bool legal = true;

        int fromRingInt = ringDiameter(fromVector);
        int toRingInt = ringDiameter(toVector);

        if (samePegChoseCheck(from, to))
        {
            return false;

        }
        if (emptyPeg(fromVector))
        {
            return false;
        }

        if (toRingCheck(toRingInt)) {

            return true;
        }

        else if (!ringSizeCheck(fromRingInt, toRingInt))
        {
            return false;
        }

        return legal;
    }

    //precondition: there must be at least one ring in the game for this to work properly
    //postcondition: this will check if all the rings are in vectorC, 
    //if so will adjust the booleans of GameOver and Winner which will end the game
    void checkGame()
    {

        if (vectorC.size() == rings)
        {
            setGameOver();
            setWinner();
        }
    }

    //precondition: value must be a int vector
    //postcondition: will return the value of the last element of the vector, if empty will return zero
    int ringDiameter(vector<int> vector)
    {

        if (vector.size() > 0)
        {
            int diameter = vector.at(vector.size() - 1);
            return diameter;
        }
        else if (vector.size() <= 0)
        {
            return 0;
        }
    }

    //precondition: first two values must be chars of A B or C and the third value must be integer
    //postcondition: this will check if the move is legal if so will carry out the transfer of rings and
    // increment the number of turns by one
    void moveRings(char from, char to, int& turns)
    {

        vector<int> fromVector = assignVector(from);
        vector<int> toVector = assignVector(to);


        if (CheckCheck(from, to, fromVector, toVector) == false)
        {

            return;
        }

        int tempIntFrom;
        int tempIntTo;

        tempIntFrom = fromVector.at(fromVector.size() - 1);

        if (toVector.size() > 0)
        {
            tempIntTo = toVector.at(toVector.size() - 1);
        }

        if (toVector.size() == 0)
        {
            fromVector.pop_back();
            toVector.push_back(tempIntFrom);
        }
        else
        {
            fromVector.pop_back();
            toVector.push_back(tempIntFrom);
        }

        setVector(fromVector, from);
        setVector(toVector, to);
        turns = ++turns;
    }

    //precondition: no condition
    //postcondition: this will set the gameOver value to true
    void setGameOver()
    {
        gameOver = true;

    }

    //precondition: no condition
    //postcondition: this will set the Winner value to true
    void  setWinner()
    {
        winner = true;
    }

    //precondition: no condition
    //postcondition: will return the value of gameOver
    bool getGameOver()
    {
        return gameOver;
    }

    //precondition: no condition
    //postcondition: will return the value of Winner
    bool getWinner()
    {
        return winner;
    }

    //precondition: no condition
    //postcondition: this will set the amount of rings for the TowerOfHanoi Class which must be an interger whithin 1-64
    int setRings()
    {
        return rings = inputInteger("\n\tEnter the number of rings (1..64) to begin: ", 1, 64);
        cout << endl;
    }

    //precondition: must be a set amount of rings in the class of TowerOfHanoi
    //postcondition: will set all the numbers to VectorA starting the game
    void setGame()
    {
        for (int i = rings - 1; i >= 0; i--)
        {
            vectorA.push_back(i + 1);
        }
    }

    //precondition: the three vectors must be initialized
    //postcondition: This will output the values of the three vectors from top down 
    //(smallest number on top, also the last element), if there's no value on the position will print out
    // a "|" simulating an empty slot in the peg
    void printRings()
    {

        for (int i = rings - 1; i >= 0; i--)
        {
            cout << "\t\t\t";
            if (vectorA.size() <= i)
            {
                cout << "  |";
            }
            else if (vectorA.size() + 1 > i)
            {
                cout << "  " << vectorA.at(i);
            }
            else
            {
                cout << "ERROR A";
            }

            cout << "\t ";
            if (vectorB.size() <= i)
            {
                cout << "  |";
            }
            else if (vectorB.size() > i)
            {
                cout << "  " << vectorB.at(i);
            }
            else
            {
                cout << "ERROR B";
            }

            cout << "\t  ";
            if (vectorC.size() <= i)
            {
                cout << "  |";
            }
            else if (vectorC.size() + 1 > i)
            {
                cout << "  " << vectorC.at(i);
            }
            else
            {
                cout << "ERROR C";
            }
            cout << "\t\t\t" << endl;
        }
    }

    //precondition: no condition
    //postcondition: this will output the base of the pegs
    void printBase()
    {
        cout << "\t\t       ===|===  ===|===  ===|===   " << endl;
        cout << "\t\t\t  A        B        C   " << endl << endl;
    }

    //precondition: game must be initialize as well as vectors
    //postcondition: will printout the rings and the base together
    void displayTowers()
    {
        cout << endl;
        printRings();
        printBase();
    }
};

//main driver function
void runTowerOfHanoi()
{
    char optionChar;

    cout << "\n\tThe Tower of Hanoi also called the Tower of Brahma or Lucas' Tower is a mathematical game.";
    cout << "\n\tIt consists of three pegs and a number of rings of different sizes, which can slide onto";
    cout << "\n\tany peg.The game starts with the rings in a neat stack in ascending order of size on one";
    cout << "\n\tpeg, the smallest at the top, thus making a conical shape.";
    cout << "\n\n\tThe objective of the game is to move the entire stack from the starting peg - A to ending peg - B,";
    cout << "\n\tobeying the following simple rules :";
    cout << "\n\t      1. Only one disk can be moved at a time.";
    cout << "\n\t      2. Each move consists of taking the upper disk from one of the stacks and";
    cout << "\n\t         placing it on top of another stack or on an empty peg.";
    cout << "\n\t      3. No larger disk may be placed on top of a smaller disk.\n";

    do
    {
        bool winner = false;
        TowerOfHanoi towerObj;

        towerObj.setRings();
        towerObj.setGame();

        char fromChar = '0', toChar = '0';
        int moves = 0;
        clrScrn();
        cout << endl << "\t\t\t     Tower of Hanoi" << endl << endl << endl;
        do
        {

            towerObj.displayTowers();

            fromChar = inputChar("\tSelect the top disk from the start peg( A, B, C or Q-quit): ", static_cast<string>("abcq"));

            if (fromChar == 'Q')
            {
                break;
            }

            toChar = inputChar("\tSelect the peg( A, B, C or Q-quit) to move the selected disk): ", static_cast<string>("abcq"));

            if (toChar == 'Q')
            {
                break;
            }

            towerObj.moveRings(fromChar, toChar, moves);

            towerObj.checkGame();

            clrScrn();

            towerObj.displayErrorMessage();

            towerObj.resetMessage();
            winner = towerObj.getWinner();

        } while (towerObj.getGameOver() == false);

        if (winner == true)
        {

            towerObj.displayTowers();
            cout << "\t\t\tCongratulations you have won!" << endl;
        }
        cout << endl << "\t\t\t\tMoves: " << moves << endl << endl;

        optionChar = inputChar("\n\t\tPlay again? y-yes n-no: ", static_cast<string> ("yn"));


    } while (optionChar != 'N');
    clrScrn();
}