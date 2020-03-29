#include "Employee.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Employee::Employee()
{
	this->employeeName = "0";
	this->employeeID = "0";
}

void Employee::SetName(string employeeName)
{
	this->employeeName = employeeName;
}

string Employee::GetName()
{
	return this->employeeName;
}

void Employee::SetID(string employeeID)
{
	this->employeeID = employeeID;
}

string Employee::GetID()
{
	return this->employeeID;
}

string const Employee::GetType()
{
	string employeeType = "Employee";

	return employeeType;
}

bool Employee::ReadData(ifstream& employeeDataIn)
{
	getline(employeeDataIn, this->employeeName);
	getline(employeeDataIn, this->employeeID);

	if (employeeDataIn.good())
		return true;
	else
		return false;
}

bool const Employee::WriteData(ofstream& employeeDataOut)
{
	employeeDataOut << this->employeeName << endl;
	employeeDataOut << this->employeeID << endl;

	if (employeeDataOut.good())
		return true;
	else
		return false;
}