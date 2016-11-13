/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 8, 2015
 ** Description: This defines the interface for the Dice class.
 *********************************************************************/

#ifndef Die_hpp
#define Die_hpp

#include <stdio.h>
#include <iostream>
#include <stdlib.h>


class Die {
    
private:
    int sides;
    
public:
    Die(int s);
    int roll();
    
};

#endif /* Die_hpp */
