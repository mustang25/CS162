/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 22, 2015
 ** Description: This implements the Queue class.
 *********************************************************************/

#include "Queue.hpp"

//Queue constructor that sets the front to NULL
Queue::Queue() {
    front = NULL;
    back = NULL;
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
void Queue::add(Creature* newCreature) {
    
    //If queue is empty add the first value and set it to the front
    if (front == NULL) {
        front = new QueueNode(newCreature, NULL, NULL);
        back = front;
    }
    else {
        //move through queue until we reach the last value
        back->next = new QueueNode(newCreature, back, NULL);
        back = back->next;
    }
}

//remove first number from queue and return the value
Creature* Queue::remove() {
    Creature* returnVal;
    QueueNode* nodePtr;
    
    //If the queue is empty inform the user and return 0
    if (!front) {
        std::cout << "The queue is currently empty" << std::endl;
        return NULL;
    }
    else {
        nodePtr = front;                 //set nodePtr = front
        returnVal = nodePtr->creature;     //store the return val from nodePtr
        front = front->next;              //have front = the second value in queue
       // delete nodePtr;                 //delete the previous first value
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
        std::cout << nodePtr->creature->getType() << std::endl;
        nodePtr = nodePtr->next;
    }
    
}

bool Queue::isEmpty() {
    if (front == NULL) {
        return true;
    }
    else
        return false;
}

