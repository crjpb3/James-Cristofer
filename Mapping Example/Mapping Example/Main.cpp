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
	map<string, string> example_map;
	map<string, string>::iterator itr;
	pair<string, string> map_pair;
	map_pair.first = "Test";
	map_pair.second = "Test again";

	example_map.insert(map_pair);

	for (itr = example_map.begin(); itr != example_map.end(); itr++)
	{
		cout << itr->first << ": " << itr->second << endl;
	}

	
	return 0;
}