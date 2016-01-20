/*********************************************************************
 ** Author: Rob Navarro
 ** Date: December 2, 2015
 ** Description: This implements the FibonacciR class.
 ** Note this function was copied with permission from:
 ** http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
 *********************************************************************/


#include "FibonacciR.hpp"
#include <iostream>

FibonacciR::FibonacciR() {
    
}

FibonacciR::FibonacciR(int n):n_(n) {
    
}

FibonacciR::~FibonacciR() {
    
}

int FibonacciR::Fibonacci(int n) {
    if (n==0)
        return 0;
    else if (n==1)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void FibonacciR::PrintFibonacci() {
    int FibNum = Fibonacci(n_);
    
    //loop function an extra 100000 for better timing results
    for (int i = 0; i < 100000; i++) {
        Fibonacci(n_);
    }
    std::cout << n_ << "th recursive fibonacci number: " << FibNum << std::endl;
}