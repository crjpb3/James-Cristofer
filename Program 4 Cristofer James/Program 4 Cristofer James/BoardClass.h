#pragma once
#ifndef BOARD_CLASS_H
#define BOARD_CLASS_H
#include "PlayerClass.h"
using namespace std;

struct Tile
{
	bool isEmpty;
	char currChar;
	int rowPos;
	int colPos;
};

class Board
{
public:
	Board();
	Board(Player* p1, Player* p2);
	void runGame();
	void createBoard();
	void printBoard();
	void saveBoard();
	void verifyTile(int row, int col);
	void updateTile(int row, int col);
	void checkWinner();

private:
	Tile tileArray[3][3];
	Player* players[2];
};
#endif