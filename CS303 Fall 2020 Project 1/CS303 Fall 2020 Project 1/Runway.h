#pragma once
#ifndef RUNWAY_H
#define RUNWAY_H
using namespace std;

class Runway
{
public:
	Runway() {}
	~Runway() {}

	bool get_availability() { bool is_avail = available; return is_avail; }
	int get_num_landings() { int landings_completed = num_landings;  return landings_completed; }
	int get_num_takeoffs() { int takeoffs_completed = num_takeoffs;  return takeoffs_completed; }
	char get_type() { int curr_type = Curr_Flight.get_req_type(); return curr_type; }

	void accept_request(Request Flight)
	{
		available = false;
		Curr_Flight = Flight;
	}

	void update_runway()
	{//Updates the amount of time the current takeoff or landing procedure has left before the Runway object becomes available for another Request and updates the number of landings or takeoffs performed
		operation_time_remaining -= 5;

		if (operation_time_remaining <= 0)
		{
			if (Curr_Flight.get_req_type() == 'L')
				num_landings++;
			else
				if (Curr_Flight.get_req_type() == 'T')
					num_takeoffs++;

			available = true;
			operation_time_remaining = 15;
			Curr_Flight.reset();//Sets the object back to default values
		}
	}
	
private:
	bool available = true;
	int operation_time_remaining = 15;//A takeoff or landing takes 15 minutes
	int num_landings = 0;
	int num_takeoffs = 0;
	Request Curr_Flight;
};
#endif