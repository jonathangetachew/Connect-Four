#pragma once

#include <iostream>
#include <vector>


const int TIE_VAL = -1;
// Indexes for board values
const int NO_VAL = 45; ///> integer value for the character '-'
const int X_VAL = 1;
const int O_VAL = 2;

class Board
{
public:
	Board(int width, int height);
	~Board();
	
    // Prints the board to standard output
    void print() const;
    // If no player won, returns NO_VAL. Otherwise returns X_VAL, O_VAL or TIE_VAL
    int checkVictory(int a, int b, int currentPlayer) const;
	// If the chosen column is full return true, else return false
	bool isColumnFull(int column);
	// Place the token then return the row it's placed in
	int placeChar(int column, int player);
	
	// Getters	
	int getVal(int x, int y) const { return board[x][y]; } // Gets value at x,y spot
	int getNoOfCols() { return m_noOfCols; }
	int getNoOfRows() { return m_noOfRows; }


private:
	// Resets the board to the default values
	void reset();

	// Our board
	char** board = NULL;

	// Variables for number of columns and rows
	int m_noOfCols;
	int m_noOfRows;

};

