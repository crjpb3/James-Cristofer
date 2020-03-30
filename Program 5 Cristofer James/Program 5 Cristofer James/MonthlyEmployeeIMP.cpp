#include "MonthlyEmployee.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

MonthlyEmployee::MonthlyEmployee()
{
	Employee::SetName("0");
	Employee::SetID("0");
	this->employeeRank = 10;
}

bool MonthlyEmployee::SetRank(int employeeRank)
{
	if ((employeeRank >= 1) && (employeeRank <= 10))
	{
		this->employeeRank = employeeRank;
		return true;
	}
	else
		return false;
}

string MonthlyEmployee::GetType() const
{
	string employeeType = "Monthly Employee";
	return employeeType;
}

bool MonthlyEmployee::ReadData(ifstream& employeeDataIn)
{
	int empRank;
	Employee::ReadData(employeeDataIn);
	employeeDataIn >> empRank;
	
	if (employeeDataIn)
	{
		SetRank(empRank);
		return true;
	}
	else
		return false;
}

bool MonthlyEmployee::WriteData(ofstream& employeeDataOut) const
{
	Employee::WriteData(employeeDataOut);
	employeeDataOut << this->employeeRank << endl;

	if (employeeDataOut)
		return true;
	else
		return false;
}