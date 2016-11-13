/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 22, 2015
 ** Description: This defines the interface for the Queue class.
 *********************************************************************/


#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <iostream>
#include "Creature.hpp"

class Stack {
protected:
    struct StackNode {
        Creature* creature;
        StackNode* next;
        //Stack node constructor
        StackNode(Creature* newCreature, StackNode* next1) {
            creature = newCreature;
            next = next1;
        };
    };
    StackNode *head;
public:
    Stack();                        //Constructor
    ~Stack();                       //Destructor
    void add(Creature*);            //Add value to stack
    Creature* remove();                   //Remove value from stack
    void displayStack();            //Display the stack
    bool isEmpty();
};

#endif /* Stack_hpp */
