#include "Queue.hpp"

Queue::Queue(QueueNode* newHead, QueueNode* newTail) {
	this->mpHead = newHead;
	this->mpTail = newTail;
}

//shallow copy for now until I determine I need a deep copy
Queue& Queue::operator= (const Queue& rhs) {
	this->mpHead = rhs.mpHead;
	this->mpTail = rhs.mpTail;
	return *this;
}


Queue::~Queue() {
	QueueNode* pMem = mpHead;
	QueueNode* pPrev = nullptr;
	if (mpHead != nullptr) {
		while (pMem != nullptr) {
			pPrev = pMem;
			pMem = pMem->getpNext();
			delete pPrev;
		}
	}
}


//getters
QueueNode* Queue::getmpHead(void) const {
	return this->mpHead;
}
QueueNode* Queue::getmpTail(void) const {
	return this->mpTail;
}
//setters
void Queue::setmpHead(QueueNode* const newmpHead) {
	this->mpHead = newmpHead;
}
void Queue::setmpTail(QueueNode* const newmpTail) {
	this->mpTail = newmpTail;
}

bool Queue::enqueue(Data* const newData) {

	QueueNode* pMem = new QueueNode(newData); //replaces makeNode()
	bool success = false;

	if (pMem != nullptr) {

		//allocated space for a Node 
		success = true;

		//check if empty
		if (this->isEmpty()) {
			//it's empty
			this->mpHead = this->mpTail = pMem;
		}
		else
		{
			//it's not empty
			this->mpTail->setpNext(pMem);
			this->mpTail = pMem;
		}

	}
	return success;
}

//checks if the time for the front of the line is done, if its not then it increments down 1 min if they are done we dequeue
bool Queue::checkQueue() {
	bool dequeued = false;
	if (this->getmpHead() != nullptr) {
		
		QueueNode* pMem = this->getmpHead();
		int num = this->getmpHead()->getpData()->getServiceTime();
		if (pMem->getpData()->getServiceTime() != 0) {
			this->getmpHead()->getpData()->setServiceTime(num - 1);
		}
		else {
			this->dequeue();
			dequeued = true;
		}

	}
	return dequeued;
}

bool Queue::isEmpty() {

	if (this->mpHead == nullptr) {
		return true;
	}
	else
		return false;
}

//takes out the head and prints a statement
void Queue::dequeue() {
	QueueNode* pMem = this->mpHead;
	string data;

	cout << "Customer: " << pMem->getpData()->getCustumerNumber() << " has finished checking out their time waiting in total was: " 
		<< pMem->getpData()->getTotalTime() << " minutes. They checked out in ";

	this->mpHead = pMem->getpNext();
	delete pMem;
}

//public and private helper to print the queue
void Queue::printQueue() {
	printQueueRecursive(this->mpHead);
}

void Queue::printQueueRecursive(QueueNode* pCur) {

	if (pCur == nullptr) {
		cout << endl;
		return;
	}
	else
	cout << *(pCur);
	printQueueRecursive(pCur->getpNext());
}