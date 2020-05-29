//Cristofer James
//May 29, 2020
#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <string>
#include <queue>
using namespace std;

class Simple_Queue
{
public:
	Simple_Queue();
	void add_to_queue(string name);
	void remove_current();
	string get_current();
	bool get_empty();

private:
	queue<string> person_queue;
	bool is_empty;
};
#endif