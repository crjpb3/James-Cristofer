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
	Employee* employees[100]{ nullptr };

	char empType; //Used by the switch statement to determine the employee type
	int empNum = 0; //Used for iterating through the employees[] array and for getting the total number of employee entries
	int totalHourlyEmp = 0; //Keeps track of total number of Hourly Employees
	int totalMonthlyEmp = 0; //Keeps track of total number of Monthly Employees

	fin.open("input.txt");
	fin >> empType;

	while (!fin.eof())
	{//Reads through the employee data file
		fin.ignore(INT_MAX, '\n'); //removes the newline character left in the stream by "fin >> empType;" so the getline() functions in ReadData() pull the proper inputs

		switch (toupper(empType))
		{
		case 'H':
		{//Handles Hourly Employee entries
			employees[empNum] = new HourlyEmployee;
			employees[empNum]->ReadData(fin);
			totalHourlyEmp++; //Increment the number of Hourly Employees
			break;
		}
		case 'M':
		{//Handles Monthly Employee entries
			employees[empNum] = new MonthlyEmployee;
			employees[empNum]->ReadData(fin);
			totalMonthlyEmp++; //Increment the number of Monthly Employees
			break;
		}
		default:
		{//If neither 'H' nor 'M' are read for employee type, an error message is displayed and the program exits
			fin.close();
			cout << "\n\tThere was an error reading the file." << endl;
			exit(1);
		}
		}
		empNum++; //Increment the employee number; this line performs one final increment before the loop ends which is equal to the total number of employee entries
		fin >> empType;
	}
	fin.close();

	cout << "There are " << totalHourlyEmp << " hourly employees." << endl;
	cout << "There are " << totalMonthlyEmp << " monthly employees." << endl;

	
	fout.open("output.txt");
	fout << "\tMonthly Employees" << endl;
	for (int a = 0; a < empNum; a++)
	{//Iterate through employees[] to print only the Monthly Employees
		if(employees[a]->GetType().compare("Monthly Employee") == 0)
			employees[a]->WriteData(fout);
	}
	fout << endl;
	fout.close();

	fout.open("output.txt", ofstream::app);
	fout << "\tHourly Employees" << endl;
	for (int a = 0; a < empNum; a++)
	{//Iterate through employees[] to print only the Hourly Employees
		if (employees[a]->GetType().compare("Hourly Employee") == 0)
			employees[a]->WriteData(fout);
	}
	fout.close();

	for (int a = 0; a < empNum; a++)
	{//Frees the dynamic objects and assigns the used employees[] pointers to nullptr
		delete employees[a];
		employees[a] = nullptr;
	}

	return 0;
}