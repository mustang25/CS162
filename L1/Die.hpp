/*********************************************************************
 ** Author: Rob Navarro
 ** Date: September 30, 2015
 ** Description: This defines the interface for the Dice class.
 *********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die {
    
private:
    int sides;
    
public:
    Die(int s);
    int roll();
    
};


#endif
