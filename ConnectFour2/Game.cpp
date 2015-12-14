#include "Game.h"
#include "Board.h"

using namespace std;

void Game::run() {    
	// Initialize the game
	init();

	// Main Game loop
	while (m_gameState != GameState::EXIT) {

		m_board->print();

		if (m_currentPlayer == X_VAL) {
			cout << "Player X's Turn \n";			
		}
		else {
			cout << "Player 0's Turn \n";
		}

		Position pos = playerMove();

		int rv = m_board->checkVictory(pos.x, pos.y, m_currentPlayer); // Variable to accept the return value from checkVictory

		if (rv != NO_VAL) {
			endGame(rv == TIE_VAL);
		}
		else {
			changePlayer();
			// Add a bunch of blank space to "clear" the command prompt
			for (int i = 0; i < 3; i++) {
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			}
		}

    }
		
}

void Game::init() {

	m_gameState = GameState::PLAYING;
	m_currentPlayer = X_VAL;
	
	printf("\n\n****** Welcome to Connect-Four ******\n\n");

	int cols, rows;
	printf("Enter number of columns: ");
	cin >> cols;
	printf("Enter number of rows: ");
	cin >> rows;

	// Initialize our board with the user inputs
	m_board = new Board(cols, rows);


}

Position Game::playerMove(){
	// Get input
	bool wasValid = false;
	// Initializing the position 
	Position position;
	position.x = -1;
	position.y = -1;

	int col;
	do {
		printf("Enter the Column: ");
		while (!(std::cin >> col)) {
			cin.clear();
			cin.ignore(1000, '\n');
			printf("ERROR: Invalid input!");
		}
		
		if (col < 1 || col > m_board->getNoOfCols() ) {
			printf("ERROR: Invalid Column!\n\n");
		}
		else if ( m_board->isColumnFull(col) ) { ///> Check whether the column is full or not
			printf("ERROR: Column is Full!\n\n");
		}
		else {
			wasValid = true;
		}

	} while (!wasValid);

	// Now place the token, then get the position
	position.x = m_board->placeChar(col, m_currentPlayer);
	position.y = col - 1;

	return position;
}

void Game::changePlayer() {
	if (m_currentPlayer == X_VAL) {
		m_currentPlayer = O_VAL;
	}
	else {
		m_currentPlayer = X_VAL;
	}
}

void Game::endGame(bool wasTie) {
	// Clear the screen
	for (int i = 0; i < 3; i++) {
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	}
	// Print the board
	m_board->print();

	if (wasTie) {
		printf("\n\n Tie game! \n\n  Enter any key to play again, or Z to exit: ");
	}
	else {
		if (m_currentPlayer == X_VAL) {
			printf("\n\n  Player X won! \n\n  Enter any key to play again, or Z to exit: ");
		}
		else {
			printf("\n\n  Player O won! \n\n  Enter any key to play again, or Z to exit: ");
		}
	}

	char input;
	std::cin >> input;
	if (input == 'Z' || input == 'z') {
		m_gameState = GameState::EXIT;

	}
	else {

		// Clear the screen
		for (int i = 0; i < 3; i++) {
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		}
		// Re run the game
		run();
	}

}