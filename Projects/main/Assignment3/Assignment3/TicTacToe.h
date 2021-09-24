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
	char board[3][3];
	const int WIDTH = int(3);
	const bool DEBUG = true;
	//char board[3][3];
	char compSym;
	char usrSym;
	

	void setMove(int col, int row, char symb) {
		if (isEmpty(col, row))
			*(*(board + col) + row) = symb;
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

		//initialize the board
		
		//board = new char*[WIDTH];
		//for (int i = 0; i < WIDTH; i++) {
		//	board[i] = new char[WIDTH];
		//}//end for
		

		//end initialize the board

		this->compSym = char(cSym);
		this->usrSym = char(uSym);


	}//end Board [ARGUMENT CONSTRUCTOR]

	/// [DESTRUCTOR]
	~Board() {
		
		/*for (int i = 0; i < WIDTH; i++) {
			
				delete *(this->board + i) ;
		}
		delete [](this->board);*/

	
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
	void setCompMove(int col, int row) {
		setMove(col, row, compSym);
	}
	
	/// Method: setUsrMove
	/// Precondition:
	/// Postcondition:
	void setUsrMove(int col, int row){
		setMove(col, row, usrSym);
	}


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
	/// Precondition:
	/// Postcondition:
	void mDrawBoard() const {

		for (int row = 0; row < WIDTH; row++) {
			for (int col = 0; col < WIDTH; col++) {
				if (col != 2)
					std::cout << "\t" << *(*(board + row) + col) << "\t|";//change to use prinf if possible
				else
					std::cout << "\t" << *(*(board + row) + col);
				//System.out.print(col);
			}//end for
			std::cout << "\n";
			if (row != 2)
				std::cout << "\n--------------------------------------------------\n";
			std::cout << "\n";
		}//end for
		if (DEBUG)std::cout << "\n[DEBUG]: " << "Board drawn\n";
		if (DEBUG)std::cout << "\n[DEBUG]: " << "Im in draw Board\n";


	}//end mDrawBoard



	/// Method: isEmpty
	/// Precondition:
	/// Postcondition:
	bool isEmpty(int col, int row) const{
		if(DEBUG) std::cout << "\n[DEBUG]: " << (int)*(*(board + row) + col) << endl;//debugging
		return *(*(board + col) + row) == 0;
		
	}//end isEmpty

	/// Method: isEmpty
	/// Precondition:
	/// Postcondition:
	bool isEmpty(int leg) const {
		int col = convertToCol(leg);
		int row = convertToRow(leg);
		if (DEBUG) std::cout << "\n[DEBUG]: " << *(*(board + row) + col) << endl;//debugging
		return *(*(board + row) + col) == 0;

	}//end isEmpty


	/// Method: convertToLeg
	/// Precondition:
	/// Postcondition:
	int convertToLeg(int col, int row)const  {
		return col + (row * 3);
	}//end convertToLeg

	int convertToCol(int leg) const{
		return leg % 3;
	}

	int convertToRow(int leg) const{
		return leg / 3;
	}




	/// Method: getCompSym
	/// Precondition:
	/// Postcondition:
	char getCompSym() const{
		return this->compSym;
	}//end getCompSym

	/// Method: getUsrSym
	/// Precondition:
	/// Postcondition:
	char getUsrSym() const {
		return this->usrSym;
	}//end getUsrSym

	

	//##############################################################################################
	//	check methods
	//##############################################################################################


	/// Method: checkWinner
	/// Precondition:
	/// Postcondition:
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
		if (diagItter < 3)
			inDiag = false;
		else//if greater than 2 return value if matched with needing blockign 
			return (diagItter == 3);

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
	/// Precondition:
	/// Postcondition:
	bool isValidMove(int x, int y) const {
		if (this->isEmpty(x, y))
			return true;

	}//end isValdMove

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
	void drawBoard() const{
		
		for (int row = 0; row < WIDTH; row++) {
			for (int col = 0; col < WIDTH; col++) {
				if (col != 2)
					std::cout << "\t" << this->getBoard(col, row) << "\t|";//change to use prinf if possible
				else
					std::cout << "\t" << *(*(board + col) + row);
				//System.out.print(col);
			}//end for
			cout << "\n";
			if (row != 2)
				cout << "\n--------------------------------------------------\n";
			cout << "\n";
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
	static void drawBoard(char **board, const int WIDTH, const bool DEBUG = true) {

		for (int row = 0; row < WIDTH; row++) {
			for (int col = 0; col < WIDTH; col++) {
				if (col != 2)
					std::cout << "\t" << *(*(board + row) + col) << "\t|";//change to use prinf if possible
				else
					std::cout << "\t" << *(*(board + row) + col);
				//System.out.print(col);
			}//end for
			cout << "\n";
			if (row != 2)
				cout << "\n--------------------------------------------------\n";
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
	const bool DEBUG = true;
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
		for (int i = 0; i < WIDTH; i++) {
			if (DEBUG) std::cout << "\ni:" << i << "\n";//debugging
			
			for (int j = 0; j < WIDTH; j++) {
				
				if (DEBUG) {
					std::cout << "\n";
					std::cout << "j:" << j;//debugging
					std::cout << "comp board" << compBoard.getBoard(i, j) << "\n";
				}//end debugging if


				if (compBoard.getBoard(i, j) != currentBoard.getBoard(i, j)) {//if the playing board doens't equal the copy
					compBoard.setBoard(i, j) = currentBoard.getBoard(i, j);//sets the value within the computer's board
				}//end if
			}//end for
		
		}//end for
	}//end updateBoard


	/// Method: checkCol
	/// Precondition:
	/// Postcondition:
	bool checkCol(char symb) {
		if (DEBUG) header("[DEBUG]: COL");
		int emptySpace = -1;
		int blockingSpace = 0;
		int colItter = 0;
		bool inCol = false;

		//end declarations

		for (int row = 0; row < WIDTH; row++) {//loops as long as the inCol is false and within bounds of array
			if (DEBUG)std::cout << "\nrow:" << row << "\n";
			colItter = 0;
			inCol = false;
			for (int col = 0; col < WIDTH; col++) {
				if (DEBUG)std::cout << "\ncol: " << col << "\n";//debugging
				if (DEBUG)std::cout << compBoard.getBoard(col, row);//debugging
				if (compBoard.getBoard(col, row) == symb)//if symbol is found
					colItter++;//raise itterator
				else if ( compBoard.getBoard(col, row) == 0) {//if empty space
					emptySpace = compBoard.convertToLeg(col, row);//set emptySpace value
					if (DEBUG)std::cout << "\nES: " << emptySpace;//debugging
				}//end else if

				if (compBoard.getBoard(col, row) != symb)//if not the symbol looking for
					blockingSpace = compBoard.convertToLeg(col, row);//set the blocking space

				if (colItter == 2)
					inCol = (emptySpace == blockingSpace);//if the space to block is already taken don't set inCol to true
			}//end for
			if (DEBUG)std::cout << "inCol: " << inCol;
			if (DEBUG) {
				std::cout << "\nblockSpace: " << blockingSpace;
				std::cout << "\nemptySpace: " << emptySpace;
				std::cout << "\ncolItter: " << colItter;
			}//end DEBUG if
			if (inCol)
				return (emptySpace == blockingSpace) ? emptySpace : -1;
		}//end for
		if (DEBUG)std::cout << inCol;//debugging
		return (colItter < 2) ? -1 : ((emptySpace == blockingSpace) ? emptySpace : -1);
		//if the row itterator is less than 2 produce -1, if it is greater than 2 check if the blocking space and epty space are the same
	   //if the blocking space and empty space are the same then output the empty space, otherwise -1
	}



	/// Method: checkRow
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
			if (DEBUG) printf("\ncol: %i", col);//debugging
			for (int row = 0; row < WIDTH; row++) {
				if (DEBUG)printf("\nrow: %i ", row);//debugging
				if (DEBUG)std::cout << (compBoard.getBoard(col, row));//debugging
				if (compBoard.getBoard(col, row) == symb)//if symbol found
					rowItter++;//raise itterator
				else if (compBoard.getBoard(col, row) == 0) {//if empty space
					emptySpace = compBoard.convertToLeg(col, row);//set emptySpace value
					if (DEBUG)std::cout << "\nES:" << emptySpace;//debugging
				}//end else if

				if (compBoard.getBoard(col, row) != symb)
					blockingSpace = compBoard.convertToLeg(col, row);

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



	/// Method: checkDiag
	/// Precondition:
	/// Postcondition:
	bool checkDiag(char symb) {
		if (DEBUG)std::cout << "DIAG";//debugging
		int emptySpace = -1;
		int blockingSpace = 0;
		int diagItter = 0;
		bool inDiag = false;

		//end declarations

		for (int row = 0, col = 0; row < WIDTH && col < WIDTH && !inDiag; row++, col++) {
			if (DEBUG)std::cout << "i:" << row;//debugging
			if (DEBUG)std::cout << "i: " << col;//debugging
			if (DEBUG)std::cout << compBoard.getBoard(col, row);//debugging
			if (compBoard.getBoard(col, row) == symb)//if symbol is found
				diagItter++;//increase itterator
			else if (compBoard.getBoard( col , row) == 0) {//if empty space
				emptySpace = compBoard.convertToLeg(col, row);//set emptySpace value
				if (DEBUG)std::cout << "ES:" + emptySpace;//debugging
			}//end else if

			if (compBoard.getBoard(col, row) != symb)//if not symbol
				blockingSpace = compBoard.convertToLeg(col, row);//set blocking space

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
				if (DEBUG)std::cout << compBoard.getBoard(col, row);//debugging

				if (compBoard.getBoard(col, row) == symb)
					diagItter++;
				else if (compBoard.getBoard(col, row) == 0) {
					emptySpace = compBoard.convertToLeg(col, row);
					if (DEBUG)std::cout << "ES:" + emptySpace;//debugging
				}//end else if

				if (compBoard.getBoard(col, row) != symb)
					blockingSpace = compBoard.convertToLeg(col, row);

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



	// Uses minimax algorithm
	//	firt check if the center i available,
	// 	then check if the corner are available
	//	If none of these options are available then will move to block the other player
	/// Method: preferredOpen
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


	/// Method: getNextMove
	/// Precondition:
	/// Postcondition:
	/// uses preferredOpen
	int getNextMove(Board board) {
		updateBoard(board);//updates the computer's board
		int move = 0;//for when there is a draw or exhausted options
		//TicTacToe testPlayer = new TicTacToe(userSymb, compSymb);

		//if no spot will stop the user
		//then pick a preferredOpen

		if (checkWin(compBoard.getUsrSym()) != -1) {//if user symbol doesn't have move to block
			//compBoard.setMove(((checkWin(compBoard.getUserSymb())) != -1)? (checkWin(compBoard.getUserSymb())) :, compBoard.getUserSymb());
			//if(compBoard.isWinner(compBoard.getCompSymb()))//if this truly  makes the computer a winner

			if (DEBUG) {
				std::cout << "----- Inside user checks -----";
				std::cout << ("check win of user " + (checkWin(compBoard.getUsrSym()) != -1));
				std::cout << ("Check Win user retruns:" + checkWin(compBoard.getUsrSym()));
			}//end debugging block

			return checkWin(compBoard.getUsrSym());
		}//end else if

		if (DEBUG) {
			std::cout << ("computer Board");//debugging
			compBoard.drawBoard();
			//std::cout << ("end debugging");

			std::cout << ("check win of computer ( if != -1 )" + (checkWin(compBoard.getCompSym()) != -1));
			std::cout << ("check win computer returns: " + checkWin(compBoard.getCompSym()));
			std::cout << ("check preferred Opens" + preferredOpen());
		}//end debugging block

		if (checkWin(compBoard.getCompSym()) != -1) {//if the computer has a winnable spot
			compBoard.setCompMove(checkWin(compBoard.getCompSym()), compBoard.getCompSym());
			if (compBoard.checkWinner(compBoard.getCompSym()))//if this truly  makes the computer a winner
				return checkWin(compBoard.getCompSym());
		}//end if

		else if (preferredOpen() != -1) {
			return preferredOpen();//return the preferredOpen value
		}//end else if
		//returns -1 if there is an error / cats game draw
		for (int i = 0; i < WIDTH; i++)
			for (int j = 0; j < WIDTH; j++)
				if (compBoard.isEmpty(i, j))
					move = compBoard.convertToLeg(i, j);
		return move;
	}//end getNextMove

	/// Method: 
	/// Precondition:
	/// Postcondition:
	int checkWin(char symb) {
		if (DEBUG)std::cout << checkRow(symb);//end debugging
		if (checkRow(symb) != -1)
			return checkRow(symb);
		else if (checkCol(symb) != -1)
			return checkCol(symb);
		else if (checkDiag(symb) != -1)
			return checkDiag(symb);
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
	Board gameBoard = Board();
	TicTacToeAI computer = TicTacToeAI(gameBoard);
	int userWins = int();
	int compWins = int();
	int draws = int();
	//string record = string("ScoreSheet.txt");//filepath to where storing records, if letf blank defaults to ScoreSheet.txt
	const bool DEBUG = true;



public:

	/// [Default Constructor]
	TicTacToe() {
		compMove = new bool();
		userMove = new bool();
		
	}

	
	/// [DESTRUCTOR]
	~TicTacToe() {
		delete compMove;
		delete userMove;


	}//end desctructor



	/// Method: 
	/// Precondition:
	/// Postcondition:
	void play() {
		bool userStarts = false;
		bool keepPlaying = true;
		//int loopIt = 0;
		int userMove = 0;
		int compMove = 0;
		int compWins = 0;
		int userWins = 0;
		

		std::cout << ("\nWould you like to go first? ((Y)ES : (N)O): ");
		if (inputChar("\nChoice: ", 'Y', 'N') == 'y') {
			
			std::cout << "\nYou will be playing as " << gameBoard.getUsrSym() << " and the computer will be "  << gameBoard.getCompSym();
			userStarts = true;
		}//end if

		while (keepPlaying) {
			std::cout << "\n";
			gameBoard.drawBoard();//draws the legend
			gameBoard.clear();//clears the board for gameplay
			
			std::cout << "\n\n\n";//blank line for visibility
			

			if (userStarts) {
				do {//loops as long as is not a valid move or is taken
					std::cout << ("Please enter a valid your move");
					userMove = gameBoard.convertToLeg(inputInteger("\nEnter the column: ", 0, 2), inputInteger("\nEnter the row: ", 0, 2));
					//userStarts = false;
					if (DEBUG)std::cout << (gameBoard.isEmpty(userMove));
				} while ((userMove >= 9 || userMove < 0) || !gameBoard.isEmpty(userMove));//if user move is out of bounds of moves or move is not empty
				gameBoard.setUsrMove(gameBoard.convertToCol(userMove), gameBoard.convertToRow(userMove));//sets the user move to the board

			}//end if
			while (!(gameBoard.checkWinner(gameBoard.getUsrSym()) || gameBoard.checkWinner(gameBoard.getCompSym()) || gameBoard.isDraw())) {//loops as long a no one is the winner and no draw
				//if(userStarts ){
				//	do{//loops as long as is not a valid move or is taken
				//		
				//		userMove = gameBoard.convertToLeg(inputInteger("Please enter the column", 0, 2), inputInteger("Please enter the row ", 0, 2));
				//		//userStarts = false;
				//	}while((userMove >= 9 || userMove < 0) && !gameBoard.isEmpty(userMove) );//if user move is out of bounds of moves or move is not empty
				//	gameBoard.setUsrMove(gameBoard.convertToCol(userMove), gameBoard.convertToRow(userMove));//sets the user move to the board

				//}//end if

				std::cout << "\n\n\n";
				gameBoard.drawBoard();//draws the board

				
				compMove = computer.getNextMove(this->gameBoard);
				if (DEBUG) std::cout << "\nComputers move: " << compMove << "\n";
				gameBoard.setCompMove(gameBoard.convertToCol(compMove), gameBoard.convertToRow(compMove));
				std::cout << "The computer moves" ;//blank line for visibility
				
				gameBoard.drawBoard();
				computer.updateBoard(this->gameBoard);
				if (DEBUG)std::cout << "looping?: " << gameBoard.checkWinner(gameBoard.getUsrSym())  << " : "  << gameBoard.checkWinner(gameBoard.getCompSym()) << " : " <<  gameBoard.isDraw();
				
				if (gameBoard.checkWinner(gameBoard.getUsrSym()))
					break;
				else if (gameBoard.checkWinner(gameBoard.getCompSym()))
					break;
				else if (gameBoard.isDraw())
					break;

				do {//loops as long as is not a valid move or is taken
					
					userMove = gameBoard.convertToLeg(inputInteger("Please enter the col: ", 0, 2), inputInteger("Please enter the row: ", 0, 2));
					if (DEBUG) std::cout << gameBoard.isEmpty(userMove);
				} while ((userMove >= 9 || userMove < 0) || !gameBoard.isEmpty(userMove));//if user move is out of bounds of moves or move is not empty
				gameBoard.setUsrMove(gameBoard.convertToCol(userMove), gameBoard.convertToRow(userMove));//sets the user move to the board


			}//end while
			


			if (gameBoard.checkWinner(gameBoard.getUsrSym())) {
				std::cout << ("YOU WONNNNNNN");
				userWins++;
			}//end if
			else if (gameBoard.checkWinner(gameBoard.getUsrSym())) {
				std::cout << ("The Computer Won :\'( ");
				compWins++;
			}//end else if
			else if (gameBoard.isDraw()) {
				std::cout << "IT WAS A DRAW";
			}//end draw
			else//trailing else
				std::cout << "There was an error";
			gameBoard.clear();

			printf("%50s %n %31s %35s %n", "ScoreBoard", "Computer Wins: " , compWins, "User Wins " , userWins);
			char choiceCh = inputChar("Would you like to keep playing? ((Y)ES : (N)O):", 'Y', 'N');
			
			
			keepPlaying = choiceCh == 'y';//if they want to keep playing is true
			

		}//end while
		std::cout << "\nBye";
	}



};



