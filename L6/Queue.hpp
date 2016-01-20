//
//  Queue.hpp
//  Lab6
//
//  Created by Rob Navarro on 11/4/15.
//  Copyright © 2015 Rob Navarro. All rights reserved.
//

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
        QueueNode(int val1,QueueNode* prev1, QueueNode* next1) {
            value = val1;
            prev = prev1;
            next = next1;
        };
    };
    QueueNode *front;
    QueueNode *back;
public:
    Queue();
    ~Queue();
    void add(int);
    int remove();
    void displayQueue();
};

#endif /* Queue_hpp */
