#include "HourlyEmployee.h"
#include <iostream>
#include <string>
using namespace std;

HourlyEmployee::HourlyEmployee()
{
	Employee::Employee();
	this->experiencedEmployee = 'F';
	this->employeeSalary = 0.0;
}