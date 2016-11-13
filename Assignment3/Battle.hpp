/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 8, 2015
 ** Description: This defines the interface for the Battle class.
 *********************************************************************/
#ifndef Battle_hpp
#define Battle_hpp

#include <stdio.h>
#include <stdlib.h>
#include "Creature.hpp"

class Battle {
private:
    Creature* p1;
    Creature* p2;
    int p1Attack;
    int p2Attack;
    int p1Defense;
    int p2Defense;
    int p1Health;
    int p2Health;
    int damage;
    int round;

public:
    Battle (Creature*, Creature*);
    void fight();
    
};

#endif /* Battle_hpp */
