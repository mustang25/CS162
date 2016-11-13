/*********************************************************************
 ** Author: Rob Navarro
 ** Date: September 30, 2015
 ** Description: This implements the Die class.
 *********************************************************************/

# include <iostream>
# include <cstdlib>
# include "Die.hpp"

int xRan;

//Die constuctor, the number of sides are set
Die::Die(int s) {
    sides = s;
}

//This function rolls the die and returns a random number. 
int Die::roll(){
    xRan = rand()%sides+1;
    
    std::cout << "The die rolled a: " << xRan << std::endl;
    
    return xRan;
}
