#include "HourlyEmployee.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

HourlyEmployee::HourlyEmployee()
{
	Employee::SetName("0");
	Employee::SetID("0");
	this->experiencedEmployee = 'F';
	this->employeeSalary = 0.0;
}

bool HourlyEmployee::SetExpertEmployee(char newExpert)
{
	if ((newExpert == 'F') || (newExpert == 'T'))
	{
		this->experiencedEmployee = newExpert;
		return true;
	}
	else
		return false;
}

char HourlyEmployee::GetExpertEmployee() const
{
	return this->experiencedEmployee;
}

bool HourlyEmployee::SetSalary(double newSalary)
{
	if ((newSalary >= 1000) && (newSalary <= 10000))
	{
		this->employeeSalary = newSalary;
		return true;
	}
	else
		return false;
}

double HourlyEmployee::GetSalary() const
{
	return this->employeeSalary;
}

string HourlyEmployee::GetType() const
{
	string employeeType = "Hourly Employee";

	return employeeType;
}

bool HourlyEmployee::ReadData(ifstream& employeeDataIn)
{
	double empSalary;
	char expertVal;

	Employee::ReadData(employeeDataIn);
	cin.get(expertVal);
	cin.ignore(INT_MAX, '\n');
	cin >> empSalary;

	if (employeeDataIn.good())
	{
		SetExpertEmployee(expertVal);
		SetSalary(empSalary);
		return true;
	}
	else
		return false;
}

bool HourlyEmployee::WriteData(ofstream& employeeDataOut) const
{
	Employee::WriteData(employeeDataOut);
	employeeDataOut << GetExpertEmployee() << endl;
	employeeDataOut << GetSalary() << endl;

	if (employeeDataOut.good())
		return true;
	else
		return false;
}