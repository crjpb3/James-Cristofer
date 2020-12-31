#pragma once
#ifndef Airport_H
#define Airport_H
#include <queue>
#include "Request.h"
#include "Runway.h"
using namespace std;

class Airport
{
public:
	Airport() {}
	~Airport() {}
	void simulate();
	void add_to_Q(Request* p);
	Request get_next_flight();
	void Q_pop();
	void update_minutes_in_Q(Request Flight);
	float calculate_avg_min_in_Q(int sum_min_in_Q, int total_requests);
	void update_airport();
	void show_Q(queue<Request> curr_Q);
	void simulation_report();

private:
	const int simulation_duration_mins = 120;
	int curr_time = 0;//Using 24-hour clock and starting the clock at 00:00(midnight/12:00AM) for simplicity
	int sum_min_in_landing_Q = 0;
	int sum_min_in_takeoff_Q = 0;
	int total_landings = 0;
	int total_takeoffs = 0;
	int total_landing_requests = 0;
	int total_takeoff_requests = 0;
	Request* req_ptr = nullptr;
	queue<Request> landing_Q;
	queue<Request> takeoff_Q;
	Runway Strip1;
	Runway Strip2;

};
#endif