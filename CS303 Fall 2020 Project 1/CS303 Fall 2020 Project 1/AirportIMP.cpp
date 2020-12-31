#include <iostream>
#include <iomanip>
#include "Airport.h"
using namespace std;

void Airport::simulate()
{
	while (curr_time <= simulation_duration_mins)
	{
		//Creates a new request each iteration; iterations are increments of 5
		req_ptr = new Request(curr_time);
		add_to_Q(req_ptr);

		if (Strip1.get_availability() && (get_next_flight().get_req_type() != '_'))
		{//Accepts Requests into Strip1 for operation
			Strip1.accept_request(get_next_flight());
			update_minutes_in_Q(get_next_flight());
			Q_pop();
		}

		if (Strip2.get_availability() && (get_next_flight().get_req_type() != '_'))
		{//Accepts Requests into Strip2 for operation
			Strip2.accept_request(get_next_flight());
			update_minutes_in_Q(get_next_flight());
			Q_pop();
		}
		update_airport();
	}

	req_ptr = nullptr;
	total_landings = Strip1.get_num_landings() + Strip2.get_num_landings();
	total_takeoffs = Strip1.get_num_takeoffs() + Strip2.get_num_takeoffs();
}

void Airport::add_to_Q(Request* p)
{//Adds the object to the appropriate queue if it is a valid Request type; default objects will not be added to either queue
	if (p->get_req_type() == 'L')
	{
		landing_Q.push(*p);
		total_landing_requests++;
	}
	else
		if (p->get_req_type() == 'T')
		{
			takeoff_Q.push(*p);
			total_takeoff_requests++;
		}
}

Request Airport::get_next_flight()
{//Pulls from the appropriate queue if it's not empty; returns a default Request object if both queues are empty
	Request Blank;
	if (!landing_Q.empty())
		return landing_Q.front();
	else
		if (!takeoff_Q.empty())
			return takeoff_Q.front();

	return Blank;
}

void Airport::Q_pop()
{//Pops the appropriate queue so long as it's not empty
	if (!landing_Q.empty())
		landing_Q.pop();
	else
		if (landing_Q.empty() && !takeoff_Q.empty())
			takeoff_Q.pop();
}

void Airport::update_minutes_in_Q(Request Flight)
{//Updates the sum of minutes in each queue for average claculation
	int minutes = 0;
	int r_time_min = Flight.get_request_time();
	int curr_time_min = curr_time;
	minutes = curr_time_min - r_time_min;//Calculates the time the request has been in the queue
	
	if (Flight.get_req_type() == 'L')
	{
		sum_min_in_landing_Q += minutes;
	}
	else
		if (Flight.get_req_type() == 'T')
		{
			sum_min_in_takeoff_Q += minutes;
		}
}

float Airport::calculate_avg_min_in_Q(int sum_min_in_Q, int total_requests)
{
	float avg_min = 0.0;

	if (total_requests <= 0)//Avoid division by zero
		avg_min = 0;
	else
		avg_min = static_cast<float>(sum_min_in_Q) / static_cast<float>(total_requests);

	return avg_min;
}

void Airport::update_airport()
{
	curr_time += 5;
	Strip1.update_runway();
	Strip2.update_runway();
}

void Airport::simulation_report()
{	
	cout << "\t=====Simulation Report=====" << endl << endl;
	cout << "Total Number of Landings Completed: " << total_landings << endl;
	cout << "\n\t>Runway 1 Number of Landings: " << Strip1.get_num_landings() << endl;
	cout << "\t>Runway 2 Number of Landings: " << Strip2.get_num_landings() << endl << endl;
	cout << "Total Number of Takeoffs Completed: " << total_takeoffs << endl;
	cout << "\n\t>Runway 1 Number of Takeoffs: " << Strip1.get_num_takeoffs() << endl;
	cout << "\t>Runway 2 Number of Takeoffs: " << Strip2.get_num_takeoffs() << endl << endl;

	cout << "\n***Landing Queue Remaining Contents***" << endl << endl;
	show_Q(landing_Q);
	cout << "\n***Takeoff Queue Remaining Contents***" << endl << endl;
	show_Q(takeoff_Q);

	cout << fixed << setprecision(2) << "\nAverage Minutes Spent in Landing Queue: " << calculate_avg_min_in_Q(sum_min_in_landing_Q, total_landing_requests) << " minutes." << endl;
	cout << fixed << setprecision(2) << "Average Minutes Spent in Takeoff Queue: " << calculate_avg_min_in_Q(sum_min_in_takeoff_Q, total_takeoff_requests) << " minutes." << endl;
}

void Airport::show_Q(queue<Request> curr_Q)
{//Displays items left in the passed queue
	int flight_num = 1;
	int hour;
	int minute;

	if (curr_Q.empty())
	{
		cout << "\t[EMPTY QUEUE]" << endl << endl;
		return;
	}

	while (!curr_Q.empty())
	{
		hour = curr_Q.front().get_request_time() / 60;//Calculates number of clock hours from the total duration minutes
		minute = curr_Q.front().get_request_time() % 60;//Calculates number of clock minutes from the total duration minutes

		cout << "\t|Flight " << flight_num << ", Request Time: " << hour << ":";

		if (minute < 10)//Corrects the output when minutes are less than 10
			cout << "0" << minute << "AM|" << endl;
		else
			cout << minute << "AM|" << endl;

		update_minutes_in_Q(curr_Q.front());//Accounts for the time of Requests remaining in the queue
		curr_Q.pop();
		flight_num++;
	}
	cout << endl << endl;
}