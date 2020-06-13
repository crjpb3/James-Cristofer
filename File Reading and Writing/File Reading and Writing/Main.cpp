//Cristofer James
//June 10, 2020
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	string name;
	int age_years;
	char choice;

	cout << "A - Display stored info" << endl;
	cout << "B - Enter info to store" << endl;
	cin >> choice;
	if (toupper(choice) == 'A')
	{
		fin.open(filename);
		fin >> name;
		fin >> age_years;
		fin.close(filename);
		cout << "Name: " << name << endl;
		cout << "Age: " << age_years << endl;
	}
	else
	{
		fout.open(filename);
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter age: ";
		cin >> age_years;
		fout << name << endl;
		fout << age_years << endl;
		fout.close(filename);
	}
	system("cls");
	cout << "Operations Complete" << endl;




	return 0;
}