#include <iostream>
#include <string>
#include "PlayerClass.h"
using namespace std;

Player::Player()
{
	this->plrName = "NoName";
	this->plrChar = '?';
	this->plrRow = NULL;
	this->plrCol = NULL;
}

Player::Player(string plrName, char plrChar)
{//Constrcuts the Player object
	this->plrName = plrName;
	this->plrChar = plrChar;
}

void Player::setName(string plrName)
{//Sets the player's game name
	this->plrName = plrName;
}

string Player::getName()
{
	return this->plrName;
}

void Player::setChar(char plrChar)
{//Sets the player's game token
	this->plrChar = plrChar;
}

char Player::getChar()
{
	return this->plrChar;
}

void Player::setRow(int plrRow)
{//Sets the row to the player's row input
	this->plrRow = plrRow;
}

int Player::getRow()
{//Gets the row from player class
	return plrRow;
}

void Player::setCol(int plrCol)
{//Sets the row to the player's column input
	this->plrCol = plrCol;
}


int Player::getCol()
{//Gets the column from player class
	return plrCol;
}