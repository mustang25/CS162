/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 22, 2015
 ** Description: This defines the interface for the Queue class.
 *********************************************************************/

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <iostream>
#include "Creature.hpp"

class Queue {
protected:
    struct QueueNode {
        Creature* creature;
        QueueNode* next;
        QueueNode* prev;
        QueueNode(Creature* newCreature,QueueNode* prev1, QueueNode* next1) {
            creature = newCreature;
            prev = prev1;
            next = next1;
        };
    };
    QueueNode *front;
    QueueNode *back;
public:
    Queue();
    ~Queue();
    void add(Creature*);
    Creature* remove();
    void displayQueue();
    bool isEmpty();
    Creature* returnBack();
};

#endif /* Queue_hpp */
