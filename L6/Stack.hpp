//
//  Stack.hpp
//  Lab6
//
//  Created by Rob Navarro on 11/4/15.
//  Copyright © 2015 Rob Navarro. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <iostream>

class Stack {
protected:
    struct StackNode {
        int value;
        StackNode* next;
        //Stack node constructor
        StackNode(int val1, StackNode* next1) {
            value = val1;
            next = next1;
        };
    };
    StackNode *head;
public:
    Stack();                //Constructor
    ~Stack();               //Destructor
    void add(int);          //Add value to stack
    int remove();           //Remove value from stack
    void displayStack();    //Display the stack
};

#endif /* Stack_hpp */
