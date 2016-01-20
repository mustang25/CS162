/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 18, 2015
 ** Description: This defines the interface for the Queue class.
 *********************************************************************/

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <iostream>

class Queue {
protected:
    struct QueueNode {
        int value;
        QueueNode* next;
        QueueNode* prev;
        QueueNode(int val1, QueueNode* prev1, QueueNode* next1) {
            value = val1;
            prev = prev1;
            next = next1;
        };
    };
    QueueNode* front;
    QueueNode* back;
    
public:
    Queue();
    ~Queue();
    void addBack(int);
    int getFront();
    void removeFront();
};


#endif /* Queue_hpp */
