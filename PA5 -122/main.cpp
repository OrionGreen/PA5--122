#include "TestSims.hpp"

int main(void) {

	TestSim sim;
	sim.TestEnqueueEmpty();
	sim.TestEnqueueOne();
	sim.TestDequeueone();
	sim.TestDequeueTwo();

	sim.TestSimulation();

	Sleep(400);

	sim.runApp();

	return 0;
}