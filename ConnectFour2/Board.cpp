#include "Board.h"

using namespace std;


Board::Board(int width, int height) {
	m_noOfCols = width;
	m_noOfRows = height;

	board = new char*[m_noOfRows];

	for (int i = 0; i < m_noOfRows; i++) {
		board[i] = new char[m_noOfCols];
	}

	//Clear the board
	reset();
}
Board::~Board() {
	// Deallocates the memory reserved by our board
	// First removes the columns then the rows
	for (int i = 0; i < m_noOfRows; i++) {
		delete[] board[i];
	}

	delete[] board;
}

void Board::reset() {
	// Reset the board
	for (int i = 0; i < m_noOfRows; i++) {
		for (int j = 0; j < m_noOfCols; j++) {
			board[i][j] = '-';
		}
	}

}

void Board::print() const {
	cout << "\n ";
	for (int i = 0; i < (4 * m_noOfCols) - (m_noOfCols / 2 + 1); i++)
		cout << "*";
	cout << endl;

	for (int i = 0; i < m_noOfRows; i++) {
		cout << " *  ";
		for (int j = 0; j < m_noOfCols; j++) {
			cout << board[i][j] << "  ";
		}
		cout << "* " << endl;
	}

	cout << "  ";
	for (int i = 0; i < (4 * m_noOfCols) - (m_noOfCols / 2 + 3); i++)
		cout << "_";
	cout << endl;

	cout << " *  ";
	for (int i = 1; i <= m_noOfCols; i++) {
		cout << i << "  ";
	}
	cout << "*\n";

	cout << " ";
	for (int i = 0; i < (4 * m_noOfCols) - (m_noOfCols / 2 + 1); i++)
		cout << "*";
	cout << endl;

}

int Board::checkVictory(int a, int b, int currentPlayer) const {

	// Number of tokens one player has to place consecutively inorder to win
	int consecutiveTokens = 4;

	int vertical = 1;//(|)
	int horizontal = 1;//(-)
	int diagonal1 = 1;//(\)
	int diagonal2 = 1;//(/)
	char player = board[a][b];
	int i;//vertical(rows)
	int j;//horizontal(columns)

	// Check for vertical(|)
	// Check down
	for (i = a + 1; i < m_noOfRows; i++) {
		if (player != '-' && board[i][b] == player) {
			vertical++;
		}
		else {
			break;
		}
	}

	// Check up
	for (i = a - 1; i >= 0; i--) {
		if (player != '-' && board[i][b] == player) {
			vertical++;
		}
		else {
			break;
		}
	}
	// If player consecutively placed the required amount of tokens vertically
	if (vertical >= consecutiveTokens) {
		return currentPlayer;
	}

	// Check for horizontal(-)
	// Check left
	for (j = b - 1; j >= 0; j--) {
		if (player != '-' && board[a][j] == player) {
			horizontal++;
		}
		else {
			break;
		}
	}

	// Check right
	for (j = b + 1; j < m_noOfCols; j++) {
		if (player != '-' && board[a][j] == player) {
			horizontal++;
		}
		else {
			break;
		}
	}
	// If player consecutively placed the required amount of tokens horizontally
	if (horizontal >= consecutiveTokens) {
		return currentPlayer;
	}

	// Check for diagonal 1 (\)
	// Up and left
	for (i = a - 1, j = b - 1; i >= 0 && j >= 0; i--, j--) {
		if (player != '-' && board[i][j] == player) {
			diagonal1++;
		}
		else {
			break;
		}
	}

	// Down and right
	for (i = a + 1, j = b + 1; i <= m_noOfRows - 1 && j <= m_noOfCols - 1; i++, j++) {
		if (player != '-' && board[i][j] == player) {
			diagonal1++;
		}
		else {
			break;
		}
	}
	// If player consecutively placed the required amount of tokens diagonally
	if (diagonal1 >= consecutiveTokens) {
		return currentPlayer;
	}

	// Check for diagonal 2(/)
	// Up and right
	for (i = a - 1, j = b + 1; i >= 0 && j <= m_noOfCols - 1; i--, j++) {
		if (player != '-' && board[i][j] == player) {
			diagonal2++;
		}
		else {
			break;
		}
	}

	// Up and left
	for (i = a + 1, j = b - 1; i <= m_noOfRows - 1 && j >= 0; i++, j--) {
		if (player != '-' && board[i][j] == player) {
			diagonal2++;
		}
		else {
			break;
		}
	}
	// If player consecutively placed the required amount of tokens diagonally
	if (diagonal2 >= consecutiveTokens) {
		return currentPlayer;
	}

	// Check for tie
	int counter = 0;
	for (i = 0; i < m_noOfCols; i++) {
		if (board[0][i] == '-') {
			break;
		}
		else {
			counter++;
		}
	}
	// If the board is full and no player placed the required amount of tokens consecutively   
	if (counter == m_noOfCols) {
		return TIE_VAL;
	}
		
	// This will be executed if no player has won or the game hasn't ended
	return NO_VAL;
	

}

bool Board::isColumnFull(int column) {
	if (board[0][column - 1] == '-') {
		return false;
	}
	return true;
}

int Board::placeChar(int col, int player) {
	char ch;
	if (player == X_VAL) {
		ch = 'X';
	}
	else {
		ch = 'O';
	}
	// Variable to get the row the token was placed in
	int row;
	for (int i = m_noOfRows - 1; i >= 0; i--) {
		if (board[i][col - 1] == '-') {
			row = i;
			board[i][col - 1] = ch;
			break;
		}
	}

	return row;
}







