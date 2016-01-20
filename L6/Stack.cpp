//
//  Stack.cpp
//  Lab6
//
//  Created by Rob Navarro on 11/4/15.
//  Copyright © 2015 Rob Navarro. All rights reserved.
//

#include "Stack.hpp"

//Default stack constructor that sets the head to NULL
Stack::Stack() {
    head = NULL;
}

//Stack destructor that cleans up memory from Stack
Stack::~Stack() {
    StackNode* nodePtr = head;
    while (nodePtr != 0) {
        StackNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

//Add number to the front of the stack
void Stack::add(int number) {
    //If stack is empty, set head to be the first value
    if (head == NULL) {
        head = new StackNode(number, NULL);
    }
    //If stack is not empty add value to the end of the stack
    else {
        StackNode* nodePtr = head;                  //set nodePtr to = head
        nodePtr = nodePtr->next;                    //move nodePtr to next position in the stack
        nodePtr = head;                             //Now set the nodePtr = head
        head = new StackNode(number, nodePtr);      //replace the old head value with new stack val
    }
    
}

//Remove first number from stack
int Stack::remove() {
    int returnVal;
    StackNode* nodePtr;
    
    //Check if the stack is empty
    if (!head) {
        //If empty inform user and return -1
        std::cout << "The stack is currently empty" << std::endl;
        return -1;
    }
    else {
        nodePtr = head;                 //set nodePtr = to the current head value
        returnVal = nodePtr->value;     //store return value from current head
        head = head->next;              //move second value in stack to the head of stack
        delete nodePtr;                 //delete the old head value
        return returnVal;               //return the value from old head
    }
}

void Stack::displayStack() {
    StackNode* nodePtr = head;

    //Display all values in the stack until the nodePtr = NULL
    while (nodePtr != NULL){
        std::cout << nodePtr->value << std::endl;
        nodePtr = nodePtr->next;
        
    }
}
