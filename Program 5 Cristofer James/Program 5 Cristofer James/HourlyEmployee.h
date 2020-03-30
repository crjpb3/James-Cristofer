#pragma once
#ifndef HOURLY_EMPLOYEE_H
#define HOURLY_EMPLOYEE_H
#include "Employee.h"
#include <string>
using namespace std;

class HourlyEmployee:public Employee
{
public:
	HourlyEmployee();
	bool SetExpertEmployee(char newExpert);
	char GetExpertEmployee() const;
	bool SetSalary(double newSalary);
	double GetSalary() const;
	virtual string GetType() const override;
	virtual bool ReadData(ifstream& employeeDataIn) override;
	virtual bool WriteData(ofstream& employeeDataOut) const override;

private:
	char experiencedEmployee;
	double employeeSalary;
};
#endif