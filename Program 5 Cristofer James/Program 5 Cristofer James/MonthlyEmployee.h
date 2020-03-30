#pragma once
#ifndef MONTHLY_EMPLOYEE_H
#define MONTHLY_EMPLOYEE_H
#include "Employee.h"
#include <string>
using namespace std;

class MonthlyEmployee:public Employee
{
public:
	MonthlyEmployee();
	bool SetRank(int employeeRank);
	virtual string GetType() const override;
	virtual bool ReadData(ifstream& employeeDataIn) override;
	virtual bool WriteData(ofstream& employeeDataOut) const override;

private:
	int employeeRank;
};
#endif