// File: TowerOfHanoi.h	
// Names:
//      Ben Halpern
//		Thien Nguyen
//		Itz Rodriquez
//	Professor Quach
//	CMPR 131

#pragma once

#include <iostream>
#include <vector>
#include "input.h"
#include "TowerOfHanoi.h"
#include "TicTacToe.h"
#include "NQueens.h"
using namespace std;


//prototypes
int menuOption();
void Option1();
void Option2();
void Option3();



int main() {


    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;

        case (1): Option1() ; break;
        case (2): Option2() ; break;
        case (3): Option3() ; break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        
        }
        cout << "\n";
        pause();
    } while (true);

    return EXIT_SUCCESS;

}//end main


int menuOption() {

    header("CMPR131 Chapter 3 - Assignmnet 3 by Thien , Itz, Tony, Jose, and Ben");
    string options[] = { "\n\t\t1 > Tic-Tac-Toe ",
                         "\n\t\t2 > Towers of Hanoi",
                         "\n\t\t3 > n-queens",
                         "\n\t" + string(100 , char(196)) +
                         "\n\t\t0 > exit "

    };
    for (string option : options)
        cout << option;
    header("");

    int optionInteger = inputInteger("\nOption: ", 0, 3);
    clrScrn();
    return optionInteger;

}//end menuOptions

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Option driver functions
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Option1(){

    //TicTacToe instruction here
    cout << "\n       Tic-tac-toe (also known as Noughts and crosses or Xs and Os) is a game for two"
        << "\nplayers, Xand O, who take turns marking the spaces in a 3?3 grid.The player who"
        << "\nsucceeds in placing three of their marks in a horizontal, vertical, or diagonal"
        << "\nrow wins the game."
        << "\nThis tic - tac - toe program plays against the computer.Human player, X, will always"
        << "\nfirst.Time will be recorded for the fastestand the slowest game.Average time will"
        << "\nthen be calculatedand displayed.\n";

    //start playing
    TicTacToe gamePlay = TicTacToe();
    gamePlay.play();

}//end Option1

void Option2(){
    runTowerOfHanoi();



}//end Option2

void Option3(){

    NQueens game;
    game.runNQueens();

}//end Option3