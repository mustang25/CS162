/*********************************************************************
 ** Author: Rob Navarro
 ** Date: December 2, 2015
 ** Description: This implements  the FibonacciNR class.
 ** Note this function was copied with permission from:
 ** http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
 *********************************************************************/


#include "FibonacciNR.hpp"
#include <iostream>

FibonacciNR::FibonacciNR() {
    
}

FibonacciNR::FibonacciNR(int n):n_(n) {
    
}

FibonacciNR::~FibonacciNR() {
    
}

int FibonacciNR::Fibonacci(int n) {
    int first = 0;
    int second = 1;
    int counter = 2;
    while (counter < n) {
        int temp = second;
        second = first + second;
        first = temp;
        ++counter;
    }
    if (n==0)
        return 0;
    else
        return first + second;
}

void FibonacciNR::PrintFibonacci() {
    int result = Fibonacci(n_);
    for (int i = 0; i < 1000000; i++) {
        Fibonacci(n_);
    }
    std::cout << n_ << "th nonrecursive fibonacci Number: " << result << std::endl;
}
