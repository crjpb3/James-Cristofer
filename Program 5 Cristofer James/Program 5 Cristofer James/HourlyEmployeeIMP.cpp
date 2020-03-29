#include "HourlyEmployee.h"
#include <iostream>
#include <string>
using namespace std;

HourlyEmployee::HourlyEmployee()
{
	Employee::SetName("0");
	Employee::SetID("0");
	this->experiencedEmployee = 'F';
	this->employeeSalary = 0.0;
}