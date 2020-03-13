#include <iostream>
#include <string>
#include "BoardClass.h"
using namespace std;

Board::Board()
{
	createBoard();
}

Board::Board(Player* p1, Player* p2)
{//Constructs the Board object
	createBoard();
	players[0] = p1;
	players[1] = p2;

	cout << "Player 1 name: " << p1->getName() << endl;
}

void Board::runGame()
{//Runs the game and functions

}

void Board::createBoard()
{//Creates new board
	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			tileArray[a][b].isEmpty = true;
			tileArray[a][b].rowPos = a;
			tileArray[a][b].colPos = b;
			tileArray[a][b].currChar = ' ';
		}
	}
}

void Board::printBoard()
{//Prints the current board

}

void Board::saveBoard()
{//Saves board to an output file

}

void Board::verifyTile(int row, int col)
{//Verifies that the tile at the position chosen by the player is available

}

void Board::updateTile(int row, int col)
{//Updates the selected tile's availability and sets currChar to the calling player's character

}

void Board::checkWinner()
{//Checks for a winner

}