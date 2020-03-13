#pragma once
#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H
#include <string>
using namespace std;

class Player
{
public:
	Player();
	Player(string plrName, char plrChar);
	void setName(string plrName);
	string getName();
	void setChar(char plrChar);
	char getChar();
	void setRow(int plrRow);
	int getRow();
	void setCol(int plrCol);
	int getCol();


private:
	string plrName;
	char plrChar;
	int plrRow;
	int plrCol;
};
#endif