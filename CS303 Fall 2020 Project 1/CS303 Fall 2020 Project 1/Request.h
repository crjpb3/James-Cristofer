#pragma once
#ifndef REQUEST_H
#define REQUEST_H
using namespace std;

class Request
{
public:
	Request();
	~Request() {}
	Request(int r_time);
	void reset();
	char get_req_type() { int type = request_type; return type; }
	int get_request_time() { int req_time = request_time; return req_time; }
	void set_type(char type);
	void set_req_time(int req_time);
	char generate_req_type();
	Request operator =(Request& Copy);

private:
	int request_time;
	char request_type;

};
#endif