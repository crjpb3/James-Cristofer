#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

void menu();
void readData(int size, int idNum[], string firstName[], string lastName[], string cityName[], string stateAbbr[], double gpa[]);
int getInput();
void validateInput(int& input);
void display_Info(int size, int ID[], string first[], string last[], string city[], string state[], double GPA[]);
void display(int size, int ID[], string first[], string last[], string city[], string state[], double GPA[]);
void count_city(int size, string city[], string state[]);

int main()
{
	const int ARRAY_SIZE = 10;
	int studentID[ARRAY_SIZE];
	string firstName[ARRAY_SIZE];
	string lastName[ARRAY_SIZE];
	string cityName[ARRAY_SIZE];
	string state[ARRAY_SIZE];
	double studentGPA[ARRAY_SIZE];
	bool isExit = false;

	readData(ARRAY_SIZE, studentID, firstName, lastName, cityName, state, studentGPA);
	menu();
	
	do
	{
		getInput();

	} while (!isExit);
}

void menu()
{
	cout << "Welcome to Student Center" << endl;
	cout << "1- Display Student Info" << endl;
	cout << "2- Display Student Info sorted by City" << endl;
	cout << "3- Display Student Info sorted by City and total number of students in each city" << endl;
	cout << "4- Exit" << endl;
	cout << "Please choose an option: ";
}

void readData(const int size, int idNum[], string firstName[], string lastName[], string cityName[], string state[], double gpa[])
{
	ifstream inFile;
	int arrayPos = 0;

	inFile.open("Student_Info.txt");

	while ((arrayPos < size) && (!inFile.eof()))
	{
		inFile >> idNum[arrayPos] >> firstName[arrayPos] >> lastName[arrayPos] >> cityName[arrayPos] >> state[arrayPos] >> gpa[arrayPos];
		arrayPos++;
	}
}


int getInput()
{
	int userInput;
	cin >> userInput;
}

void validateInput(int& input)
{
	while ((input < 1) || (input > 4))
	{
		cout << "That input is invalid." << endl << endl;
		menu();
		cin >> input;
	}
}

void display_Info(int size, int ID[], string first[], string last[], string city[], string state[], double GPA[])
{

}

void display(int size, int ID[], string first[], string last[], string city[], string state[], double GPA[])
{

}

void count_city(int size, string city[], string state[])
{

}