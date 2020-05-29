//Cristofer James
//May 29, 2020
#include "Simple Queue.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	Simple_Queue daily_queue;
	vector<string> names;

	names.push_back("Steve Johnson");
	names.push_back("Sarah Stevenson");
	names.push_back("Sandy Taman");
	names.push_back("Jordan Fenster");
	names.push_back("Travis Hammen");
	unsigned int v_size = names.size();

	for (unsigned int i = 0; i < v_size; i++)
	{
		daily_queue.add_to_queue(names.at(i));
	}

	while (!daily_queue.get_empty())
	{
		system("cls");
		cout << "Serving: " << daily_queue.get_current();
		cin.ignore();
		daily_queue.remove_current();
	}

	system("cls");
	cout << "The Queue is now empty" << endl;
	cin.ignore();
	return 0;
}