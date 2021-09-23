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
*  board[col][row]
* private methods:
*	checkCol()
*	checkRow()
*	checkDiagR()
*	checkDiagL()
*		
* 
* 
* public methods:
*	getBoard()
*	setBoard()
*	drawBoard()
*	checkWinner()
* 
* 
*/
class Board {
private:
	char** board;
	const int WIDTH = int(3);
	const bool DEBUG = true;
	//char board[3][3];
	char compSym;
	char usrSym;
	

	//##############################################################################################
	//	checkWin methods (private)
	//##############################################################################################



	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//! NOTE:
	//! Includes computer checks, that need to be moved to compAI class
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



	/// Method: 
	/// Precondition:
	/// Postcondition:
	bool checkCol( char symb) {
		if (DEBUG) header("[DEBUG]: COL");
		int emptySpace = -1;
		int blockingSpace = 0;
		int colItter = 0;
		bool inCol = false;

		//end declarations

		for (int row = 0; row < WIDTH; row++) {//loops as long as the inCol is false and within bounds of array
			if (DEBUG)std::cout << "row:" + row);
			colItter = 0;
			inCol = false;
			for (int col = 0; col < WIDTH; col++) {
				if (DEBUG)std::cout << "col: " << col;//debugging
				if (DEBUG)std::cout << board[col][row];//debugging
				if (board[col][row] == symb)//if symbol is found
					colItter++;//raise itterator
				else if (board[col][row] == 0) {//if empty space
					emptySpace = compBoard.convToLeg(col, row);//set emptySpace value
					if (DEBUG)std::cout << "\nES: " << emptySpace;//debugging
				}//end else if

				if (board[col\[row] != symb)//if not the symbol looking for
					blockingSpace = compBoard.convToLeg(col, row);//set the blocking space

				if (colItter == 2)
					inCol = (emptySpace == blockingSpace);//if the space to block is already taken don't set inCol to true
			}//end for
			if (DEBUG)std::cout << "inCol: " + inCol);
			if (DEBUG) {
				std::cout << "blockSpace: " + blockingSpace);
				std::cout << "emptySpace: " + emptySpace);
				std::cout << "colItter: " + colItter);
			}//end DEBUG if
			if (inCol)
				return (emptySpace == blockingSpace) ? emptySpace : -1;
		}//end for
		if (DEBUG)std::cout << inCol);//debugging
		return (colItter < 2) ? -1 : ((emptySpace == blockingSpace) ? emptySpace : -1);
		//if the row itterator is less than 2 produce -1, if it is greater than 2 check if the blocking space and epty space are the same
	   //if the blocking space and empty space are the same then output the empty space, otherwise -1
	}



	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//! NOTE:
	//! Includes computer checks, that need to be moved to compAI class
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


	/// Method: 
	/// Precondition:
	/// Postcondition:
	bool checkRow(char symb) {
		int emptySpace = -1;
		int blockingSpace = 0;
		int rowItter = 0;
		bool inRow = false;
		//end declarations


		for (int col = 0; col < WIDTH && !inRow; col++) {//loops as long as is within bounds, and there are not 2 in a row
			rowItter = 0;//resets itterator if on next row 
			if (DEBUG) printf("\ncol: %i" , col);//debugging
			for (int row = 0; row < WIDTH; row++) {
				if (DEBUG)printf("\nrow: %i " , row);//debugging
				if (DEBUG)std::cout << (getBoard(col, row));//debugging
				if (getBoard(col, row) == symb)//if symbol found
					rowItter++;//raise itterator
				else if (getBoard(col, row) == 0) {//if empty space
					emptySpace = compBoard.convToLeg(col, row);//set emptySpace value
					if (DEBUG)std::cout << "\nES:" << emptySpace;//debugging
				}//end else if

				if (getBoard(col, row) != symb)
					blockingSpace = compBoard.convToLeg(col, row);

				if (rowItter == 2)//if there are 2 in a row
					inRow = (emptySpace == blockingSpace);//check to see if the blocking space and the empty space are the same
			}//end for
			if (DEBUG) {
				std::cout << "\nblockSpace: " << blockingSpace;
				std::cout << "\nemptySpace: " << emptySpace;
				std::cout << "\nrowItter: " << rowItter;
			}//end DEBUG if  

			if (inRow)
				return (emptySpace == blockingSpace) ? emptySpace : -1;//if the blocking space and empty space are the same then output the empty space, otherwise -1
		}//end for
		if (DEBUG) std::cout << (inRow);//debugging
		return (rowItter < 2) ? -1 : ((emptySpace == blockingSpace) ? emptySpace : -1);
		//if the row itterator is less than 2 produce -1, if it is greater than 2 check if the blocking space and epty space are the same
		//if the blocking space and empty space are the same then output the empty space, otherwise -1
	}

	///// Method: 
	///// Precondition:
	///// Postcondition:
	//bool checkDiagR(char symb) {
	//	return true;
	//}

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//! NOTE:
	//! Includes computer checks, that need to be moved to compAI class
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	/// Method: 
	/// Precondition:
	/// Postcondition:
	bool checkDiag(char symb) {
		if (DEBUG)std::cout << "DIAG");//debugging
		int emptySpace = -1;
		int blockingSpace = 0;
		int diagItter = 0;
		bool inDiag = false;

		//end declarations

		for (int row = 0, col = 0; row < WIDTH && col < WIDTH && !inDiag; row++, col++) {
			if (DEBUG)std::cout << "i:" << row;//debugging
			if (DEBUG)std::cout << "i: " << col;//debugging
			if (DEBUG)std::cout << board[col][row];//debugging
			if (board[col][row] == symb)//if symbol is found
				diagItter++;//increase itterator
			else if (board[col][row] == 0) {//if empty space
				emptySpace = compBoard.convToLeg(col, row);//set emptySpace value
				if (DEBUG)std::cout << "ES:" + emptySpace);//debugging
			}//end else if

			if (board[col][row]!= symb)//if not symbol
				blockingSpace = compBoard.convToLeg(col, row);//set blocking space

			if (diagItter == 2)//if the diagItterator is 2
				inDiag = (emptySpace == blockingSpace);//set the inDiag only if the empty space matches the blocking space

		}//end for
		if (DEBUG) std::cout << "1st inDiag: " << inDiag;
		if (DEBUG) {
			std::cout << "blockSpace: " << blockingSpace;
			std::cout << "emptySpace: " << emptySpace;
			std::cout << "diagItter: " << diagItter;
		}//end DEBUG if  
		//if diagItter is less than 2 set reset the inDiag and do next check
		if (diagItter < 2)
			inDiag = false;
		else//if greater than 2 return value if matched with needing blockign 
			return (diagItter > 2) ? ((emptySpace == blockingSpace) ? emptySpace : -1) : -1;

		//if first inDiag is false, check the other side
		if (!inDiag) {
			emptySpace = 0;
			blockingSpace = 0;;
			for (int row = WIDTH - 1, col = 0; row >= 0 && col < WIDTH && !inDiag; row--, col++) {
				if (DEBUG)std::cout << "i:" + row;//debugging
				if (DEBUG)std::cout << "i: " + col;//debugging
				if (DEBUG)std::cout << board[col, row));//debugging

				if (board[col][row] == symb)
					diagItter++;
				else if (board[col][row] == 0) {
					emptySpace = compBoard.convToLeg(col, row);
					if (DEBUG)std::cout << "ES:" + emptySpace;//debugging
				}//end else if

				if (board[col][row] != symb)
					blockingSpace = compBoard.convToLeg(col, row);

				if (DEBUG) {
					std::cout << "blockSpace: " + blockingSpace;
					std::cout << "emptySpace: " + emptySpace;
					std::cout << "diagItter: " + diagItter;

				}//end DEBUG if  

				if (diagItter == 2)
					inDiag = (emptySpace == blockingSpace);

			}//end for
			if (inDiag)
				return (emptySpace == blockingSpace) ? emptySpace : -1;
		}//end if
		if (DEBUG)std::cout << "2nd inDiag:" + inDiag;//debugging
		return (diagItter < 2) ? -1 : ((emptySpace == blockingSpace) ? emptySpace : -1);
	}

	/// Method: 
	/// Precondition:
	/// Postcondition:
	int convertMove(int col, int row) {
		return col + (row * 3);
	}


