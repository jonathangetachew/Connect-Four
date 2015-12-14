#pragma once

#include "Board.h"

enum class GameState { PLAYING, EXIT };

// Struct for position on the board
struct Position {
	int x;
	int y;
};


class Game
{
    public:

        void run();

    private:

        void init();
		// Return the position the player placed the token, else return -1
		Position playerMove();
		void changePlayer();
		void endGame(bool wasTie);

        GameState m_gameState;
        Board* m_board;
		int m_currentPlayer;

};
