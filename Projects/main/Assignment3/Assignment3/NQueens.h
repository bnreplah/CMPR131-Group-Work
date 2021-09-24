//	Names:
//	Jose Chavez
//	Tony Cheng
//	Professor Quach
//	CMPR 131
//	Assignment 3: NQueens
//	9/23/21


#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "input.h"
#include <stdlib.h>
using namespace std;

class NQueens
{
private:

	int** grid;
	int boardSize;
	bool gameOver;
	bool win;
	int queenTotal;
	int moveTotal;
	string opinion;

public:
	//constructor
	NQueens() {
		//deleteGrid();
		queenTotal = 0;
		gameOver = false;
		win = false;
		boardSize = 0;
		moveTotal = 0;

	}
	//preconditions: N/A
	//postcondition: displays description and instructions for the game 
	void gameExplain() {
		cout << "\n\t The n-queens puzzle is the problem of placing n chess queens on a nxn chessboard";
		cout << "\n\tso that no two queens threaten each other; thus, a solution requires that no two";
		cout << "\n\tqueens share the same row, column, or diagonal.Solutions exist for all natural";
		cout << "\n\tnumbers n with the exception of n = 2 and n = 3";
	}
	//preconditions:N/A
	//postcondition:input the number to set the dimensions of the grid
	void iniGrid() {
		cout << endl << endl;
		string prompt = "\tEnter the board dimension nxn:";
		boardSize = inputInteger(prompt);
		grid = new int* [boardSize];
		for (int i = 0; i < boardSize; i++) {
			grid[i] = new int[boardSize];
		}
		for (int col = 0; col < boardSize; col++) {
			for (int row = 0; row < boardSize; row++) {
				grid[row][col] = 0;
			}
		}
	}
	//preconditions: The grid needs to be initailized and the dimensions need to be set for this to work 
	//postcondition: displays grid 
	void printGrid() {
		cout << "\t" + to_string(boardSize) + "-Queens" << endl;
		cout << "\t" << char(201);
		for (int row = 0; row < (2 * boardSize) - 1; row++) {
			cout << char(205);
		}
		cout << char(187) << endl;
		for (int midcol = 0; midcol < boardSize; midcol++) {
			cout << "\t" << char(186);
			for (int midrow = 0; midrow < boardSize; midrow++) {
				if (grid[midcol][midrow] == 1) {
					cout << 'Q';
				}
				else {
					cout << '_';
				}
				if (midrow == boardSize - 1) {
					cout << char(186);
				}
				else {
					cout << '|';
				}
			}
			cout << endl;
		}
		cout << "\t" << char(200);
		for (int row = 0; row < (2 * boardSize) - 1; row++) {
			cout << char(205);
		}
		cout << char(188) << endl;
		cout << endl;
	}
	//preconditions: N/A
	//postcondition: displays users options to play the game
	char gameOptions() {

		string options[] = { "\tGame Options",
						"\n\t" + string(50 , char(196)) +
						"\n\tA > Place a queen",
						"\n\tB > Remove an existing queen",
						"\n\t" + string(50 , char(196)) +
						"\n\t0 > return",
						"\n\t" + string(50 , char(196))

		};
		for (string option : options)
			cout << option;
		return inputChar(string("\n\tOption: "), string("ab0"));
	}
	//preconditions:N/A
	//postcondition:positions the queen depending on the integers the user input for the colum and row
	void addQueen() {
		int start = 1;
		bool unblockQueen = true;
		string prompt = "\tPosition a queen in the row (1.." + to_string(boardSize) + "):";
		int row = inputInteger(prompt, start, boardSize) - 1;
		prompt = "\tPosition a queen in the column (1.." + to_string(boardSize) + "):";
		int column = inputInteger(prompt, start, boardSize) - 1;
		if (queenTotal == 0) {
			grid[row][column] = 1;
			queenTotal++;
			moveTotal++;
			cout << endl;
		}
		else if (grid[row][column] == 1) {
			cout << "\tERROR: a queen has already placed in the position (row and column). Try again." << endl;
		}
		else {
			if (unblockQueen == true) {
				unblockQueen = checkrow(row);
			}
			if (unblockQueen == true) {
				unblockQueen = checkcol(column);
			}
			if (unblockQueen == true) {
				unblockQueen = checkdia(row, column);
			}

			if (unblockQueen == true) {
				grid[row][column] = 1;
				queenTotal++;
				moveTotal++;
				cout << endl;
			}
		}
		cout << endl;
	}
	//preconditions: there needs to be an existing queen 
	//postcondition: removes the queen depending on the input from the user 
	void removeQueen() {
		int start = 1;
		string prompt = "\tEnter an existing queen from the row (1.." + to_string(boardSize) + "):";
		int row = inputInteger(prompt, start, boardSize) - 1;
		prompt = "\tEnter an existing queen from the column (1.." + to_string(boardSize) + "):";
		int column = inputInteger(prompt, start, boardSize) - 1;
		if (grid[row][column] == 1) {
			grid[row][column] = 0;
			queenTotal--;
			moveTotal++;
		}
		else {
			cout << "\tERROR: No such queen existed." << endl;
		}
	}
	//preconditions: must be an integer in the range of the dimension 
	//postcondition: checks if there is any existing queens in the row, returns true if row is empty, else returns false 
	bool checkrow(int row) {
		for (int cRow = 0; cRow < boardSize; cRow++) {
			if (grid[row][cRow] == 1) {
				cout << "\tERROR: conflict with queens in existing row.Try again." << endl;
				return false;
			}
		}
		return true;
	}
	//preconditions: must be an integer in the range of the dimension
	//postcondition: checks if there is any existing queens in the column, returns true if column is empty, else returns false
	bool checkcol(int column) {
		for (int cCol = 0; cCol < boardSize; cCol++) {
			if (grid[cCol][column] == 1) {
				cout << "\tERROR: conflict with queens in existing column.Try again." << endl;
				return false;
			}
		}
		return true;
	}
	//preconditions:must be an integer in the range of the dimension
	//postcondition: checks if there is any existing queens diagonaly from the chosen space, returns true if diagonal path is empty, else returns false
	bool checkdia(int row, int column) {
		int Crow = row;
		int Ccol = column;
		do {
			if (grid[Crow][Ccol] == 1) {
				cout << "\tERROR: conflict with queens in existing diagonal.Try again." << endl;
				return false;
			}
			Crow++;
			Ccol++;
		} while (Crow < boardSize && Ccol < boardSize);
		Crow = row;
		Ccol = column;
		do {
			if (grid[Crow][Ccol] == 1) {
				cout << "\tERROR: conflict with queens in existing diagonal.Try again." << endl;
				return false;
			}
			Crow++;
			Ccol--;
		} while (Crow < boardSize && Ccol > -1);
		Crow = row;
		Ccol = column;
		do {
			if (grid[Crow][Ccol] == 1) {
				cout << "\tERROR: conflict with queens in existing diagonal.Try again." << endl;
				return false;
			}
			Crow--;
			Ccol++;
		} while (Crow > -1 && Ccol < boardSize);
		Crow = row;
		Ccol = column;
		do {
			if (grid[Crow][Ccol] == 1) {
				cout << "\tERROR: conflict with queens in existing diagonal.Try again." << endl;
				return false;
			}
			Crow--;
			Ccol--;
		} while (Crow > -1 && Ccol > -1);
		return true;
	}
	//preconditions:N/A
	//postcondition:checks the total number of queens and the size of the board are equal to determine a victory
	bool checkWin() {
		if (queenTotal == boardSize) {
			cout << "Congratulation! You have solved " + to_string(boardSize) + "-Queens in " + to_string(moveTotal) + " move." << endl;
			printGrid();
			return true;
		}
		else {
			return false;
		}
	}
	//preconditions: user would need to play and win the game  
	//postcondition:ask user if they want to play again, if yes then the game is reset and runs again, if no then exit 
	void playAgain() {
		char again;
		string prompt = "\nPlay again? (Y-yes or N-no)";
		again = inputChar(prompt, string("yn"));
		if (again == 'Y') {
			win = false;
			iniGrid();
			playGame();
			playAgain();
		}
	}
	//preconditions: initialize the board 
	//postcondition: plays the game 
	void playGame() {
		do
		{
			cout << endl;
			printGrid();
			switch (gameOptions())
			{
			case '0': exit; break;
			case 'A': addQueen(); break;
			case 'B': removeQueen(); break;
			default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
			}
			win = checkWin();
			cout << "\n";
			pause();
		} while (win == false);
	}
	//preconditions:N/A
	//postcondition: driver function that runs NQueens 
	int runNQueens() {
	
		gameExplain();
		iniGrid();
		playGame();
		playAgain();
		return 0;
	}
};
