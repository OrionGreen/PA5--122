#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <time.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;


class Data

{

public: // Member functions

    Data(int customerNum, int serviceTime, int totalTime);

    Data& operator= (const Data& rhs);

    ~Data();
    //setters 
    void setCustomerNumber(int const newCustomerNumber);
    void setServiceTime(int const newServiceTime);
    void setTotalTime(int const newTotalTime);

    //getters
    int getCustumerNumber(void) const;
    int getServiceTime(void) const;
    int getTotalTime(void) const;


private:

    int mCustomerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1

    int mServiceTime;   // Random time; varies between express and normal lanes; units in minutes

    int mTotalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

}; // This memory needs to be allocated on the heap!