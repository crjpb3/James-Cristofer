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
	virtual string GetType() const;
	virtual bool ReadData(ifstream& employeeDataIn) const = 0;
	virtual bool WriteData(ofstream& employeeDataOut) const = 0;

private:
	string employeeName;
	string employeeID;
};
#endif