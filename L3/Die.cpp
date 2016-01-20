//****************************************************************
//Date: 10/15/2015
//Description: This is the Die Class function implementation file.
//****************************************************************
#include "Die.hpp"
#include <cstdlib>
    
//Default constructor
Die::Die()
{
   sides = 6;
}

//This constructor takes the # of desired sides as a parameter
//and assigns that value to the sides data member
Die::Die(int *sidesIn)
{
   sides = *sidesIn;
}

//This function rolls the die and returns a random number 
//between 1 and the # of sides
int Die::roll()
{
   int number = rand()%sides+1;
   return number;
} 

