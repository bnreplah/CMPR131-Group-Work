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

public:
    //default constructor
    TowerOfHanoi() {

        rings = 0;
        vectorA.empty();
        vectorA.empty();
        vectorA.empty();
        gameOver = false;
        winner = false;
    }

    void assignVector(char from, char to)
    {

        if (from == 'A')
        {
        }


    }
    void checkLegalMove()
    {


    }
    void moveRings(char from, char to)
    {


    }

    void checkGame() {
        bool gameDone = false;
        bool gameWon = false;

        if (vectorC.size() == rings)
        {
            bool gameDone = true;
            bool gameWon = true;

            setGameOver(gameDone);
            setWinner(gameWon);
        }
    }
    void setGameOver(bool gameSet) {

        gameOver = gameSet;
    }

    void  setWinner(bool win) {

        winner = win;
    }

    bool getGameOver() {

        return gameOver;
    }
    bool getWinner() {

        return winner;
    }
    int setRings()
    {
        return rings = inputInteger("\n\tEnter the number of rings (1..64) to begin: ", 1, 64);
        cout << endl;

    }

    void setGame()
    {
        for (int i = 0; i < rings; i++)
        {
            vectorA.push_back(i + 1);
        }
    }

    void printRings()
    {

        for (int i = 0; i < rings; i++)
        {
            cout << "\t\t";
            if (vectorA.size() <= i) {
                cout << "  |";
            }
            else if (vectorA.size() + 1 > i) {
                cout << "  " << vectorA.at(i);
            }
            else {
                cout << "ERROR A";
            }

            cout << "\t ";

            if (vectorB.size() <= i) {
                cout << "  |";
            }
            else if (vectorB.size() > i)
            {
                cout << "  " << vectorB.at(i);
            }
            else {
                cout << "ERROR B";
            }


            cout << "\t  ";
            if (vectorC.size() <= i) {
                cout << "  |";
            }
            else if (vectorC.size() + 1 > i) {
                cout << "  " << vectorC.at(i);
            }
            else {
                cout << "ERROR C";
            }
            cout << "\t\t" << endl;
        }
    }
    void printBase() {

        cout << "\t       ===|===  ===|===  ===|===   " << endl;
        cout << "\t\t  A        B        C   " << endl;
    }

    void displayTowers()
    {
        cout << endl;
        printRings();
        printBase();
    }
};


void runTowerOfHanoi() {
        
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

   
        TowerOfHanoi towerObj;
    
    
        towerObj.setRings();
        
        towerObj.setGame();
    
        char fromChar = '0', toChar = '0';
    
        int moves = 0;
        cout << endl << "\tTower of Hanoi" << endl;
    
        do
    
        {
        
            towerObj.displayTowers();
        
            fromChar = inputChar("Select the top disk from the start peg( A, B, C or Q-quit: ", "ABCQ");
        
            toChar = inputChar("Select the peg( A, B, C or Q-quit) to move the selected disk: ", "ABCQ");
        
            towerObj.checkGame();
        
            moves++;
    
        } while (towerObj.getGameOver() != false || fromChar != 'Q' || toChar != 'Q');

    

        cout << endl << "Moves: " << moves;

        optionChar = inputChar("Play again? y-yes n-no: ", "yn");

    
    } while (optionChar !='N');

    



}






