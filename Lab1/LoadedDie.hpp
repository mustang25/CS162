/*********************************************************************
 ** Author: Rob Navarro
 ** Date: September 30, 2015
 ** Description: This defines the interface for the Dice class.
 *********************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

class LoadedDie {
    
private:
    int sides;
    
public:
    LoadedDie(int s);
    int roll(int i, int r);
    
};


#endif
