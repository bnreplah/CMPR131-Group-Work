// File: TicTacToe.h	
// Names:
//      Ben Halpern
//		Thien Nguyen
//		Itz Rodriquez
//	Professor Quach
//	CMPR 131
/*
* Description: This program plays the tic tac toe game against the computer using the minimax algorithm as an AI
* 
* 
*/


#pragma once



#include <iostream>
#include "input.h"
#include <vector>
#include <fstream>
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
	char board[3][3];/// board[col][row]
	const int WIDTH = int(3);
	const bool DEBUG = false;
	char compSym = char();
	char usrSym = char();
	
	//set move private member function for setting the char symb a the position
	bool setMove(int col, int row, char symb) {
		if (isEmpty(col, row)) {
			board[col][row] = symb;
			return true;
		}
		else
			return false;
	}//end setMove



public:


	//##############################################################################################
	//	Constructors
	//##############################################################################################


	/// [DEFAULT CONSTRUCTOR]
	Board() {
		//initialize the board
		//board = new char*[WIDTH];
		//for (int i = 0; i < WIDTH; i++) {
		//	*(board + i) = new char[WIDTH];
		//	
		//}//end for
		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < WIDTH; j++)
				*(*(board + i) + j) = 0;
		}

		
		//end initialize the board

		this->compSym = char('X');
		this->usrSym = char('O');


	}//end Board [DEFAULT CONSTRUCTOR]

	
	/// [ARGUMENT CONSTRUCTOR]
	///	Precondition:
	/// Postcondition:
	Board(char cSym, char uSym) {
		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < WIDTH; j++)
				*(*(this->board + i) + j) = char();
		}//end for
		//end initialize the board

		this->compSym = char(cSym);
		this->usrSym = char(uSym);


	}//end Board [ARGUMENT CONSTRUCTOR]

	Board(const Board& boardCopy){
		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < WIDTH; j++)
				*(*(this->board + i) + j) = *(*(boardCopy.board + i) + j);
		}//end for

		this->compSym = char(boardCopy.compSym);
		this->usrSym = char(boardCopy.usrSym);

	}//copy constructor



	/// [DESTRUCTOR]
	//~Board() {
	//	
	//	/*for (int i = 0; i < WIDTH; i++) {
	//		
	//			delete *(this->board + i) ;
	//	}
	//	delete [](this->board);*/

	//
	//}//end destructor


	//#############################################################################################
	// overloaded operators
	//##############################################################################################

	/// Method: 
	/// Precondition:
	/// Postcondition:
	char& operator [](int intMove) {
		int col = intMove / 3;
		int row = intMove % 3;

		return *(board + col)[row];
	}//end [] operator


	void operator =(const Board& rightBoard) {
		for (int i = 0; i < WIDTH ; i++)
			for (int j = 0; j < WIDTH; j++) {
				*(*(board + i ) + j) = rightBoard.getBoard(i, j);
			}//end nested for

		this->compSym = rightBoard.compSym;
		this->usrSym = rightBoard.usrSym;
	}//end operator = 


	//##############################################################################################
	//	mutators ( set methods )
	//##############################################################################################


	int setMove(int move, char symbol) {
		int row = convertToRow(move);
		int  col = convertToCol(move);
		cout << (col) << " : " << (row);//debugging
		//i.e. if move = 5; col = 2; row = 
		board[col][row] = symbol;
		
		return move;
	}//end getPlayerMove

	
	/// Method: clear 
	/// Precondition:
	/// Postcondition:
	void clear() {

		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < WIDTH; j++) {
				*(*(board + i) + j) = 0;
			}
		}
		if (DEBUG) mDrawBoard();

	}//end clear


	/// Method: setBoard
	/// Precondition:
	/// Postcondition:
	char& setBoard(int col, int row) {
		return *(board + col)[row];
	}

	/// Method: setCompMove
	/// Precondition: 
	/// Postcondition: 
	bool setCompMove(int leg) {
		return setMove(leg, compSym);
	}
	
	/// Method: setUsrMove
	/// Precondition: 
	/// Postcondition: 
	bool setUsrMove(int col, int row){
		if (isEmpty(col, row))
			return setMove(col, row, usrSym);
		else
			return false;
	}//end 
	/// Method: setUsrMove
	/// Precondition: 
	/// Postcondition: 
	bool setCompMove(int col, int row){
		if (isEmpty(col, row))
			return setMove(col, row, compSym);
		else
			return false;
	}//end 

	//##############################################################################################
	//	Accessors ( get methods )
	//##############################################################################################

	///// Method: getBoard
	///// Precondition:
	///// Postcondition:
	//char getBoard() {
	//	return board;
	//}//end getBoard

	/// Method: getBoard 
	/// Precondition: 
	/// Postcondition: 
	char getBoard(int col, int row) const {
		return *(*(board + col) + row);
	}//end getBoard const

	/// Method: mDrawBoard
	/// Precondition: N/A
	/// Postcondition: draws out the board
	void mDrawBoard() const {

		for (int row = 0; row < WIDTH ; row++) {
			for (int col = 0; col < WIDTH ; col++) {
				if (col < WIDTH - 1)
					std::cout << "\t" << *(*(board + col) + row) << "\t" << string(1,char(186));//change to use prinf if possible
				else
					std::cout << "\t" << *(*(board + col) + row) << "\t";
				//System.out.print(col);
			}//end for
			std::cout << "\n";
			if (row < WIDTH - 1)
				std::cout << "\n" << string(50, char(205)) << "\n";
			std::cout << "\n";
		}//end for
		if (DEBUG)std::cout << "\n[DEBUG]: " << "Board drawn\n";
		if (DEBUG)std::cout << "\n[DEBUG]: " << "Im in draw Board\n";


	}//end mDrawBoard



	/// Method: isEmpty
	/// Precondition:
	/// Postcondition:
	bool isEmpty(int col, int row) const{
		if(DEBUG) std::cout << "\n[DEBUG]: " << *(*(board + row) + col) << endl;//debugging
		return *(*(board + col) + row) == 0;
		
	}//end isEmpty

	/// Method: isEmpty
	/// Precondition: N/A
	/// Postcondition: 
	bool isEmpty(int leg) const {
		int col = convertToCol(leg);
		int row = convertToRow(leg);
		if (DEBUG) std::cout << "\n[DEBUG]: " << *(*(board + col) + row) << endl;//debugging
		return *(*(board + col) + row) == 0;

	}//end isEmpty


	/// Method: convertToLeg
	/// Precondition:
	/// Postcondition:
	int convertToLeg(int col, int row)const  {
		return col + (row * WIDTH);
	}//end convertToLeg


	/// Method: convertToCol
	/// Precondition: (int) is a leg value of the quadrant of the tic tac toe board from 0 to 9 
	/// Postcondition: 
	int convertToCol(int leg) const{
		return leg % WIDTH;
	}//end convertToCol

	/// Method: convertToRow
	/// Precondition: (int) is a leg value of the quadrant of the tic tac toe board from 0 to 9
	/// Postcondition: returns the leg into a row value
	int convertToRow(int leg) const{
		return leg / WIDTH;
	}//end convertToRow

	/// Method: getCompSym
	/// Precondition: N/A
	/// Postcondition: returns the symbol for the computer
	char getCompSym() const{
		return this->compSym;
	}//end getCompSym

	/// Method: getUsrSym
	/// Precondition: N/A
	/// Postcondition: returns the symbol for the user
	char getUsrSym() const {
		return this->usrSym;
	}//end getUsrSym

	//##############################################################################################
	//	check methods
	//##############################################################################################

	/// Method: checkWinner
	/// Precondition: (char) symb is the symb to check for winner
	/// Postcondition: returns true if the char is that of the winner of the game
	bool checkWinner(char symb) const {
		//bool winner = false;
		int rowItter = 0;
		//bool inRow = false;
		//int emptySpace = -1;
		//int blockingSpace = 0;
		int diagItter = 0;
		bool inDiag = false;
		int colItter = 0;
		//bool inCol = false;

		//the last three variables are succesion counters 

		//checks diagonal
		if (DEBUG)std::cout << "\nDIAG\n";//debugging


		//end declarations

		for (int row = 0, col = 0; row < WIDTH && col <= WIDTH; row++, col++) {
			if (DEBUG)std::cout << "\ni:" << row << "\n";//debugging
			if (DEBUG)std::cout << "\ni: " <<  col << "\n";//debugging
			if (DEBUG)std::cout << getBoard(col, row) << "\n";//debugging
			if (getBoard(col, row) == symb)//if symbol is found
				diagItter++;//increase itterator


		}//end for
		if (DEBUG) std::cout << "\n" << "1st inDiag: " << inDiag << "\n";

		//if diagItter is less than 2 set reset the inDiag and do next check
		if (diagItter < WIDTH)
			inDiag = false;
		else//if greater than 2 return value if matched with needing blockign 
			return (diagItter == WIDTH);

		//if first inDiag is false, check the other side
		if (!inDiag) {
			diagItter = 0;
			for (int row = WIDTH - 1, col = 0; row >= 0 && col < WIDTH; row--, col++) {
				if (DEBUG)std::cout << "\n" <<"i:" << row << "\n";//debugging
				if (DEBUG)std::cout << "\n" << "i: " << col << "\n";//debugging
				if (DEBUG)std::cout << "\n" << getBoard(col, row) << "\n";//debugging

				if (getBoard(col, row) == symb)
					diagItter++;

				if (DEBUG) {
					std::cout << "diagItter: " << diagItter << "\n";

				}//end DEBUG if  


			}//end for

		}//end if
		if (DEBUG)std::cout << "\n2nd inDiag:" << inDiag << "\n";//debugging
		if (diagItter == 3)
			return true;


		//end check diagonal

		if (DEBUG) std::cout << "\n" << "Row" << "\n";// debugging
		//row check

		//end declarations


		for (int col = 0; col < WIDTH; col++) {//loops as long as is within bounds, and there are not 2 in a row
			rowItter = 0;//resets itterator if on next row 
			if (DEBUG) std::cout << "\n" << "col:" << col << "\n";//debugging
			for (int row = 0; row < WIDTH; row++) {
				if (DEBUG)std::cout << "\n" << "row: " << row << "\n";//debugging
				if (DEBUG)std::cout << getBoard(col, row) << "\n";//debugging

				if (getBoard(col, row) == symb)//if symbol found
					rowItter++;//raise itterator


				if (rowItter == 3)//if reaches 3 before reset on new row
					return true;

			}//end for
			if (DEBUG) {
				std::cout << "\n" << "rowItter: " << rowItter << "\n";
			}//end DEBUG if  


		}//end for
		//if(DEBUG) std::cout << (inRow);//debugging
		if (rowItter == 3)//if exits loop at 3
			return true;

		//column check
		if (DEBUG) std::cout << "\n" << "COL" << "\n";

		//end declarations

		for (int row = 0; row < WIDTH; row++) {//loops as long as the inCol is false and within bounds of array
			if (DEBUG)std::cout << "row:" << row << "\n";
			colItter = 0;
			//inCol = false;
			for (int col = 0; col < WIDTH; col++) {
				if (DEBUG)std::cout << "\n" << "col: " << col << "\n";//debugging
				if (DEBUG)std::cout << "\n" << getBoard(col, row) << "\n";//debugging

				if (getBoard(col, row) == symb)//if symbol is found
					colItter++;//raise itterator

				if (colItter == 3)
					return true;
			}//end for
			//if(DEBUG)std::cout << ("inCol: "+inCol);
			if (DEBUG) {
				std::cout << "colItter: " << colItter << "\n";
			}//end DEBUG if

		}
		//if(DEBUG)std::cout << (inCol);//debugging
		//end for
		return colItter == 3;

	}//end checkWinner

	/// Method: isValidMove
	/// Precondition: (int) x, and y is a move within the matrix from 0, 2 for both x and y inclusive
	/// Postcondition: returns true if the move isn't empty
	bool isValidMove(int x, int y) const {
		return this->isEmpty(x, y);
		

	}//end isValdMove


	/// Method: isValidMove
	/// Precondition: N/A
	/// Postcondition: returns true if its a cats game
	bool isDraw() {
		int spacesFilled = 0;
		for (int i = 0; i < WIDTH; i++)
			for (int j = 0; j < WIDTH; j++)
				if (getBoard(i,j) != 0)
					spacesFilled++;
		//if neither are winners and all the spaces are full

		return !checkWinner(usrSym) && !checkWinner(compSym) && spacesFilled == 9;
	}//end isDraw



	/// Method: drawBoard
	/// Precondition:
	/// Postcondition:
	void drawBoard() {
		
		for (int row = 0; row < WIDTH ; row++) {
			for (int col = 0; col < WIDTH ; col++) {
				if (col < WIDTH - 1)
					std::cout << "\t" << *(*(board + col) + row) <<"\t" << string(1, char(186));//change to use prinf if possible
				else
					std::cout << "\t" << *(*(board + col) + row) << "\t";
				
			}//end for
			std::cout << "\n";
			if (row < WIDTH - 1)
				std::cout << "\n" << string(50, char(205)) << "\n";
			std::cout << "\n";
		}//end for
		if (DEBUG)std::cout << "\n[DEBUG]: " << "Board drawn\n";
		if (DEBUG)std::cout << "\n[DEBUG]: " << "Im in draw Board\n";

	}//end drawBoard


	//##############################################################################################
	//	static functions
	//##############################################################################################

	// Need to do: improve graphical draw of the board
	
	/// Method: drawBoard
	/// Precondition:
	/// Postcondition:
	static void drawBoard(Board board, const int WIDTH, const bool DEBUG = true) {

		for (int row = 0; row < WIDTH; row++) {
			for (int col = 0; col < WIDTH; col++) {
				if (col < WIDTH -1)
					std::cout << "\t" << board.getBoard(col , row) << "\t" <<string(1, char(186));//change to use prinf if possible
				else
					std::cout << "\t" << board.getBoard(col, row) << "\t";
				//System.out.print(col);
			}//end for
			cout << "\n";
			if (row < WIDTH -1 )
				cout << "\n"<< string(50, char(205)) <<"\n";
			cout << "\n";
		}//end for
		if (DEBUG)std::cout << "\n[DEBUG]: " << "Board drawn\n";
		if (DEBUG)std::cout << "\n[DEBUG]: " << "Im in draw Board\n";


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
	const bool DEBUG = false;
	const int WIDTH = 3;

public:

	//[Default Constructor]
	TicTacToeAI(Board currentBoard) {
		compBoard = currentBoard;
	}//end Default constructor


	/// Method: updateBoard
	/// Precondition:
	/// Postcondition:
	void updateBoard(Board currentBoard) {
		compBoard = currentBoard;
		for (int i = 0; i < WIDTH; i++) {
			if (DEBUG) std::cout << "\ni:" << i << "\n";//debugging
			
			for (int j = 0; j < WIDTH; j++) {
				
				if (DEBUG) {
					std::cout << "\n";
					std::cout << "\nj:" << j;//debugging
					std::cout << "\ncomp board: " << compBoard.getBoard(i, j) << "\n";
					compBoard.drawBoard();
				}//end debugging if


				
			}//end for
		
		}//end for
	}//end updateBoard
	
	//-1 no 3 in a row or 2 in a row
	// 9 found 3 in a row
	// else returns the leg index of the position to block the 3 in a row
	int m3inRow(char symb) {
		int inRow = 0;
		int emptySpace = 0;
		for (int col = 0; col < WIDTH; col++) {
			inRow = 0;//reset inRow prior to every row
			for (int row = 0; row < WIDTH; row++) {
				if (compBoard.getBoard(col, row) == symb) {
					inRow++;
				}//end if
				if (compBoard.getBoard(col, row) != compBoard.getUsrSym() && compBoard.getBoard(col, row) != compBoard.getCompSym())
					emptySpace = compBoard.convertToLeg(col, row);
				//end if
			}
			if (inRow == 2) {
				if (compBoard.isEmpty(emptySpace))
					return emptySpace;
				//end if
			}//end if
			if (inRow == 3)
				return 9;//winner found
		}//end for
		return -1;//if not found any 2 inRow
	}
	
	//-1 no 3 in a col or 2 in a col
	// 9 found 3 in a col
	// else returns the leg index of the position to block the 3 in a col
	int m3inCol(char symb) {
		int inCol = 0;
		int emptySpace = 0;
		for (int row = 0; row < WIDTH; row++) {
			inCol = 0;//reset inRow prior to every row
			for (int col = 0; col < WIDTH; col++) {
				if (compBoard.getBoard(col, row) == symb) {
					inCol++;
				}//end if
				if (compBoard.getBoard(col, row) != compBoard.getUsrSym() && compBoard.getBoard(col, row) != compBoard.getCompSym())
					emptySpace = compBoard.convertToLeg(col, row);
				//end if
			}
			if (inCol == 2) {
				if (compBoard.isEmpty(emptySpace))
					return emptySpace;
				//end if
			}//end if
			if (inCol == 3)
				return 9;//winner found
		}//end for
		return -1;//if not found any 2 inRow
	}
	
	//-1 no 3 in a col or 2 in a col
	// 9 found 3 in a col
	// else returns the leg index of the position to block the 3 in a col
	int m3inDiagDown(char symb) {
		int inDiag = 0;
		int emptySpace = 0;
		for (int row = 0, col = 0; row < WIDTH && col < WIDTH; row++, col++) {
			
			if (compBoard.getBoard(col, row) == symb) {
				inDiag++;
			}//end if
			if (compBoard.getBoard(col, row) != compBoard.getUsrSym() && compBoard.getBoard(col, row) != compBoard.getCompSym())
				emptySpace = compBoard.convertToLeg(col, row);
			//end if
			
			if (inDiag == 2) {
				if (compBoard.isEmpty(emptySpace))
					return emptySpace;
				//end if
			}//end if
			if (inDiag == 3)
				return 9;//winner found
		}//end for
		return m3inDiagUp(symb);//if not found find in the up diagonal
	}
	
	//-1 no 3 in a diag or 2 in a diag
	// 9 found 3 in a diag
	// else returns the leg index of the position to block the 3 in a diag
	int m3inDiagUp(char symb) {
		int inDiag = 0;
		int emptySpace = 0;
		for (int row = WIDTH -1, col = 0; row >= 0 && col < WIDTH; row--, col++) {
			
			if (compBoard.getBoard(col, row) == symb) {
				inDiag++;
			}//end if
			if (compBoard.getBoard(col, row) != compBoard.getUsrSym() && compBoard.getBoard(col, row) != compBoard.getCompSym())
				emptySpace = compBoard.convertToLeg(col, row);
			//end if
			
			if (inDiag == 2) {
				if (compBoard.isEmpty(emptySpace))
					return emptySpace;
				//end if
			}//end if
			if (inDiag == 3)
				return 9;//winner found
		}//end for
		return -1;//if not found any 2 inRow
	}
	
	

	// Uses minimax algorithm
	//	firt check if the center is available,
	// 	then check if the corner are available
	//	If none of these options are available then will move to block the other player
	/// Method: preferredOpen
	/// Precondition:
	/// Postcondition:
	int preferredOpen(Board board) const {
		if (board.isEmpty(1, 1))
			return 4;//if the center is open, take the center.
		//then checks corners
		else if (board.isEmpty(0, 0))
			return 0;
		else if (board.isEmpty(2, 0))
			return 2;
		else if (board.isEmpty(0, 2))
			return 6;
		else if (board.isEmpty(2, 2))
			return 8;
		return -1;//return -1 if none of the values are available
	}//end preferedOpen


	/// Method: getNextMove
	/// Precondition:
	/// Postcondition:
	/// uses preferredOpen
	int getNextMove(Board board) {
		int move = -1;
		
		updateBoard(board);
		move = m3inRow(board.getUsrSym());
		if (move == 9)//checks to see if there is a winner
			return 9;//3 in row found in row
		if (move == -1) {
			move = m3inCol(board.getUsrSym());
			if (move == 9)//checks to see if there is a winner
				return 9;//3 in a row found in column
			if (move == -1) {
				move = m3inDiagDown(board.getUsrSym());
				if (move == 9)//checks to see if there is a winner
					return 9;//3 in a row found in either diagonals
				if (move == -1) {//if there are not 2, or 3 in a row with an empty blocking space
					//check to see if can win
					
					
					move = m3inRow(board.getCompSym());
					if (move == 9)//checks to see if there is a winner
						return 9;//3 in row found in row
					if (move == -1) {
						move = m3inCol(board.getCompSym());
						if (move == 9)//checks to see if there is a winner
							return 9;//3 in a row found in column
						if (move == -1) {
							move = m3inDiagDown(board.getCompSym());
							if (move == 9)//checks to see if there is a winner
								return 9;//3 in a row found in either diagonals
							if (move == -1) {//if there are not 2, or 3 in a row with an empty blocking space
								//check to see if can win


								move = preferredOpen(board);
								if (move == -1) {//if preferred open returns -1, and none fo the prefered open are open
									for (int col = 0; col < WIDTH; col++) {//find next open space and return it
										for (int row = 0; row < WIDTH; row++) {
											if (board.isEmpty(col, row))
												return board.convertToLeg(col, row);
										}
									}
								}//end if
								else {
									if (board.isEmpty(move)) {
										return move;
									}//end if
									else
										return -1;
								}//end else
							}//end if
							else
								return move;
						}//end if
						else {
							return move;
						}//end else
					}//end if
					else {
						return move;
					}//end else
				}//end if
				else
					return move;
			}//end if
			else {
				return move;
			}//end else
		}//end if
		else {
			return move;
		}//end else
		return -1;
	}//end getNextMove

	///// Method: CheckWin
	///// Precondition: 
	///// Postcondition: 
	//int checkWin(char symb) {
	//	if (DEBUG)std::cout << "\n" << checkRow(symb);//end debugging
	//	if (DEBUG)std::cout << "\n" << checkCol(symb);//end debugging
	//	if (DEBUG)std::cout << "\n" << checkDiag(symb);//end debugging
	//	if (DEBUG)std::cout << "\n" << preferredOpen(compBoard);//end debugging
	//	if (DEBUG)compBoard.drawBoard();
	//	if (checkRow(symb) != -1)
	//		return checkRow(symb);
	//	else if (checkCol(symb) != -1)
	//		return checkCol(symb);
	//	else if (checkDiag(symb) != -1)
	//		return checkDiag(symb);
	//	else if (preferredOpen(compBoard) != -1)
	//		return preferredOpen(compBoard);
	//	return -1;
	//}


};




