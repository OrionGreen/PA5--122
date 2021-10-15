#pragma once
#include "Data.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <time.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class QueueNode

{

public: // Member functions
    QueueNode(Data* newData);

    QueueNode& operator= (const QueueNode& rhs);

    ~QueueNode();

    //setters
    void setpData(Data* const newpData);
    void setpNext(QueueNode* const newpNext);

    //getters
    Data* getpData(void) const;
    QueueNode* getpNext(void) const;

private:

    Data* mpData;    // The memory for Data will need to be allocated on the heap as well!
    QueueNode* mpNext;

};