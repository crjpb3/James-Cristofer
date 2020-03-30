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

bool HourlyEmployee::SetSalary(double employeeSalary)
{
	if ((employeeSalary >= 1000) && (employeeSalary <= 10000))
	{
		this->employeeSalary = employeeSalary;
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
	char expertVal;
	double empSalary;

	Employee::ReadData(employeeDataIn);
	employeeDataIn >> expertVal;
	employeeDataIn >> empSalary;

	if (employeeDataIn)
	{
		SetExpertEmployee(expertVal);
		SetSalary(empSalary);
		return true;
	}
	else
	{
		return false;
	}
}

bool HourlyEmployee::WriteData(ofstream& employeeDataOut) const
{
	Employee::WriteData(employeeDataOut);
	employeeDataOut << GetExpertEmployee() << endl;
	employeeDataOut << GetSalary() << endl;

	if (employeeDataOut)
		return true;
	else
		return false;
}