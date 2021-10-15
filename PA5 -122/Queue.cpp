#include "Queue.hpp"

Queue::Queue(QueueNode* newHead, QueueNode* newTail) {
	this->mpHead = newHead;
	this->mpTail = newTail;
}

//shallow copy for now until I determine I need a deep copy
Queue& Queue::operator= (const Queue& rhs) {
	this->mpHead = rhs.mpHead;
	this->mpTail = rhs.mpTail;
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