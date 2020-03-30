#include "Employee.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Employee::Employee()
{
	this->employeeName = "0";
	this->employeeID = "0";
}

void Employee::SetName(const string& employeeName)
{
	this->employeeName = employeeName;
}

string Employee::GetName() const
{
	return this->employeeName;
}

void Employee::SetID(const string& employeeID)
{
	this->employeeID = employeeID;
}

string Employee::GetID() const
{
	return this->employeeID;
}

string Employee::GetType() const
{
	string employeeType = "Employee";

	return employeeType;
}

bool Employee::ReadData(ifstream& employeeDataIn)
{
	string empName;
	string empID;
	getline(employeeDataIn, empName);
	getline(employeeDataIn, empID);

	if (employeeDataIn)
	{
		SetName(empName);
		SetID(empID);
		return true;
	}
	else
		return false;
}

bool Employee::WriteData(ofstream& employeeDataOut) const
{
	
	employeeDataOut << GetName() << endl;
	employeeDataOut << GetID() << endl;
	
	if (employeeDataOut)
		return true;
	else
		return false;
}