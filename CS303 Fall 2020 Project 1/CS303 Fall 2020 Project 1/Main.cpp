//Cristofer James
//CS303 Fall 2020, 4pm Tue/Thur
//Project 1: Airport Simulation
#include <iostream>
#include <ctime>
#include "Airport.h"
#include <omp.h>
using namespace std;
//DEVELOPMENT ISSUES:
//(1)Trying to work out the best way to get the classes and struct to work together
//(2)Trying to work out how to best handle the time
//(3)Issues with overloading the insertion operator <<; Seems even though I was returning the proper type on the right hand side, r_queue.front(CURR_TIME) which returns a Request obj,
//it was looking at r_queue which was invalidating the operand; Fixed it by switching the expected right hand side operand to a Runway_Queue obj rather than a Request obj
//(4)Realizing some functions can be consolidated and reducing the needed lines code
//(5)Deciding to rename and restructure a core class(Runway_Queue -> Airport) to make the program structure more intuitive and cohesive; Need to rework the class to accomodate the design change
//(6)Getting wrong number from a variable; Discovered int data type will take non-decimal numbers; 00100 is not the same as 100
//(7)Program is compiling and running, however, it hangs for an unknown reason. Using cout statements, I monitored the function calls and progress through the program in the console during runtime
//(8)Issues with class destructors; program would hang before exiting Main
//(9)Queues are somehow having more elements than were added; i.e. add 2 printing 5
//(10)Incorrectly placed Q_pop() calls causing items to be removed from the queues prematurely
//(11)Investigating update execution offset during simulation loop
//(12)The number of requests made and the number of requests completed were differing; Discovered a logic error in Runway causing the issue
//(13)Encountered an issue where default Requests were being accepted; corrected with an additional condtion in the simulation loop
//(14)Originally planned to use clock time, but encountered some issues with it and opted to just to duration time
//Some of the issues above are irrelevant at the time of completion since the source code has been altered through the development

int main()
{
	srand(time(0));
	Airport KCI;
	KCI.simulate();
	KCI.simulation_report();
	return 0;
}