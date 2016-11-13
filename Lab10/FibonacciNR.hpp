/*********************************************************************
 ** Author: Rob Navarro
 ** Date: December 2, 2015
 ** Description: This defines the interface for the FibonacciNR class.
 ** Note this function was copied with permission from:
 ** http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
 *********************************************************************/

#ifndef FibonacciNR_hpp
#define FibonacciNR_hpp

#include <stdio.h>

class FibonacciNR {
public:
    FibonacciNR(int n);
    virtual ~FibonacciNR();
    void PrintFibonacci();
private:
    FibonacciNR();
    int Fibonacci(int n);
    int n_;
};

#endif /* FibonacciNR_hpp */
