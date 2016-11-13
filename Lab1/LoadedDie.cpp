/*********************************************************************
 ** Author: Rob Navarro
 ** Date: September 30, 2015
 ** Description: This implements the Die class.
 *********************************************************************/

# include <iostream>
# include <cstdlib>
# include "LoadedDie.hpp"

int ran;

//Loaded die constructor, the number of sides are set
LoadedDie::LoadedDie(int s) {
    sides = s;
}

//This function rolls the die for a random number.
//Whenever the roll is a even number and the value is from 1 - 4,
//a value of 2 is added to the roll.
//This allows the loaded die to have a higher roll on average.
int LoadedDie::roll(int rollNum, int r){
    ran = rand()%sides+1;
    
    if (rollNum % 2 == 0) {
        if (ran + 1 < sides)
            ran += 2;
    };

    std::cout << "The loaded die rolled a: " << ran << std::endl;
    return ran;
}

