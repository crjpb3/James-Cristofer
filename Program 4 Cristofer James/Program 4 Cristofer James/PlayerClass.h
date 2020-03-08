#pragma once
#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H
#include <string>
using namespace std;

class Player
{
public:
	void player();
	void setRow();
	void setCol();
	int getRow();
	int getCol();


private:
	string plrName;
	char plrChar;
};
#endif