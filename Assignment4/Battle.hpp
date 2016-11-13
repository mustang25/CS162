/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 22, 2015
 ** Description: This defines the interface for the Battle class.
 *********************************************************************/
#ifndef Battle_hpp
#define Battle_hpp

#include <stdio.h>
#include <stdlib.h>
#include "Creature.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

class Battle {
private:
    Creature* p1;
    Creature* p2;
    Creature* winner;
    Creature* loser;
    int p1Attack;
    int p2Attack;
    int p1Defense;
    int p2Defense;
    int p1Health;
    int p2Health;
    int damage;
    int round;
    
    

public:
    Battle();
    Battle (Creature*, Creature*);
    void fight();
    void restoreHealth(Creature*);
    void setP1(Creature*);
    void setP2(Creature*);
    
};

#endif /* Battle_hpp */
