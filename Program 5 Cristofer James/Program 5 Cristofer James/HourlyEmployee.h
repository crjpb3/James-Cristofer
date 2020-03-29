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
	char const GetExpertEmployee();
	double const GetSalary();
	virtual string GetType();
	bool SetExpertEmployee(char newExpert);
	bool SetSalary(double newSalary);
	virtual bool ReadData(ifstream& employeeDataIn);
	virtual bool WriteData(ofstream& employeeDataOut);

private:
	char experiencedEmployee;
	double employeeSalary;
};
#endif