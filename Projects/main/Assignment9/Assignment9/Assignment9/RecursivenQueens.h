//  File: application.h
//	Team Members:
//      Ben Halpern
//      Itz Rodriquez
//      Tony Cheng
//      Jose Chavez
//      Thien Nguyen
//      Jesus Sierra
//	Professor Q
//	CMPR 131
//	Assignment 6
//	10/7/21
//
/// Professor Q
/// CMPR 131
/// Assignment 9
/// 11/1/21
/// Description:
///
///
/// Reviewed by:	[Name]	:	[Date]
///							:	
///							:
///							:
///							:
///							:

#pragma once

#include <iostream>
#include "input.h"
#include <stack>

class nQueenStack {
private:

	std::stack<pair<int, int>> mQueens;
	std::size_t mBoardSize = size_t(0);
	int mRecursionCounter = 0;
	pair<int, int> mTempStore = pair<int, int>();
	bool mSolveGame = false;

public:

	///default constructor
	nQueenStack() {
	}

	/// PreCondition: N/A
	/// PostCondition: Change boardSize with user input integer from 1 to 100
	void setBoardSize() {
		mBoardSize = inputInteger("\n\t\tEnter a number(1..100) of queens: ", 1, 100);
	}

	//Precondition: Class objects must be initialized
	//Postcondition: Will return the value of mTempStore
	pair<int, int> getTemp() {
		return mTempStore;
	}

	//Precondition: Class objects must be initialized
	//Postcondition: Will return the top value of the mQueens
	pair<int, int> getTop() {
		return mQueens.top();
	}

	//Precondition: Class objects must be initialized
	//Postcondition: Will return the boolean value of mSolveGame
	bool returnGameSolve() {
		return mSolveGame;
	}

	//Precondition: Class objects must be initialized
	/// PostCondition: User input on placing the first queen, value must be from 1 to board size
	void placeFirstQueen() {
		int columnPlacement = inputInteger("\n\t\tEnter the column(1.." + std::to_string(mBoardSize) + ") to place the first queen:", 1, int(mBoardSize));
		mQueens.push(std::pair<int, int>(1, columnPlacement));
	}

	/// PreCondition: Given a stack<pair<int, int>
	/// PostCondition: return a stack in reverse order
	std::stack<pair<int, int>> reverseStack(std::stack<pair<int, int>> pOriginal) {
		std::stack<pair<int, int>> originalCopy = pOriginal;
		std::stack<pair<int, int>> reverse;

		while (originalCopy.empty() == false) {
			reverse.push(originalCopy.top());
			originalCopy.pop();
		} // end while
		return reverse;
	}

	/// PreCondition: N/A
	/// PostCondition: print out a grid showing the solution
	void printGrid() {
		std::stack<pair<int, int>> GridStack = reverseStack(mQueens);
		std::cout << "\t" + to_string(mBoardSize) + "-Queens Solution" << endl;
		std::cout << "\t" << char(201);

		for (int row = 0; row < (2 * mBoardSize) - 1; row++) {
			std::cout << char(205);
		} // end for
		std::cout << char(187) << endl;

		for (int midrow = 0; midrow < int(mBoardSize); midrow++) {
			std::cout << "\t" << char(186);
			for (int midcol = 0; midcol < int(mBoardSize); midcol++) {
				if (GridStack.empty() == false && GridStack.top() == std::pair<int, int>(midrow + 1, midcol + 1)) {
					std::cout << 'Q';
					GridStack.pop();
				} // end if
				else {
					std::cout << '_';
				} // end else
				if (midcol == int(mBoardSize) - 1) {
					std::cout << char(186);
				} // end if
				else {
					std::cout << '|';
				} // end else
			} // end for
			std::cout << endl;
		} //end for
		std::cout << "\t" << char(200);

		for (int row = 0; row < (2 * mBoardSize) - 1; row++) {
			std::cout << char(205);
		} //end for
		std::cout << char(188) << endl;
		std::cout << endl;
	} // end void function

	/// PreCondition: given a stack<pair<int, int> and a pair<int, int>
	/// PostCondition: check if the current queen will intersect with a previous placed queen, if it intersects return true, else return false
	bool CheckQueenPlacement(std::stack<pair<int, int>> pOriginal, pair<int, int> pCurrentPlace) {
		bool failCheck = false;
		std::stack<pair<int, int>> originalCopy = std::stack<pair<int, int>>();
		originalCopy = pOriginal;

		while (originalCopy.empty() == false) {
			if (failCheck == false) {
				failCheck = this->CheckVertical(pCurrentPlace.second, originalCopy.top().second);
			} // end if
			if (failCheck == false) {
				failCheck = this->CheckDia(pCurrentPlace, originalCopy.top());
			} // end if
			if (failCheck == true) {
				return false;
			} // end if
			originalCopy.pop();
		} // end while
		return true;
	} //end bool function

