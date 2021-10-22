#pragma once
#include "QueueNode.hpp"
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


class Queue

{

public: // Member functions
    Queue(QueueNode* newHead = nullptr, QueueNode* newTail = nullptr);

    Queue& operator= (const Queue& rhs);

    ~Queue();


    //getters
    QueueNode* getmpHead(void) const;
    QueueNode* getmpTail(void) const;
    //setters
    void setmpHead(QueueNode* const newmpHead);
    void setmpTail(QueueNode* const newmpTail);

	bool enqueue(Data* const newData);

    bool checkQueue();

	bool isEmpty();

	void dequeue();

	void printQueue();

    void printQueueRecursive(QueueNode* pCur);

private:

    QueueNode* mpHead;
    QueueNode* mpTail;

};