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
#include "input.h"
#include <vector>
//prototypes

/**
* Class holding the board
*/
class Board {
private:
	char** gameBoard;
	char* compSym = nullptr;
	char* usrSym = nullptr;
	int width = int(3);

public:

	//[deafult constructor]
	Board() {

		//initialize the board
		
		gameBoard = new char*[width];
		for (int i = 0; i < width; i++) {
			gameBoard[i] = new char[width];
		}//end for
		
		//end initialize the board



	}

	//destructor
	~Board() {

		




	}//end destructor


	//stub
	string getBoard() const {
		return "";


	}//end getBoard

	
	//stub
	void setMove(char chSym, int x, int y) {

	}//end setMove

	//stub
	bool isValidMove() {
		return true;
	
	}//end isValdMove

	//stub
	bool checkWinner() const {
		return false;
	
	}//end checkWinner


	char& operator []( int intMove ) {

	}//end [] operator



};//end class Board




//AI Class since it checks its moves agains the implemented board in an internal board
/**
* 
* 
* 
* 
*/
class TicTacToeAI{ //: Board {
private:
	Board compBoard;


public:

	//[Default Constructor]
	TicTacToeAI() {

	}

	int getNextMove() {

	}



};




/**
* Driver class for TicTacToe Game
* 
* 
* 
*/
class TicTacToe {
private:
	bool* compMove = nullptr;
	bool* userMove = nullptr;
	Board gmBoard;





public:

	/// [Default Constructor]
	TicTacToe() {
		


	}


	~TicTacToe() {



	}//end desctructor





};



