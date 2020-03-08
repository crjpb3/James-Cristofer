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
	void board();
	void printBoard();
	void verifyTileEmpty(int row, int col);
	void updateTile(int row, int col);

private:
	bool isGameOver;
};
#endif