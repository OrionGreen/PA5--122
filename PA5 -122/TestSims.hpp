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
   bool TestEnqueueOne();
   bool TestDequeueone();
   bool TestDequeueTwo();

   void TestSimTime(int minutes);
   void TestSimulation();
   void runApp();

private:
    Queue express;
    Queue normal;

};