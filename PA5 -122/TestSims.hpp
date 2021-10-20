#pragma once
#include "QueueNode.hpp"
#include "Data.hpp"
#include "Queue.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;


class TestSim

{

public: // Member functions
    TestSim();
    ~TestSim();

   bool TestEnqueueEmpty();
   bool TestEnququqOne();
   bool TestDequeueone();
   bool TestDequeueTwo();
   void TestSimTime(int minutes);

   void TestSimulation();

private:
    Queue express;
    Queue normal;

};