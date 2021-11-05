//  File: RecursiveQueens.h
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

#pragma once

#include <iostream>
#include "input.h"
#include <stack>


class nQueenStack {
private:
	std::stack<pair<int, int>> queens;
	std::size_t boardSize = size_t(0);
public:
	///default constructor
	nQueenStack() {
	}
	/// PreCondition: N/A
	/// PostCondition: Change boardSize with user input integer from 1 to 100
	void setBoardSize() {
		boardSize = inputInteger("\n\t\tEnter a number(1..100) of queens: ", 1, 100);
	}

	pair<int, int> getTop() {
		return queens.top();
	}

	/// PreCondition: N/A
	/// PostCondition: User input on placing the first queen, value must be from 1 to board size
	void placeFirstQueen() {
		int columnPlacement = inputInteger("\n\t\tEnter the column(1.." + std::to_string(boardSize) + ") to place the first queen:", 1, int(boardSize));
		queens.push(std::pair<int, int>(1, columnPlacement));
	}

	/// PreCondition: Given a stack<pair<int, int>>
	/// PostCondition: return a stack in reverse order
	std::stack<pair<int, int>> reverseStack(std::stack<pair<int, int>> original) {
		std::stack<pair<int, int>> originalCopy = original;
		std::stack<pair<int, int>> reverse;
		while (originalCopy.empty() == false) {
			reverse.push(originalCopy.top());
			originalCopy.pop();
		}
		return reverse;
	}

	/// PreCondition: N/A
	/// PostCondition: print out a grid showing the solution
	void printGrid() {
		std::stack<pair<int, int>> GridStack = reverseStack(queens);
		std::cout << "\t" + to_string(boardSize) + "-Queens Solution" << endl;
		std::cout << "\t" << char(201);
		for (int row = 0; row < (2 * boardSize) - 1; row++) {
			std::cout << char(205);
		}
		std::cout << char(187) << endl;
		for (int midrow = 0; midrow < int(boardSize); midrow++) {
			std::cout << "\t" << char(186);
			for (int midcol = 0; midcol < int(boardSize); midcol++) {
				if (GridStack.empty() == false && GridStack.top() == std::pair<int, int>(midrow + 1, midcol + 1)) {
					std::cout << 'Q';
					GridStack.pop();
				}
				else {
					std::cout << '_';
				}
				if (midcol == int(boardSize) - 1) {
					std::cout << char(186);
				}
				else {
					std::cout << '|';
				}
			}
			std::cout << endl;
		}
		std::cout << "\t" << char(200);
		for (int row = 0; row < (2 * boardSize) - 1; row++) {
			std::cout << char(205);
		}
		std::cout << char(188) << endl;
		std::cout << endl;
	}

	/// PreCondition: given a stack<pair<int, int>> and a pair<int, int>
	/// PostCondition: check if the current queen will intersect with a previous placed queen, if it intersects return true, else return false
	bool CheckQueenPlacement(std::stack<pair<int, int>> original, pair<int, int> currentPlace) {
		bool failCheck = false;
		std::stack<pair<int, int>> originalCopy = original;
		while (originalCopy.empty() == false) {
			if (failCheck == false) {
				failCheck = this->CheckVertical(currentPlace.second, originalCopy.top().second);
			}
			if (failCheck == false) {
				failCheck = this->CheckDia(currentPlace, originalCopy.top());
			}
			if (failCheck == true) {
				return false;
			}
			originalCopy.pop();
		}
		return true;

	}

	/// PreCondition:give 2 int
	/// PostCondition: check if the 2 queens are in the same column, return true if they, else return false
	bool CheckVertical(int currentPlace, int test) {
		if (currentPlace == test) {
			return true;
		}
		else {
			return false;
		}
	}

	/// PreCondition: given 2 pair<int,int>
	/// PostCondition: check if the 2 queens are in the same diagonal, return true if they, else return false
	bool CheckDia(pair<int, int> currentPlace, pair<int, int> test) {
		int rowDifference = test.first - currentPlace.first;
		pair<int, int> test1col = pair<int, int>(currentPlace.first, test.second + rowDifference);
		pair<int, int> test2col = pair<int, int>(currentPlace.first, test.second - rowDifference);
		if (test1col.second <= this->boardSize) {
			if (currentPlace == test1col) {
				return true;
			}
		}
		if (test2col.second > 0) {
			if (currentPlace == test2col) {
				return true;
			}
		}
		return false;
	}

	
		
	/// PreCondition: N/A
	/// PostCondition: Solve the nQueen problem, this will continue until the stack is empty or boardSize is equal to the size of the stack. 
	///		if stack is empty, prints no solution. if boardSize is equal to the size of the stack show the solution.
	/// !!!! board size is equal to the size of the stack when ? size or length of one dimension ?
	void solveQueens(int RowCheck, int ColCheck) {
		int currentRowCheck = RowCheck;
		int currentColCheck = ColCheck;
		bool NextQueenAdded = false;
		
		//recursion part
		if (queens.empty() == true) {
			std::cout << "\n\tNo solution";
			return;
		}
		else if (queens.size() == boardSize) {//so if board size is 2 will stop if there are 2 queens?
			printGrid();
			return;
		}
		else {
			if (currentColCheck > int(boardSize)) {//so if the current col is greater than the board size? but the board size is the max dimentsion in every direction?
				currentRowCheck = queens.top().first;
				currentColCheck = queens.top().second + 1;//adds one and the second value of the next value in the queen stack and sets that to current colCheck 
				queens.pop();//pop off the next value pair of queens 
				solveQueens(currentRowCheck, currentColCheck); //recursive call passing the row and col by value
				return;//then exit
			}
			if (currentColCheck <= int(boardSize)) {//if the col check is less than or equal to the boardSize
				NextQueenAdded = CheckQueenPlacement(queens, pair<int, int>(currentRowCheck, currentColCheck));//run the checkQueenPlacement on the queens present, and pass the pair of currentrow and currentcol
				if (NextQueenAdded == true) {//if the placement is true
					queens.push(std::pair<int, int>(currentRowCheck, currentColCheck)); //push the next queen value to the stack
					solveQueens(queens.top().first + 1, 1);//recursive call incrimenting the first value of the queens stack and passing the currentColCheck to be 1
					return;
				}
			}
			if (currentColCheck <= int(boardSize) && queens.empty() == false && NextQueenAdded == false) {
				currentColCheck++;
				solveQueens(currentRowCheck, currentColCheck);
			}
			
		}
	}
};



//////////////////////////
// MAIN DRIVER FUNCTION //
//////////////////////////
// Precondition: N/A 
// Postcondition: main driver, runs selected function
void runRecursivenQueens()
{
	nQueenStack game;
	header("3> n-Queens Problem");
	//std::cout << '\n' << string(100, char(196));
	game.setBoardSize();
	game.placeFirstQueen();
	game.solveQueens(game.getTop().first + 1, 1);
}
