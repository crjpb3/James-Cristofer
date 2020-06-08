//Cristofer James
//June 3, 2020
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <map>
using namespace std;

int main()
{
	map<string, double> transaction_map;
	pair<string, double> pair1;
	pair1.first = "Transaction Test";
	pair1.second = 10.50;
	transaction_map.insert(pair1);
	map<string, map<string, double>> base_map;
	map<string, map<string, double>>::iterator itr;
	map<string, double>::iterator itr2;
	pair<string, map<string, double>> pair2;
	pair2.first = "Base Test";
	pair2.second = transaction_map;

	base_map.insert(pair2);


	for (itr = base_map.begin(); itr != base_map.end(); itr++)
	{
		cout << itr->first << ": ";
		for (itr2 = transaction_map.begin(); itr2 != transaction_map.end(); itr2++)
		{
			cout << itr2->first << ": " << itr2->second << endl;
		}
	}

	
	return 0;
}