/**
* Driver class for TicTacToe Game
* 
* 
* 
*/
class TicTacToe {
private:
	
	Board gameBoard = Board();
	TicTacToeAI computer = TicTacToeAI(gameBoard);
	int userWins = int();
	int compWins = int();
	int draws = int();
	time_t *gameTime = nullptr;
	//string record = string("ScoreSheet.txt");//filepath to where storing records, if letf blank defaults to ScoreSheet.txt
	const bool DEBUG = false;



public:

	/// [Default Constructor]
	TicTacToe() {
		gameTime = new time_t();
		
	}

	
	/// [DESTRUCTOR]
	~TicTacToe() {
		delete gameTime;

	}//end desctructor


	void outToFile( string outText) {
		fstream file = fstream();
		file.open("ScoreSheet.txt", ios::app | ios::out);
		file << outText;
		file.close();
	}


	void play(bool debug = false) {
		
		bool playAgain = bool(false);
		bool winDraw = false;

		do {
			char userSymbol = char('O');
			char compSymbol = char('X');
			bool userStarts = bool();
			bool keepPlaying = bool(true);
			int column = int();
			int row = int();
			int computerMove = int();
			int computerCol = int();
			int computerRow = int();
			string outText = string();
			gameBoard.clear();//clear the board initiall
			time(gameTime);
			do {//main runtime loop
				userStarts = inputChar("would you like to go first (Y)es or (N)o: ", string("YN")) == 'Y';
				if (userStarts) {
					gameBoard.drawBoard();
					do {
						column = inputInteger("\nPlease enter a valid move for the column, (0...2): ", 0, 2);
						row = inputInteger("\nPlease enter a valid move for the row, (0...2): ", 0, 2);
						if (!gameBoard.isEmpty(column, row) && !gameBoard.isValidMove(column, row))
							std::cout << "\nThat move is invalid or taken, Please enter a valid move!\n";
					} while (!gameBoard.isEmpty(column, row));
					gameBoard.setUsrMove(column, row);
					if (debug)std::cout << "\nYour move: col: " << column << " row: " << row << " gameBoard: '" << gameBoard.getBoard(column, row) << "'\n";
					gameBoard.drawBoard();
				}
				do {//as long as no win or draw keep playing
					//######################################################################################################################################
					//computer move block
					computer.updateBoard(gameBoard);//update the computers board with the current board

					if (debug)std::cout << "\nThe computer wants to move: " << computer.getNextMove(gameBoard);

					computerMove = computer.getNextMove(gameBoard);//call the AI getNextMove
					if (computerMove == 9) {//if returns 9 means that there is a winner on the board
						winDraw = gameBoard.checkWinner(compSymbol);//.: check if the computer is a winner
						if (winDraw)//if win stop playing
							keepPlaying = false;
						winDraw = gameBoard.checkWinner(userSymbol);//.: check if the user is a winner
						if (winDraw)//if win stop playing
							keepPlaying = false;
						winDraw = gameBoard.isDraw();
						if (winDraw)//if draw stop playing
							keepPlaying = false;
						break;//break if entered if statement since 9 is not a valid move
					}//end if
					if (computerMove == -1)//if -1 is returned, means that there was an error
						std::cout << "\nError in the computer move block";
					//end if

					if (debug)std::cout << "\nIs that a valid move?: " << boolalpha << gameBoard.isEmpty(computerMove);
					if (debug)std::cout << "\nComputer move: \ncol: " << gameBoard.convertToCol(computerMove);
					if (debug)std::cout << "\nrow: " << gameBoard.convertToRow(computerMove);

					computerCol = gameBoard.convertToCol(computerMove);//convert the value to column 
					computerRow = gameBoard.convertToRow(computerMove);//convert he value to row

					if (gameBoard.isEmpty(computerMove))
						gameBoard.setCompMove(computerCol, computerRow);
					else
						std::cout << "\nError with the AI";
					//end computer move block
					//######################################################################################################################################
					std::cout << "\n";
					gameBoard.drawBoard();

					//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
					//check if the computer is a winner
					if (debug)std::cout << "\nIs the computer a winner: " << gameBoard.checkWinner(compSymbol);
					winDraw = gameBoard.checkWinner(compSymbol);
					if (winDraw)
						keepPlaying = false;
					winDraw = gameBoard.isDraw();
					if (winDraw)
						keepPlaying = false;
					//end computer win check
					//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					if (!winDraw && keepPlaying) {
						keepPlaying = (inputChar("\nWould you like to keep playing? (Y)es or (N)o : ", string("YN")) == 'Y');
						if (keepPlaying) {
							do {
								column = inputInteger("\nPlease enter a valid move for the column, (0...2): ", 0, 2);
								row = inputInteger("\nPlease enter a valid move for the row, (0...2): ", 0, 2);
								if (!gameBoard.isEmpty(column, row) && !gameBoard.isValidMove(column, row))
									std::cout << "\nThat move is invalid or taken, Please enter a valid move!\n";
							} while (!gameBoard.isEmpty(column, row));
							gameBoard.setUsrMove(column, row);
							if (debug)std::cout << "\nYour move: col: " << column << " row: " << row << " gameBoard: '" << gameBoard.getBoard(column, row) << "'\n";
							gameBoard.drawBoard();
						}
						if (debug)std::cout << "\nIs the user a winner: " << gameBoard.checkWinner(userSymbol);
						winDraw = gameBoard.checkWinner(userSymbol);
						if (winDraw)
							keepPlaying = false;
						winDraw = gameBoard.isDraw();
						if (winDraw)
							keepPlaying = false;
					}
				} while (!winDraw && keepPlaying);


				std::cout << "\nThe game is a draw: " << boolalpha << gameBoard.isDraw();
				if (gameBoard.isDraw())
					draws++;
				std::cout << "\nIs the User a Winner: " << boolalpha << gameBoard.checkWinner(userSymbol);
				if (gameBoard.checkWinner(userSymbol))
					userWins++;
				std::cout << "\nIs the Computer a Winner: " << boolalpha << gameBoard.checkWinner(compSymbol);
				if (gameBoard.checkWinner(compSymbol))
					compWins++;
				std::cout << "\nYou were playing for " << (time(0) - *gameTime) << "s ::" << difftime(time(0), *gameTime) << "s";
				*gameTime = (time(0) - *gameTime);
				std::cout << "\nScoreBoard:	computerWins: " << compWins << "  userWins: " << userWins << "  Draws: " << draws;
				outText = "\nScoreBoard:	computerWins: " + to_string(compWins) + "  userWins: " + to_string( userWins) + "  Draws: " + to_string(draws) + "  game time: " + to_string(*gameTime);
				outToFile(outText);
			} while (keepPlaying);
			playAgain = (inputChar("\nWould you like to play again? (Y)es or (N)o : ", string("YN")) == 'Y');
						
		} while (playAgain);
		std::cout << "\nThank you for playing...";
	}

};



