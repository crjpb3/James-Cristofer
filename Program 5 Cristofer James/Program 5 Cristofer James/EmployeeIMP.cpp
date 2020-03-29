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

string Employee::GetType() const
{
	string employeeType = "Employee";

	return employeeType;
}