//Cristofer James
//CS201R Spring 2020
//Program 4
#include <iostream>
#include <string>
#include "BoardClass.h"
using namespace std;

int main()
{
	Player* p1;
	Player* p2;
	Board* board;

	string tempName;
	char tempChar;

	cout << "Enter a name for player 1: ";
	getline(cin, tempName);
	cout << "\nEnter a game character for player 1: ";
	cin.get(tempChar);
	cin.ignore(INT_MAX, '\n');
	p1 = new Player(tempName, tempChar);

	cout << "\nEnter a name for player 2: ";
	getline(cin, tempName);
	cout << "\nEnter a game character for player 2: ";
	cin.get(tempChar);
	cin.ignore(INT_MAX, '\n');
	p2 = new Player(tempName, tempChar);

	board = new Board(p1, p2);


	return 0;
}