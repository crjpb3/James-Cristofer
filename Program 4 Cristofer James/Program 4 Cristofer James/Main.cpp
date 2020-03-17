//Cristofer James
//CS201R Spring 2020
//Program 4
#include <iostream>
#include "BoardClass.h"
using namespace std;

void newGame(bool& quit);
void resetPtr(Board* board);

int main()
{
	bool quitCmnd = false;

	Player* p1 = nullptr;
	Player* p2 = nullptr;
	Board* board = nullptr;

	do
	{
		board = new Board(p1, p2);
		resetPtr(board);
		newGame(quitCmnd);

	} while (!quitCmnd);

	cout << "\t\tClosing Program" << endl << endl;

	return 0;
}

void newGame(bool& quit)
{
	char userInput;

	cin.ignore(INT_MAX, '\n');
	cout << "Would you like to play again(Y|N): ";
	cin.get(userInput);

	while ((toupper(userInput) != 'Y') && (toupper(userInput) != 'N'))
	{
		cout << endl << endl;
		cout << "Please enter a valid choice(Y|N): ";
		cin.get(userInput);
	}
	cout << endl << endl;

	if (toupper(userInput) != 'Y')
		quit = true;

	cin.ignore(INT_MAX, '\n');
	system("cls");
}

void resetPtr(Board* board)
{
	delete board;
	board = nullptr;
}