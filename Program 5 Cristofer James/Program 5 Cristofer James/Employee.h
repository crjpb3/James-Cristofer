#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
public:
	Employee();
	void SetName(string employeeName);
	string GetName();
	void SetID(string employeeID);
	string GetID();
	virtual const string GetType();
	virtual bool ReadData(ifstream& employeeDataIn);
	virtual const bool WriteData(ofstream& employeeDataOut);

private:
	string employeeName;
	string employeeID;
};
#endif