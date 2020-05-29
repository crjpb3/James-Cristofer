//Cristofer James
//Created May 21, 2020
#pragma once
#ifndef BASIC_ATM_H
#define BASIC_ATM_H
#include <string>
using namespace std;

class Basic_ATM
{
public:
	Basic_ATM(string acct_number, double acct_balance, int pin);
	void single_action_access(int entered_pin);

private:
	string account_number;
	int acct_pin;
	double account_balance;
	bool is_overdrawn;
	const string overdrawn_notice = "\n\tThis account is currently overdrawn. Further withdrawals and purchases have been disabled.";
	//Main helper functions
	void account_inquiry();
	void acct_deposit(double deposit_amount);
	void acct_withdrawal(double withdrawal_amount);
	//Secondary helper functions
	void overdraw_check();
	string get_acct_num();
	string mask_acct_num(string acct_num);
	double get_acct_balance();
	bool validate_pin_num(int check_pin);
	void log_transaction(string transaction_location, double transaction_amount);
};
#endif