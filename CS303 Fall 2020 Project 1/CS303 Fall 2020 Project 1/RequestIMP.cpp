#include <iostream>
#include "Request.h"
using namespace std;

Request::Request()
{
	request_time = -1;
	request_type = '_';
}

Request::Request(int r_time)
{
	request_time = r_time;
	request_type = generate_req_type();
}

void Request::set_type(char type)
{
	request_type = type;
}

void Request::set_req_time(int req_time)
{
	request_time = req_time;
}

void Request::reset()
{
	request_time = -1;
	request_type = '_';
}

char Request::generate_req_type()
{
	int type_val = rand() % 100;

	if ((type_val % 2) == 0)
		return 'L';

	return 'T';
}

Request Request::operator =(Request& Orig)
{
	this->request_time = Orig.get_request_time();
	this->request_type = Orig.get_req_type();
	return *this;
}