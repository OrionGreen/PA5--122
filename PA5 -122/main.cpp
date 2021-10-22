#include "TestSims.hpp"

int main(void) {

	TestSim sim;

	//testing enqueue and dequeue
	sim.TestEnqueueEmpty();
	sim.TestEnqueueOne();
	sim.TestDequeueone();
	sim.TestDequeueTwo();

	//run the 24 hour sim
	sim.TestSimulation();

	Sleep(400);

	//app to run sim for any amount of time you would like
	sim.runApp();

	return 0;
}