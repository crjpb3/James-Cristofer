//Cristofer James
//Created May 21, 2020
#include "Basic_ATM.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int input_pin;
	Basic_ATM Test("1234567890", 50.00, 1234);

	while (1)
	{
		cout << "Press 'ENTER' to start...";
		cin.ignore();
		system("cls");
		cout << "Enter your PIN number: ";
		cin >> input_pin;
		Test.single_action_access(input_pin);
		cin.ignore();
		system("cls");
	}
	return 0;
}