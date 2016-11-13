/*********************************************************************
 ** Author: Rob Navarro
 ** Date: December 2, 2015
 ** Description: This defines the interface for the FibonacciR class.
 ** Note this function was copied with permission from:
 ** http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
 *********************************************************************/

#ifndef FibonacciR_hpp
#define FibonacciR_hpp

#include <stdio.h>

class FibonacciR {
private:
    FibonacciR();
    int Fibonacci(int n);
    int n_;
public:
    FibonacciR(int n);
    virtual ~FibonacciR();
    void PrintFibonacci();
};

#endif /* FibonacciR_hpp */