public:


	//##############################################################################################
	//	Constructors
	//##############################################################################################


	/// [DEFAULT CONSTRUCTOR]
	Board() {
		//initialize the board

		board = new char* [WIDTH];
		for (int i = 0; i < WIDTH; i++) {
			board[i] = new char[WIDTH];
		}//end for

		//end initialize the board

		this->compSym = char('X');
		this->usrSym = char('O');


	}//end Board [DEFAULT CONSTRUCTOR]

	
	/// [ARGUMENT CONSTRUCTOR]
	///	Precondition:
	/// Postcondition:
	Board(char cSym, char uSym) {

		//initialize the board
		
		board = new char*[WIDTH];
		for (int i = 0; i < WIDTH; i++) {
			board[i] = new char[WIDTH];
		}//end for
		
		//end initialize the board

		this->compSym = char(cSym);
		this->usrSym = char(uSym);


	}//end Board [ARGUMENT CONSTRUCTOR]

	/// [DESTRUCTOR]
	~Board() {

		for (int i = 0; i < WIDTH; i++) {
			delete board[i];
		}
		delete []board;

	}//end destructor


	//#############################################################################################
	// overloaded operators
	//##############################################################################################

	/// Method: 
	/// Precondition:
	/// Postcondition:
	char& operator [](int intMove) {
		int col = intMove / 3;
		int row = intMove % 3;

		return board[col][row];
	}//end [] operator

	Board& operator =(const Board& rightBoard) {
		for (int i = 0; i < WIDTH ; i++)
			for (int j = 0; j < WIDTH; j++) {
				this->board[i][j] = rightBoard.board[i][j];
			}//end nested for

		this->compSym = rightBoard.compSym;
		this->usrSym = rightBoard.usrSym;
	}


	//##############################################################################################
	//	mutators ( set methods )
	//##############################################################################################


	/// Method: 
	/// Precondition:
	/// Postcondition:
	void clear() {

		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < WIDTH; j++) {
				board[i][j] = 0;
			}
		}
		if (DEBUG) mDrawBoard();

	}//end clear


	//##############################################################################################
	//	Accessors ( get methods )
	//##############################################################################################





	/// Method: 
	/// Precondition:
	/// Postcondition:
	char** getBoard() const {
		return (this->board);
	}//end getBoard

	char& getBoard(int col, int row) {
		return board[col][row];
	}



	/// Method: 
	/// Precondition:
	/// Postcondition:
	void mDrawBoard() const {

		for (int row = 0; row < WIDTH; row++) {
			for (int col = 0; col < WIDTH; col++) {
				if (col != 2)
					std::cout << "\t" << board[row][col] << "\t|";//change to use prinf if possible
				else
					std::cout << "\t" << board[row][col];
				//System.out.print(col);
			}//end for
			cout << "\n";
			if (row != 2)
				cout << "\n--------------------------------------------------\n";
			cout << "\n";
		}//end for
		if (DEBUG)std::cout << "\n[DEBUG]: " << "Board drawn\n";
		if (DEBUG)std::cout << "\n[DEBUG]: " << "Im in draw Board";


	}//end mDrawBoard


	/// Method: 
	/// Precondition:
	/// Postcondition:
	void setMove(char chSym, int x, int y) {
		int move = convertMove(x, y);
	}//end setMove


	/// Method: 
	/// Precondition:
	/// Postcondition:
	bool isEmpty(int col, int row) const{
		if(DEBUG) std::cout << "[DEBUG]: " << (int)board[row][col] << endl;//debugging
		return board[col][row] == 0; 
		
	}//end isEmpty


	

	//##############################################################################################
	//	check methods
	//##############################################################################################


	/// Method: 
	/// Precondition:
	/// Postcondition:
	bool checkWinner() const {
		return false;

	}//end checkWinner


	/// Method: 
	/// Precondition:
	/// Postcondition:
	bool isValidMove(int x, int y) const {
		if (this->isEmpty(x, y))
			return true;

	}//end isValdMove





	//##############################################################################################
	//	static functions
	//##############################################################################################

	// Need to do: improve graphical draw of the board
	
	/// Method: 
	/// Precondition:
	/// Postcondition:
	static void drawBoard(char board[3][3], const int WIDTH, const bool DEBUG = true) {

		for (int row = 0; row < WIDTH; row++) {
			for (int col = 0; col < WIDTH; col++) {
				if (col != 2)
					std::cout << "\t" << board[row][col] << "\t|";//change to use prinf if possible
				else
					std::cout << "\t" << board[row][col];
				//System.out.print(col);
			}//end for
			cout << "\n";
			if (row != 2)
				cout << "\n--------------------------------------------------\n";
			cout << "\n";
		}//end for
		if (DEBUG)std::cout << "\n[DEBUG]: " << "Board drawn\n";
		if (DEBUG)std::cout << "\n[DEBUG]: " << "Im in draw Board";


	}//end drawBoard [static]


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
	TicTacToeAI(Board currentBoard) {
		compBoard = currentBoard;
	}//end Default constructor




	// Uses minimax algorithm
	//	firt check if the center i available,
	// 	then check if the corner are available
	//	If none of these options are available then will move to block the other player
	/// Method: 
	/// Precondition:
	/// Postcondition:
	int preferredOpen() const {
		if (compBoard.isEmpty(1, 1))
			return 4;//if the center is open, take the center.
		//then checks corners
		else if (compBoard.isEmpty(0, 0))
			return 0;
		else if (compBoard.isEmpty(0, 2))
			return 2;
		else if (compBoard.isEmpty(2, 0))
			return 6;
		else if (compBoard.isEmpty(2, 2))
			return 8;
		return -1;//return -1 if none of the values are available
	}//end preferedOpen


	/// Method: 
	/// Precondition:
	/// Postcondition:
	int getNextMove() {

	}//end getNextMove


	int checkWin() {
		if (DEBUG)std::cout << checkInRow(symb));//end debugging
		if (checkInRow(symb) != -1)
			return checkInRow(symb);
		else if (checkInCol(symb) != -1)
			return checkInCol(symb);
		else if (checkInDiag(symb) != -1)
			return checkInDiag(symb);
		else if (preferredOpen() != -1)
			return preferredOpen();
		return -1;
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
	Board gameBoard;
	int userWins = int();
	int compWins = int();
	int draws = int();
	string record = string("ScoreSheet.txt");//filepath to where storing records, if letf blank defaults to ScoreSheet.txt




public:

	/// [Default Constructor]
	TicTacToe() {
		


	}

	
	/// [DESTRUCTOR]
	~TicTacToe() {



	}//end desctructor



	/// Method: 
	/// Precondition:
	/// Postcondition:
	void play() {

	}



};



