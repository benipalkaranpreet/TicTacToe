#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>

class Board
{
	std::vector<char> square;
	// Places x at p
	void move(int p, char x);
	// Returns the char at p
	char get(int p);
	// Check if the game if over, returns 'X' or 'O' if there is a winner, '0' otherwise
	char check();
	// Prints the Board
	void printB();
public:
	Board();
	// runs a single game of tic tac toe, return 'X', 'O', '0', depening on winner or if tie
	char play();
};

#endif
