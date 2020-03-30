//Cristofer James
//CS201R
//Program 5
#include <iostream>
#include <fstream>
#include <string>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "MonthlyEmployee.h"

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	Employee* employees[100]{ NULL };

	char empType;
	int empNum = 0;
	int totalHourlyEmp = 0;
	int totalMonthlyEmp = 0;
	int totalEmp;

	fin.open("input.txt");
	fin >> empType;

	while (!fin.eof())
	{
		if (toupper(empType) == 'H')
		{
			employees[empNum] = new HourlyEmployee;
			employees[empNum]->ReadData(fin);
			totalHourlyEmp++;
		}
		else
			if (toupper(empType) == 'M')
			{
				employees[empNum] = new MonthlyEmployee;
				employees[empNum]->ReadData(fin);
				totalMonthlyEmp++;
			}

		empNum++;
	}

	totalEmp = empNum + 1;

	cout << "There are " << totalHourlyEmp << " hourly employees." << endl;
	cout << "There are " << totalMonthlyEmp << " monthly employees." << endl;

	for (int a = 0; a < totalEmp; a++)
	{

	}

	return 0;
}