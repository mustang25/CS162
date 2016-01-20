//
//  main.cpp
//  Lab6
//
//  Created by Rob Navarro on 11/4/15.
//  Copyright © 2015 Rob Navarro. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"
#include "Queue.hpp"

int main(int argc, const char * argv[]) {
    //Test the stack
    Stack n;
    std::cout << "Testing the stack" << std::endl;
    n.remove();
    n.add(5);
    n.add(10);
    n.add(15);
    n.add(20);
    n.displayStack();
    std::cout << n.remove() << std::endl;
    std::cout << n.remove() << std::endl;
    std::cout << n.remove() << std::endl;
    std::cout << n.remove() << std::endl;
    
    //Test the queue
    Queue q;
    std::cout << "Testing the queue" << std::endl;
    q.remove();
    q.add(3);
    q.add(6);
    q.add(9);
    q.add(12);
    q.displayQueue();
    std::cout << q.remove() << std::endl;
    std::cout << q.remove() << std::endl;
    std::cout << q.remove() << std::endl;
    std::cout << q.remove() << std::endl;
    
    return 0;
}


