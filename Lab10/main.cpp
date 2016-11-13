/*********************************************************************
 ** Author: Rob Navarro
 ** Date: December 2, 2015
 ** Description: This program caculates the fib and tail numbers based
 ** on what number the user inputs. The time that it takes to calculate
 ** the number is also displayed in clicks and milliseconds
 *********************************************************************/


#include <iostream>
#include <time.h>
#include <stdio.h>

#include "FibonacciNR.hpp"
#include "FibonacciR.hpp"

long rfactorial (int n);
long facotrialHelper(int n, int result);
long factorial(int n);


int main(int argc, const char * argv[]) {
    clock_t t;
    int n = 0;
    float nrTime;
    float rTime;
    float ntrTime;
    float trTime;
    
    std::cout << "What number should be used to calculate the Fibonacci number? ";
    std::cin >> n;
    
    //Create iteration fib object
    //Results are displayed in milliseconds and clicks
    FibonacciNR fr(n);
    t = clock();
    fr.PrintFibonacci();
    t = clock() - t;
    //convert time to seconds
    nrTime = float(t)/CLOCKS_PER_SEC;
    //We need to divide the total clicks or seconds by 1000001 since we ran the function that many times
    std::cout << "The nonrecursive function took: " << t/1000001 << " clicks." << std::endl;
    nrTime /= 1000001;
    std::cout << "The nonrecursive function took: " << nrTime * 1000<< " milliseconds." << std::endl;
    
    //Create double recursive fib object
    //Results are display in milliseconds and clicks
    FibonacciR f(n);
    t = clock();
    f.PrintFibonacci();
    t = clock() - t;
    //Convert time to seconds
    rTime = float(t)/CLOCKS_PER_SEC;
    //We need to divide the total clicks or seconds by 100001 since we ran the function that many times
    std::cout << "The recursive function took: " <<  t/100001 << " clicks." << std::endl;
    rTime /= 100001;
    std::cout << "The recursive function took: " <<  rTime * 1000 << " milliseconds." << std::endl;
    
    //Give user option to change tail recursive number
    std::cout << "What number should be used to calculate the not tail and tail recursive? ";
    std::cin >> n;
    
    //Time the non tail recursive function by looping an extra 1000000 times
    t = clock();
    for (int i = 0; i < 1000000; i++) {
        rfactorial(n);
    }
    std::cout << "The " << n << "th non tail recursive number: " << rfactorial(n) << std::endl;
    t = clock() - t;
    ntrTime = float(t)/CLOCKS_PER_SEC;
    ntrTime /= 1000001;
    std::cout << "The non tail function took: " << t/1000001 << " clicks." << std::endl;
    std::cout << "The non tail function took: " <<  ntrTime * 1000 << " milliseconds." << std::endl;

    
    //Time the tail recursive function by looping an extra 1000000 times
    t = clock();
    for (int i = 0; i < 1000000; i++) {
        factorial(n);
    }
    std::cout << "The " << n << "th tail recursive number: " << factorial(n) << std::endl;
    t = clock() - t;
    trTime = float(t)/CLOCKS_PER_SEC;
    trTime /= 1000001;
    std::cout << "The tail function took: " << t/1000001 << " clicks." << std::endl;
    std::cout << "The tail function took: " <<  trTime * 1000 << " milliseconds." << std::endl;
    
    
    return 0;
}

//**The following functions were taken from the course website with permission by the instructor.

//Not Tail Recursive

long rfactorial(int n) {
    if (n == 1)
        return 1;
    else
        return n * rfactorial(n-1);
}

//Tail Recursive

long factorialHelper(int n, int result) {
    if (n==1)
        return result;
    else
        return factorialHelper(n-1,n*result);
}

long factorial(int n) {
    return factorialHelper(n,1);
}