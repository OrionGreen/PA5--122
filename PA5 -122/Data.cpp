#pragma once 
#include "Data.hpp"

Data::Data(int customerNum, int serviceTime, int totalTime) {
	this->mCustomerNumber = customerNum;
	this->mServiceTime = serviceTime;
	this->mTotalTime = totalTime;
}

Data& Data::operator= (const Data& rhs) {
	if (this != &rhs) {//self assignment?
//this pointer - address of instance of object
		this->mCustomerNumber = rhs.mCustomerNumber;
		this->mServiceTime = rhs.mServiceTime;
		this->mTotalTime = rhs.mTotalTime;
	}

	return *this;
}

Data::~Data() {

}

//setters 

void Data::setCustomerNumber(int const newCustomerNumber) {
	this->mCustomerNumber = newCustomerNumber;
}
void Data::setServiceTime(int const newServiceTime) {
	this->mServiceTime = newServiceTime;
}
void Data::setTotalTime(int const newTotalTime) {
	this->mTotalTime = newTotalTime;
}

//getters
int Data::getCustumerNumber(void) const {
	return this->mCustomerNumber;
}
int Data::getServiceTime(void) const {
	return this->mServiceTime;
}
int Data::getTotalTime(void) const {
	return this->mTotalTime;
}