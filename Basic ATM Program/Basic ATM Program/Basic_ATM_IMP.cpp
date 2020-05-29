//Cristofer James
//Created May 21, 2020
#include "Basic_ATM.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <string>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

//I do not know the back end of ATM software, so this is a basic idea of how I assume it works

//ISSUES//
//I've learned that system("cls") is not a good way to handle clearing the screen, but I have not found a better way to handle it currently for such a simple program
//cin.ignore() had been working fine as a means to pause the program for the user to read the display. For some reason, it stopped working properly so I had to replace it with system("pause")

//IMPROVEMENTS/CHANGES//
//Rather than create an instantiation of an object at the beginning of Main, the program would need to receive the account number(through the user's card) and PIN number from the user
//it would then need to compare these inputs with a database of bank accounts
//It would need to search for the account number and then compare the entered PIN number with the PIN number stored for the account to determine whether access is granted

Basic_ATM::Basic_ATM(string acct_number, double acct_balance, int pin)
{
	this->account_number = acct_number;
	this->account_balance = acct_balance;
	this->acct_pin = pin;
	this->is_overdrawn = false;
}

void Basic_ATM::single_action_access(int entered_pin)
{//Controls access to the class actions //This could probably be a separate class that controls the access, I'm not sure if that would make the process more secure
	system("cls");
	if (!validate_pin_num(entered_pin))
	{
		cout << "\n\tInvalid Pin Number" << endl << endl;
		return;
	}
	else
	{
		char user_input;
		cout << "||Account Actions||" << endl;
		cout << "(1) Account Inquiry" << endl;
		cout << "(2) Deposit" << endl;
		cout << "(3) Withdrawal" << endl;
		cout << "(4) Quit" << endl;
		cin >> user_input;

		switch (user_input)
		{
		case '1':
		{
			system("cls");
			account_inquiry();
			system("pause");
			//cout << "\nPress any key to continue...";
			//cin.ignore();
			break;
		}
		case '2':
		{
			double deposit_amount;
			cout << "Enter the deposit amount: ";
			cin >> deposit_amount;
			acct_deposit(deposit_amount);

			system("cls");
			cout << fixed << setprecision(2);
			cout << "\tTransaction Complete" << endl << endl;
			cout << "Account Number: " << get_acct_num() << endl;
			cout << "Amount Deposited: $" << deposit_amount << endl;
			if (get_acct_balance() < 0.00)
			{
				cout << "Available Balance: -$" << get_acct_balance() * -1 << endl;
			}
			else
			{
				cout << "Available Balance: $" << get_acct_balance() << endl;
			}
			system("pause");
			//cout << "\nPress any key to continue...";
			//cin.ignore();
			break;
		}
		case '3':
		{
			double withdrawal_amount;

			if (this->is_overdrawn)
			{
				cout << "This account is overdrawn. The withdrawal cannot be processed." << endl;
				system("pause");
				//cout << "\n\nPress any key to continue...";
				//cin.ignore();
				return;
			}
			else
			{
				cout << "Enter the withdrawal amount: ";
				cin >> withdrawal_amount;
				acct_withdrawal(withdrawal_amount);

				system("cls");
				cout << fixed << setprecision(2);
				cout << "\tTransaction Complete" << endl << endl;
				cout << "Account Number: " << get_acct_num() << endl;
				cout << "Amount Withdrawn: $" << withdrawal_amount << endl;
				if (get_acct_balance() < 0.00)
				{
					cout << "Available Balance: -$" << get_acct_balance() * -1 << endl;
				}
				else
				{
					cout << "Available Balance: $" << get_acct_balance() << endl;
				}
				system("pause");
				//cout << "\nPress any key to continue...";
				//cin.ignore();
			}
			break;
		}
		case '4':
		{
			system("cls");
			cout << "\n\tGOODBYE" << endl;
			sleep_for(2s);
			break;
		}
		default:
		{
			system("cls");
			cout << "\tAn error occurred. Returning to the main screen";
			sleep_for(2s);
			break;
		}
		}
	}
	return;
}

//Main helper functions
void Basic_ATM::account_inquiry()
{
	double balance = this->account_balance;
	string acct_id = get_acct_num();

	cout << fixed << setprecision(2);
	cout << "Account Number: " << acct_id << endl;
	cout << "Available Balance: $" << get_acct_balance() << endl;
}

void Basic_ATM::acct_deposit(double deposit_amount)
{
	this->account_balance += deposit_amount;
	log_transaction("ATM", deposit_amount);
	overdraw_check();
}

void Basic_ATM::acct_withdrawal(double withdrawal_amount)
{//Adjusts the amount to show that it is a reduction of funds and performs appropriate actions
	double amount = withdrawal_amount * -1.00;
	this->account_balance += amount;
	log_transaction("ATM", amount);//Would need to get the ATM's location and affiliated bank/company
	overdraw_check();
}

//Secondary helper functions
void Basic_ATM::overdraw_check()
{
	if (this->account_balance < 0.00)
		this->is_overdrawn = true;
	else
		this->is_overdrawn = false;
}

string Basic_ATM::get_acct_num()
{
	string acct_id = mask_acct_num(this->account_number);
	return acct_id;
}

string Basic_ATM::mask_acct_num(string acct_num)
{//Masks the account number so the entire number isn't displayed through secondary variables
	string mask_acct_num = acct_num;
	int acct_num_length = acct_num.size();

	for (int i = 0; i < (acct_num_length - 4); i++)
	{
		mask_acct_num.replace(i, 1, "X");
	}
	return mask_acct_num;
}

double Basic_ATM::get_acct_balance()
{
	double balance = this->account_balance;
	return balance;
}

bool Basic_ATM::validate_pin_num(int check_pin)
{
	if (check_pin == this->acct_pin)
		return true;
	else
		return false;
}

void Basic_ATM::log_transaction(string transaction_location, double transaction_amount)
{//Logs each transaction made by an account to a file for that account number
	string location = transaction_location;
	double amount = transaction_amount;
	ofstream transaction_out;

	transaction_out.open(this->account_number + "_transaction_list.txt", ios::app);
	transaction_out << fixed << setprecision(2);
	transaction_out << location << endl;
	if (amount >= 0.00)//Outputs the proper format
		transaction_out << "$" << amount << endl;
	else
	{
		transaction_out << "-$" << amount * -1.00 << endl;
	}
	transaction_out.close();
}