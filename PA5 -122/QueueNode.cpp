#include "QueueNode.hpp"

QueueNode::QueueNode(Data* newData) {
	this->mpData = newData;
	this->mpNext = nullptr;
}

QueueNode& QueueNode::operator= (const QueueNode& rhs) {

	if (this != &rhs) {//self assignment?
		//this pointer - address of instance of object
		mpNext = rhs.mpNext;
		mpData = rhs.mpData;
	}

	return *this;
}

QueueNode::~QueueNode() {
}

//setters
void QueueNode::setpData(Data* const newpData) {
	this->mpData = newpData;
}
void QueueNode::setpNext(QueueNode* const newpNext) {
	this->mpNext = newpNext;
}

//getters
Data* QueueNode::getpData(void) const {
	return this->mpData;
}
QueueNode* QueueNode::getpNext(void) const {
	return this->mpNext;
}