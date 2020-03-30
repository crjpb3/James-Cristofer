#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
public:
	Employee();
	void SetName(const string& employeeName);
	string GetName() const;
	void SetID(const string& employeeID);
	string GetID() const;
	virtual string GetType() const;
	virtual bool ReadData(ifstream& employeeDataIn) = 0;
	virtual bool WriteData(ofstream& employeeDataOut) const = 0;

private:
	string employeeName;
	string employeeID;
};
#endif