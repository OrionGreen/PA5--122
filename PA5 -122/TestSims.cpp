#include "TestSims.hpp"

//no constructor or destructor
TestSim::TestSim() {

}

TestSim::~TestSim() {

}

//testing for the queueing and dequeueing
bool TestSim::TestEnqueueEmpty() {
	Data* data = new Data(1, 9, 9);
	Queue Q1;
	bool works = false;

	Q1.enqueue(data);

	if (Q1.getmpHead()->getpData()->getCustumerNumber() == 1) {
		works = true;
	}
	if (works) {
		cout << "Inserting into an Empty Queue Works!" << endl;
	}

	return true;
}
bool TestSim::TestEnqueueOne() {
	Data* data = new Data(1, 9, 9);
	Queue Q1;
	bool works = false;
	
	Q1.enqueue(data);
	data = new Data(2, 9, 18);
	Q1.enqueue(data);

	if (Q1.getmpTail()->getpData()->getCustumerNumber() == 2) {
		works = true;
	}
	if (works) {
		cout << "Inserting into Queue Works!" << endl;
	}

	return true;
}
bool TestSim::TestDequeueone() {
	Data* data = new Data(1, 9, 9);
	Queue Q1;
	bool works = false;
	Q1.enqueue(data);
	Q1.dequeue();
	if (Q1.getmpHead() == nullptr) {
		works = true;
	}
	if (works) {
		cout << "Dequeuing to make the Queue Empty Works!" << endl;
	}
	return true;
}
bool TestSim::TestDequeueTwo() {
	Data* data = new Data(1, 9, 9);
	Queue Q1;
	bool works = false;
	Q1.enqueue(data);
	data = new Data(2, 11, 11);
	Q1.enqueue(data);

	Q1.dequeue();
	if (Q1.getmpHead()->getpData()->getCustumerNumber() == 2) {
		works = true;
	}
	if (works) {
		cout << "Dequeuing the front Works!" << endl;
	}
	return true;
}



//The general program flow is as follows :
//
//Generate a random number between 1 – 5 and 3 – 8 for expressand normal lanes, respectively.This represents the arrival time of the first customer into each lane.Set the variable for total time elapsed to 0.
//As customers arrive into each line, randomly generate a service time for each. Start processing the customers in the lanes based on service time.Randomly generate the arrival time of the next customer into each line.Elapsed time should be updated by one unit.
//As each minute elapses, a new customer may arriveand /or another customer may be done checking out.Display the appropriate messages as described above.
//For every 10 minutes, print out the entire queue for each line
//Repeat steps 2 through 4 for n minutes of simulation

//actual sim code 
void TestSim::TestSimTime(int minutes) {
	srand(time(NULL));

	int timeMaster = 0;
	int NewCustArEx = (rand() % 5) + 1 ;
	int NewCustArNorm = (rand() % 6) + 3;
	int serviceTimeNorm = 0;
	int serviceTimeEx = 0;
	int custNum1 = 0;
	int custNum2 = 0;

	int timeElapsedNorm = 0;
	int timeElapsedEx = 0;

	Queue Express;
	Queue Normal;

	while (timeMaster != minutes) {
		
		if (timeMaster  == NewCustArEx) {
			int totalTimeWaiting = 0;
			custNum1 += 1;

			if (!Express.isEmpty()) {
				QueueNode* pMem = Express.getmpHead();
				while (pMem != nullptr) {
					totalTimeWaiting += pMem->getpData()->getServiceTime();
					pMem = pMem->getpNext();
				}
			}

			serviceTimeEx = (rand() % 5) + 1;
			totalTimeWaiting += serviceTimeEx;
			Data* data = new Data(custNum1, serviceTimeEx ,totalTimeWaiting);

			Express.enqueue(data);
			cout << "Customer Number: " << custNum1 << " has arrived into the Express Line." << endl;
			NewCustArEx += (rand() % 5) + 1;
		}

		if (timeMaster == NewCustArNorm) {
			int totalTimeWaiting = 0;
			custNum2 += 1;

			if (!Normal.isEmpty()) {
				QueueNode* pMem = Normal.getmpHead();
				while (pMem != nullptr) {
					totalTimeWaiting += pMem->getpData()->getServiceTime();
					pMem = pMem->getpNext();
				}
			}

			serviceTimeNorm = (rand() % 8) + 2;
			totalTimeWaiting += serviceTimeNorm;
			Data* data = new Data(custNum2, serviceTimeNorm ,totalTimeWaiting);

			Normal.enqueue(data);
			cout << "Customer Number: " << custNum2 << " has arrived into the Normal Line." << endl;
			NewCustArNorm += (rand() % 6) + 3;
		}

		bool dequeued = false;
		dequeued = Normal.checkQueue();
		if (dequeued) {
			cout << timeElapsedNorm - 1 << " minutes from the normal checkout line" << endl;
			timeElapsedNorm = 0;
		}

		dequeued = false;
		dequeued = Express.checkQueue();
		if (dequeued) {
			cout << timeElapsedEx - 1 << " minutes from the express checkout line" << endl;
			timeElapsedEx = 0;
		}

		if(timeMaster != 0 && timeMaster % 10 == 0) {
			cout << "Lines at time: " << timeMaster << endl << endl;
			cout << "Express Line" << endl;
			Express.printQueue();
			cout << "Normal Line" << endl;
			Normal.printQueue();
		}

		timeMaster++;
		timeElapsedNorm++;
		timeElapsedEx++;
	}
}

//runs simulation for 24 hours
void TestSim::TestSimulation() {
	TestSimTime(1440);
}

//allows the user to input any amount of minues to run sin for.
void TestSim::runApp() {
	cout << endl << "Please Enter an amount of minutes to run the simulation:" << endl;
	int minutes = 0;
	cin >> minutes;
	system("cls");

	TestSimTime(minutes);
}