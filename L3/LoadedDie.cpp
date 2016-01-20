//*******************************************************************************
//Date: 10/15/2015
//Description: This is the function implementation file for the LoadedDie class.     
//*******************************************************************************
#include <cstdlib>
#include "LoadedDie.hpp"

//This is the default constructor
LoadedDie::LoadedDie()
{
   sides = 6;
}

//This constructor takes the number of sides as a parameter
LoadedDie::LoadedDie(int *sidesIn)
{
   sides = *sidesIn;
}

//This function "rolls" the loaded die
int LoadedDie::roll()
{
   int number = rand() % sides + 1;
   int half = sides / 2;//This is the lowest # that we want the rolls to be, 
                        //decimals will be truncated
   while (number < half) //This loop stops when number is greater than or equal to half
   {
      number = rand() % sides + 1;
   }
   return number;
}
