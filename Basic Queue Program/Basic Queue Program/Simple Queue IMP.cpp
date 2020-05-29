//Cristofer James
//May 29, 2020
#include "Simple Queue.h"
#include <iostream>
#include <queue>
using namespace std;

Simple_Queue::Simple_Queue()
{
	this->is_empty = true;
}

void Simple_Queue::add_to_queue(string name)
{
	this->person_queue.push(name);
	this->is_empty = false;
}

void Simple_Queue::remove_current()
{
	this->person_queue.pop();
	if (person_queue.empty())
		this->is_empty = true;
}

string Simple_Queue::get_current()
{
	string current_person = this->person_queue.front();
	return current_person;
}

bool Simple_Queue::get_empty()
{
	bool empty = this->is_empty;
	return empty;
}