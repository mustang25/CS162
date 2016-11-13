//
//  Queue.cpp
//  Lab6
//
//  Created by Rob Navarro on 11/4/15.
//  Copyright © 2015 Rob Navarro. All rights reserved.
//

#include "Queue.hpp"

//Queue constructor that sets the front to NULL
Queue::Queue() {
    front = NULL;
}

//Queue destructor for mem cleanup
Queue::~Queue() {
    QueueNode* nodePtr = front;
    while (nodePtr != 0) {
        QueueNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

//Add int to end of queue
void Queue::add(int number) {
    
    //If queue is empty add the first value and set it to the front
    if (front == NULL) {
        front = new QueueNode(number, NULL, NULL);
        back = front;
    }
        else {
            //move through queue until we reach the last value
            back->next = new QueueNode(number, back, NULL);
            back = back->next;
    }
}

//remove first number from queue and return the value
int Queue::remove() {
    int returnVal;
    QueueNode* nodePtr;
    
    //If the queue is empty inform the user and return 0
    if (!front) {
        std::cout << "The queue is currently empty" << std::endl;
        return -1;
    }
    else {
        nodePtr = front;                 //set nodePtr = front
        returnVal = nodePtr->value;     //store the return val from nodePtr
        front = front->next;              //have front = the second value in queue
        delete nodePtr;                 //delete the previous first value
        if (front != NULL) {
            front->prev = NULL;          //set the front prev value to NULL since it's the first val
        }
        return returnVal;               //return the return value
    }
}

void Queue::displayQueue() {
    QueueNode* nodePtr = front;
    
    //Display all values in the queue until the nodePtr = NULL
    while (nodePtr != NULL) {
        std::cout << nodePtr->value << std::endl;
        nodePtr = nodePtr->next;
    }
    
}