	/// PreCondition: Parameters must int
	/// PostCondition: check if the 2 queens are in the same column, return true if they, else return false
	bool CheckVertical(int pCurrentPlace, int pTest) {
		if (pCurrentPlace == pTest) {
			return true;
		} // end if
		else {
			return false;
		}//end else 
	} // end bool function

	/// PreCondition: given 2 pair<int,int>
	/// PostCondition: check if the 2 queens are in the same diagonal, return true if they, else return false
	bool CheckDia(pair<int, int> pCurrentPlace, pair<int, int> pTest) {
		int rowDifference = pTest.first - pCurrentPlace.first;
		pair<int, int> test1col = pair<int, int>(pCurrentPlace.first, pTest.second + rowDifference);
		pair<int, int> test2col = pair<int, int>(pCurrentPlace.first, pTest.second - rowDifference);
		
		if (test1col.second <= this->mBoardSize) {
			if (pCurrentPlace == test1col) {
				return true;
			} // end if
		} //end if
		if (test2col.second > 0) {
			if (pCurrentPlace == test2col) {
				return true;
			} // end if
		} // end if
		return false;
	}// end bool function
	/// PreCondition: N/A
	/// PostCondition: try to push a new queen on the stack, this will continue until the stack is empty or a new queen is pushed
	pair<int, int> checkRowQueen(int pRowCheck, int pColCheck) {
		int currentRowCheck = pRowCheck;
		int currentColCheck = pColCheck;
		bool RowCheckGood = false;

		while (RowCheckGood == false) {
			if (currentColCheck > int(mBoardSize)) {
				return pair<int, int>(0, 0);
			} //end if 
			if (currentColCheck <= int(mBoardSize)) {
				RowCheckGood = CheckQueenPlacement(mQueens, pair<int, int>(currentRowCheck, currentColCheck));
			} // end if
			if (currentColCheck <= int(mBoardSize) && RowCheckGood == false) {
				currentColCheck++;
			}// end if
		}//end while
		return pair<int, int>(currentRowCheck, currentColCheck);
	} // end of double stack method

	/// PreCondition: N/A
	/// PostCondition: Solve the nQueen problem, this will continue until the stack is empty or boardSize is equal to the size of the stack. 
	///		if stack is empty, prints no solution. if boardSize is equal to the size of the stack show the solution.
	bool solveQueens(int pRowCheck, int pColCheck) {
		if (mRecursionCounter > 8) {
			mRecursionCounter = 0;
			mTempStore = pair<int, int>(pRowCheck, pColCheck);
			return false;
		} // end if

		int solveRowCheck = pRowCheck;
		int solveColCheck = pColCheck;
		pair<int, int> NextQueenAdded = pair<int, int>();
		NextQueenAdded = checkRowQueen(solveRowCheck, solveColCheck);
		//recursion part
		if (mQueens.empty() == true) {
			std::cout << "\n\tNo solution";
			mSolveGame = true;
			return mSolveGame;
		} // end if
		else if (mQueens.size() == mBoardSize) {//so if board size is 2 will stop if there are 2 queens?
			printGrid();
			mSolveGame = true;
			return mSolveGame;
		} // end else if
		else if (NextQueenAdded == pair<int, int>(0, 0)) {
			solveRowCheck = mQueens.top().first;
			solveColCheck = mQueens.top().second + 1;
			mQueens.pop();
			mRecursionCounter++;
			return solveQueens(solveRowCheck, solveColCheck);
		} // end else if
		else if (NextQueenAdded != pair<int, int>(0, 0)) {
			mQueens.push(NextQueenAdded);
			solveRowCheck = mQueens.top().first + 1;
			solveColCheck = 1;
			mRecursionCounter++;
			return solveQueens(solveRowCheck, solveColCheck);
		}//end else if
	} // end bool function
};

//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runRecursivenQueens(){
	nQueenStack game;
	header("3> n-Queens Problem");
	
	game.setBoardSize();
	game.placeFirstQueen();
	game.solveQueens(game.getTop().first + 1, 1);
	
	while (game.returnGameSolve() == false) {
		pair<int, int> buffer = game.getTemp();
		game.solveQueens(buffer.first, buffer.second);
	}// end while
}// end void 

