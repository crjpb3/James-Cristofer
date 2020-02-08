//Cristofer James
//CS201R
//Program 2
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int option_choice;
	int num_walls;
	int length = 0;
	int height = 0;
	double wall_area = 0;

	cout << "Welcome to the paint shop" << endl << endl;
	cout << "We have a couple of options that you can choose from:" << endl;
	cout << "1) Paint the interior of the house" << endl;
	cout << "2) Paint the exterior of the house" << endl;
	cout << "3) Paint both interior and exterior of the house" << endl;
	cout << "Which option would you like?";
	cin >> option_choice;

	//input_validation(option_choice);
	
	switch (option_choice)
	{
	case 1:
	{
		cout << "How many walls will be painted?";
		cin >> num_walls;
		//input_validation(num_walls);

		

		break;
	}
	case 2:
	{

		break;
	}
	case 3:
	{

		break;
	}
	}

	cout << "How many walls will be painted?";
	cin >> num_walls;

	//input_validation(num_walls);

	return 0;
}

int house_area(int len, int height, int w, int walls)
{
	for (int w = 1; w <= walls; w++)
	{
		cout << "Enter the length for wall " << w;
		cin >> len;
		cout << "Enter the height for wall " << w;
		cin >> height;

		return (len * height) + house_area(len, height, w, walls);
	}
}