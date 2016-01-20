/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 18, 2015
 ** Description: This is the implementation of the Queue class
 *********************************************************************/

#include "Queue.hpp"

//Constructor for a new queue sets the default int to -1 and set next and prev to front
Queue::Queue() {
    front = new QueueNode(-1, front, front);
    back = front;
}

//Destructor that deletes all nodes using a loop until the last node. The last node is deleted once the
//loop completes.
Queue::~Queue() {
    QueueNode* nodePtr = front;
    while (nodePtr != back) {
        QueueNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
    delete nodePtr;
}

//Add a value to the back of the queue
void Queue::addBack(int newVal) {
    QueueNode* nodePtr = front;
    
    //If queue is empty the front value will be = -1
    //If this is the case we will update the front value
    //Pointers do not change since there is only 1 value
    if (front->value == -1) {
        front->value = newVal;
    }
    //If the queue is not empty we will add a node to the end of the queue
    else {
        nodePtr = back + 1;
        nodePtr = new QueueNode(newVal, back, front);
        back->next = nodePtr;
        back = nodePtr;
        front->prev = back;
    }
}

//Return the front value of the queue
int Queue::getFront() {
    return front->value;
}

//Remove the front value of the queue
void Queue::removeFront() {
    //If the queue is empty return an error message
    if (getFront() == -1) {
        std::cout << "The queue is currently empty" << std::endl;
    };
    //If the queue is not empty and the front is equal to the back set the value of front = -1 to indcate the queue is now empty
    if (front == back) {
        front->value = -1;
    }
    //Finally if we remove the front node, update the front pointer to the next node and update the new front prev pointer to back. Also update back next pointer.
    else {
        QueueNode* nodePtr = front;
        front = front->next;
        delete nodePtr;
        front->prev = back;
        back->next = front;
    }

}
