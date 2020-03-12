#include "BoardClass.h"
using namespace std;
const int TILE_ARRAY_SIZE = 3;

void Board::board()
{//Constructs the Board object
	Player p1;
	Player p2;
	//Game board creation
	Tile tileArray[TILE_ARRAY_SIZE][TILE_ARRAY_SIZE];
	isGameOver = false;

	for (int a = 0; a < TILE_ARRAY_SIZE; a++)
	{//Initialize the tile structures of the game board
		for (int b = 0; b < TILE_ARRAY_SIZE; b++)
		{
			Tile gameTile;
			gameTile.isEmpty = true;
			gameTile.rowPos = a;
			gameTile.colPos = b;
		}
	}
}
void Board::printBoard()
{//Prints the current board

}

void Board::verifyTileEmpty(int row, int col)
{//Verifies that the tile at the position chosen by the player is available

}

void Board::updateTile(int row, int col)
{//Updates the selected tile's availability and sets currChar to the calling player's character

}