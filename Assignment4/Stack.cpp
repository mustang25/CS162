/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 22, 2015
 ** Description: This implements the Stack class.
 *********************************************************************/


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
void Stack::add(Creature* newCreature) {
    //If stack is empty, set head to be the first value
    if (head == NULL) {
        head = new StackNode(newCreature, NULL);
    }
    //If stack is not empty add value to the top of the stack
    else {
        StackNode* nodePtr = head;                  //set nodePtr to = head
        nodePtr = nodePtr->next;                    //move nodePtr to next position in the stack
        nodePtr = head;                             //Now set the nodePtr = head
        head = new StackNode(newCreature, nodePtr);      //replace the old head value with new stack val
    }
    
}

//Remove first number from stack
Creature* Stack::remove() {
    Creature* returnCreature;
    StackNode* nodePtr;
    
    //Check if the stack is empty
    if (!head) {
        //If empty inform user and return -1
        std::cout << "The stack is currently empty" << std::endl;
        return NULL;
    }
    else {
        nodePtr = head;                 //set nodePtr = to the current head value
        returnCreature = nodePtr->creature;     //store return value from current head
        head = head->next;              //move second value in stack to the head of stack
        delete nodePtr;                 //delete the old head value
        return returnCreature;               //return the value from old head
    }
}

void Stack::displayStack() {
    StackNode* nodePtr = head;

    //Display all values in the stack until the nodePtr = NULL
    while (nodePtr != NULL){
        std::cout << nodePtr->creature->getName() << std::endl;
        nodePtr = nodePtr->next;
        
    }
}

bool Stack::isEmpty() {
    if (head == NULL) {
        return true;
    }
    else
        return false;
}
