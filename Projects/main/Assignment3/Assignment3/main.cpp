// File:
// Assignment:
// Professor:
// Team Members:
// 
// 
// 
// 
// Description:
//
//
//
//
//

#pragma once

#include <iostream>
#include <vector>
#include "input.h"
#include "TowerOfHanoi.h"
#include "TicTacToe.h"
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
                         "\n" + string(100 , char(196)) +
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
    

    //start playing
    TicTacToe gamePlay = TicTacToe();
    gamePlay.play();

}
void Option2(){
    runTowerOfHanoi();



}
void Option3(){



}